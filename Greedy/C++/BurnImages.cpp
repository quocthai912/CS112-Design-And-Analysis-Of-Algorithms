// SOLUTION: Greedy + Sorting
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> images(n);
    for (int i = 0; i < n; i++)
    {
        cin >> images[i];
    }
    sort(images.begin(), images.end());
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (W >= images[i])
        {
            count += 1;
            W -= images[i];
        }
        else
            break;
    }
    cout << count;
    return 0;
}