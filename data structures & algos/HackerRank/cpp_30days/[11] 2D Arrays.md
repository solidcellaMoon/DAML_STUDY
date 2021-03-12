# [11] 2D Arrays



**[[링크]](https://www.hackerrank.com/challenges/30-2d-arrays/problem?h_r=email&unlock_token=354ae326cb40d855aba28156d8fe81e4ee2748b1&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder)**



`vector`의 용도도 대충 알 수 있다.

파이썬으로 해결했던 똑같은 문제: [[링크]](https://github.com/solidcellaMoon/studynote/blob/master/data%20structures%20%26%20algos/HackerRank/Interview%20Preparation%20Kit/1%20Arrays/2D%20Array%20-%20DS.md)





``` c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr(6);
    
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    //My code ---
    
    int sum, max = -9*7;
    int top, middle, down = 0;
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            top = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            middle = arr[i+1][j+1];
            down = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            
            sum = top + middle + down;  
            if (sum > max) max = sum;
        }
    }
    
    cout << max << endl;
    
    return 0;
}

```

