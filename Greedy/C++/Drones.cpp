#include <bits/stdc++.h>
using namespace std;

struct Drone
{
    int pos;
    int dis;
};

bool cmp(Drone d1, Drone d2)
{
    return d1.dis < d2.dis;
}

void Solution(vector<Drone> drones)
{
    sort(drones.begin(), drones.end(), cmp);
    int second = 0;
    for (int i = 0; i < drones.size(); i++)
    {
        if (second == drones[i].dis)
        {
            cout << -1;
            return;
        }
        second++;
    }
    for (int i = 0; i < drones.size(); i++)
    {
        cout << drones[i].pos << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Drone> drones;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        Drone temp;
        temp.pos = i + 1;
        // Chebyshev Distance
        temp.dis = max(abs(x), abs(y));
        drones.push_back(temp);
    }
    Solution(drones);
    return 0;
}