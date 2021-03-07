# [6] Let's Review



**[[링크]](https://www.hackerrank.com/challenges/30-review-loop/problem?h_r=email&unlock_token=451ce6e6a171818022c2abb63caac8ffa4f4ecf5&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder)**

벡터 쓰는 법도 나중에 좀 찾아봐야할듯...



``` c++
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    string str;
    
    cin >> t;
    
    for(int i=0; i<t; i++){
        cin >> str;
        string odd, even;
        
        for(int j=0; j<str.length();j++){
            if(j%2 == 0) even += str[j];
            else odd += str[j];
        }
        cout << even << " " << odd << endl; //결과 출력
    }
    return 0;
}
```

