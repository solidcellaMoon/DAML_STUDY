#include <iostream>

using namespace std;

class student
{
    private:
        char * name;
        int age;
        char * hobby;

    public:
        void ShowInfo();
        void SetInfo(char * _name, int _age, char * _hobby);
        void Study();
        void Sleep();
        
}; //Ŭ���� �ڿ��� �����ݷ��� ���ϴ�.

void student::ShowInfo(){
    cout << "�̸�: " << name << ", ����: " << age << ", ���: " << hobby << endl;
    }

void student::SetInfo(char * _name, int _age, char *_hobby){
    name = _name;
    age = _age;
    hobby = _hobby;
}

void student::Study(){
    cout << "������" << endl;
}

void student::Sleep(){
    cout << "�ڴ���" << endl;
}


int main() {

    student stu;

    stu.SetInfo("kkk", 10, "����");
    stu.ShowInfo();

    for(int i = 0; i < 2; i++){
        stu.Study();
        stu.Sleep();
    }

    return 0;
}