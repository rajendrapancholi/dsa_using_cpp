/* Count Number of Substrings
You are given a string s and a positive integer k.
Return the number of substrings that contain exactly k distinct characters.

Examples
Example 1:
Input:
 s = "pqpqs", k = 2  
Output:
 7  
Explanation:
  All substrings with exactly 2 distinct characters:  
"pq", "pqp", "pqpq", "qp", "qpq", "pqs", "qs"  
Total = 7.

Example 2:
Input:
 s = "abcbaa", k = 3  
Output:
 5  
Explanation:
  All substrings with exactly 3 distinct characters:  
Total = 8.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
  int atMostKDistinct(string s, int k) {
    if(s.size() < k) return 0;
    int left = 0, res = 0;
    unordered_map<char, int> freq;
    for (int right = 0; right < s.size(); right++) {
      freq[s[right]]++;
      while (freq.size() > k) {
        freq[s[left]]--;
        if (freq[s[left]] == 0) freq.erase(s[left]);
        left++;
      }
      res += (right - left + 1);
    }
    return res;
  }
public:
  int findNSubstr(string s, int k){
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
  }
};

int main() {
  string  s = "pqpqs"; int k = 2; // Output: 7
  // string   s = "abcbaa"; int k = 3 ; // Output: 8
  Solution sl;
  cout<<sl.findNSubstr(s, k)<<endl;
  return 0;
}
