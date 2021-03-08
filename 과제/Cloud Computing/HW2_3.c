#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define MAXSIZE 5

/*
이 프로그램은 프로세스 2개로 실행한다고 가정한다. (MPI_Type_vector 활용)

① 프로그램에 2차원 정수 배열 A[5][5]과 B[5][5]를 선언하고 모두 0으로 초기화해 놓는다.
② 프로세스 0은 배열 A를 다음과 같은 값으로 채운다. (A[i][j] = i * 5 + j).
③ 프로세스 1은 배열 B를 다음과 같은 값으로 채운다. (B[i][j] = i * 5 + j + 50).
④ 프로세스 0은 배열 A의 3번 열을 프로세스 1에게 보낸다.
프로세스 1은 받은 열을 배열 B의 4번 열에 저장한다.
⑤ 프로세스 1은 배열 B의 2번 열을 프로세스 0에게 보낸다.
프로세스 0은 받은 열을 배열 A의 4번 열에 저장한다.
⑥ 프로세스 1은 배열 B를 화면에 출력한다.
*/

int main(void)
{
    //정수 배열 A[5][5]과 B[5][5]를 선언하고 모두 0으로 초기화해 놓는다
    int A[MAXSIZE][MAXSIZE] = {0,}, B[MAXSIZE][MAXSIZE] = {0,};
    int myid, numprocs; // myid: 각 프로세스 번호, numprocs: 전체 프로세스 개수
    int i, j;
    MPI_Datatype columntype;
    MPI_Status status;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    

    //프로세스 0은 배열 A를 다음과 같은 값으로 채운다.
    //A[i][j] = i * 5 + j
    if (myid == 0){
        for(i=0; i<MAXSIZE; i++){
            for(j=0;j<MAXSIZE;j++){
                A[i][j] = i*5 + j;
            }
        }
    }

    //프로세스 1은 배열 B를 다음과 같은 값으로 채운다.
    //B[i][j] = i * 5 + j + 50
    if (myid == 0){
        for(i=0; i<MAXSIZE; i++){
            for(j=0;j<MAXSIZE;j++){
                B[i][j] = i*5 + j + 50;
            }
        }
    }

    //프로세스 0은 배열 A의 3번 열을 프로세스 1에게 보낸다.
    MPI_Type_vector(MAXSIZE, 1, MAXSIZE, MPI_INT, &columntype);
    MPI_Type_commit(&columntype);

    if (myid == 0){
        MPI_Send(
            &A[0][3], 1, columntype,
            1, 5, MPI_COMM_WORLD);
    }


    //프로세스 1은 받은 열을 배열 B의 4번 열에 저장한다.
    if(myid == 1){
        MPI_Recv(
            &B[0][4], 1, columntype,
            0, 5, MPI_COMM_WORLD, &status);
    }


    //프로세스 1은 배열 B의 2번 열을 프로세스 0에게 보낸다.
    if(myid == 1){
        MPI_Send(
            &B[0][2], 1, columntype,
            0, 5, MPI_COMM_WORLD);
    }

    //프로세스 0은 받은 열을 배열 A의 4번 열에 저장한다.
    if(myid == 0){
        MPI_Recv(
            &A[0][4], 1, columntype,
            1, 5, MPI_COMM_WORLD, &status);
    }

    //프로세스 1은 배열 B를 화면에 출력한다.
    if(myid == 1){
        for(i=0; i<MAXSIZE; i++){
            for(j=0;j<MAXSIZE;j++){
                printf("%d ", B[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;

}