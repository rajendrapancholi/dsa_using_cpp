#include <iostream>
using namespace std;

// Define a generic 3-element structure (like pair but with 3 values)
template <typename T1, typename T2, typename T3>
struct trie {
    T1 first;
    T2 second;
    T3 third;

    // Constructors
    trie() = default;
    trie(const T1& a, const T2& b, const T3& c)
        : first(a), second(b), third(c) {}
};
