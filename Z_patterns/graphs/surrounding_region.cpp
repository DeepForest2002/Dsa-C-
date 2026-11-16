#include <bits/stdc++.h>
using namespace std;

int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};

bool isValid(int r, int c, int row, int col)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return false;
    return true;
}

void dfs(vector<vector<char>> &boards, int row, int col, int i, int j)
{
    boards[i][j] = '#';
    for (int k = 0; k < 4; k++)
    {
        int r = i + x[k];
        int c = j + y[k];
        if (isValid(r, c, row, col) && boards[r][c] == '0')
            dfs(boards, row, col, r, c);
    }
    return;
}

void solve(vector<vector<char>> &board)
{
    int row = board.size();
    int col = board[0].size();

    // first row
    for (int j = 0; j < col; j++)
    {
        if (board[0][j] == 'O')
            dfs(board, row, col, 0, j);
    }

    // last row
    for (int j = 0; j < col; j++)
    {
        if (board[row - 1][j] == 'O')
            dfs(board, row, col, row - 1, j);
    }

    // first col
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == 'O')
            dfs(board, row, col, i, 0);
    }

    // last col
    for (int i = 0; i < row; i++)
    {
        if (board[i][col - 1] == 'O')
            dfs(board, row, col, i, col - 1);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == '#')
                board[i][j] = 'O';
            else
                board[i][j] = 'X';
        }
    }
}

int main()
{
    return 0;
}