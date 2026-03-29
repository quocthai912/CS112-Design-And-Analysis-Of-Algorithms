#include <bits/stdc++.h>
using namespace std;

bool canGet = false;
bool visited[100][100] = {false};

void Backtracking(int i, int j, vector<vector<int>> &maze)
{
    // Ghi nhận đã đi đến đích
    if (i == maze.size() - 1 && j == maze[0].size() - 1)
    {
        canGet = true;
    }
    // Cắt các nhánh đệ quy phía sau vì đã đi đến đích
    if (canGet == true)
        return;
    // Chạm chướng ngại vật, quay lui
    if (maze[i][j] == 0)
        return;
    // Đi thành công đến ô này, tiếp tục đi thử sang các ô khác
    if (i + 1 <= maze.size() - 1)
    {
        // Nếu ô này chưa đi, đi thử
        if (visited[i + 1][j] == false)
        {
            visited[i + 1][j] = true;
            Backtracking(i + 1, j, maze);
            visited[i + 1][j] = false;
        }
    }
    if (j + 1 <= maze[0].size() - 1)
    {
        if (visited[i][j + 1] == false)
        {
            visited[i][j + 1] = true;
            Backtracking(i, j + 1, maze);
            visited[i][j + 1] = false;
        }
    }
}

bool canGetCheese(vector<vector<int>> &maze)
{
    // Reset lại mảng Visited cho mỗi Test Case
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            visited[i][j] = false;
        }
    }
    // Tương tự với biến canGet
    canGet = false;
    Backtracking(0, 0, maze);
    return canGet;
}