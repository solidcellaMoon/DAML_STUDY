#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define MAXSIZE 10

/*
① 프로그램에 2차원 정수 배열 A[10][10]을 선언한다.
② 프로세스 0은 이 배열의 각 원소를 다음과 같은 값으로 채운다. (A[i][j] = i * 10 + j).
③ 프로세스 0은 MPI_Bcast( )를 통해 다른 프로세스들에게 배열 A[ ][ ]의 값을 복사해 준다.
④ 프로세스 1은 (대표로) 자신의 배열 A[ ][ ]를 화면에 출력한다. (전송 확인을 위한 것임.)
*/

int main(void)
{
    int myid, numprocs; // myid: 각 프로세스 번호, numprocs: 전체 프로세스 개수
    int A[MAXSIZE][MAXSIZE];
    int i, j;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    // 0번 프로세스에서 A배열에 숫자를 채운다.
    // A[i][j] = i*10 + j
    if (myid == 0){
        for(i=0; i<MAXSIZE; i++){
            for(j=0;j<MAXSIZE;j++){
                A[i][j] = i*10 + j;
            }
        }
    }

    //프로세스 0은 MPI_Bcast( )를 통해 다른 프로세스들에게 배열 A[ ][ ]의 값을 복사해 준다.
    MPI_Bcast(
        A, MAXSIZE*MAXSIZE, MPI_INT,
        0, MPI_COMM_WORLD);

    //프로세스 1은 (대표로) 자신의 배열 A[ ][ ]를 화면에 출력한다. (전송 확인을 위한 것임.)
    if(myid == 1){
        for(i=0; i<MAXSIZE; i++){
            for(j=0;j<MAXSIZE;j++){
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;

}