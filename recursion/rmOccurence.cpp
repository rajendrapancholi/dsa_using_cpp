/**********************
Program Name        : Remove all the occurences of 'a' from the string "abcdaef".
Author              : Rajendra Pancholi
Date of creation    : 08/11/2024
Organization        : NIT Patna
***********************/

#include <iostream>
using namespace std;

// Method 1:
/* string rmOccurence(string &str, char ch, int i)
{
// Base case: if the index reaches the end of the string
    if (str[i] == '\0')
    {
        return "";
    }
    string curr = "";
    curr += str[i];

    return ((str[i] == ch) ? "" : curr) + rmOccurence(str, ch, i + 1);
} */

// Method 2:
string rmOccurence(const string &str, char ch, int i = 0)
{
    // Base case: if the index reaches the end of the string
    if (i == str.size())
    {
        return "";
    }
    // If the current character matches the character to remove, skip it
    if (str[i] == ch)
    {
        return rmOccurence(str, ch, i + 1);
    }
    // Otherwise, include the current character in the result
    return str[i] + rmOccurence(str, ch, i + 1);
}

int main()
{
    string str = "abcdaef";
    str = rmOccurence(str, 'a', 0);
    cout << str << endl;
    return 0;
}