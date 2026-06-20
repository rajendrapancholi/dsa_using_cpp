/* Candy
A line of N kids is standing there. The rating values listed in the integer array ratings are assigned to each kid. These kids are receiving candy according to the following criteria:

There must be at least one candy for every child.
Kids whose scores are higher than their neighbours receive more candies than their neighbours.
Return the minimum number of candies needed to distribute among children.

Examples
Input: ratings = [1, 0, 5]  
Output: 5  
Explanation: The distribution of candies will be 2, 1, 2 to the first, second, and third child respectively.


Input: ratings = [1, 2, 2]  
Output: 4  
Explanation: The distribution of candies will be 1, 2, 1 to the first, second, and third child respectively.The third gets only 1 candy because it satisfies both conditions mentioned above.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
  struct Rating {
    int id, rating;
  };
public:
  int minCandyDistr(int ratings[], int n){
    Rating tempR[n];
    int candy[n];
    for(int i = 0; i < n; i++){
      tempR[i] = {i, ratings[i]};
      candy[i] = 1;
    }
    sort(tempR, tempR + n, [](Rating a, Rating b){
      return a.rating < b.rating;
    });
    int reqCandy = 0;
    for(int i = 0; i < n; i++){
      if(tempR[i].id - 1 >= 0 && tempR[i].rating > ratings[tempR[i].id - 1]){
        candy[tempR[i].id] = candy[tempR[i].id - 1] + 1;
      }
      else if (tempR[i].id + 1 < n && tempR[i].rating > ratings[tempR[i].id + 1]){
        candy[tempR[i].id] = candy[tempR[i].id + 1] + 1;
      }
    }
    for(int i = 0; i < n; i++) reqCandy += candy[i];
    return reqCandy;
  }
  
  int minCandyDistr2(int ratings[], int n){
    int reqCandies = n, i = 1;
    while(i < n){
      if(ratings[i] == ratings[i - 1]){
        i++;
        continue;
      }
      int pk = 0;
      while(i < n && ratings[i] > ratings[i - 1]){
        pk++; reqCandies += pk; i++;
      }
      int vl = 0;
      while(i < n && ratings[i] < ratings[i - 1]){
        vl++; reqCandies += vl; i++;
      }
      reqCandies -= min(pk, vl);
    }
    return reqCandies;
  }
};

int main() {
  Solution sl;
  int ratings[] = {1, 3, 6, 8, 9, 5, 3}; // Output: 5
  
  int n = sizeof(ratings)/sizeof(ratings[0]);
  cout<<sl.minCandyDistr(ratings, n)<<endl;
  cout<<sl.minCandyDistr2(ratings, n)<<endl;
  return 0;
}
