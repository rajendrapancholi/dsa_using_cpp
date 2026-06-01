/* Number of substring containing all three characters
Given a string s , consisting only of characters 'a' , 'b' , 'c'.Find the number of substrings that contain at least one occurrence of all these characters 'a' , 'b' , 'c'.

Examples
Input : s = "abcba"
Output :  5
Explanation : The substrings containing at least one occurrence of the characters 
'a' , 'b' , 'c' are "abc" , "abcb" , "abcba" , "bcba" , "cba".

Input : s = "ccabcc"
Output : 8
Explanation : The substrings containing at least one occurrence of the characters
'a' , 'b' , 'c' are "ccab" , "ccabc" , "ccabcc" , "cab" , "cabc" , "cabcc" , "abc" , "abcc".
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int findNSubstringContainsChars(string &s, vector<char> &arr){
    int count = 0;
    for(int i = 0; i < s.size(); i++){
      unordered_map<char, int> mp;
      for(auto it: arr){
        mp[it]++;
      }
      
      int remainUniqEle = mp.size();

      for(int j = i; j < s.size(); j++){
        if(mp[s[j]] > 0){
          mp[s[j]]--;
          if(mp[s[j]] == 0) remainUniqEle--;
        }
        if(remainUniqEle == 0) {
          count += s.size() - j;
          break;
        }
      }
    }
    return count;
  }

  int findNSubstringContainsCharsSW(string &s, vector<char> &arr){
    int count = 0, left = 0;
    unordered_map<char, int> mp;
    for(auto it: arr)
      mp[it]++;
    int remainUniqEle = mp.size();
    for(int right = 0; right < s.size(); right++){
      if(mp.find(s[right]) != mp.end()){
        mp[s[right]]--;
        if(mp[s[right]] == 0) remainUniqEle--;
      }

      while(remainUniqEle == 0) {
        count += s.size() - right;
        if(mp.find(s[left]) != mp.end()) {
          if(mp[s[left]] == 0)
            remainUniqEle++;
          mp[s[left]]++;
        }
        left++;
      }
    }
    return count;
  }
};

int main() {
  string s = "abcba";
  vector<char> arr = {'a', 'b', 'c'};
  Solution sl;
  cout<<sl.findNSubstringContainsChars(s, arr)<<endl;
  cout<<sl.findNSubstringContainsCharsSW(s, arr)<<endl;
  return 0;
}
