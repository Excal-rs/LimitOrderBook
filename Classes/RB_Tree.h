#pragma once

#include <queue>
#include "Node.h"


class RB_Tree {
    public:
         using enum Node::Colour;

         RB_Tree(): root(nullptr){}

         // Insertion methods ----------------------------------------------
         void insert (Order newOrder){
            if (!root){
               Node* newNode = new Node(newOrder);
               newNode->setColour(BLACK);
            }

            Node* nodeOrParent = searchOrFindParent(newOrder.getPrice());
            if (nodeOrParent->getPrice() == newOrder.getPrice()){
               nodeOrParent->enqueue(newOrder);
               return;
            } else {
               Node* newNode = new Node(newOrder);
               if (nodeOrParent->getPrice() > newOrder.getPrice()){
                  nodeOrParent->setLeft(newNode);
               } else {
                  nodeOrParent->setRight(newNode);
               }

               fixInsertionViolations(newNode);
            }
         }

         void fixInsertionViolations(Node* node);


         // Fetching methods ----------------------------------------------
         Node* minimum(){
            Node* currentNode = root;
            while (currentNode->getLeft() != nullptr){
               currentNode = currentNode->getLeft();
            }

            return currentNode;
         }

         Node* maximum(){
            Node* currentNode = root;
            while (currentNode->getRight() != nullptr){
               currentNode = currentNode->getRight();
            }

            return currentNode;
         }


         Node* searchOrFindParent(double targetPrice){
            Node* current = root;
            Node* parent = nullptr;

            while (current) {
               parent = current;
               if (targetPrice == current->getPrice()) {
                     return current; // existing node 
               } else if (targetPrice < current->getPrice()) {
                     current = current->getLeft();
               } else{
                     current = current->getRight();
               }
            }
            return parent; // where the new node should attach
         }

         
         // Rotations -----------------------------------------------------

         // Traversals ----------------------------------------------------


         
    private:
         Node* root; 


};


/* 

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