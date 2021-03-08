# [2] Operators



**[[링크]](https://www.hackerrank.com/challenges/30-operators/problem?h_r=email&unlock_token=dcf8c44aa9470fa6a411b3e177cd656ea51ec7a5&utm_campaign=30_days_of_code_continuous&utm_medium=email&utm_source=daily_reminder)**



``` c++
#define calc(m,x) (m*(x)/100)
using namespace std;

void solve(double meal_cost, int tip_percent, int tax_percent) {
    double(answer);
    answer = meal_cost + calc(meal_cost,tip_percent) + calc(meal_cost,tax_percent);
    cout << fixed << setprecision(0)<< answer << endl;
}
```



``` c++
#include <bits/stdc++.h>
#define calc(m,x) (m*(x)/100)

using namespace std;

// Complete the solve function below.
void solve(double meal_cost, int tip_percent, int tax_percent) {
    double(answer);
    answer = meal_cost + calc(meal_cost,tip_percent) + calc(meal_cost,tax_percent);
    cout << fixed << setprecision(0)<< answer << endl;
}

int main()
{
    double meal_cost;
    cin >> meal_cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tip_percent;
    cin >> tip_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int tax_percent;
    cin >> tax_percent;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    solve(meal_cost, tip_percent, tax_percent);

    return 0;
}

```

