// File: monopoly_board.cpp
// Created by axavi on 2/25/2026.

#include "monopoly_board.h"

// -------------------------------
// MonopolySpace definitions
// -------------------------------
MonopolySpace::MonopolySpace() {
    propertyName = "";
    propertyColor = "";
    value = 0;
    rent = 0;
}

MonopolySpace::MonopolySpace(string propertyName, string propertyColor, int value, int rent) {
    this->propertyName = propertyName;
    this->propertyColor = propertyColor;
    this->value = value;
    this->rent = rent;
}

bool MonopolySpace::isEqual(MonopolySpace other) {
    return propertyName == other.propertyName;
}

void MonopolySpace::print() const {
    cout << propertyName << " | " << propertyColor
         << " | $" << value << " | Rent " << rent << endl;
}

int main() {
    CircularLinkedList<MonopolySpace> board;

    cout << (board.addSpace(MonopolySpace("GO", "None", 0, 0)) ? "Added GO" : "Failed GO") << endl;
    cout << (board.addSpace(MonopolySpace("Mediterranean Avenue", "Brown", 60, 2)) ? "Added Med" : "Failed Med") << endl;

    cout << "Board size: " << board.size() << endl;
    cout << "\n Board view from player (next 5 spaces):\n";
    board.printFromPlayer(5);

    return 0;
}