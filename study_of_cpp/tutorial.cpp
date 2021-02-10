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
        
}; //구조체 뒤에는 세미콜론을 씁니다.

void student::Show(){
    cout << "아이디: " << id << endl;
    cout << "이름: " << name << endl;
    cout << "백분율 " << precentage << endl;
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