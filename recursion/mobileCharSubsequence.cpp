/**********************
Program Name        : Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
Author              : Rajendra Pancholi
Date of creation    : 11/12/2024
Organization        : NIT Patna
***********************/
/**********************
Input digits = "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
**********************/
#include <iostream>
#include <vector>
using namespace std;

void comb(string &digits, vector<string> &str, vector<string> &lst, string result, int i)
{
    // Base case
    if (i == digits.length())
    {
        lst.push_back(result);
        return;
    }

    int digit = digits[i] - '0';

    if (digit <= 1)
    {
        comb(digits, str, lst, result, i + 1);
    }
    for (int j = 0; j < str[digit].size(); j++)
    {
        comb(digits, str, lst, result + str[digit][j], i + 1);
    }

    return;
}

int main()
{
    string digits = "24";
    vector<string> str(10);
    str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> lst;
    comb(digits, str, lst, "", 0);
    for (int i = 0; i < lst.size(); i++)
    {
        cout << lst[i] << " ";
    }

    return 0;
}