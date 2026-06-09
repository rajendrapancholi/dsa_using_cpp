/* Check if two Strings are anagrams of each other
Given two strings, check if two strings are anagrams of each other or not.

Examples
Example 1:
Input: CAT, ACT
Output: true
Explanation: Since the count of every letter of both strings are equal.

Example 2:
Input: RULES, LESRT 
Output: falsel
Explanation: Since the count of U and T  is not equal in both strings.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isAnagram(string &s1, string &s2){
    if(s1.size() != s2.size()) return false;
    int freq[26] = {0};
    for(int i = 0; i < s1.size(); i++){
      freq[s1[i] - 'A']++;
      freq[s2[i] - 'A']--;
    }
    for(int i = 0; i < 26; i++){
      if(freq[i] != 0) return false;
    }
    return true;
  }
};

int main() {
  string s1 = "CAT", s2 = "ACT"; // Output: true
  Solution sl;
  cout<<sl.isAnagram(s1, s2)<<endl;
  return 0;
}
