// ================================
// File: monopoly_board.h
// Created by axavi on 2/25/2026.
// ================================

#ifndef MONOPOLY_BOARD_MONOPOLY_BOARD_H
#define MONOPOLY_BOARD_MONOPOLY_BOARD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static constexpr int MAX_SPACES = 40;

// ------------------------------------
// Data class
// ------------------------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace();
    MonopolySpace(const string& propertyName, const string& propertyColor, int value, int rent);

    bool isEqual(const MonopolySpace& other) const;
    void print() const;
};

// ------------------------------------
// Template Node Class
// ------------------------------------
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;

    explicit Node(T value) : data(value), nextNode(nullptr) {}
};

// ---------------------------------------
// Template Circular Linked List class
// ---------------------------------------
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;

    Node<T>* playerNode;
    int nodeCount;
    int passGoCount;

public:
    CircularLinkedList()
        : headNode(nullptr),
          tailNode(nullptr),
          playerNode(nullptr),
          nodeCount(0),
          passGoCount(0) {}

    // Core A: Add a Space with Capacity Enforcement
    bool addSpace(T value) {
        if (nodeCount >= MAX_SPACES) {
            return false;
        }

        Node<T>* newNode = new Node<T>(value);

        if (headNode == nullptr) {
            headNode = newNode;
            tailNode = newNode;
            playerNode = newNode;
            tailNode->nextNode = headNode;
        } else {
            tailNode->nextNode = newNode;
            tailNode = newNode;
            tailNode->nextNode = headNode;
        }

        nodeCount++;
        return true;
    }

    int size() const { return nodeCount; }

    int addMany(const vector<T>& values) {
        int added = 0;

        for (const T& v : values) {
            if (!addSpace(v)) {
                break;
            }
            added++;
        }

        return added;
    }

    void movePlayer(int steps) {
        if (steps <= 0) return;
        if (playerNode == nullptr || headNode == nullptr || tailNode == nullptr) return;

        for (int i = 0; i < steps; i++) {
            if (playerNode == tailNode) {
                passGoCount++;
            }
            playerNode = playerNode->nextNode;
        }
    }

    int getPassGoCount() const { return passGoCount; }

    void printFromPlayer(int count) const {
        if (count <= 0) return;

        if (playerNode == nullptr) {
            cout << "[Board is empty]\n";
            return;
        }

        const Node<T>* cur = playerNode;

        for (int i = 0; i < count; i++) {
            cur->data.print();
            cur = cur->nextNode;
        }
    }

    // Cleanup: prevent memory leaks
    ~CircularLinkedList() {
        clear();
    }

    // Edge-case helper: countSpaces O(n)
    int countSpaces() const {
        if (headNode == nullptr) return 0;

        int count = 0;
        const Node<T>* cur = headNode;

        do {
            count++;
            cur = cur->nextNode;
        } while (cur != headNode);

        return count;
    }

    // Optional helper: print full board once
    void printBoardOnce() const {
        if (headNode == nullptr) {
            cout << "[Board is empty]\n";
            return;
        }

        const Node<T>* cur = headNode;

        do {
            cur->data.print();
            cur = cur->nextNode;
        } while (cur != headNode);
    }

    // Cleanup: delete all nodes safely
    void clear() {
        if (headNode == nullptr) return;

        // why: break the cycle so deletion terminates
        tailNode->nextNode = nullptr;

        Node<T>* cur = headNode;
        while (cur != nullptr) {
            Node<T>* toDelete = cur;
            cur = cur->nextNode;
            delete toDelete;
        }

        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;
        nodeCount = 0;
        passGoCount = 0;
    }

};

#endif // MONOPOLY_BOARD_MONOPOLY_BOARD_H