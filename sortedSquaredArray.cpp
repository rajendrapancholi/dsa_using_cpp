// Q3: Given an integer array 'a' sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

void sortedSquaredArray(vector<int> &v)
{
    int leftptr = 0;
    int rightptr = v.size() - 1;
    vector<int> ansV;
    while (leftptr <= rightptr)
    {
        if (abs(v[leftptr]) < abs(v[rightptr]))
        {
            ansV.push_back(v[rightptr] * v[rightptr]);
            rightptr--;
        }
        else
        {
            ansV.push_back(v[leftptr] * v[leftptr]);
            leftptr++;
        }
    }
    reverse(ansV.begin(), ansV.end());
    for (int ele : ansV)
    {
        cout << ele << " ";
    }
    cout << endl;

    return;
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    sortedSquaredArray(v);

    return 0;
}