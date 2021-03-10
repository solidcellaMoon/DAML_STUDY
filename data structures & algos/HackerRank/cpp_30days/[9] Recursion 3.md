# [9] Recursion 3



**[[링크]](https://www.hackerrank.com/challenges/30-recursion/problem?h_r=email&unlock_token=733f46a260d1d369704479f27f6b0dbecb7f9d17&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder)**



``` c++
#include <bits/stdc++.h>

using namespace std;

// Complete the factorial function below.
int factorial(int n) {
    if (n > 1) {
        return n*factorial(n-1);
    } else {
        return 1;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = factorial(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

```

