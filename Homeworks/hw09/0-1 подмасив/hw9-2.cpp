#include<iostream>
#include<unordered_map>
using namespace std;

int maxLength(int arr[], int n)
{
    unordered_map<int, int> hM;

    int sum = 0; 
    int max_len = 0; 

    for (int i = 0; i < n; i++) {
       
        int temp = 1;
        if (arr[i] == 0)temp = -1;
        sum += temp;;
        if (sum == 0) {
            max_len = i + 1;
           
        }

        if (hM.find(sum + n) != hM.end()) {
            if (max_len < i - hM[sum + n]) {
                max_len = i - hM[sum + n];
               
            }
        }
        else 
            hM[sum + n] = i;
    }
    return max_len;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
  
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    cout<<maxLength(arr, n);
   
    return 0;
}
