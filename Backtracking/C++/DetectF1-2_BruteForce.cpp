// SOLUTION: Vét Cạn (Brute Force)
// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Ý tưởng tương tự Code Python
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    int N, F0, D;
    cin >> N >> F0 >> D;
    vector<bool> nhiem_benh;
    vector<Point> people;
    for (int i = 0; i < N; i++)
    {
        Point A;
        cin >> A.x >> A.y;
        nhiem_benh.push_back(false);
        people.push_back(A);
    }
    F0 -= 1;
    int count_F1 = 0;
    int count_F2 = 0;
    for (int i = 0; i < N; i++)
    {
        if (i != F0)
        {
            if (hypot((people[F0].x - people[i].x), (people[F0].y - people[i].y)) < D)
            {
                count_F1 += 1;
                nhiem_benh[i] = true;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (i != F0 && nhiem_benh[i] == false)
        {
            for (int j = 0; j < N; j++)
            {
                if (j != i && j != F0 && nhiem_benh[j] == true)
                {
                    if (hypot((people[j].x - people[i].x), (people[j].y - people[i].y)) < D)
                    {
                        count_F2 += 1;
                        break;
                    }
                }
            }
        }
    }
    cout << count_F1 << " " << count_F2;
    return 0;
}