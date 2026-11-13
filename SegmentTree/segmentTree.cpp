#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> tree;
  int n = 0;
  void build(vector<int>& arr, int node, int start, int end){ // O(n)
    if(start==end) tree[node] = arr[start];
    else {
      int mid = start + (end-start)/2;
      build(arr, 2*node, start, mid);
      build(arr, 2*node+1, mid+1, end);
      tree[node] = tree[2*node]+tree[2*node+1];
    }
  }
  void update(int node, int start, int end, int idx, int val){ // O(log(n))
    if(start==end) tree[node] = val;
    else {
      int mid = start + (end - start)/2;
      if(idx<=mid) update(2*node, start, mid, idx, val);
      else update(2*node+1, mid+1, end, idx, val);
      tree[node] = tree[2*node] + tree[2*node+1];
    }
  }
  int query(int node, int start, int end, int l, int r){ // O(log(n))
    if(r<start || l>end) return 0; // not overlap
    if(l<=start && r>=end) return tree[node]; // full overlap
    int mid = start + (end - start)/2;
    return query(2*node, start, mid, l, r)+query(2*node+1, mid+1, end, l, r);
  }
public:
  Solution(vector<int>& arr): n(arr.size()) {
    tree.resize(4 * n);
    build(arr, 1, 0, n-1);
  }
  void update(int idx, int val) {
    update(1, 0, n-1, idx, val);
  }
  int query(int l, int r) {
    return query(1, 0, n-1, l, r);
  }
};

int main() {
  // Fast I/O Optimization
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> arr = {1, 3, 5, 7, 9};

  Solution sl(arr);
  // cout<<sl.query(0,3)<<endl;
  sl.update(2, 10);
  cout<<sl.query(0,3)<<endl;
  
  return 0;
}