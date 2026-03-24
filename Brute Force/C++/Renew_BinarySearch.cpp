// SOLUTION: Binary Search
#include <iostream>
using namespace std;

__int128 trees_of_days(unsigned long long a, unsigned long long k, unsigned long long b, unsigned long long m, unsigned long long days)
{
    /*
    Hàm được dùng để tính tổng số cây hai đội chặt được trong n ngày cho trước
    Args:
       a (int): Số cây đội I hạ được mỗi ngày
       k (int): Các ngày nghỉ của đội I (k, 2k, 3k,...)
       b (int): Số cây đội II hạ được mỗi ngày
       m (int): Các ngày nghỉ của đội II (m, 2m, 3m,...)
       days (int): Số ngày cho trước, hàm sẽ tính tổng số cây hai đội chặt được trong (days) ngày này
    Returns:
       trees_team_one + trees_team_two (int): Tổng số cây hai đội chặt được trong (days) ngày cho trước
    */
    __int128 trees_team_one = (days - (days / k)) * a;
    __int128 trees_team_two = (days - (days / m)) * b;
    return trees_team_one + trees_team_two;
}

int main()
{
    unsigned long long a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;
    unsigned long long left = 1;
    unsigned long long right = n;
    unsigned long long days = 1;
    while (left <= right)
    {
        unsigned long long mid = (left + right) / 2;
        __int128 trees = trees_of_days(a, k, b, m, mid);
        if (trees >= n)
        {
            days = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << days;
    return 0;
}