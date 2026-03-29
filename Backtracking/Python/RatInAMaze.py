class Solution:
    canGet = False
    visited = [[]]

    def Backtracking(self, i, j, maze):
        if i == len(maze) - 1 and j == len(maze[0]) - 1:
            self.canGet = True
        if self.canGet == True:
            return
        if maze[i][j] == 0:
            return
        if i + 1 <= len(maze) - 1:
            if self.visited[i + 1][j] == False:
                self.visited[i + 1][j] = True
                self.Backtracking(i + 1, j, maze)
                self.visited[i + 1][j] = False
        if j + 1 <= len(maze[0]) - 1:
            if self.visited[i][j + 1] == False:
                self.visited[i][j + 1] = True
                self.Backtracking(i, j + 1, maze)
                self.visited[i][j + 1] = False

    def canGetCheese(self, maze) -> bool:
        self.canGet = False
        self.visited = [[False] * len(maze[0]) for _ in range(len(maze))]
        self.Backtracking(0, 0, maze)
        return self.canGet
