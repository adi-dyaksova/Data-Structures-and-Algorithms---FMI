#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int MAX = 25;
char arr[MAX][MAX];
bool visited[MAX][MAX];
int rows, cols;
int result;
int K;
void solve(int counter, int x, int y) {
    if (arr[x][y] == 'e') {
        if (counter == K+1)result++;
        return;
    }
    counter++;
    visited[x][y] = true;

    if (x > 0 && arr[x - 1][y] != 'x' && !visited[x - 1][y]) {
        solve(counter, x - 1, y);
    }
    if (x < rows - 1 && arr[x + 1][y] != 'x' && !visited[x + 1][y]) { 
        solve(counter, x + 1, y);
    }
    if (y > 0 && arr[x][y - 1] != 'x' && !visited[x][y - 1]) {
        solve(counter, x, y-1);
    }
    if (y < cols - 1 && arr[x][y + 1] != 'x' && !visited[x][y + 1]) { 
        solve(counter, x, y+1);
    }
    visited[x][y] = false;
}

int main() {

    cin >> rows >> cols;
    K = rows * cols;
    int startX, startY;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != '-')K--;
            if (arr[i][j] == 's') {
                startX = i;
                startY = j;
            }
        }
    }
    solve(0,startX, startY); 
    cout << result;
    return 0;
}
