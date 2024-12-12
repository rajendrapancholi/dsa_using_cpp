/**********************
Program Name        : Given a string, we have to find out all its subsequences of it.
Author              : Rajendra Pancholi
Date of creation    : 11/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
#include <vector>
using namespace std;

void subsequence(string &str, string tempStr, vector<string> &lst, int i)
{
    if (i == str.length())
    {
        lst.push_back(tempStr);
        return;
    }
    subsequence(str, tempStr + str[i], lst, i + 1);
    subsequence(str, tempStr, lst, i + 1);
    return;
}

int main()
{

    string str = "abc";
    int ln = str.length();
    // cout << ln << endl;
    vector<string> lst;
    subsequence(str, "", lst, 0);
    for (int i = 0; i < lst.size(); i++)
    {
        cout << lst[i] << " ";
    }

    return 0;
}