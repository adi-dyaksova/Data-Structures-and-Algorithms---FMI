#include <iostream> 
#include<queue>
using namespace std;

int subLength(deque<int> dequeue, int x)
{
    
    int curr_sum = 0, min_len = dequeue.size() + 1;

    int start = 0, end = 0;
    while (end < dequeue.size())
    {
        while (curr_sum < x && end < dequeue.size())
            curr_sum += dequeue[end++];

        while (curr_sum >= x && start < dequeue.size())
        {
            
            if (end - start < min_len)
                min_len = end - start;

            curr_sum -= dequeue[start++];
        }
    }
    if (min_len == dequeue.size() + 1){
        return -1;
    }
    return min_len;
}


int main()
{
  int N, K;
    cin >> N>>K;

    deque<int> deq;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        deq.push_back(temp);
    }

    cout << subLength(deq,K);

    return 0;
}