#include <iostream>

namespace A{
    void Add(){
        printf("namespace A�� Add() ȣ��\n");
    }

    void Count(){
        printf("namespace A�� Count() ȣ��\n");
    }
}

using A::Add;

int main(){

    Add();
    A::Count();
    //�׳� Count();��� ���� ��õ��� �ʾұ⿡ ����

    return 0;
}