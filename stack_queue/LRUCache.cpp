#include <unordered_map>
using namespace std;

class LRUCache {
private:
  struct Node {
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
  };

  int capacity;
  int size;
  Node *head;
  Node *tail;
  unordered_map<int, Node *> cache;

  void removeNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addNode(Node *node) {
    Node *first = head->next;

    head->next = node;
    node->prev = head;
    node->next = first;
    first->prev = node;
  }

public:
  LRUCache(int capacity) : capacity(capacity), size(0) {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);

    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    auto it = cache.find(key);

    if (it == cache.end()) {
      return -1;
    }

    Node *node = it->second;

    removeNode(node);
    addNode(node);

    return node->val;
  }

  void put(int key, int value) {
    auto it = cache.find(key);

    if (it != cache.end()) {
      Node *node = it->second;

      removeNode(node);
      node->val = value;
      addNode(node);
      return;
    }

    Node *node = new Node(key, value);
    cache[key] = node;

    addNode(node);
    ++size;

    if (size > capacity) {
      Node *leastRecentlyUsed = tail->prev;

      removeNode(leastRecentlyUsed);
      cache.erase(leastRecentlyUsed->key);
      delete leastRecentlyUsed;

      --size;
    }
  }

  ~LRUCache() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }
};
