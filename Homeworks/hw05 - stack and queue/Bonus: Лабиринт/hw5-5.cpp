#include<iostream>
#include<queue>
using namespace std;
const int MAX = 1000;
bool forbidden[MAX][MAX];
int used[MAX][MAX];

int op[4][2] = { {1,0}, {-1,0}, {0,1} ,{0,-1} }; //right left up down

bool checkExit(int newX, int newY, int fX, int fY) {
    return newX == fX && newY == fY;
}

bool checkIndex(int newX, int newY, int N, int M) {
    if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
        return true;
    }
    return false;
}

int main() {

    int** right = new int*[MAX];
    for (int i = 0; i < MAX; i++)
    {
        right[i] = new int[MAX];
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            right[i][j] = -1;
        }
    }

    int** left = new int* [MAX];
    for (int i = 0; i < MAX; i++)
    {
        left[i] = new int[MAX];
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            left[i][j] = -1;
        }
    }

    int** up = new int* [MAX];
    for (int i = 0; i < MAX; i++)
    {
        up[i] = new int[MAX];
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            up[i][j] = -1;
        }
    }

    int** down = new int* [MAX];
    for (int i = 0; i < MAX; i++)
    {
        down[i] = new int[MAX];
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            down[i][j] = -1;
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            used[i][j] = -1;
        }
    }
    int N, M;
    cin >> N >> M;
    int sX=0, sY=0, fX=0, fY=0;
    queue<pair<int, int>> q;

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            char temp;
            cin >> temp;
            if (temp == '#' ) {
                forbidden[row][col] = true;
            }
            else if (temp == 'S') {
                sX = row;
                sY = col;
                q.push(make_pair(sX, sY));
                used[row][col] = 0;
            }
            else if(temp == 'F') {
                fX = row;
                fY = col;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int x = -1;
        for (int j = 0; j < M; j++) {
            if (forbidden[i][j]) {
                x = -1;
            }
            else {
                left[i][j] = x;
                if (x == -1) x = j;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int x = -1;
        for (int j = M - 1; j >= 0; j--) {
            if (forbidden[i][j]) {
                x = -1;
            }
            else {
                right[i][j] = x;
                if (x == -1) x = j;
            }
        }
    }

    for (int j = 0; j < M; j++) {
        int x = -1;
        for (int i = 0; i < N; i++) {
            if (forbidden[i][j]) {
                x = -1;
            }
            else {
                up[i][j] = x;
                if (x == -1) x = i;
            }
        }
    }

    for (int j = 0; j < M; j++) {
        int x = -1;
        for (int i = N - 1; i >= 0; i--) {
            if (forbidden[i][j]) {
                x = -1;
            }
            else {
                down[i][j] = x;
                if (x == -1) x = i;
            }
        }
    }
 

    bool exit = false;
   
    while (!q.empty() && !exit) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first; 
        int y = curr.second;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + op[i][0];
            int newY = y + op[i][1];
            if (checkIndex(newX, newY,N,M) && forbidden[newX][newY] == false && used[newX][newY] == -1) {
                if (checkExit(newX, newY, fX, fY)) {
                   
                    exit = true;
                }
                    used[newX][newY] = used[x][y] + 1;
                    q.push({ newX,newY });
            }
        }
        if (left[x][y] != -1 && used[x][left[x][y]] == -1) {
            if (checkExit(x, left[x][y], fX, fY)) {
               
                exit = true;
            }
            used[x][left[x][y]] = used[x][y] + 1;
            q.push({ x, left[x][y] });
        }
        if (right[x][y] != -1 && used[x][right[x][y]] == -1) {
            if (checkExit(x, right[x][y], fX, fY)) {
             
                exit = true;
            }
            used[x][right[x][y]] = used[x][y] + 1;
            q.push({ x, right[x][y] });
        }
        if (up[x][y] != -1 && used[up[x][y]][y] == -1) {
            if (checkExit(up[x][y], y, fX, fY)) {
               
                exit = true;
            }
            used[up[x][y]][y] = used[x][y] + 1;
            q.push({ up[x][y], y });
        }
        if (down[x][y] != -1 && used[down[x][y]][y] == -1) {
            if (checkExit(down[x][y], y, fX, fY)) {
           
                exit = true;
            }
            used[down[x][y]][y] = used[x][y] + 1;
            q.push({ down[x][y], y });
        }

    }

    cout << used[fX][fY];

 


    for (int i = 0; i < MAX; i++)
    {
        delete[] right[i];
    }
    delete[] right;
    for (int i = 0; i < MAX; i++)
    {
        delete[] left[i];
    }
    delete[] left;
    for (int i = 0; i < MAX; i++)
    {
        delete[] up[i];
    }
    delete[] up;
    for (int i = 0; i < MAX; i++)
    {
        delete[] down[i];
    }
    delete[] down;

    return 0;
}