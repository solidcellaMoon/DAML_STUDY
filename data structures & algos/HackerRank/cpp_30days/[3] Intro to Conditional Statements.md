# [3] Intro to Conditional Statements

**[[링크]](https://www.hackerrank.com/challenges/30-conditional-statements/problem?h_r=email&unlock_token=f2816ab11ea39758ffa477af77baf80b9a32ff07&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder)**

``` c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (N % 2 == 1){
        cout << "Weird" << endl;
    } else if (N > 1 && N < 6){
        cout << "Not Weird" << endl;
    } else if (N < 21){
        cout << "Weird" << endl;
    } else{
        cout << "Not Weird" << endl;
    }

    return 0;
}
```

