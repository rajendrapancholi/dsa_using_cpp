#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string s;
// dp[pos][tight][leading_zero][prev_digit (0 se 10 tak)]
long long dp[20][2][2][11];

long long solve(int pos, int tight, int leading_zero, int prev_digit) {
  // Base Case: Saare dabbe bhar gaye -> 1 valid number mil gaya
  if (pos == s.size()) {
    return 1;
  }

  if (dp[pos][tight][leading_zero][prev_digit] != -1) {
    return dp[pos][tight][leading_zero][prev_digit];
  }

  long long ans = 0;
  int limit = (tight == 1) ? (s[pos] - '0') : 9;

  for (int d = 0; d <= limit; d++) {
    // RULE: Agar asli number shuru ho chuka hai (leading_zero == 0)
    // aur current digit 'd' pichhle digit ke barabar hai, toh skip karo!
    if (leading_zero == 0 && d == prev_digit) {
      continue;
    }

    int next_tight = (tight == 1 && d == limit) ? 1 : 0;
    int next_leading_zero = (leading_zero == 1 && d == 0) ? 1 : 0;

    // Agar abhi bhi leading zero hi chal raha hai toh prev_digit ko 10 hi
    // rakho, warna 'd'
    int next_prev = (next_leading_zero == 1) ? 10 : d;

    ans += solve(pos + 1, next_tight, next_leading_zero, next_prev);
  }

  return dp[pos][tight][leading_zero][prev_digit] = ans;
}

int main() {
  long long n = 25;
  s = to_string(n);
  memset(dp, -1, sizeof(dp));

  // Shuruat: pos=0, tight=1, leading_zero=1, prev_digit=10
  // (Note: Ye 0 se N tak count karta hai, isme '0' bhi included hai)
  cout << "0 se " << n << " tak valid numbers: " << solve(0, 1, 1, 10) << endl;
  // Output: 24 (0 se 25 mein sirf '11' aur '22' invalid hain, 26 - 2 = 24)
  return 0;
}
