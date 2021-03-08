#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define MAXSIZE 1000

//프로세스 P0는 정수 배열 A[1000]를 임의의 양수로 채워 놓는다.
//이 배열에 홀수가 몇 개 들어있는지 계산하는 효율적인 MPI 프로그램을 작성하시오.

int main(void)
{
    int myid, numprocs;
    int subsize, myresult, result; // myres: 프로세스의 결과, res: 전체 결과
    int A[MAXSIZE], *recvA; // recvA는 프로세스마다 할당받을 A의 일부분이다.
    int i;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    // 0번 프로세스에서 A배열에 숫자를 채운다.
    // A에는 1~1000까지의 숫자가 들어있다.
    if (myid == 0){
        for(i=0; i<MAXSIZE; i++) A[i] = i+1 ;
    }

    subsize = MAXSIZE/numprocs; // subsize = 1000/프로세스개수
    recvA = (int *)malloc(sizeof(int)*subsize); // recvA의 길이 = subsize

    //Scatter로 각 프로세스에 보낸다
    MPI_Scatter(
        A, subsize, MPI_INT,
        recvA, subsize, MPI_INT,
        0, MPI_COMM_WORLD);

    //각 프로세스에서 홀수의 개수를 구한다.
    myresult = 0;
    for(i=0; i<subsize; i++){
        if(recvA[i]%2 != 0) myresult++;
    }

    // Compute global sum
    MPI_Reduce(&myresult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    //0번 프로세스에서 최종결과를 출력한다.
    if (myid == 0){
        printf(
            "%d부터 %d까지의 홀수는 %d개 입니다.\n",
            A[0], A[MAXSIZE-1], result);
    }

    MPI_Finalize();
    return 0;

}