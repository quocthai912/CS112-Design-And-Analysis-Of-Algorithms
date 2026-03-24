// SOLUTION: Brute Force (Vét Cạn)
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void Canarium(long long k, long long &m, long long &n)
{
    /*
    Hàm chính được sử dụng để giải quyết bài toán
    Args:
       k (int): Số hạt trám thu thập được
       m, n (int): Cặp nghiệm của bài toán
    */
    long long N = (4 * k) - 1;
    long long start = sqrt(N);
    if (start % 2 == 0)
    {
        start -= 1;
    }
    for (long long i = start; i >= 3; i -= 2)
    {
        if (N % i == 0)
        {
            long long a = i;
            long long b = N / i;
            m = (a - 1) / 2;
            n = (b - 1) / 2;
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    vector<long long> testCase;
    for (int j = 0; j < t; j++)
    {
        long long k;
        cin >> k;
        testCase.push_back(k);
    }
    for (int j = 0; j < testCase.size(); j++)
    {
        long long m = -1;
        long long n = -1;
        Canarium(testCase[j], m, n);
        cout << m << " " << n << endl;
    }
    return 0;
}