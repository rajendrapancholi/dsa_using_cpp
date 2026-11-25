/* Count No-Zero Pairs That Sum to N
A no-zero integer is a positive integer that does not contain the digit 0 in its
decimal representation.

Given an integer n, count the number of pairs (a, b) where:

a and b are no-zero integers.
a + b = n
Return an integer denoting the number of such pairs.

Example 1:
Input: n = 2
Output: 1

Explanation:
The only pair is (1, 1).
Example 2:
Input: n = 3
Output: 2

Explanation:
The pairs are (1, 2) and (2, 1).
Example 3:
Input: n = 11
Output: 8
Explanation:
The pairs are (2, 9), (3, 8), (4, 7), (5, 6), (6, 5), (7, 4), (8, 3), and (9, 2). Note that (1, 10) and (10, 1) do not satisfy the conditions because 10 contains 0 in its decimal representation.

Constraints:
2 <= n <= 1015
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string s;
  // dp[pos][carry][done_a][done_b]
  long long dp[20][2][2][2];

  long long solve(int pos, int carry, int done_a, int done_b) {
    // Base Case: n ke saare digits match ho gaye
    if (pos == s.size()) {
      // Last mein koi carry bacha nahi hona chahiye
      return (carry == 0) ? 1 : 0;
    }
    if (dp[pos][carry][done_a][done_b] != -1) {
      return dp[pos][carry][done_a][done_b];
    }
    long long ans = 0;
    int target = s[pos] - '0';
    // 'a' ke liye valid digits decide karo:
    // Agar done_a == 1 hai toh sirf 0 le sakte hain.
    // Agar done_a == 0 hai toh 1..9 le sakte hain, aur (pos > 0) ho toh 0 lekar
    // yahin khatam bhi kar sakte hain.
    vector<int> choices_a;
    if (done_a == 1) {
      choices_a.push_back(0);
    } else {
      if (pos > 0)
        choices_a.push_back(0); // Number aage khatam (leading zero)
      for (int d = 1; d <= 9; d++)
        choices_a.push_back(d);
    }
    // Same 'b' ke liye
    vector<int> choices_b;
    if (done_b == 1) {
      choices_b.push_back(0);
    } else {
      if (pos > 0)
        choices_b.push_back(0);
      for (int d = 1; d <= 9; d++)
        choices_b.push_back(d);
    }

    for (int da : choices_a) {
      for (int db : choices_b) {
        int sum = da + db + carry;
        if (sum % 10 == target) {
          int next_carry = sum / 10;
          int next_done_a = (done_a == 1 || da == 0) ? 1 : 0;
          int next_done_b = (done_b == 1 || db == 0) ? 1 : 0;

          ans += solve(pos + 1, next_carry, next_done_a, next_done_b);
        }
      }
    }

    return dp[pos][carry][done_a][done_b] = ans;
  }

  long long countNoZeroPairs(long long n) {
    s = to_string(n);
    // Right-to-left chalne ke liye string ko reverse kar do
    reverse(s.begin(), s.end());

    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 0, 0);
  }
};
