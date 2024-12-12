/**********************
Program Name        : Combination of string.
Author              : Rajendra Pancholi
Date of creation    : 11/12/2024
Organization        : NIT Patna
***********************/
#include <iostream>
#include <vector>
using namespace std;

void combination(string &str, int idx, string result, vector<string> &cmb)
{
    if (idx == str.size() - 1)
    {
        // cout << str << " ";
        // cmb.insert(cmb.begin(), result);
        cmb.push_back(result);
        return;
    }

    for (int i = idx; i < str.size(); i++)
    {
        swap(str[idx], str[i]);
        result = str;
        combination(str, idx + 1, result, cmb);
        swap(str[idx], str[i]);
        result = str;
    }
    return;
}

void f(string &str, int idx)
{
    if (idx == str.size() - 1)
    {
        cout << str << " ";
        return;
    }

    for (int i = idx; i < str.size(); i++)
    {
        swap(str[idx], str[i]);
        f(str, idx + 1);
        swap(str[idx], str[i]);
    }
}
int main()
{

    string str = "ABC";
    vector<string> cmb;
    combination(str, 0, "", cmb);
    // f(str, 0);
    for (int i = 0; i < cmb.size(); i++)
    {
        cout << cmb[i] << " ";
    }

    return 0;
}