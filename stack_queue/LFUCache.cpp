#include <unordered_map>

using namespace std;

class LFUCache {
private:
  struct Node {
    int key, val;
    int freq;
    Node *prev;
    Node *next;
    Node(int k, int v)
        : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
  };

  struct DLList {
    Node *head;
    Node *tail;
    DLList() {
      head = new Node(-1, -1);
      tail = new Node(-1, -1);
      head->next = tail;
      tail->prev = head;
    }

    void addNode(Node *n) {
      Node *oldHeadNext = head->next;
      head->next = n;
      n->next = oldHeadNext;
      n->prev = head;
      oldHeadNext->prev = n;
    }

    void removeNode(Node *n) {
      n->prev->next = n->next;
      n->next->prev = n->prev;
    }

    bool isEmpty() { return head->next == tail; }
  };

  int capacity;
  int size;
  int minFreq;
  unordered_map<int, Node *> cache;
  unordered_map<int, DLList *> freqMap;

  void updateFrequency(Node *n) {
    int oldFreq = n->freq;
    DLList *oldList = freqMap[oldFreq];
    oldList->removeNode(n);

    if (oldList->isEmpty() && oldFreq == minFreq) {
      minFreq++;
    }

    n->freq++;
    int newFreq = n->freq;

    if (freqMap.find(newFreq) == freqMap.end()) {
      freqMap[newFreq] = new DLList();
    }
    freqMap[newFreq]->addNode(n);
  }

public:
  LFUCache(int cap) {
    capacity = cap;
    size = 0;
    minFreq = 0;
  }

  int get(int key) {
    if (cache.find(key) == cache.end()) {
      return -1;
    }
    Node *n = cache[key];
    updateFrequency(n);
    return n->val;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;

    if (cache.find(key) != cache.end()) {
      Node *n = cache[key];
      n->val = value;
      updateFrequency(n);
      return;
    }

    if (size >= capacity) {
      DLList *minList = freqMap[minFreq];
      Node *toEvict = minList->tail->prev;

      cache.erase(toEvict->key);
      minList->removeNode(toEvict);
      delete toEvict;
      size--;
    }

    Node *newNode = new Node(key, value);
    cache[key] = newNode;

    minFreq = 1;
    if (freqMap.find(1) == freqMap.end()) {
      freqMap[1] = new DLList();
    }
    freqMap[1]->addNode(newNode);
    size++;
  }
};
