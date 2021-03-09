# [8] Dictionaries and Maps



**[[링크]](https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?h_r=email&unlock_token=c87e16a337b14c1597a98e91ac0b3a263e3de069&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder)**

c++ map 관련 블로그 글중엔 마땅히 정리 잘 된게 없어보임... 나중에 더 찾아보기로.



``` c++
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    map <string, int> dict;
    string name;
    int number, n;
    
    /*딕셔너리에 n개만큼 입력받음*/
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> name >> number;
        dict[name] = number;
    }
    
    /*쿼리 입력*/
    while(cin >> name){
        if(dict[name]){
            cout << name << "=" << dict[name] << endl;
        } else{ //딕셔너리에 해당 키가 없으면 false가 출력됨
            cout << "Not found" << endl;
        }
    }
     
    return 0;
}
```

