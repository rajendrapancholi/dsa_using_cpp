/**********************
Program Name        : ProgramName
Author              : Rajendra Pancholi
Date of creation    : 06/02/2025
Organization        : NIT Patna
***********************/
/**********************
 * A new racing track for kids is being built in New York with 'n' starting spots. The spots are located along a straight line at possitions x1, x2.....xb(xu<= 10^9). For each 'i', xi+1>xi. At a time only 'm' children are allowed to enter the race. Since the race track is for kids, they may run into each other while running. To prevent this, we want to choose the starting spots such that the minimum distance between any two of them is as  large as possible. What is the largest minimum distance?
 * The first line of input will contain the value of n, the number of starting spots.
 * The second line of input wil contain the n numbers denoting the location of each spot.
 * The third line will contain the value of m, number of children.
 * Input
 * 5
 * [ 1, 2, 4, 8, 9 ]
 * Output
 * 3
 ***********************/

#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> &arr, int stud, int pos) // TC = O(length.arr)
{
    int reqStd = 1;
    int prevLoc = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - prevLoc > pos)
            reqStd++;
        else
            prevLoc = arr[i];
        if (reqStd == stud)
            return true;
    }

    return false;
}

int maxDistance(vector<int> &arr, int stud) //  TC => O(arr(Max-Min)*length.arr) => O(n*k)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum = sum + arr[i];

    for (int lst = sum; lst >= 0; lst--)
    {
        if (isPossible(arr, stud, lst))
        {
            return lst;
        }
    }
    return -1;
}

int maxDistanceBS(vector<int> &arr, int stud) //  TC => O(log(n)*length.arr) => O(k*log(n))
{
    int n = arr.size();
    int left = 1;
    int right = arr[n - 1] - arr[0];
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isPossible(arr, stud, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, 8, 9};
    // int ans = maxDistance(arr, 3); // 3 = students
    int ans = maxDistanceBS(arr, 3); // 3 = students
    cout << ans << endl;
    return 0;
}