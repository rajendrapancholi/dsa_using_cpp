/* Lemonade Change
Given an array representing a queue of customers and the value of bills they hold, determine if it is possible to provide correct change to each customer. Customers can only pay with 5$, 10$ or 20$ bills and we initially do not have any change at hand. Return true, if it is possible to provide correct change for each customer otherwise return false.

Examples
Example 1:
Input: bills = [5, 5, 5, 10, 20]
Output: True
Explanation:
Initially we have 0 change and the queue of customers is [5, 5, 5, 10, 20].
First Customer pays 5$, no change required.
Second Customer pays 5$, no change required.
Third Customer pays 5$, no change required.
The Fourth Customer pays 10$, out of the three 5$ bills we have, we pay a 5$ bill and accept the 10$ bill.
Fifth Customer pays 20$, out of the two 5$ bills and one 10$ bill we have, we pay 15$ in change and have one 5$ bill left.
Hence, it is possible to provide change to all customers.

Example 2:
Input: bills = [5, 5, 10, 10, 20]
Output: False
Explanation: 
Initially, we have 0 change and the queue of customers is [5,5,10,10,20].
The first customer pays 5$, no change required.
The second customer pays 5$, no change required.
The third customer pays 10$, we collect a 5$ bill and give back a 5$ bill.
The fourth customer pays 10$, we collect a 5$ bill and give back a 5$ bill.
The fifth customer pays 20$, we cannot give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    int cfive = 0, cten = 0;
    for (const int bill : bills) {
      if (bill == 5) cfive++;
      else if (bill == 10) {
        if (cfive == 0) return false;
        cfive--;
        cten++;
      } else { // bill == 20
        if (cten > 0 && cfive > 0) cten--, cfive--;
        else if (cfive >= 3) cfive -= 3;
        else
          return false;
      }
    }
    return true;
  }
};

int main() {
  vector<int> bills = {5, 5, 5, 10, 20}; // Output: True          
  Solution sl;
  cout<<(sl.lemonadeChange(bills) ? "True" : "False")<<endl;
  return 0;
}
