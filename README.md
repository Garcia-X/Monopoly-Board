# Monopoly Board Simulator 

This project simulates a simplified Monopoly-style board using a circular linked list.
The list is used for pointer-based traversal (moving the player around the ring),
including wrapping around and tracking how many times the player passes GO.

## Build and Run

### Build (CLion)
1. Open the project folder in CLion
2. Click Build

### Build (Command Line)
From the project folder:
g++ -std=c++17 monopoly_board.cpp -o MonopolyBoard

### Run
./MonopolyBoard

## Data Structures Used

### MonopolySpace
Represents one board space:
- propertyName
- propertyColor
- value
- rent

### CircularLinkedList<T> (circular singly linked list)
The board is stored as a circular singly linked list:
- headNode: first space
- tailNode: last space, always links back to headNode
- playerNode: the player’s current position for traversal
- nodeCount: number of spaces currently in the board
- passGoCount: how many times the player passes GO

## 40-Space Board Limit
The board has a hard maximum of 40 spaces.
- addSpace rejects additions once 40 nodes exist
- addMany stops adding exactly at capacity

## Functions Implemented

### Board Construction
- addSpace(value): add one space to the tail (keeps circular links), enforces max 40
- addMany(values): add multiple spaces until the board is full, returns number added

### Traversal / Gameplay
- movePlayer(steps): moves playerNode forward steps times, node-by-node, wraps naturally
- getPassGoCount(): returns number of times the player has passed GO

### Display
- printFromPlayer(count): prints exactly count spaces starting from playerNode (no infinite loop)
- printBoardOnce(): prints the board exactly once around the ring

### Edge Cases / Cleanup
- countSpaces(): counts nodes by traversing exactly once (O(n))
- clear(): breaks the cycle and deletes all nodes safely
- ~CircularLinkedList(): destructor calls clear() to prevent memory leaks

### Advanced Option A
- findByColor(color): traverses the ring once and returns matching space names
- removeByName(name): deletes first matching node and handles head/tail/only-node cases

## Traversal and Movement Logic
Movement advances playerNode one node at a time using nextNode.
Because the list is circular, moving past the tail returns to the head automatically.
Passing GO is detected when a move crosses from tailNode back to headNode.