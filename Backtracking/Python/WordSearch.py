# Solution: Quay Lui (Backtracking)
# ACCEPT
import ast

visited = [[False] * 6 for _ in range(6)]
solution = []
result = []


def Backtracking(i, j, board, word):
    # Đã tìm được lời giải
    if len(result) > 0:
        return
    # Bước đi sai, quay lui
    if solution[-1] != word[len(solution) - 1]:
        return
    # Lưu lời giải S cho bài toán
    if len(solution) == len(word):
        temp = []
        for k in range(len(solution)):
            temp.append(solution[k])
        result.append(temp)
    # Chưa tìm được lời giải và đi đúng, tiến hành đi tiếp sang các ô khác
    if j + 1 >= 0 and j + 1 <= len(board[0]) - 1:
        # Kiểm tra xem ô đã đi chưa, nếu chưa đi, tiến hành đi thử sang ô này
        if visited[i][j + 1] == False:
            solution.append(board[i][j + 1])
            visited[i][j + 1] = True
            Backtracking(i, j + 1, board, word)
            # Quay Lui khi đi sai, trả về trạng thái trước đó
            visited[i][j + 1] = False
            solution.pop()
    if j - 1 >= 0 and j - 1 <= len(board[0]) - 1:
        if visited[i][j - 1] == False:
            solution.append(board[i][j - 1])
            visited[i][j - 1] = True
            Backtracking(i, j - 1, board, word)
            visited[i][j - 1] = False
            solution.pop()
    if i + 1 >= 0 and i + 1 <= len(board) - 1:
        if visited[i + 1][j] == False:
            solution.append(board[i + 1][j])
            visited[i + 1][j] = True
            Backtracking(i + 1, j, board, word)
            visited[i + 1][j] = False
            solution.pop()
    if i - 1 >= 0 and i - 1 <= len(board) - 1:
        if visited[i - 1][j] == False:
            solution.append(board[i - 1][j])
            visited[i - 1][j] = True
            Backtracking(i - 1, j, board, word)
            visited[i - 1][j] = False
            solution.pop()


def WordSearch(board, word):
    global visited, solution
    for i in range(len(board)):
        for j in range(len(board[0])):
            # Tọa độ xuất phát
            if board[i][j] == word[0]:
                solution.append(board[i][j])
                visited[i][j] = True
                Backtracking(i, j, board, word)
                if len(result) > 0:
                    return True
                visited = [[False] * 6 for _ in range(6)]
                solution = []
    return False


if __name__ == "__main__":
    board_str = input()
    board = ast.literal_eval(board_str)
    word = input()
    if WordSearch(board, word) == True:
        print("true")
    else:
        print("false")
