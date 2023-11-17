#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int op[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool used[500][500];

int main() {
    int N, M;
    cin >> M>> N;
    int** arr = new int*[500];
    for (int i = 0; i < 500; i++)
    {
        arr[i] = new int[500];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    int** arr2 = new int* [500];
    for (int i = 0; i < 500; i++)
    {
        arr2[i] = new int[500];
    }


    int x, y, R;
    cin >> x >> y >> R;
    
    used[--x][--y] = true;
    
    if(R==1){
        cout<<arr[x][y];
        return 0;
    }
    
    arr2[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({ x,y });

    int sum = 0;
    
        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();

            for (int x = 0; x < 4; x++) {
                int newX = cell.first + op[x][0];
                int newY = cell.second + op[x][1];

                if (newX >= 0 && newX < N && newY >= 0 && newY < M) {
                    if (!used[newX][newY] && arr[newX][newY]!=-1 ) {
                        used[newX][newY] = true;
                        q.push({ newX, newY });
                        arr2[newX][newY] = arr2[cell.first][cell.second] + 1;

                        if (arr2[newX][newY] == R) {
                            sum += arr[newX][newY];
                        }
                    }
                }
            }
        }
    
    cout << sum;
   
    for (int i = 0; i < 500; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    for (int i = 0; i < 500; i++)
    {
        delete[] arr2[i];
    }
    delete[] arr2;
    return 0;
}