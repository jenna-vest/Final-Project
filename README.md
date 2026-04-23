# Red-Black Tree for Student Score Data

## About the Program

### Project Goal

This project implements a red black tree to store student data, including their IDs and current scores in a course.

### Red-Black Tree Data Structure

In a standard binary search tree, each node has up to two children. A nodes left child must have a smaller value than the node, while a node's right child must have a larger value. A red-black tree improves upon this data structure by maintaining balance, resulting in a worst case time complexity of O(log n) for both searching and inserting, as opposed to the BST's worst case time complexity of O(n). Because of this, the red-black tree data structure is highly useful for data that is often changed or needs to be sorted, such as student score data.

### Red-Black Tree Invariants

* All nodes must be assigned a color of either red or black.
* A red node must not have a red child.
* The root and all leaf nodes are black.
* Any path from a node to all descendent leaf nodes must be the same height (i.e., contain the same number of black nodes).

### Red-Black Tree Implementation

## Running the program

This program was designed to run from a `main.cpp` file, rather than a build folder. To set up and run the program:
1. Go to program directory using `cd <path>\Final Project`.
2. Run `g++ main.cpp -o main`.
3. Run `./main.exe`.

When the program starts, 40 data points (including IDs from 1 to 40 and various scores from 0 to 100) are loaded into a new tree. Users have the option to use this tree or create a new one. After the tree has loaded, the user will view a menu, which allows them to select a function they would like to run.

When first starting the program, the user will read "What would you like to do? (Please select a number from the menu below)". The the following menu options will be presented.
<img width="336" height="367" alt="image" src="https://github.com/user-attachments/assets/6367c4b1-36b1-4615-8cb8-d1c31ba38df4" />

At this point, the user may press a number to select one of the given options. 

After the option is selected and completed, the user sees the following: "Press any key to continue..."

Then the user must press any key before seeing the menu again. 

### Option 1
