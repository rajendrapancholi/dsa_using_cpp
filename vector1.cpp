#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // create a vector with size
    // vector<int> v(5);

    // vector<int> v; // increase capacity through 2^n
    // vector<int> v1 = {1, 2, 3, 4, 5, 6}; // size of the vector is equal to capacity of the vector size()==vector()

    // Insert element at the end of the vector
    // v.push_back(11);
    // v.push_back(12);
    // v.push_back(13);
    // v.push_back(14);
    // v.push_back(15);

    // cout << "Size of v: " << v.size() << endl;
    // cout << "Capacity of v: " << v.capacity() << endl;

    // cout << "Size of v1: " << v1.size() << endl;
    // cout << "Capacity of v1: " << v1.capacity() << endl;

    // Insert elements of the list using for loop.
    // for (int i = 0; i < 5; i++)
    // {
    //     int element;
    //     cout << "Enter element at " << i << " = ";
    //     cin >> element;
    //     v.push_back(element);
    // }

    // Delete element at the end of the vector usign inbuild method pop_back()
    // v.pop_back();

    // Delete element at the kth posion in the vector.
    // v.erase(v.begin() + 2);

    // Insert element at the kth position of the vector.
    // v.insert(v.begin() + 3, 225);

    // Q1: Find the last occurence of an element x in given array.
    // {1, 2, 3, 2, 1, 3, 1}
    vector<int> v2 = {1, 2, 3, 2, 1, 3, 1};
    int x;
    int occurence = -1;
    cout << "Enter x: ";
    cin >> x;

    // m1 traverse at begin of the array.
    for (int i = 0; i < v2.size(); i++)
    {
        if (v2[i] == x)
        {
            occurence = i;
        }
    }
    if (occurence == -1)
    {
        cout << "M1- Element was not found!" << endl;
    }
    else
    {
        cout << "Occurence(m1) of " << x << " is: " << occurence << endl;
    }

    // m2 traverse at end of the array.
    for (int i = v2.size() - 1; i >= 0; i--)
    {
        if (v2[i] == x)
        {
            occurence = i;
            break;
        }
    }
    if (occurence == -1)
    {
        cout << "M2- Element was not found!" << endl;
    }
    else
    {
        cout << "Occurence(m2) of " << x << " is: " << occurence << endl;
    }

    // Display all elements of the vector.
    cout << "Elements are :" << endl;
    for (int i = 0; i < v2.size(); i++)
    {
        // cout << "Element at " << i << " is :" << v[i] << endl;
        cout << v2[i] << " ";
    }
    cout << endl
         << "size = " << v2.size() << endl;
    cout << "capacity = " << v2.capacity() << endl;

    return 0;
}