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
        
}; //클래스 뒤에는 세미콜론을 씁니다.

void student::ShowInfo(){
    cout << "이름: " << name << ", 나이: " << age << ", 취미: " << hobby << endl;
    }

void student::SetInfo(char * _name, int _age, char *_hobby){
    name = _name;
    age = _age;
    hobby = _hobby;
}

void student::Study(){
    cout << "공부중" << endl;
}

void student::Sleep(){
    cout << "자는중" << endl;
}


int main() {

    student stu;

    stu.SetInfo("kkk", 10, "게임");
    stu.ShowInfo();

    for(int i = 0; i < 2; i++){
        stu.Study();
        stu.Sleep();
    }

    return 0;
}