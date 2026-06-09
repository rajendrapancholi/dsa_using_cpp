/* Isomorphic String
Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
Examples
Example 1
Input:
 s = "paper", t = "title"
Output:
 true
Explanation:
 The characters in "s" can be mapped one-to-one to characters in "t": 
'p' → 't', 'a' → 'i', 'e' → 'l', 'r' → 'e'
Since the mapping is consistent and unique for each character, the strings are isomorphic.

Example 2
Input:
 s = "foo", t = "bar"
Output:
 false
Explanation:
 'f' → 'b' is fine, 'o' → 'a' for the first 'o', But the second 'o' in "s" would need to map to 'r' in "t", which conflicts with the earlier mapping of 'o' → 'a'
This inconsistency makes it impossible to convert "s" to "t" using a one-to-one character mapping.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isomorphicStr(string &s, string &t){
    int sl = s.size(), tl = t.size();
    if(sl != tl) return false;
    int hash1[256] = {0}, hash2[256] = {0};
    for(int i = 0; i < sl; i++){
      if(hash1[s[i]] != hash2[t[i]]) return false;
      hash1[s[i]] = i + 1;
      hash2[t[i]] = i + 1;
    }
    return true;
  }
};

int main() {
  // string s = "paper", t = "title"; // Output: true
  string s = "foo", t = "bar"; // Output: false

  Solution sl;
  cout<<(sl.isomorphicStr(s, t) ? "True" : "False")<<endl;
  return 0;
}
