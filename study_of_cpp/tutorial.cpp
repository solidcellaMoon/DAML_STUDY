#include <iostream>

using namespace std;

struct student
{
    private:
        int id;
        char *name;
        float precentage;

    public:
        void Show();
        void SetInfo(int _id, char * _name, float _percentage);
        
}; //����ü �ڿ��� �����ݷ��� ���ϴ�.

void student::Show(){
    cout << "���̵�: " << id << endl;
    cout << "�̸�: " << name << endl;
    cout << "����� " << precentage << endl;
    }

void student::SetInfo(int _id, char * _name, float _percentage){
    id = _id;
    name = _name;
    precentage = _percentage;
}

int main() {

    student s;

    s.SetInfo(1, "kkk", 90.5);
    s.Show();

    return 0;
}