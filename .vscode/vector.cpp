#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v;                       // increase capacity through 2^n
    vector<int> v1 = {1, 2, 3, 4, 5, 6}; // size of the vector is equal to capacity of the vector size()==vector()

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
    for (int i = 0; i < v.size(); i++)
    {
        int element;
        cout << "Enter element at " << i << " = ";
        cin >> element;
        v.push_back(element);
    }

    // Display all elements of the vector.
    cout << "Elements are :" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Element at " << i << " is :" << v[i] << endl;
    }

    return 0;
}