// File: monopoly_board.h
// Created by axavi on 2/25/2026.


#ifndef MONOPOLY_BOARD_MONOPOLY_BOARD_H
#define MONOPOLY_BOARD_MONOPOLY_BOARD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const int MAX_SPACES = 40;

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
    MonopolySpace(string propertyName, string propertyColor, int value, int rent);

    bool isEqual(MonopolySpace other);
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
// Spring 2026 version: traversable board
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
                    return false; // reject cleanly without touching pointers
                }

                Node<T>* newNode = new Node<T>(value);

                if (headNode == nullptr) {
                    headNode = newNode;
                    tailNode = newNode;
                    playerNode = newNode;
                    tailNode->nextNode = headNode; // start the ring
                } else {
                    tailNode->nextNode = newNode;
                    tailNode = newNode;
                    tailNode->nextNode = headNode; // keep ring intact
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
};
#endif //MONOPOLY_BOARD_MONOPOLY_BOARD_H