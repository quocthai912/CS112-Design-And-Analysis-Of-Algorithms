// SOLUTION: Greedy + Sorting
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> gifts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> gifts[i];
    }
    sort(gifts.begin(), gifts.end());
    int min_distance = INT_MAX;
    int endSlidingWindow = m - 1;
    for (int i = 0; i < n; i++)
    {
        int distance = gifts[endSlidingWindow] - gifts[i];
        if (distance < min_distance)
            min_distance = distance;
        endSlidingWindow++;
        if (endSlidingWindow > n - 1)
            break;
    }
    cout << min_distance;
    return 0;
}