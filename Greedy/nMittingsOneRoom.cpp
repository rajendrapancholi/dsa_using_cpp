/* N meetings in one room
There is one meeting room in a firm. You are given two arrays, start and end each of size N. For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i] will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time. Print the order in which these meetings will be performed.

Examples
Input: N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}
Output: [1, 2, 4, 5]
Explanation: These meeting can be conducted in the room.


Input: N = 2, start[] = {1,5}, end[] = {7,8}
Output: [1]
Explanation: Any one out of the two meeting can take place.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
  struct Item{
    int s = 0;
    int e = 0;
  };
  static bool comparator(Item &a, Item &b){
    return a.e < b.e;
  }
  
public:
  int findMaxMittings(int N, int start[], int end[]){
    Item it[N];
    int pet = -1, mt[N] = {-1}, ct = 0;
    for(int i = 0; i < N; i++)
      it[i] = {start[i], end[i]}, mt[i] = -1;
    sort(it, it + N, comparator);
    for(int i = 0; i < N; i++){
      if(pet == -1){
        mt[ct++] = i+1;
        pet = it[i].e;
        continue;
      }
      if(it[i].s >= pet){
        mt[ct++] = i+1;
        pet = it[i].e;
      }
    }
    for(int i = 0; i<N; i++){
      if(mt[i] == -1) continue;
      cout<<mt[i]<< ' ';
    }
    cout<<endl;
    return ct;
  }
};

int main() {
  int N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9};
  Solution sl;
  cout<<sl.findMaxMittings(N, start, end)<<endl;
  return 0;
}
