/**********************
Program Name        : Check whether a given number is palindrome or not using recursively.
Author              : Rajendra Pancholi
Date of creation    : 07/11/2024
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;
bool palindrome(int num, int *temp)
{
    // Base case of the recursion.
    if (num >= 0 && num <= 9)
    {
        int lastDigitOfTemp = (*temp) % 10;
        (*temp) /= 10;
        return num == lastDigitOfTemp;
    }
    bool res = (palindrome(num / 10, temp) && (num % 10) == ((*temp) % 10));
    (*temp) /= 10;
    return res;
}
int main()
{
    int num = 12321;
    int *temp = &num;
    cout << (palindrome(num, temp) ? "Yes, Polindrome." : "Not, Polindrome.") << endl;

    return 0;
}