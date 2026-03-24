// SOLUTION: Brute Force (Vét Cạn)
#include <iostream>
using namespace std;

int main()
{
    unsigned long long a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;
    unsigned long long so_cay_chat_duoc = 0;
    unsigned long long days = 0;
    while (so_cay_chat_duoc < n)
    {
        if (days % k != 0)
        {
            so_cay_chat_duoc += a;
        }
        if (days % m != 0)
        {
            so_cay_chat_duoc += b;
        }
        if (so_cay_chat_duoc >= n)
        {
            break;
        }
        days += 1;
    }
    cout << days;
    return 0;
}
