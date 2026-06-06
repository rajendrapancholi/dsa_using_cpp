/* Reverse Words in a String
Given an input string, containing upper-case and lower-case letters, digits, and spaces( ' ' ). A word is defined as a sequence of non-space characters. The words in s are separated by at least one space. Return a string with the words in reverse order, concatenated by a single space.

Examples
Input: s = "welcome to the jungle"
Output: "jungle the to welcome"
Explanation: The words in the input string are "welcome", "to", "the", and "jungle". Reversing the order of these words gives "jungle", "the", "to", and "welcome". The output string should have exactly one space between each word.

Input: s = " amazing coding skills "
Output: "skills coding amazing"
Explanation: The input string has leading and trailing spaces, as well as multiple spaces between the words "amazing", "coding", and "skills". After trimming the leading and trailing spaces and reducing the multiple spaces between words to a single space, the words are "amazing", "coding", and "skills". Reversing the order of these words gives "skills", "coding", and "amazing". The output string should not have any leading or trailing spaces and should have exactly one space between each word.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  string reverseWordsInStr(string &s){
    string result = "";
    int i = s.size() - 1;
    while (i >= 0) {
      while (i >= 0 && s[i] == ' ') i--;
      if (i < 0) break;
      int end = i;
      while (i >= 0 && s[i] != ' ') i--;
      string word = s.substr(i + 1, end - i);
      if (!result.empty()) {
        result += " ";
      }
      result += word;
    }
    return result;
  }
};

int main() {
  string s = " amazing coding skills "; // Output: "skills coding amazing"
  Solution sl;
  cout<<sl.reverseWordsInStr(s)<<endl;
  return 0;
}
