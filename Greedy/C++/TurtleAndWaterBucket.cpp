// SOLUTION: Greedy
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long L;
    cin >> L;
    if (L % 5 == 0)
    {
        cout << (L / 5);
    }
    else
    {
        cout << (L / 5) + 1;
    }
    return 0;
}