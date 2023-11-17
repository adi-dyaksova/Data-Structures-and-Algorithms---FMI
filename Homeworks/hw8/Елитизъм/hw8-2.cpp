#include <iostream> 
#include<set>
#include<vector>
#include<queue>
#include <iomanip> 

using namespace std;
double nums[500000];



void printMedians(double arr[], int n)
{
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double> > minHeap;

    double median = arr[0];
    maxHeap.push(arr[0]);

    cout <<fixed<<setprecision(1)<< median << "\n";
    for (int i = 1; i < n; i++)
    {
        double x = arr[i];
        if (maxHeap.size() > minHeap.size())
        {
            if (x < median)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else
                minHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if (maxHeap.size() == minHeap.size())
        {
            if (x < median)
            {
                maxHeap.push(x);
                median = (double)maxHeap.top();
            }
            else
            {
                minHeap.push(x);
                median = (double)minHeap.top();
            }
        }
        else
        {
            if (x > median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            }
            else
                maxHeap.push(x);

            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }

        cout <<fixed<<setprecision(1)<< median << "\n";
    }
}


int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double temp;
        cin >> temp;
        nums[i] = temp;
    }
    printMedians(nums,n);

    return 0;
}