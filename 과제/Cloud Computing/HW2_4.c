#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define MAXSIZE 102 // 벽포함 전체 공간 크기
#define MINSIZE 100 // 방안 내부 크기
#define LOOP 100 // 온도 계산 반복 횟수

/*
프로세스 4개 또는 5개를 사용하여 실행할 때 문제없이 실행되어야 한다.
각 프로세스가 담당할 구역은 임의로 정할 수 있으나,
프로세스당 workload는 균등해야 한다. 

① 방의 크기는 102x102이다. 가장자리 외벽을 제외한 내부의 크기는 100x100이다.
② 방의 외벽과 내부의 초기 온도는 0도이다. 외벽의 온도는 항상 0도이다.
③ 벽난로는 방의 북쪽에 있으며, 항상 200도의 열을 낸다. (위치 R[0][40]~R[0][59] 지점)
④ 방의 내부 (100x100)의 온도만 10,000 회 update 한다. (벽난로와 외벽의 온도는 고정)
⑤ 방의 온도를 update 할 때는 배열 2개를 사용하지 않고,
원래 배열 상에서 그대로 (프로그램에서와 같이) update 한다.
⑥ 한참 후의 방의 온도 계산이 끝나고 나면,
사용자가 지정하는 구역의 온도를 화면에 출력해준다. (계산 결과 확인용)

*/

int main(void)
{
    double R[MAXSIZE][MAXSIZE] = {0.0}; // 방안의 초기 온도는 모두 0
    int myid, numprocs; // myid: 각 프로세스 번호, numprocs: 전체 프로세스 개수
    int subsize = 0; // 전체 배열을 각 프로세스에게 몇줄의 데이터를 보내는가?
    int tag = 5; // 태그 정보

    MPI_Datatype exchangeType; // 각 프로세스마다 겹치는 데이터 전송용 단위
    MPI_Datatype resultType; // 최종 온도 전송을 위한 단위
    MPI_Status status;

    int new_i; // 각 프로세스에서 작업한 배열 위치를 기록하기 위한 인덱스
    int i, j, k, m1, m2, n1, n2;


    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);


    subsize = MINSIZE / numprocs; // 100*100에서 n=5일 경우, subsize = 20
    new_i = subsize*myid; // 시작 위치일 경우 +1, 끝 위치일 경우 +subsize

    // 벽난로의 온도 (계속 유지한다)
    if(myid == 0){
        for(j=40;j<60;j++){
            R[0][j] = 200.0;
        }
    }
    //난로가 포함된 정보를 전체 프로세스에 전달!
    MPI_Bcast(R,MAXSIZE*MAXSIZE,MPI_DOUBLE,0,MPI_COMM_WORLD);

    // 1. 현재 온도 갱신 & 전송 단계---------------------


    // 각 프로세스마다 겹치는 데이터 전송용 단위 - 가로(MAXSIZE)*세로(1)의 직사각형 형태
    MPI_Type_vector(MAXSIZE, 1, 1, MPI_DOUBLE, &exchangeType);
    MPI_Type_commit(&exchangeType);

    // 각 프로세스가 할 일 
    for(k=0;k<LOOP;k++){
        //각 구역의 방 온도 업데이트
        for(i=1;i<=subsize;i++){
            for(j=1;j<=MINSIZE;j++){
                R[new_i+i][j] =
                0.25 * (R[new_i+i][j-1]+ R[new_i+i][j+1]+ R[new_i-1+i][j] + R[new_i+1+i][j]);
            }
        }

        //이웃한 프로세스로 전달 과정 - procs 번호에 따라 경우를 나누어 작성
        if(myid == numprocs-1){
            MPI_Sendrecv(
                &R[new_i+1][0], 1, exchangeType, numprocs-2, tag,
                &R[new_i][0], 1, exchangeType, numprocs-2, tag,
                MPI_COMM_WORLD, &status);

        } else if(myid != 0){
            MPI_Sendrecv(
                &R[new_i+1][0], 1, exchangeType, myid-1, tag,
                &R[new_i][0], 1, exchangeType, myid-1, tag,
                MPI_COMM_WORLD, &status);

            MPI_Sendrecv(
                &R[new_i+subsize][0], 1, exchangeType, myid+1, tag,
                &R[new_i+subsize+1][0], 1, exchangeType, myid+1, tag,
                MPI_COMM_WORLD, &status);

        } else{
            MPI_Sendrecv(
                &R[new_i+subsize][0], 1, exchangeType, myid+1, tag,
                &R[new_i+subsize+1][0], 1, exchangeType, myid+1, tag,
                MPI_COMM_WORLD, &status);
        }
    }

    // 2. 최종 온도 전송 단계---------------------


    // 최종 온도 전송을 위한 단위 - 가로(MINSIZE)*세로(1)의 직사각형 형태
    MPI_Type_vector(MINSIZE, 1, 1, MPI_DOUBLE, &resultType);
    MPI_Type_commit(&resultType);

    //각 프로세스는 0번 프로세스로 최종온도 전송
    if(myid != 0){
        for(i=1;i<=subsize;i++){
                MPI_Send(&R[new_i+i][1],1,resultType,0,tag,MPI_COMM_WORLD);
        }
    } else{ // 0번 프로세스는 데이터를 받는다
            for(k=1;k<=numprocs-1;k++){
                for(i=1;i<=subsize;i++){
                    MPI_Recv(&R[subsize*k+i][1],1,resultType,k,tag,MPI_COMM_WORLD,&status);
                }
            }
    }

    // 최종 온도 출력!
    if(myid == 0){
        printf("출력할 구간 (m1, m2, n1, n2) : ");
        scanf("%d %d %d %d", &m1, &m2, &n1, &n2);

        for(i=m1; i<=m2; i++){ // 세로구간
            for(j=n1; j<=n2; j++){ // 가로구간
                printf("%7.1f",R[i][j]);
            }
            printf("\n");
        }
    }


    MPI_Finalize();
    return 0;

}