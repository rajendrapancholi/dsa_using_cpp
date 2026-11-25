#include <cstring>
#include <iostream>
#include <string>
using namespace std;

string s;
int K;
long long dp[20][2][200]; // [pos][tight][sum]

long long solve(int pos, int tight, int sum) {
  if (sum > K)
    return 0;

  // Base Case: Saare dabbe bhar gaye
  if (pos == s.size()) {
    // Agar total sum K ke barabar hai toh 1 valid number mil gaya!
    return (sum == K) ? 1 : 0;
  }

  // DP check: Pehle se solve hai toh wahi return karo
  if (dp[pos][tight][sum] != -1) {
    return dp[pos][tight][sum];
  }

  int limit = (tight == 1) ? (s[pos] - '0') : 9;
  long long ans = 0;

  // 0 se limit tak har digit try karo
  for (int d = 0; d <= limit; d++) {
    int next_tight = (tight && d == limit) ? 1 : 0;

    // Agle dabbe par jao aur sum mein 'd' jod do
    ans += solve(pos + 1, next_tight, sum + d);
  }

  return dp[pos][tight][sum] = ans;
}

int main() {
  long long n = 25;
  K = 7;
  s = to_string(n);
  memset(dp, -1, sizeof(dp));

  cout << "Answer: " << solve(0, 1, 0) << endl; // Output: 3 (7, 16, 25)
  return 0;
}
