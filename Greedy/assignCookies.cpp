/* Assign Cookies
Consider a scenario where a teacher wants to distribute cookies to students, with each student receiving at most one cookie. Given two arrays, student and cookie, the ith value in the student array describes the minimum size of cookie that the ith student can be assigned. The jth value in the cookie array represents the size of the jth cookie. If cookie[j] >= student[i], the jth cookie can be assigned to the ith student. Maximize the number of students assigned with cookies and output the maximum number.

Examples
Memoization
Algorithm
We use recursion to try all ways of assigning cookies to children. At each step, if the current cookie can satisfy the current child, we try both: assigning it or skipping it, and take the better result. If it can't satisfy, we skip. To avoid recalculating the same subproblems, we store results in a 2D dp[child][cookie] array. This saves time by reusing already computed answers.
Sort both student and cookie array in ascending order.
Begin from the first student and the first cookie and at each step, check if the current cookie can satisfy the current student.
If the cookie can't satisfy the student, skip it and try the next one.
If yes, either give the cookie to the student and move to the next student and next cookie or skip the cookie and try giving the next one to the same student.
For every student-cookie pair, remember the result so you don’t recalculate it later. Repeat the process until you’ve considered all students or all cookies.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
  int acutil(vector<int> &s, vector<int> &c, int si, int ci){
    if(si >= s.size() || ci >= c.size())
      return 0;
    int result = 0;
    if(s[si] <= c[ci]) result = max(result, 1 + acutil(s, c, si + 1, ci + 1));
    else result = max(result, acutil(s, c, si, ci + 1));

    return result;
  }
public:
  int assignCookiesM1(vector<int> &s, vector<int> &c){ // tc 2^n; sp n(recurstion stack)
    sort(s.begin(), s.end());
    sort(c.begin(), c.end());
    return acutil(s, c, 0, 0);
  }

  int assignCookiesM2(vector<int> &s, vector<int> &c){
    sort(s.begin(), s.end());
    sort(c.begin(), c.end());
    int si = 0, ci = 0;
    while(si < s.size() && ci < c.size()){
      if(s[si] <= c[ci]) si++;
      ci++;
    }
    return si;
  }
};

int main() {
  vector<int> student = {1, 2, 3};
  vector<int> cookie = {1, 1};
  Solution sl;
  cout<<sl.assignCookiesM1(student, cookie)<<endl;
  cout<<sl.assignCookiesM2(student, cookie)<<endl;
  return 0;
}
