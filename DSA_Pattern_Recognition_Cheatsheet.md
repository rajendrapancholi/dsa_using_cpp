# DSA Pattern Recognition — Quick Reference Cheat Sheet

> How to use this: for every topic, scan the **"When you see..." → Pattern** table first. That's the recognition trigger. Templates/complexity follow for quick recall.

- Sorting Techniques
- Solve Problems on Arrays [Easy -> Medium -> Hard]
- Strings
- Binary Search [1D, 2D Arrays, Search Space]
- Bit Manipulation [Concepts & Problems]
- LinkedList [Single LL, Double LL, Medium, Hard Problems]
- Sliding Window & Two Pointer Combined Problems
- Recursion [PatternWise]
- Stack and Queues [Pre-In-Post-fix, Monotonic Stack, Implementation]
- Greedy Algorithms [Easy, Medium/Hard]
- Dynamic Programming [Patterns and Problems]
- Heaps [Learning, Medium, Hard Problems]
- Binary Trees [Traversals, Medium and Hard Problems]
- Binary Search Trees [Concept and Problems]
- Graphs [Concepts & Problems]
- Tries

## 1. Sorting Techniques

| Algorithm | Idea | Time | Space | Stable? | When to use |
|---|---|---|---|---|---|
| Bubble Sort | Repeated adjacent swaps | O(n²) | O(1) | Yes | Never in practice; teaching only |
| Selection Sort | Pick min, place at front | O(n²) | O(1) | No | Minimizing swaps matters |
| Insertion Sort | Insert into sorted prefix | O(n²), O(n) best | O(1) | Yes | Nearly-sorted / small / online data |
| Merge Sort | Divide, sort halves, merge | O(n log n) | O(n) | Yes | Need stability, linked lists, external sort, counting inversions |
| Quick Sort | Pivot partition | O(n log n) avg, O(n²) worst | O(log n) | No | General purpose, in-place, cache-friendly |
| Heap Sort | Build max-heap, extract | O(n log n) | O(1) | No | Guaranteed O(n log n), no extra space |
| Counting Sort | Frequency array | O(n+k) | O(k) | Yes | Small integer range |
| Radix Sort | Digit-by-digit counting sort | O(d(n+k)) | O(n+k) | Yes | Fixed-width integers/strings |
| Cyclic Sort | Place each num at index `num` | O(n) | O(1) | — | Array has values in range `[1,n]` or `[0,n-1]` |

**"When you see..." → Pattern**
- "Sort with O(1) extra space, values in range 1..n" → **Cyclic Sort** (find missing/duplicate number problems)
- "Count inversions / merge two sorted lists" → **Merge Sort** merge step
- "Kth smallest/largest without full sort" → **Quickselect** (partition-based)
- "Sort colors / 3 distinct values" → **Dutch National Flag** (3-way partition)
- "Sort by frequency" → Counting/Bucket sort

## 2. Arrays

### Easy
| Signal | Pattern |
|---|---|
| "Find max/min subarray sum" | Kadane's Algorithm |
| "Move zeros / remove duplicates in-place" | Two-pointer (read/write pointer) |
| "Rotate array by k" | Reverse trick (reverse whole, reverse parts) |
| "Union/Intersection of two sorted arrays" | Two-pointer merge |
| "Leaders in array / next greater on right" | Traverse right→left with running max |

### Medium
| Signal | Pattern |
|---|---|
| "Rearrange positives/negatives alternately" | Two-pointer with placeholder swap |
| "Next permutation" | Find pivot from right, swap, reverse suffix |
| "Subarray sum equals K" | Prefix sum + HashMap |
| "Majority element (> n/2)" | Boyer-Moore Voting |
| "Majority element (> n/3)" | Extended Boyer-Moore (2 candidates) |
| "3Sum / 4Sum" | Sort + two-pointer (fix k-2 elements) |
| "Merge overlapping intervals" | Sort by start, sweep & merge |
| "Merge two sorted arrays in-place" | Gap method / two-pointer from back |
| "Count inversions" | Merge sort modification |
| "Max product subarray" | Track running max AND min (negatives flip) |

### Hard
| Signal | Pattern |
|---|---|
| "Median of two sorted arrays" | Binary search on smaller array partition |
| "Trapping rain water" | Two-pointer with leftMax/rightMax, or prefix/suffix max arrays |
| "Max rectangle in histogram / binary matrix" | Monotonic stack |
| "Count subarrays with XOR = K" | Prefix XOR + HashMap |
| "Smallest window containing all elements" | Sliding window + HashMap |

## 3. Strings

| Signal | Pattern |
|---|---|
| "Check anagram" | Frequency array/HashMap comparison |
| "Longest palindromic substring" | Expand around center, or DP, or Manacher's (optimal) |
| "Check palindrome ignoring case/non-alnum" | Two-pointer from ends |
| "Longest common prefix" | Vertical scanning / sort & compare first-last |
| "Pattern matching (substring search)" | KMP (LPS array), Z-function, or Rabin-Karp (rolling hash) |
| "Minimum insertions/deletions to make palindrome" | LCS with reverse string (DP) |
| "Group anagrams" | HashMap with sorted-string / char-count key as key |
| "Roman to integer / integer to roman" | Greedy symbol mapping |
| "Word break" | DP with HashSet dictionary lookup |
| "Longest repeating substring / distinct substrings count" | Suffix Array / Trie |
| "String compression / run-length" | Two-pointer, count consecutive chars |
| "Valid parentheses / balanced brackets" | Stack |
| "Count & say / string transformation sequences" | Simulation with build-string loop |

## 4. Binary Search

**Core signal:** search space is **sorted OR monotonic** (even if not an explicit array — "can I achieve X with value V?" being monotonic is enough).

### Template
```
lo, hi = 0, n-1
while lo <= hi:
    mid = lo + (hi-lo)//2
    if condition(mid): hi = mid - 1   # or lo = mid+1, depends on direction
    else: lo = mid + 1
return lo
```

### 1D Array
| Signal | Pattern |
|---|---|
| "Find element in sorted array" | Standard binary search |
| "Find first/last occurrence" | Lower bound / Upper bound variants |
| "Search in rotated sorted array" | Identify sorted half each iteration |
| "Find peak element" | Compare mid with mid+1, go toward larger side |
| "Find minimum in rotated sorted array" | Binary search comparing mid with hi |
| "Single element in sorted array (others appear twice)" | Binary search on even/odd index parity |
| "Sqrt(x), Nth root" | Binary search on answer value |

### 2D Array
| Signal | Pattern |
|---|---|
| "Search in row-wise & column-wise sorted matrix" | Start top-right/bottom-left corner, eliminate row/col |
| "Search in matrix sorted like flattened 1D array" | Treat as 1D, mid → (mid/cols, mid%cols) |
| "Kth smallest in sorted matrix" | Binary search on value range + count ≤ mid |
| "Find row with max ones (sorted rows)" | Binary search per row |

### Binary Search on Answer / Search Space
| Signal | Pattern |
|---|---|
| "Minimize the maximum" / "Maximize the minimum" | Binary search on answer + feasibility check |
| "Allocate books / painters / ship packages within D days" | Binary search on max-load, check with greedy simulation |
| "Aggressive cows (max min distance)" | Binary search on distance, greedy placement check |
| "Koko eating bananas (min speed)" | Binary search on speed, check total hours |
| "Median of data stream / two arrays" | Binary search on partition |

## 5. Bit Manipulation

### Concepts
```
Check bit i:      (n >> i) & 1
Set bit i:         n | (1 << i)
Clear bit i:        n & ~(1 << i)
Toggle bit i:       n ^ (1 << i)
Remove last set bit: n & (n-1)
Isolate last set bit: n & (-n)
Check power of 2:   n > 0 && (n & (n-1)) == 0
Count set bits:     Brian Kernighan's (loop n &= n-1)
```

### Problems
| Signal | Pattern |
|---|---|
| "Single number (others appear twice)" | XOR all elements (a^a=0) |
| "Two numbers appear once, rest twice" | XOR all → find differing bit → split into 2 groups |
| "Number appears thrice, rest twice" | Bit counting mod 3 |
| "Count set bits from 0 to n" | DP: `bits[i] = bits[i>>1] + (i&1)` |
| "Subsets / power set generation" | Bitmask iterate 0 to 2^n - 1 |
| "XOR of range / XOR 1 to n" | Pattern based on n%4 |
| "Minimum bit flips to convert A to B" | Count set bits in A^B |
| "Maximum XOR of two numbers in array" | Trie of bits (binary trie) |
| "Divide two integers without / or *" | Bit shifting to subtract powers of 2 |

## 6. Linked List

### Single LL
| Signal | Pattern |
|---|---|
| "Detect cycle" | Floyd's Slow/Fast pointer |
| "Find start of cycle" | Floyd's — after meeting, reset one pointer to head, move both by 1 |
| "Find middle of list" | Slow/Fast pointer (fast moves 2x) |
| "Reverse a linked list" | Iterative 3-pointer (prev/curr/next), or recursive |
| "Reverse in groups of K" | Recursive/iterative with group boundary check |
| "Remove Nth node from end" | Two-pointer with N gap |
| "Detect & remove loop" | Floyd's + relink |
| "Check palindrome LL" | Find middle → reverse second half → compare |
| "Merge two sorted LLs" | Dummy node + two-pointer merge |
| "Add two numbers as LL" | Simulate addition with carry, dummy node |
| "Intersection point of two LLs" | Two-pointer switch heads (equalize path length) |
| "Sort a linked list" | Merge sort (slow/fast to split) |
| "Flatten a multilevel/child LL" | Recursive merge, similar to merge-sort merge |

### Doubly LL
| Signal | Pattern |
|---|---|
| "LRU Cache" | DLL + HashMap (O(1) get/put, move-to-front) |
| "Implement DLL insert/delete" | Maintain prev & next pointers both sides |
| "Flatten DLL with child pointers" | DFS-like recursive merge |

### Medium/Hard
| Signal | Pattern |
|---|---|
| "Clone LL with random pointer" | HashMap old→new, or interweaving trick |
| "Rotate list by K places" | Make circular, break at right point |
| "Reorder list (L0→Ln→L1→Ln-1...)" | Find middle, reverse second half, merge alternately |
| "Merge K sorted lists" | Min-Heap of size K, or divide & conquer merge |
| "LFU Cache" | HashMap + frequency buckets of DLLs |

## 7. Sliding Window & Two Pointer

**Core signal:** contiguous subarray/substring + condition on sum/count/distinct elements, OR two sorted sequences to compare from both ends.

| Signal | Pattern |
|---|---|
| "Fixed size K subarray max/min sum" | Fixed window: add new, remove old |
| "Longest substring without repeating chars" | Variable window + HashSet/HashMap, shrink on violation |
| "Longest substring with at most K distinct chars" | Variable window + frequency map |
| "Minimum window substring containing all chars of T" | Variable window, expand then contract when valid |
| "Max consecutive ones with at most K flips" | Variable window tracking zero-count |
| "Subarray with sum exactly K (positive nums)" | Variable window (shrink when sum > K) |
| "Subarray with sum exactly K (has negatives)" | Prefix sum + HashMap (NOT sliding window) |
| "Longest repeating char replacement" | Window + track max-freq char, shrink when `window-maxFreq > K` |
| "Fruits into baskets / at most 2 types" | Variable window, frequency map size ≤ 2 |
| "Two Sum in sorted array" | Two-pointer from both ends |
| "Container with most water" | Two-pointer, move pointer with smaller height |
| "3Sum closest / 3Sum smaller" | Sort + two-pointer per fixed element |
| "Sliding window maximum" | Monotonic deque (decreasing) |
| "Number of subarrays with exactly K distinct" | `atMost(K) - atMost(K-1)` trick |

**Template (variable window):**
```
left = 0
for right in range(n):
    add(arr[right])
    while window_invalid():
        remove(arr[left]); left += 1
    update_answer()
```

## 8. Recursion (Pattern-wise)

| Signal | Pattern |
|---|---|
| "Generate all subsets/subsequences" | Include/Exclude recursion (pick/not-pick) |
| "Subsets with duplicates (unique only)" | Sort first, skip adjacent duplicates at same recursion level |
| "Combination Sum (reuse allowed)" | Pick/not-pick, stay at same index when picking |
| "Combination Sum II (no reuse, has dupes)" | Sort, loop with `i>start && arr[i]==arr[i-1]` skip |
| "Permutations" | Swap-based recursion, or visited[] array with backtracking |
| "Permutations with duplicates" | Sort + visited[] + skip same adjacent unless prev used |
| "Palindrome partitioning" | Backtrack: try every prefix, recurse on rest if palindrome |
| "N-Queens / Sudoku Solver" | Backtracking with placement validity check |
| "Word search in grid" | DFS backtracking with visited marking/unmarking |
| "Rat in a maze" | DFS backtracking with direction array |
| "Kth permutation sequence" | Factorial number system (no need to generate all) |
| "Print all paths (tree/graph/grid)" | DFS with path list, backtrack after |

**Rule of thumb:** if "generate all ___" or "count all ways ___" → recursion/backtracking. If asked for **optimal count only** → check if DP applies instead (overlapping subproblems).

## 9. Stack and Queues

### Prefix / Infix / Postfix
| Task | Approach |
|---|---|
| Infix → Postfix | Stack for operators, precedence + associativity check |
| Infix → Prefix | Reverse infix, swap `(`↔`)`, convert to postfix, reverse result |
| Postfix evaluation | Push operands, pop 2 & apply operator on operator token |
| Prefix evaluation | Scan right→left, same stack logic |

### Monotonic Stack
| Signal | Pattern |
|---|---|
| "Next Greater Element" | Monotonic decreasing stack, traverse right→left (or left→right with index storage) |
| "Next Smaller Element" | Monotonic increasing stack |
| "Previous Greater/Smaller Element" | Same, traverse left→right |
| "Largest rectangle in histogram" | Monotonic stack storing indices, find nearest smaller left/right |
| "Maximal rectangle in binary matrix" | Histogram trick per row + largest-rectangle-in-histogram |
| "Trapping rain water" | Monotonic stack (alternative to two-pointer) |
| "Stock span problem" | Monotonic decreasing stack of (price, span) |
| "Remove K digits to form smallest number" | Monotonic increasing stack, pop greater digits |
| "Sum of subarray minimums/maximums" | Monotonic stack, count contribution via nearest smaller/greater bounds |
| "Online stock span / asteroid collision" | Stack simulation |

### Implementation Patterns
| Signal | Pattern |
|---|---|
| "Implement stack using queue(s) / queue using stack(s)" | Two-container simulation |
| "Min Stack (O(1) getMin)" | Auxiliary stack, or store (val, currentMin) pairs |
| "Max Stack" | Same idea with max, or use pairing/multiset |
| "LRU-like design with stack" | Stack + validation array |
| "Valid parentheses / balanced brackets" | Stack push open, pop & match close |
| "Circular queue / Deque implementation" | Array with front/rear modulo indexing |
| "Sliding window maximum" | Monotonic deque |
| "Celebrity problem" | Two-pointer or stack elimination |

## 10. Greedy Algorithms

### Easy
| Signal | Pattern |
|---|---|
| "Assign cookies / minimize resource matching" | Sort both, greedy two-pointer |
| "Lemonade change" | Track denominations greedily |
| "Minimum coins (canonical system)" | Greedy from largest denomination |
| "Fractional knapsack" | Sort by value/weight ratio descending |

### Medium/Hard
| Signal | Pattern |
|---|---|
| "Activity selection / max non-overlapping intervals" | Sort by end time, greedily pick |
| "Minimum meeting rooms / platforms" | Sort start & end separately, sweep with two-pointer, or min-heap |
| "Job sequencing with deadlines" | Sort by profit desc, place in latest free slot ≤ deadline |
| "Minimum number of jumps to reach end" | Greedy range-extension (BFS-like) |
| "Gas station (circuit tour)" | Greedy — if total gas ≥ total cost, single pass tracks start |
| "Candy distribution" | Two-pass greedy (left→right, right→left) |
| "Insert interval / merge intervals" | Sort + sweep |
| "Partition labels" | Track last occurrence, greedy widen window |
| "Huffman encoding" | Min-heap, always combine two smallest |
| "N meetings in one room" | Sort by finish time, greedy pick |
| "Shortest job first / minimize waiting time" | Sort by burst time |
| "Chocolate distribution" | Sort, minimize sliding window of size m |

**Rule of thumb:** greedy works when a **locally optimal choice leads to globally optimal** — usually provable via exchange argument or matroid structure. If counterexamples exist under greedy, it's likely a DP problem instead.

## 11. Dynamic Programming (Patterns)

| Pattern | Signal | Example Problems |
|---|---|---|
| **1D DP** | "Ways to reach step N", linear dependency on i-1, i-2 | Climbing stairs, House robber, Fibonacci |
| **2D Grid DP** | "Paths in grid", "min/max path sum" | Unique paths, Min path sum, Cherry pickup |
| **Knapsack (0/1)** | "Include or exclude item, weight limit" | Subset sum, Equal partition, Target sum |
| **Unbounded Knapsack** | "Unlimited use of items" | Coin change, Rod cutting |
| **LCS Family** | "Two strings, common subsequence/substring" | LCS, LPS, Edit distance, Shortest common supersequence |
| **DP on Subsequences** | "Count/find subsequence satisfying condition" | LIS, Distinct subsequences |
| **LIS Patterns** | "Longest increasing subsequence" | LIS (O(n²) or O(n log n) w/ binary search), Russian doll envelopes |
| **DP on Strings (Palindromes)** | "Partition/count palindromic substrings" | Palindrome partitioning II, Longest palindromic substring |
| **Matrix Chain Multiplication (Interval DP)** | "Optimal way to split/parenthesize/partition range" | MCM, Burst balloons, Boolean evaluation, Palindrome partitioning |
| **DP on Trees** | "Max path sum in tree", "diameter" | House robber III, Tree diameter |
| **DP on Grids w/ obstacles/varying moves** | "Min/max with obstacles or k moves" | Dungeon game, Cherry pickup II |
| **Bitmask DP** | "Assign N items to N slots optimally", small N (≤20) | TSP, Assignment problem |
| **Digit DP** | "Count numbers in range with property" | Count numbers with digit sum, no repeated digits |
| **State Machine DP** | "Buy/sell stock with cooldown/fee/K transactions" | Best time to buy/sell stock I-IV |
| **DP + Binary Search** | "LIS optimal O(n log n)" | Patience sorting |
| **Kadane variant DP** | "Max subarray with additional constraint" | Max product subarray, circular subarray |

**Recognition checklist:** overlapping subproblems + optimal substructure + (choices at each step OR two sequences OR partition points) → DP. Ask: "What changes as I move forward?" → that becomes your state.

## 12. Heaps

| Signal | Pattern |
|---|---|
| "Kth largest/smallest element" | Min-heap of size K (for largest) / Max-heap of size K (for smallest) |
| "K closest points to origin" | Max-heap of size K by distance |
| "Top K frequent elements" | Min-heap of size K by frequency, or bucket sort |
| "Merge K sorted lists/arrays" | Min-heap of size K (one element per list) |
| "Median from data stream" | Two heaps: max-heap (lower half) + min-heap (upper half) |
| "Task scheduler / rearrange with cooldown" | Max-heap by frequency + cooldown queue |
| "Connect ropes with min cost" | Min-heap, always combine two smallest |
| "IPO / maximize capital" | Two heaps: min-heap by capital requirement, max-heap by profit |
| "Sliding window median" | Two heaps + lazy deletion |
| "Dijkstra's / Prim's shortest path" | Min-heap (priority queue) for greedy edge selection |
| "Reorganize string (no adjacent same chars)" | Max-heap by frequency |

## 13. Binary Trees

### Traversals
| Type | Method |
|---|---|
| Preorder (Root-L-R) | Recursive, or stack (push right then left) |
| Inorder (L-Root-R) | Recursive, or stack with cur=cur.left unwinding |
| Postorder (L-R-Root) | Recursive, or two-stack / one-stack reversed preorder |
| Level order (BFS) | Queue, level-size snapshot for level-wise grouping |
| Morris Traversal | O(1) space using threaded binary tree (temp links via predecessor) |
| Boundary/Vertical/Diagonal traversal | Combine DFS/BFS with direction/column tracking (HashMap<col, list>) |

### Medium/Hard
| Signal | Pattern |
|---|---|
| "Height/diameter of tree" | DFS returning height, update global max at each node |
| "Balanced binary tree check" | DFS returning height, -1 sentinel for imbalance |
| "Lowest common ancestor" | Recursive: return node if found in both subtrees |
| "Max path sum (any node to any node)" | DFS returning max single-path gain, track global max sum |
| "Zigzag / spiral level order" | BFS + alternate direction flag |
| "Construct tree from inorder+preorder/postorder" | Recursive split using index map for inorder |
| "Symmetric tree / mirror check" | Recursive compare left.left vs right.right, left.right vs right.left |
| "Serialize/Deserialize tree" | Preorder with null markers, or level-order with queue |
| "Right/left view of tree" | BFS take last/first per level, or DFS with depth tracking |
| "Flatten tree to linked list" | Reverse postorder (right, left, root) with prev pointer, or Morris-like |
| "Count nodes in complete binary tree" | Binary search using height comparison (O(log²n)) |
| "Vertical order traversal" | BFS/DFS + HashMap<column, list> + sort by row/value if tie |
| "Sum tree / children sum property" | Recursive validate + adjust |

## 14. Binary Search Trees

| Signal | Pattern |
|---|---|
| "Search/Insert/Delete in BST" | Use BST property to go left/right, O(h) |
| "Validate BST" | Inorder should be strictly increasing, or min/max bound recursion |
| "Kth smallest/largest in BST" | Inorder traversal (Morris for O(1) space) |
| "LCA in BST" | Compare values with root — go left/right/stop based on range |
| "Convert sorted array to balanced BST" | Recursive pick middle as root |
| "BST iterator (O(1) amortized next())" | Controlled inorder traversal with explicit stack |
| "Two Sum in BST" | Inorder → two-pointer, or BST iterator (forward+backward) |
| "Recover BST (two nodes swapped)" | Inorder traversal, track two violating nodes |
| "Predecessor/Successor in BST" | Use BST property, O(h) traversal |
| "Merge two BSTs" | Inorder both → merge sorted arrays → build balanced BST |
| "Floor/Ceil in BST" | O(h) traversal tracking closest ≤ / ≥ |

## 15. Graphs

### Concepts
| Concept | Notes |
|---|---|
| Representation | Adjacency list (sparse) vs matrix (dense) |
| BFS | Level-by-level, shortest path in **unweighted** graph |
| DFS | Recursion/stack, used for connectivity, cycles, topological sort |
| Topological Sort | DFS (finish-time stack) or Kahn's BFS (indegree) — **DAG only** |
| Union-Find (DSU) | Path compression + union by rank/size, near O(1) ops |
| MST | Prim's (heap-based, dense) or Kruskal's (DSU-based, sparse) |
| Shortest Path (weighted, non-negative) | Dijkstra's (min-heap) |
| Shortest Path (negative weights) | Bellman-Ford (detects negative cycles) |
| All-pairs shortest path | Floyd-Warshall O(V³) |
| Bridges & Articulation Points | Tarjan's algorithm (discovery time + low-link) |
| Strongly Connected Components | Kosaraju's (2 DFS passes) or Tarjan's |

### Problems
| Signal | Pattern |
|---|---|
| "Number of islands / connected components" | DFS/BFS flood fill, or Union-Find |
| "Shortest path in unweighted graph/grid" | BFS |
| "Shortest path with weights" | Dijkstra's |
| "Shortest path with negative weights/detect negative cycle" | Bellman-Ford |
| "Shortest path in binary maze / min steps" | BFS (multi-source if multiple starts) |
| "Cycle detection (undirected)" | DFS with parent tracking, or Union-Find |
| "Cycle detection (directed)" | DFS with recursion-stack (visiting array), or Kahn's (if cycle, not all nodes processed) |
| "Course schedule / task ordering" | Topological Sort |
| "Clone a graph" | DFS/BFS + HashMap old→new |
| "Number of provinces / friend circles" | Union-Find or DFS |
| "Word Ladder (min transformations)" | BFS (graph of word transformations) |
| "Rotten oranges / multi-source spread" | Multi-source BFS |
| "Bipartite graph check" | BFS/DFS 2-coloring |
| "Minimum spanning tree" | Prim's or Kruskal's |
| "Redundant connection" | Union-Find (edge causing cycle) |
| "Alien dictionary (order of letters)" | Build graph from adjacent word comparison + Topological sort |
| "Critical connections / bridges" | Tarjan's bridge-finding |
| "Strongly connected components" | Kosaraju's or Tarjan's |
| "Swim in rising water / path with min max edge" | Binary search + BFS/DFS, or modified Dijkstra (minimize max edge) |
| "Network delay time" | Dijkstra's from source |
| "Cheapest flights within K stops" | Bellman-Ford limited to K iterations, or BFS/DFS with state (node, stops) |
| "Accounts merge / grouping via shared property" | Union-Find |
| "Grid as graph (surrounded regions, Pacific Atlantic)" | DFS/BFS from boundary inward |

## 16. Tries

| Signal | Pattern |
|---|---|
| "Implement Trie (insert/search/startsWith)" | Node with children map/array[26] + isEndOfWord flag |
| "Longest word with all prefixes present" | Trie + DFS, track valid words |
| "Word search II (multiple words in grid)" | Build Trie of words + DFS/backtracking on grid |
| "Maximum XOR of two numbers" | Binary Trie (32-bit), greedy bit-by-bit |
| "Autocomplete / prefix matching system" | Trie + DFS collecting words under a node |
| "Count distinct substrings" | Trie built from all suffixes (or suffix array/tree) |
| "Replace words with root (dictionary shortest prefix)" | Trie insert dictionary, search each word for shortest valid prefix |
| "Camelcase matching / pattern matching with prefixes" | Trie combined with pattern matching logic |

## Master Recognition Table (Cross-Topic Quick Lookup)

| Keyword in Problem | Likely Technique |
|---|---|
| "contiguous subarray/substring" | Sliding Window |
| "sorted array" | Two Pointer / Binary Search |
| "kth largest/smallest" | Heap or Quickselect |
| "all subsets/permutations/combinations" | Recursion/Backtracking |
| "minimum/maximum ways to..." | Dynamic Programming |
| "next greater/smaller element" | Monotonic Stack |
| "shortest path" | BFS (unweighted) / Dijkstra (weighted) |
| "connected components / grouping" | DFS/BFS / Union-Find |
| "prefix matching" | Trie |
| "range sum queries" | Prefix Sum / Segment Tree / Fenwick Tree |
| "in range [1, n] with O(1) space" | Cyclic Sort / Index Marking |
| "top K / frequency" | Heap or Bucket Sort |
| "overlapping intervals" | Sort + Sweep |
| "two sequences comparison" | DP (LCS family) |
| "minimize the maximum / maximize the minimum" | Binary Search on Answer |
| "tree path / ancestor" | DFS with return value propagation |
| "circular array" | Modulo indexing, or double the array |
| "in-place O(1) space array trick" | Two-pointer / Cyclic sort / marking with sign or index |

---

*Tip: When stuck, ask three questions — (1) Is there a monotonic/sorted property? → Binary Search. (2) Do choices repeat with overlapping subproblems? → DP. (3) Do I need "all ways" rather than "best way"? → Backtracking.*



## 1. Make the Cheat Sheet More “Trigger-Focused”

Right now it is excellent for reference, but a bit long for quick mental recall during a contest/interview.

**Improve it this way:**

Create a **one-page ultra-condensed version** with only the highest frequency triggers:

| When you see this...                          | First Pattern to Think |
|-----------------------------------------------|------------------------|
| Contiguous subarray / substring + condition   | Sliding Window         |
| Sorted array + pair/triplet                   | Two Pointers           |
| "Minimize the maximum" / "Maximize the minimum" | Binary Search on Answer |
| Kth largest / Top K                           | Heap (or Quickselect)  |
| Next Greater / Smaller                        | Monotonic Stack        |
| Connected components / Islands                | DFS / BFS / Union-Find |
| Shortest path (unweighted)                    | BFS                    |
| Shortest path (weighted)                      | Dijkstra               |
| All ways / generate all                       | Recursion + Backtracking |
| Optimal count / min-max with choices          | DP                     |
| Prefix matching / dictionary of words         | Trie                   |
| Overlapping intervals                         | Sort + Sweep Line      |

Keep the detailed version, but force yourself to recall from this short version first.

### 2. How to Stop Forgetting Patterns (Most Important)

Just reading the sheet does **not** lock the pattern in memory. You need **Active Recall + Spaced Repetition**.

**Daily System (Follow this strictly for 3–4 weeks):**

1. **Morning (15–20 min)**  
   Open your cheat sheet and cover the “Pattern” column.  
   Look only at the “Signal” and force yourself to recall the pattern + the key idea (without looking).

2. **Evening Practice (Main part)**  
   - Pick 4 problems from topics you already know.  
   - **Blind solve** (do not open old code).  
   - Time limit: 25–35 minutes per problem.  
   - After finishing (or failing), write in a notebook:
     - What pattern it was
     - What signal you missed or remembered late
     - The key insight you forgot

3. **Spaced Revision Schedule** for each problem:
   - Day 0 → Solved
   - Day 2 → Blind revise
   - Day 7 → Blind revise
   - Day 15 → Final check

This is the only reliable way to move patterns from “I have seen this” to “I can retrieve it under pressure”.

### 3. Speed Training Method

Do this 4–5 times a week:

- Set a timer for **50 minutes**.
- Solve **exactly 2 medium problems**.
- Rules:
  - First 3–4 minutes → only pattern recognition + approach (no coding).
  - Then code.
  - If you can’t get the approach in 6–7 minutes, look at the pattern name only (not the full solution), then continue.

Goal: Reach a stage where for standard medium problems you lock the pattern in ≤ 4 minutes.

### 4. Weak Areas I Noticed in Your Sheet (Small Improvements)

Your sheet is strong, but add these high-frequency missing triggers:

- **Prefix Sum + HashMap** → Subarray sum = K (with negatives), subarray XOR = K
- **Difference Array** → Range updates
- **Monotonic Queue/Deque** → Sliding Window Maximum / Minimum
- **Dijkstra with state** → (node, steps) or (node, cost) for problems like Cheapest Flights Within K Stops
- **Binary Search + DP / Greedy check** → Many hard problems mix these

Also, for DP, add a quick decision tree:

```
Is it a sequence / string problem? → LCS / LIS / Edit Distance family
Is it include/exclude with capacity? → Knapsack family
Is it grid paths? → Grid DP
Is it partitioning / bursting / matrix chain? → Interval DP
Is it stock buy-sell with constraints? → State Machine DP
```

### 5. Immediate Action Plan (Next 14 Days)

| Day       | What to do                                      |
|-----------|-------------------------------------------------|
| Day 1–2   | Create the 1-page ultra-short trigger version   |
| Day 3–14  | Daily: 15 min active recall of sheet + 2–3 blind timed problems |
| Every Sunday | Full mock (3 problems in 90 minutes) + update mistake notebook |

