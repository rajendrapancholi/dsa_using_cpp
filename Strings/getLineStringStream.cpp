#include <bits/stdc++.h>
using namespace std;

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string data = " apple, bannana   , cherry,date";
  stringstream ss(data); // Wrap the string in a stringstream
  string token;
  vector<string> items;
  
  // Read from 'ss' into 'token' until ',' is found
  // while (getline(ss, token, ',')) {
  //   items.push_back(token);
  // }
  // for (auto item : items) {
  //   cout << item << "\n";
  // }

  // trim `spaces, new line feed, cariage return and tabs` form both end
  while (getline(ss>>ws, token, ',')) {
    token.erase(token.find_last_not_of(" \t\n\r"));
    items.push_back(token);
  }
  for (auto item : items) {
    cout << item << "\n";
  }

  return 0;
}