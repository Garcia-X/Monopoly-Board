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

static vector<MonopolySpace> buildStandardBoard() {
    vector<MonopolySpace> s;
    s.reserve(40);

    s.push_back(MonopolySpace("GO", "None", 0, 0));

    s.push_back(MonopolySpace("Mediterranean Avenue", "Brown", 60, 2));
    s.push_back(MonopolySpace("Community Chest", "None", 0, 0));
    s.push_back(MonopolySpace("Baltic Avenue", "Brown", 60, 4));
    s.push_back(MonopolySpace("Income Tax", "None", 200, 0));
    s.push_back(MonopolySpace("Reading Railroad", "Railroad", 200, 25));
    s.push_back(MonopolySpace("Oriental Avenue", "Light Blue", 100, 6));
    s.push_back(MonopolySpace("Chance", "None", 0, 0));
    s.push_back(MonopolySpace("Vermont Avenue", "Light Blue", 100, 6));
    s.push_back(MonopolySpace("Connecticut Avenue", "Light Blue", 120, 8));

    s.push_back(MonopolySpace("Jail / Just Visiting", "None", 0, 0));
    s.push_back(MonopolySpace("St. Charles Place", "Pink", 140, 10));
    s.push_back(MonopolySpace("Electric Company", "Utility", 150, 0));
    s.push_back(MonopolySpace("States Avenue", "Pink", 140, 10));
    s.push_back(MonopolySpace("Virginia Avenue", "Pink", 160, 12));
    s.push_back(MonopolySpace("Pennsylvania Railroad", "Railroad", 200, 25));
    s.push_back(MonopolySpace("St. James Place", "Orange", 180, 14));
    s.push_back(MonopolySpace("Community Chest", "None", 0, 0));
    s.push_back(MonopolySpace("Tennessee Avenue", "Orange", 180, 14));
    s.push_back(MonopolySpace("New York Avenue", "Orange", 200, 16));

    s.push_back(MonopolySpace("Free Parking", "None", 0, 0));
    s.push_back(MonopolySpace("Kentucky Avenue", "Red", 220, 18));
    s.push_back(MonopolySpace("Chance", "None", 0, 0));
    s.push_back(MonopolySpace("Indiana Avenue", "Red", 220, 18));
    s.push_back(MonopolySpace("Illinois Avenue", "Red", 240, 20));
    s.push_back(MonopolySpace("B. & O. Railroad", "Railroad", 200, 25));
    s.push_back(MonopolySpace("Atlantic Avenue", "Yellow", 260, 22));
    s.push_back(MonopolySpace("Ventnor Avenue", "Yellow", 260, 22));
    s.push_back(MonopolySpace("Water Works", "Utility", 150, 0));
    s.push_back(MonopolySpace("Marvin Gardens", "Yellow", 280, 24));

    s.push_back(MonopolySpace("Go To Jail", "None", 0, 0));
    s.push_back(MonopolySpace("Pacific Avenue", "Green", 300, 26));
    s.push_back(MonopolySpace("North Carolina Avenue", "Green", 300, 26));
    s.push_back(MonopolySpace("Community Chest", "None", 0, 0));
    s.push_back(MonopolySpace("Pennsylvania Avenue", "Green", 320, 28));
    s.push_back(MonopolySpace("Short Line", "Railroad", 200, 25));
    s.push_back(MonopolySpace("Chance", "None", 0, 0));
    s.push_back(MonopolySpace("Park Place", "Dark Blue", 350, 35));
    s.push_back(MonopolySpace("Luxury Tax", "None", 100, 0));
    s.push_back(MonopolySpace("Boardwalk", "Dark Blue", 400, 50));

    return s;
}

int main() {
    CircularLinkedList<MonopolySpace> board;

    vector<MonopolySpace> spaces = buildStandardBoard();
    int added = board.addMany(spaces);

    cout << "Spaces requested: " << spaces.size() << endl;
    cout << "Spaces added: " << added << endl;
    cout << "Board size: " << board.size() << endl;

    cout << "\nBoard view from player (next 12 spaces):\n";
    board.printFromPlayer(12);

    cout << "\nAttempt to add a 41st space: "
     << (board.addSpace(MonopolySpace("Extra Space", "None", 0, 0)) ? "success" : "rejected")
     << endl;

    cout << "Board size after attempt: " << board.size() << endl;
    cout << "\nBoard view from player (next 45 spaces):\n";
    board.printFromPlayer(45);

    return 0;
}