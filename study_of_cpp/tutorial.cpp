#include <iostream>

using namespace std;

int main() {
    int studentNum, total = 0;
    int* studentScore;
    int i;

    //printf("학생 수를 입력하세요: ");
    cout << "학생 수를 입력하세요: ";
    //scanf("%d", &studentNum);
    cin >> studentNum;
    //studentScore = (int *)malloc(sizeof(int)*studentNum);
    studentScore = new int[studentNum];

    for (i=0; i<studentNum; i++){
        //printf("%d번 학생의 점수: ", i+1);
        cout << i + 1 << "번 학생의 점수: ";
        //scanf("%d",&studentScore[i]);
        cin >> studentScore[i];
        //total += studentScore[i];
        total += studentScore[i];
    }

    //printf("모든 학생의 평균: %d\n", total/studentNum);
    cout << "모든 학생의 평균: " << total / studentNum << endl;
    
    //free(studentScore);
    delete []studentScore;

    return 0;
}