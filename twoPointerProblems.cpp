#include <iostream>
#include <vector>

using namespace std;

void sortZerosAndOnes(vector<int> &v) // (&v)passing address of the vector becouse not extra memory reserve by copy of the vector.
{
    // Q1: Sort an array consisting of the only 0s and 1s.
    // M1:  without two pointers.
    // int countZeros = 0;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     if (v[i] == 0)
    //     {
    //         countZeros++;
    //     }
    // }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     if (i < countZeros)
    //     {
    //         v[i] = 0;
    //     }
    //     else
    //     {
    //         v[i] = 1;
    //     }
    // }

    // M2: with two pointers.
    int leftPtr = 0;
    int rightPtr = v.size() - 1;
    while (leftPtr < rightPtr)
    {
        if (v[leftPtr] == 1 && v[rightPtr] == 0)
        {
            v[leftPtr] = 0;
            v[rightPtr] = 1;
            leftPtr++;
            rightPtr--;
        }
        if (v[leftPtr] == 0)
        {
            leftPtr++;
        }
        if (v[rightPtr] == 1)
        {
            rightPtr--;
        }
    }

    return;
}
int main()
{
    cout << "Enter size of the array: ";
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    sortZerosAndOnes(v);

    // Display elements of the vector.
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    return 0;
}