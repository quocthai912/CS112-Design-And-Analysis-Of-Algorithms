// SOLUTION: Brute Force (Vét Cạn)
#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long steps = 0;
    while (a * d != b * c)
    {
        a += 1;
        b += 1;
        long long ucln = gcd(a, b);
        a /= ucln;
        b /= ucln;
        if (a * d > b * c)
        {
            cout << 0;
            return 0;
        }
        steps += 1;
    }
    cout << steps;
    return 0;
}
