#pragma once

#include <queue>
#include <Node.h>

class RB_Tree {
    public:
         RB_Tree(): root(nullptr){}
    private:
         Node* root; 

};

/*
RedBlackTree Class:



2. void insert(int value):
   - Inserts a new node with the specified 'value' into the tree.
   - Ensures that Red-Black Tree properties are maintained after insertion.

3. void insertHelper(Node* root, Node* newNode):
   - Recursive helper function to insert 'newNode' at the correct position in the tree.

4. void fixInsertViolations(Node* node):
   - After insertion, this function checks and fixes any violations of Red-Black Tree properties (e.g., two consecutive red nodes).
   - Performs necessary rotations and recoloring to restore the properties.

5. void rotateLeft(Node* node):
   - Performs a left rotation on the given 'node'.
   - Used to fix imbalance during insertion or balancing.

6. void rotateRight(Node* node):
   - Performs a right rotation on the given 'node'.
   - Used to fix imbalance during insertion or balancing.

7. void display(Node* node, int indent = 0) const:
   - A utility function to print the tree structure (for debugging or visualization).
   - Recursively displays the tree in a readable format, indenting nodes based on their level in the tree.
*/