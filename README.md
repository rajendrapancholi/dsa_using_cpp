# Data Structures in C++

This repository contains implementations of various data structures in C++. Each data structure is implemented with its basic operations, such as insertion, deletion, and traversal. The aim is to provide clear, well-documented code examples to help understand the underlying concepts and algorithms.

## Table of Contents

- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
  - [Windows](#windows)
  - [Linux](#linux)
  - [MacOS](#macos)
- [Usage](#usage)
- [Data Structures](#data-structures)
  - [Array](#array)
  - [Linked List](#linked-list)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Binary Tree](#binary-tree)
  - [Binary Search Tree](#binary-search-tree)
  - [Heap](#heap)
  - [Graph](#graph)
  - [Hash Table](#hash-table)
- [Contributing](#contributing)

## Getting Started

To get a local copy up and running, follow these simple steps.

## Prerequisites

You need to have a C++ compiler installed on your machine. For example, you can use `g++`, which is part of the GNU Compiler Collection.

## Installation

### Windows

1. Install MinGW:

   - Go to the [MinGW SourceForge page](https://sourceforge.net/projects/mingw/).
   - Click on the green "Download" button to download the mingw-get-setup.exe installer.
   - Run the installer and follow the setup instructions. Make sure to select mingw32-gcc-g++ in the "Select Components" window.
   - Add the bin directory (e.g., C:\MinGW\bin) to your system's PATH environment variable.

2. Verify Installation:

- Open a Command Prompt and type
  ```sh
  g++ --version
  ```
  to verify the installation.

### Usage

Compile the desired data structure file using the C++ compiler and run the executable. Each data structure implementation comes with a main function demonstrating its usage.

#### Example:

```sh
g++ src/array.cpp -o array
./array
```

### Linux

1. Install `g++`:

   ```sh
   sudo apt-get install g++
   ```

### MacOS

1. Install Homebrew if you haven't already:

   ```sh
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. Install g++:

   ```sh
   brew install gcc
   ```

## Data Structures

### Array

Arrays are collections of items stored at contiguous memory locations. The idea is to store multiple items of the same type together.

### Operations:

- Insertion: Add elements at a specific position.
- Deletion: Remove elements from a specific position.
- Access: Access elements using an index.
- File: src/array.cpp

### Linked List

A linked list is a linear data structure where each element is a separate object. Each element (node) contains a reference to the next node.

### Types:

- Singly Linked List: Each node points to the next node.
- Doubly Linked List: Each node points to both the next and previous nodes.
- Circular Linked List: The last node points to the first node.

### Operations:

- Insertion: Add elements at the beginning, end, or a specific position.
- Deletion: Remove elements from the beginning, end, or a specific position.
- Traversal: Traverse through the list to access elements.
- File: src/linked_list.cpp

### Stack

Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO (Last In First Out) or FILO (First In Last Out).

### Operations:

- Push: Add an element to the top of the stack.
- Pop: Remove the top element from the stack.
- Peek: Get the top element without removing it.
- IsEmpty: Check if the stack is empty.
- File: src/stack.cpp

### Queue

Queue is a linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO).

### Operations:

- Enqueue: Add an element to the end of the queue.
- Dequeue: Remove the front element from the queue.
- Front: Get the front element without removing it.
- Rear: Get the last element.
- IsEmpty: Check if the queue is empty.
- File: src/queue.cpp

### Binary Tree

A tree whose elements have at most 2 children is called a binary tree. Each element is called a node, and the top node is called the root.

### Operations:

- Insertion: Add elements to the tree.
- Deletion: Remove elements from the tree.
- Traversal: Traverse the tree in different ways (Inorder, Preorder, Postorder).
- File: src/binary_tree.cpp

### Binary Search Tree

Binary Search Tree is a node-based binary tree data structure with the following properties:

The left subtree of a node contains only nodes with keys lesser than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.

### Operations:

- Insertion: Add elements maintaining BST property.
- Deletion: Remove elements maintaining BST property.
- Search: Search for an element.
- File: src/bst.cpp

### Heap

A Heap is a special Tree-based data structure in which the tree is a complete binary tree. Generally, Heaps can be of two types:

1. Max-Heap: The key at the root node is the greatest among the keys present at all of its children.
2. Min-Heap: The key at the root node is the smallest among the keys present at all of its children.

### Operations:

- Insertion: Add elements maintaining heap property.
- Deletion: Remove elements maintaining heap property.
- Heapify: Convert an array into a heap.
- File: src/heap.cpp

### Graph

A Graph is a non-linear data structure consisting of nodes and edges. Nodes are sometimes referred to as vertices, and edges are lines or arcs that connect any two nodes in the graph.

#### Types:

1. Directed Graph: Edges have a direction.
2. Undirected Graph: Edges do not have a direction.

### Operations:

- Add Vertex: Add a vertex to the graph.
- Add Edge: Add an edge between two vertices.
- BFS: Breadth-First Search traversal.
- DFS: Depth-First Search traversal.
- File: src/graph.cpp

### Hash Table

A Hash Table is a data structure which stores data in an associative manner. In a hash table, data is stored in an array format, where each data value has a unique key associated with it.

### Operations:

- Insert: Add key-value pairs.
- Delete: Remove key-value pairs.
- Search: Search for a value by its key.
- File: src/hash_table.cpp

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

- Fork the Project
- Create your Feature Branch (git checkout -b feature/NewFeature)
- Commit your Changes (git commit -m 'Add some NewFeature')
- Push to the Branch (git push origin feature/NewFeature)
- Open a Pull Request

## Rajendra Pancholi.com

[visit now](https://www.rajendrapancholi.vercel.app)
