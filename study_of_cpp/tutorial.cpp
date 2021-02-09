#include <iostream>

//¡Ú
using namespace std;

void func(int a){
    cout << "--void func(int a)--" << endl;
}

void func(int a, int b){
    cout << "--void func(int a, int b)--" << endl;
}

void func(char ch){
    cout << "--void func(char ch)--" << endl;
}

int main(){

    func(4);
    func(5,6);
    func('a');

    return 0;
}