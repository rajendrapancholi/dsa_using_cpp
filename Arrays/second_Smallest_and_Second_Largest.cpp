// Find 2nd & 3rd Smallest and Largest Element in an array

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  int secondSmallest(vector<int>& arr){
    if(arr.size() < 2) return -1;
    int small = INT_MAX;
    int small2 = INT_MAX;
    for(int el: arr){
      if(small > el){
        small2 = small;
        small  = el;
      } else if(small2 > el && el != small){
        small2 = el;
      }
    }
    return small2;
  }

  int secondLargest(vector<int>& arr){
    if(arr.size() < 2) return -1;
    int large = INT_MIN;
    int large2 = INT_MIN;
    for(int el: arr){
      if(large < el){
        large2 = large;
        large  = el;
      } else if(large2 < el && el != large){
        large2 = el;
      }
    }
    return large2;
  }
  int thirdLargest(vector<int>& arr){
    if(arr.size() < 3) return -1;
    int large = INT_MIN;
    int large2 = INT_MIN;
    int large3 = INT_MIN;
    for(int el: arr){
      if(large < el){
        large3 = large2;
        large2 = large;
        large = el;
      } else if(large2 < el && el != large){
        large3 = large2;
        large2 = el;
      } else if(large3 < el && el != large2){
        large3 = el;
      }
    }

    return large3;
  }
  int thirdSmallest(vector<int>& arr){
    if(arr.size() < 3) return -1;
    int small = INT_MAX;
    int small2 = INT_MAX;
    int small3 = INT_MAX;
    for(int el: arr){
      if(small > el){
        small3 = small2;
        small2 = small;
        small = el;
      } else if(small2 > el && el != small){
        small3 = small2;
        small2 = el;
      } else if(small3 > el && el != small2){
        small3 = el;
      }
    }

    return small3;
  }
};

int main(){
  vector<int> arr = {1,10,3,4,5,14,7,8,9,2,11,12,13,6,15};
  Solution sl;
  cout<<"Second smallest: "<<sl.secondSmallest(arr)<<endl;
  cout<<"Second largest: "<<sl.secondLargest(arr)<<endl;
  cout<<"Third smallest: "<<sl.thirdSmallest(arr)<<endl;
  cout<<"Third largest: "<<sl.thirdLargest(arr)<<endl;
  return 0;
}