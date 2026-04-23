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

I found it somewhat difficult to implement an entire data structure from scratch, without a previously created header file to use as a template. I wasn't full sure how to set up everything needed for the header file, and initially forgot to include the `#endif` code, which led to the code not running. Eventually though, I realized I could use the BST structure header file from this course as an initial guide, and update the file as needed to create the RBT class. 

I also ran into some issues making sure that the invariance was not violated and was fixed correctly after each insertion or deletion. To help resolve this issue, I included two functions: `void check_invariance(rbt_node* node);` and `void pre_order_traversal(rbt_node* node);`. The first function checked to see whether invariance was violated and printed a message for each violation, which included where the violation occurred and what was violated. The second printed out each node's ID, score, color, level, parent, and children. I used both these codes to check "under the hood" and help me visualize the data structure, so that I could see where violations were happening and revise them where needed.

## Running the program

This program was designed to run from a `main.cpp` file, rather than a build folder. To set up and run the program:
1. Go to program directory using `cd <path>\Final Project`.
2. Run `g++ main.cpp -o main`.
3. Run `./main.exe`.

When the program starts, 40 data points (including IDs from 1 to 40 and various scores from 0 to 100) are loaded into a new tree. Users have the option to use this tree as demo or create a new one. After the tree has loaded, the user will view a menu, which allows them to select a function they would like to run.

When first starting the program, the user will read `What would you like to do? (Please select a number from the menu below)`. The the following menu options will be presented.

```
1. Create a new empty tree
2. Insert or update a score
3. Remove a score by ID
4. Check tree invariance
5. Get score by ID
6. Get all scores
7. Get maximum score
8. Get minimum score
9. Get average score
10. Get median score
11. Get percentile of a score
12. Get top K scores
13. Get bottom K scores
14. Exit
```

At this point, the user may press a number to select one of the given options. 

After the option is selected and completed, the user sees the following: `Press any key to continue...`

Then the user must press any key before seeing the menu again. 


## Node Class
The node class contains the following structure:

```
struct rbt_node {
    int score;
    int id;
    bool color; // 0 for red, 1 for black
    int level; // Level of the node in the tree
    rbt_node *left, *right, *parent;
};
```

## RBT Class (Red-Black Tree)

The red-black tree class contains the following major functions:

1. `rbt_node* initialize_node(int id, int score);` initializes a new node given an student's ID and score
2. `void insert_data(int id, int score);` inserts a new node with student's ID and score into the tree and fixes invariance
3. `void remove(int id);` removes a node from the tree using the student's ID, and fixes invariance
4. `void fix_tree(rbt_node* node);` fixes invariance in the tree
5. `int get_score(rbt_node* node, int id);` gets a student's score given their ID
6. `vector<int> get_all_scores(rbt_node* node);` prints all student scores using in-order traversal, resulting sorted scores in ascending order
7. `int get_max_score(rbt_node* node);` gets the maximum score from the tree
8. `int get_min_score(rbt_node* node);` gets the minimum score from the tree
9. `int get_average_score(rbt_node* node);` gets the average of all scores in the tree
10. `int get_median_score(rbt_node* node);` gets the median of all scores in the tree
11. `int get_percentile(rbt_node* node, int score);` gets the percentile of a given score
12. `vector<int> get_top_k_scores(rbt_node* node, int k);` gets the highest k scores in the tree
13. `vector<int> get_bottom_k_scores(rbt_node* node, int k);` gets the lowest k scores in the tree



