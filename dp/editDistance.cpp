/* Edit Distance
Problem Statement:
We are given two strings ‘S1’ and ‘S2’. We need to convert S1 to S2. The following three operations are allowed:
Deletion of a character.
Replacement of a character with another one.
Insertion of a character.
We have to return the minimum number of operations required to convert S1 to S2 as our answer.
Examples
Example 1:
Input: start = "planet", target = "plan"
Output: 2
Explanation:
To transform "planet" into "plan", the following operations are required:
1. Delete the character 'e': "planet" -> "plan"
2. Delete the character 't': "plan" -> "plan"
Thus, a total of 2 operations are needed.
Example 2:
Input: start = "abcdefg", target = "azced"
Output: 4
Explanation:
To transform "abcdefg" into "azced", the following operations are required:
1. Replace 'b' with 'z': "abcdefg" -> "azcdefg"
2. Delete 'd': "azcdefg" -> "azcefg"
3. Delete 'f': "azcefg" -> "azceg"
4. Replace 'g' with 'd': "azceg" -> "azced"
Thus, a total of 4 operations are needed.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
  int editDistance(string &start, string &target){
    int m = start.size(), n = target.size();

    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    
    
    for(int i = 0; i < n; i++){
      prev[i] = i;
    }

    for(int i = 1; i <= m; i++){
      curr[0] = i;
      for(int j = 1; j <= n; j++ ){
        if(start[i - 1] == target[j - 1]){
          curr[j] = prev[j-1];
        } else {
          curr[j] = 1 + min(prev[j-1], min(curr[j-1], prev[j]));
        }
      }
      prev = curr;
    }

    return curr[n];
  }
};

int main() {
  string start = "planet", target = "plan";
  Solution sl;
  cout<<sl.editDistance(start, target);
  return 0;
}
