#include <iostream>
#include <cstring>

using namespace std;

class Myclass{
    private:
        char *str;
    public:
        Myclass(const char *aStr){
            str = new char[strlen(aStr)+1];
            strcpy(str, aStr);
        }
        Myclass(const Myclass& mc){ //추가한 내용
            str = new char[strlen(mc.str)+1];
            strcpy(str, mc.str);
        }
        ~Myclass(){
            delete []str;
            cout << "~Myclass() called" << endl;
        }
        void ShowData(){
            cout << "str: " << str << endl;
        }
};


int main() {

    Myclass mc1("MyClass!");
    Myclass mc2 = mc1;

    mc1.ShowData();
    mc2.ShowData();

    return 0;
}