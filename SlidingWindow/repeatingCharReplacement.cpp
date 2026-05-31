/* longest repeating character replacement
Given an integer k and a string s, any character in the string can be selected and changed to any other uppercase English character. This operation can be performed up to k times. After completing these steps, return the length of the longest substring that contains the same letter.

Examples
Input: s = "BAABAABBBAAA", k = 2  
Output: 6  
Explanation: We can change the B at index 0 and 3 (0-based indexing) to A. The new string becomes "AAAAAABBBAAA". The substring "AAAAAA" is the longest substring with the same letter, and its length is 6. 

Input: s = "AABABBA", k = 1  
Output: 4  
Explanation: We can change one character to get the new string "AABBBBA". The substring "BBBB" is the longest with the same character. There are other ways to achieve this result as well.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int repeatingCharReplacement(string &s, int k){
    int n = s.size(), maxLen = 0;

    for (int i = 0; i < n; i++) {
      int hash[26] = {0};
      int maxFreq = 0;
      for (int j = i; j < n; j++) {
        int charIdx = s[j] - 'A'; 
        hash[charIdx]++;
        maxFreq = max(maxFreq, hash[charIdx]);
        int len = j - i + 1;
        int changesNeeded = len - maxFreq;
        if (changesNeeded <= k) {
          maxLen = max(maxLen, len);
        } else {
          break; 
        }
      }
    }
    return maxLen;
  }

  int repeatingCharReplacementSW(string &s, int k){
    int n = s.size(), hash[26] = {0}, maxLen = 0, maxFreq = 0, left = 0, right = 0;
    for (int right = 0; right < n; right++) {
      hash[s[right] - 'A']++;
      maxFreq = max(maxFreq, hash[s[right] - 'A']);
      while((right - left + 1) - maxFreq  > k){
        hash[s[left] - 'A']--;
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
  }
};

int main() {
  string s = "BAABAABBBAAA"; int k = 2;
  // Output: 6  
  Solution sl;
  cout<<sl.repeatingCharReplacement(s, k)<<endl;
  cout<<sl.repeatingCharReplacementSW(s, k)<<endl;
  return 0;
}
