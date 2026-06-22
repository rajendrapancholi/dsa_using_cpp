/* Program for Least Recently Used (LRU) Page Replacement Algorithm
  Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
int get(int key): Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value): Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Examples
Input: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output: [null, null, null, 1, null, -1, null, -1, 3, 4]
Explanation: 
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
Input: ["LRUCache","put","get"]
[[1],[2,1],[2]] 
Output: [null, null, 1]
Explanation: 
LRUCache lRUCache = new LRUCache(1);
lRUCache.put(2, 1); // cache is {2=1}
lRUCache.get(2);    // return 1
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
  class Node {
  public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int _key, int _val){
      key = _key;
      val = _val;
    }
  };
  Node* head = new Node(-1, -1);
  Node* tail = new Node(-1, -1);
  int cap;
  unordered_map<int, Node*> m;
  LRUCache(int capacity){
    cap = capacity;
    head->next = tail;
    tail->prev = head;
  }
  void addNode(Node* newNode){
    Node* temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
  }
  void deleteNode(Node* delNode){
    Node* delPrev = delNode->prev;
    Node* delNext = delNode->next;
    delPrev->next = delNext;
    delNext->prev = delPrev;
  }
  int get(int key_){
    if (m.find(key_) != m.end()){
      Node* resNode = m[key_];
      int res = resNode->val;
      m.erase(key_);
      deleteNode(resNode);
      addNode(resNode);
      m[key_] = head->next;
      return res;
    }
    return -1;
  }
  void put(int key_, int value){
    if (m.find(key_) != m.end()){
      Node* existingNode = m[key_];
      m.erase(key_);
      deleteNode(existingNode);
    }
    if (m.size() == cap){
      m.erase(tail->prev->key);
      deleteNode(tail->prev);
    }
    addNode(new Node(key_, value));
    m[key_] = head->next;
  }
};

int main(){
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl; 
  cache.put(3, 3);
  cout << cache.get(2) << endl; 
  cache.put(4, 4);
  cout << cache.get(1) << endl; 
  cout << cache.get(3) << endl; 
  cout << cache.get(4) << endl; 
  return 0;
}

