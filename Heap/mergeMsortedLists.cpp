/* Merge M sorted Lists
Given heads of k sorted linked lists as an array called heads, merge them into one single sorted linked list and return the head of that list.

Examples
Input : heads = [[head -> 1 -> 2 -> 3 -> 4], [head -> -4 -> -3], [head -> -5 -> -3 -> 1 -> 2 -> 3 -> 4]]
Output:  head -> -5 -> -4 -> -3 -> -3 -> 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 4
Explanation:  head -> -5 -> -4 -> -3 -> -3 -> 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 4
The nodes in bold come from the 3rd list, the underlined nodes come from the 2nd list, rest are from the 1st list.

Input : heads = [[head -> -5 -> -4 -> -1], [head -> 10 -> 11 -> 12]]
Output :  head -> -5 -> -4 -> -1 -> 10 -> 11 -> 12
Explanation : head -> -5 -> -4 -> -1 -> 10 -> 11 -> 12
The nodes in bold come from the 1st list, rest are from the 2nd list.
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node *next;
  Node(int x): val(x), next(nullptr){}
};

class Compare {
public:
  bool operator()(Node *a, Node *b){
    return a->val > b->val;
  }
};

class Solution {
public:
  Node *mergeMSortedLst(vector<Node *>lists){
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for(auto lst: lists) {
      if(lst != nullptr) pq.push(lst);
    }
    
    Node *dummy = new Node(0);
    Node *tail = dummy;

    while(!pq.empty()){
      Node *smallest = pq.top();
      pq.pop();
      tail->next = smallest;
      tail = tail->next;
      if(smallest->next!=nullptr){
        pq.push(smallest->next);
      }
    }
    return dummy->next;
  }
};

int main() {
  // Input : heads = [[head -> 1 -> 2 -> 3 -> 4], [head -> -4 -> -3], [head -> -5 -> -3 -> 1 -> 2 -> 3 -> 4]]
  // Output:  head -> -5 -> -4 -> -3 -> -3 -> 1 -> 1 -> 2 -> 2 -> 3 -> 3 -> 4 -> 4
  Node *lst1 = new Node(1);
  lst1->next = new Node(2);
  lst1->next->next = new Node(3);
  lst1->next->next->next = new Node(4);

  Node *lst2 = new Node(-4);
  lst2->next = new Node(-3);

  Node *lst3 = new Node(-5);
  lst3->next = new Node(-3);
  lst3->next->next = new Node(1);
  lst3->next->next->next = new Node(2);
  lst3->next->next->next->next = new Node(3);
  lst3->next->next->next->next->next = new Node(4);
  vector<Node *>lists = {lst1, lst2, lst3};
  
  Solution sl;
  Node *res = sl.mergeMSortedLst(lists);
  while(res != nullptr){
    cout<<res->val<<" ";
    res = res->next;
  }
  return 0;
}
