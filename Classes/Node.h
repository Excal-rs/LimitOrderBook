#pragma once

#include <queue>
#include "Order.h"

class Node {
public:
    Node(Order firstOrder, Node* parent = nullptr) 
        : parent(parent), left(nullptr), right(nullptr), colour(true) { // Red = True
        q.push(firstOrder);
    }

    // Queue Methods
    void enqueue(const Order& order) {
        q.push(order);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    Order peek() const {
        if (!q.empty()) {
            return q.front();
        }
        throw;
    }

    bool isEmpty() const {
        return q.empty();
    }

    size_t size() const {
        return q.size();
    }

    void clear() {
        while (!q.empty()) {
            q.pop();
        }
    }

    // Getter / Setters
    Node* getLeft() const { return left; }
    Node* getRight() const { return right; }
    Node* getParent() const { return parent; }

    void setLeft(Node* newLeft) { left = newLeft; }
    void setRight(Node* newRight) { right = newRight; }
    void setParent(Node* newParent) { parent = newParent; }


    bool getColour() const { return colour; }
    void setColour(bool newColour) { colour = newColour; }

private:
    std::queue<Order> q;  // Queue of orders
    bool colour;          // Red = True, Black = False (for Red-Black Tree balancing)

    Node* left;           // Left child pointer
    Node* right;          // Right child pointer
    Node* parent;         // Parent pointer
};
