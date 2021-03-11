# [10] Binary Numbers



**[[링크]](https://www.hackerrank.com/challenges/30-binary-numbers/problem)**



좀 더 간략화해도 될 것 같은데 일단 여기까지만..



``` c++
#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int main()
{
    int n;
    int idx, cntOne, maxNum = 0;
    //string binary = "";
    
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string temp = bitset<20>(n).to_string();
    
    // 필요없는 자릿수 제거하기 
    for (int i = 0; i < temp.length(); i++){
        if(temp[i] == '1'){
            idx = i;
            break;
        }
    }
    //최종 이진수
    for(int i = idx; i < temp.length(); i++){
        //binary += temp[i];
        if(temp[i] == '1'){
            cntOne ++;
            if(cntOne > maxNum) maxNum = cntOne;
        } else cntOne = 0;
        
    }
    
    cout << maxNum << endl;
    

    return 0;
}

```

