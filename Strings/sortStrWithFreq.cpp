/* Sort characters by frequency
You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.
If two or more characters have same frequency then arrange them in alphabetic order.
Examples
Example 1:
Input:
 s = "tree"
Output:
 ['e', 'r', 't']
Explanation:

e → 2
r → 1
t → 1
Since 'r' and 't' have the same frequency, they are sorted alphabetically → 'r' comes before 't'.

Example 2:
Input:
 s = "raaaajj"
Output:
 ['a', 'j', 'r']
Explanation:

a → 4
j → 2
r → 1
Characters are sorted by decreasing frequency. In case of ties, alphabetically.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
  static bool comparator(pair<int, char> p1, pair<int, char> p2) {
      if (p1.first > p2.first) return true;
      if (p1.first < p2.first) return false;
      return p1.second < p2.second; // if both equal then check order in alphabetically.
  }
public:
  string sortStr(string s){
    string ans = "";
    pair<int, char> freq[26];
    for(int i = 0; i < 26; i++){
      freq[i] = {0, i + 'a'};
    }
    for(auto c: s){
      freq[c - 'a'].first++;
    }
    
    sort(freq, freq + 26, comparator);

    for(int i = 0; i < 26; i++){
      if(freq[i].first > 0) ans += freq[i].second;
    }
    
    return ans;
  }
};

int main() {
  string s = "rajendra";
  Solution sl;
  cout<<sl.sortStr(s)<<endl;
  return 0;
}
