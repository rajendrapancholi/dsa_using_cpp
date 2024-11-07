/**********************
Program Name        : Given a number 'num' and a value 'k'. Print k multiples of num.
Author              : Rajendra Pancholi
Date of creation    : 08/11/2024
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;

void printM(int num, int k, int i)
{
    cout << i * num << " ";
    if (i == k)
        return;
    printM(num, k, i + 1);
}
int main()
{
    int num = 13;
    int k = 9;
    printM(num, k, 1);
    return 0;
}