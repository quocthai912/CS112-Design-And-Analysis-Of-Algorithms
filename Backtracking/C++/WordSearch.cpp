// Solution: Quay Lui (Backtracking)
// C++ lúc nào cũng phức tạp hơn
#include <bits/stdc++.h>
using namespace std;

bool visited[6][6] = {false};
vector<char> Solution;
vector<vector<char>> Result;

// Do INPUT là một chuỗi mảng 2 chiều nên ta phải có một hàm tiền xử lý trước
vector<vector<char>> parseBoard(const string &str)
{
    vector<vector<char>> board;
    vector<char> current_row;
    bool in_quotes = false;

    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '[')
        {
            current_row.clear(); // Bắt đầu một mảng mới
        }
        else if (str[i] == ']')
        {
            // Kết thúc mảng, đẩy current_row vào board nếu có dữ liệu
            if (!current_row.empty())
            {
                board.push_back(current_row);
                current_row.clear();
            }
        }
        else if (str[i] == '\'' || str[i] == '"')
        {
            in_quotes = !in_quotes; // Bật/tắt trạng thái đọc ký tự
        }
        else if (in_quotes)
        {
            // Nếu đang ở trong dấu nháy, lưu ký tự đó lại
            current_row.push_back(str[i]);
        }
    }
    return board;
}

void Backtracking(int i, int j, vector<vector<char>> board, string word)
{
    // Điều kiện quay lui
    if (Result.size() > 0)
        return;
    // Điều kiện quay lui
    if (Solution[Solution.size() - 1] != word[Solution.size() - 1])
        return;
    // Lời giải đã hoàn thành
    if (Solution.size() == word.length())
    {
        // Ghi nhận lời giải
        vector<char> temp;
        for (int k = 0; k < Solution.size(); k++)
        {
            temp.push_back(Solution[k]);
        }
        Result.push_back(temp);
    }
    // Đi đúng ô, tiếp tục thử đi sang các hướng khác, hướng nào sai thì quay lui
    // Các hướng phải thỏa điều kiện là vẫn nằm trong các ô của bảng và chưa từng đi tới
    if (i + 1 >= 0 && i + 1 <= board.size() - 1)
    {
        if (visited[i + 1][j] == false)
        {
            Solution.push_back(board[i + 1][j]);
            visited[i + 1][j] = true;
            Backtracking(i + 1, j, board, word);
            visited[i + 1][j] = false;
            Solution.pop_back();
        }
    }
    if (i - 1 >= 0 && i - 1 <= board.size() - 1)
    {
        if (visited[i - 1][j] == false)
        {
            Solution.push_back(board[i - 1][j]);
            visited[i - 1][j] = true;
            Backtracking(i - 1, j, board, word);
            visited[i - 1][j] = false;
            Solution.pop_back();
        }
    }
    if (j + 1 >= 0 && j + 1 <= board[0].size() - 1)
    {
        if (visited[i][j + 1] == false)
        {
            Solution.push_back(board[i][j + 1]);
            visited[i][j + 1] = true;
            Backtracking(i, j + 1, board, word);
            visited[i][j + 1] = false;
            Solution.pop_back();
        }
    }
    if (j - 1 >= 0 && j - 1 <= board[0].size() - 1)
    {
        if (visited[i][j - 1] == false)
        {
            Solution.push_back(board[i][j - 1]);
            visited[i][j - 1] = true;
            Backtracking(i, j - 1, board, word);
            visited[i][j - 1] = false;
            Solution.pop_back();
        }
    }
}

bool wordSearch(vector<vector<char>> board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            // Tìm điểm xuất phát, điểm xuất phát phải luôn có chữ cái trùng với chữ cái đầu tiên của word
            if (board[i][j] == word[0])
            {
                Solution.push_back(board[i][j]);
                visited[i][j] = true;
                Backtracking(i, j, board, word);
                // Đã tìm thấy từ, trả về True
                if (Result.size() > 0)
                    return true;
                // Không thể tìm thấy từ ở điểm xuất phát này, RESET và tìm ở điểm xuất phát khác
                Solution.clear();
                for (int k = 0; k < 6; k++)
                {
                    for (int m = 0; m < 6; m++)
                    {
                        visited[k][m] = false;
                    }
                }
            }
        }
    }
    // Duyệt qua toàn bộ ô chữ nhưng vẫn không tìm thấy, trả về False
    return false;
}

int main()
{
    vector<vector<char>> board;
    string word;
    string inputBoard;
    getline(cin, inputBoard);
    cin >> word;
    board = parseBoard(inputBoard);
    if (wordSearch(board, word) == true)
    {
        cout << "true";
    }
    else
        cout << "false";
    return 0;
}