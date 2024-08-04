#include <iostream>
#include <vector>

using namespace std;

// Q1: Given an integer array 'a', return the prefix sum/running sum in the same array without creating new array.
void runningSum(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        v[i] += v[i - 1];
    }
    for (int e : v)
    {
        cout << e << " ";
    }
    return;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    runningSum(v);
    // Display array

    cout << endl;

    return 0;
}