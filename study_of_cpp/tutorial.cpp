#include <iostream>

using namespace std;

int main() {
    int studentNum, total = 0;
    int* studentScore;
    int i;

    //printf("�л� ���� �Է��ϼ���: ");
    cout << "�л� ���� �Է��ϼ���: ";
    //scanf("%d", &studentNum);
    cin >> studentNum;
    //studentScore = (int *)malloc(sizeof(int)*studentNum);
    studentScore = new int[studentNum];

    for (i=0; i<studentNum; i++){
        //printf("%d�� �л��� ����: ", i+1);
        cout << i + 1 << "�� �л��� ����: ";
        //scanf("%d",&studentScore[i]);
        cin >> studentScore[i];
        //total += studentScore[i];
        total += studentScore[i];
    }

    //printf("��� �л��� ���: %d\n", total/studentNum);
    cout << "��� �л��� ���: " << total / studentNum << endl;
    
    //free(studentScore);
    delete []studentScore;

    return 0;
}