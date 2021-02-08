#include <iostream>

namespace A{
    void Add(){
        printf("namespace A의 Add() 호출\n");
    }

    void Count(){
        printf("namespace A의 Count() 호출\n");
    }
}

using A::Add;

int main(){

    Add();
    A::Count();
    //그냥 Count();라고 쓰면 명시되지 않았기에 에러

    return 0;
}