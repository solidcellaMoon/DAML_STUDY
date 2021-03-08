# [5] Loops

**[[링크]](https://www.hackerrank.com/challenges/30-loops/problem?h_r=email&unlock_token=f2d4fefb30835dc2f4f6500251f2d441962327f8&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder)**



``` c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int i=1;i<11;i++){
        cout << n << " x " << i << " = " << n*i << endl;
    }

    return 0;
}
```

