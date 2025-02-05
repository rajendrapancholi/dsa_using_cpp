/**********************
Program Name        : Book Allocation problem
Author              : Rajendra Pancholi
Date of creation    : 05/02/2025
Organization        : NIT Patna
***********************/
/**********************
 * Given an array 'arr' of interger numbers,'arr[i]' represents the number of pages in the 'i-th' book.
 * Ther are 'm' number of students, and the task is to allocate all the books to athe students.
 * Allocate books in such a way that.
 * 1. Each student gets at least one book.
 * 2. Each book should be allocated to to only one student.
 * 3. Book allocation should be in a contiguous manner.
 * Your have to allocate the book to 'm' students such that the maximum number of pages assigned to a student is minimum.
 * If the allocation of books is not possible return -1.

***********************/

#include <iostream>
#include <vector>

using namespace std;

// M1: Linear method [TC = O(maxPages*sizzOfArr)]
int countStudents(vector<int> &arr, int pages)
{
    int student = 1, stdPages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (stdPages + arr[i] <= pages)
        {
            stdPages += arr[i];
        }
        else
        {
            student++;
            stdPages = arr[i];
        }
    }
    return student;
}

int minPages(vector<int> &arr, int students)
{
    // count the total number of pages in all the books.
    int maxPages = 0;
    for (int i = 0; i < arr.size(); i++)
        maxPages += arr[i];
    // check for possibility
    for (int pages = 0; pages <= maxPages; pages++)
    {
        int countStd = countStudents(arr, pages);
        // cout << pages << endl;
        if (countStd == students)
            return pages;
    }
    return -1;
}

// Optimized method (binary method) [TC = O(sizzOfArr*log(maxPg))]
int minPagesM2(vector<int> &arr, int students)
{
    // Count the total number of pages in all the books.
    int right = 0, left = arr[0];
    int minPg = -1;
    for (int i = 0; i < arr.size(); i++)
        right += arr[i];
    // Check for possibility
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (countStudents(arr, mid) <= students)
        {
            minPg = mid;
            // jump to left side
            right = mid - 1;
        }
        else
        {
            // jump to right side
            left = mid + 1;
        }
    }

    return minPg;
}
int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int students = 4;
    // cout << "Minimum pages: " << minPages(arr, students) << endl;
    cout << "Minimum pages: " << minPagesM2(arr, students) << endl;
    return 0;
}