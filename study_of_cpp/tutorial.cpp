#include <iostream>

using namespace std;

class Myclass{
    private:
        int num1;
        int num2;
    public:
        Myclass(int a, int b){
            num1 = a;
            num2 = b;
        }
        void ShowData(){
            cout << "num1: " << num1 << " num2: " << num2 << endl;
        }
};

int main() {

    Myclass m1(50,40);
    Myclass m2 = m1;
    Myclass m3(m2);

    m1.ShowData();
    m2.ShowData();
    m3.ShowData();

    return 0;
}