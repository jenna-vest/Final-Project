
#include "Final_project.h"

RBT::RBT() {
    root = new rbt_node*;
    *root = nullptr;
}

RBT::~RBT() {}

rbt_node* RBT::initialize_node(int id, int score) {
    rbt_node* new_node = new rbt_node;
    new_node->id = id;
    new_node->score = score;
    new_node->color = 0; // New nodes are red by default
    new_node->level = 0; // Level will be set during insertion
    new_node->left = nullptr;
    new_node->right = nullptr;
    new_node->parent = nullptr;
    return new_node;
}

void RBT::insert(rbt_node* new_node) {
    // Insertion logic for Red-Black Tree
    if (*root == nullptr) {
        *root = new_node;
        new_node->color = 1; // Root is always black
        return;
    } else {
        rbt_node* parent = nullptr;
        rbt_node* current = *root;

        int level = 0; // Start at level 0 for the root
        while (current != nullptr) {
            parent = current;
            level = level + 1; // Use level to track the depth of the current node
            if (new_node->score < current->score) {
                current = current->left;
            } else  if (new_node->score > current->score) {
                current = current->right;
            } else {
                if (new_node->id < current->id) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
        }

        new_node->parent = parent;
        new_node->level = level; // Set the level of the new node

        if (new_node->score < parent->score) {
            parent->left = new_node;
        } else if (new_node->score > parent->score) {
            parent->right = new_node;
        } else {
            if (new_node->id < parent->id) {
                parent->left = new_node;
            } else {
                parent->right = new_node;
            }
        }
        if (parent->color == 0) new_node->color = 1; // If parent is red, new node should be black

    } return;
}

void RBT::insert_data(int id, int score) {
    rbt_node* new_node = initialize_node(id, score);
    insert(new_node);
    return;
}

void RBT::fix_tree(rbt_node* node) {
    if (node==*root) {
        node->color = 1; // Ensure the root is always black
        node->level = 0; // Root is at level 0
    } else if (node == nullptr) {
        return; // Base case: if node is null, return
    } else {
        rbt_node* parent = node->parent;
        int level = parent->level + 1; // Set the level of the new node based on its parent
        node->level = level; // Assign the calculated level to the new node
        if (level % 2 == 0) {
            node->color = 1; // Recolor the node to black
        } else {
            node->color = 0; // Recolor the node to red
        }
    }
    fix_tree(node->left); // Recursively fix the tree up to the root
    fix_tree(node->right);
}

void RBT::remove(int id) {
    // Removal logic for Red-Black Tree
    rbt_node* node = get_node(get_root(), id);
    if (node == nullptr) {
        cout << "ID not found." << endl;
        return; // Node with the given ID does not exist
    }
    if (node != nullptr) {
        rbt_node* parent = node->parent;
        if (node->left == nullptr && node->right == nullptr) {
            if (parent == nullptr) {
                *root = nullptr; // Tree becomes empty
            } else if (parent->left == node) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        } else if (node->left == nullptr) {
            if (parent == nullptr){
                //node is root
                *root=node->right;
            } else if (parent->left==node){
                parent->left=node->right;
                parent->left->parent = parent; // Update parent pointer of the child
            } else {
                parent->right = node->right;
                parent->right->parent = parent; // Update parent pointer of the child
            }
            return;
        } else if (node->right == nullptr) {
            if (parent == nullptr){
                //node is root
                *root=node->left;
            } else if (parent->left==node){
                parent->left=node->left;
                parent->left->parent = parent; // Update parent pointer of the child
            } else {
                parent->right = node->left;
                parent->right->parent = parent; // Update parent pointer of the child
            }
            return; 
        } else {
            rbt_node* child =  node->right;
            if (parent == nullptr) {
                *root = child; // Child becomes new root
                child->color = 1; // Ensure new root is black
            } else if (parent->left == node) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            child->parent = parent;
             // Update parent pointer of the child
        }
        fix_tree(get_root()); // Fix the tree after removal
        cout << "Node with ID " << id << " removed." << endl;
        return;
    }
}

void RBT::check_invariance(rbt_node* node) {
    if (node == nullptr) return;
    if (node->color == 0) { // If the node is red
        if ((node->left != nullptr && node->left->color == 0) || (node->right != nullptr && node->right->color == 0)) {
            cout << "Red-Black Tree invariant violated at node ID: " << node->id << endl;
        }
    } else if (node->color == 1) { // If the node is black
        if ((node->left != nullptr && node->left->color == 1) || (node->right != nullptr && node->right->color == 1)) {
            cout << "Red-Black Tree invariant violated at node ID: " << node->id << endl;
        }
    }
    if (node->left != nullptr && node->left->score >= node->score) {
        if (node->left->score == node->score && node->left->id >= node->id) {
            cout << "Red-Black Tree invariant violated: left child of node ID " << node->id << " has the same score but greater or equal ID." << endl;
        } else if (node->left->score > node->score) {
            cout << "Red-Black Tree invariant violated: left child of node ID " << node->id << " is less than parent." << endl;
        }
    } else if (node->right != nullptr && node->right->score <= node->score) {
        if (node->right->score == node->score && node->right->id <= node->id) {
            cout << "Red-Black Tree invariant violated: right child of node ID " << node->id << " has the same score but less or equal ID." << endl;
        } else if (node->right->score < node->score) {        
            cout << "Red-Black Tree invariant violated: right child of node ID " << node->id << " is less than parent." << endl;
        }
    }
    //int level = node->level -1;
    //if (level != node->parent->level){
    //    cout << "Red-Black Tree invariant violated:  node ID " << node->id << " is at the wrong level." << endl;
//
    //}
    check_invariance(node->left);
    check_invariance(node->right);
}

bool RBT::contains_id(rbt_node* node, int id) {
    if (node == nullptr) {
        return false;
    }
    if (node->id == id) {
        return true;
    }
    return contains_id(node->left, id) || contains_id(node->right, id);
}

rbt_node* RBT::get_node(rbt_node* node, int id) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->id == id) {
        return node;
    }
    rbt_node* left_result = get_node(node->left, id);
    if (left_result != nullptr) {
        return left_result;
    }
    return get_node(node->right, id);
}

void RBT::pre_order_traversal(rbt_node* node) {
    if (node == nullptr) return;
    cout << "ID: " << node->id << ", Score: " << node->score << ", Color: " << node->color << ", Level: " << node->level << ", Parent: " << (node->parent ? to_string(node->parent->id) : "nullptr") << ", Left: " << (node->left ? to_string(node->left->id) : "nullptr") << ", Right: " << (node->right ? to_string(node->right->id) : "nullptr") << endl;
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}

int RBT::size(rbt_node* node) {
    if (node == nullptr) return 0;
    return 1 + size(node->left) + size(node->right);
}

void RBT::to_vector(rbt_node* node, vector<int>& vec) {
    if (node == nullptr) return;
    to_vector(node->left, vec);
    vec.push_back(node->score);
    to_vector(node->right, vec);
}

rbt_node* RBT::get_root() {
    return *root;
}

void RBT::set_root(rbt_node** node) {
    root = node;
}

int RBT::get_score(rbt_node* node, int id) {
    if (node == nullptr) {
        return -1; // Return -1 if not found
    }
    if (node->id == id) {
        return node->score;
    }
    int left_result = get_score(node->left, id);
    if (left_result != -1) {
        return left_result;
    }
    return get_score(node->right, id);
}

vector<int> RBT::get_all_scores(rbt_node* node) {
    vector<int> scores;
    if (node == nullptr) return scores; // Return empty vector if tree is empty
    scores.push_back(node->score);
    vector<int> left_scores = get_all_scores(node->left);
    vector<int> right_scores = get_all_scores(node->right);
    scores.insert(scores.end(), left_scores.begin(), left_scores.end());
    scores.insert(scores.end(), right_scores.begin(), right_scores.end());
    sort(scores.begin(), scores.end());
    return scores;
}

int RBT::get_max_score(rbt_node* node) {
    if (node == nullptr) return -1; // Return -1 if tree is empty
    vector<int> scores = get_all_scores(node);
    return scores.back(); // Return the last element which is the maximum score
}

int RBT::get_min_score(rbt_node* node) {
    if (node == nullptr) return -1; // Return -1 if tree is empty
    vector<int> scores = get_all_scores(node);
    return scores.front(); // Return the first element which is the minimum score
}

int RBT::get_average_score(rbt_node* node) {
    if (node == nullptr) return -1; // Return -1 if tree is empty
    vector<int> scores = get_all_scores(node);
    int total_score = node->score;
    int count = 1;
    for (int s : scores) {
        total_score += s;
        count++;
    }
    return total_score / count; // Return average score
}

int RBT::get_median_score(rbt_node* node) {
    if (node == nullptr) return -1; // Return -1 if tree is empty
    vector<int> scores = get_all_scores(node);
    int n = scores.size();
    if (n % 2 == 0) {
        return (scores[n / 2 - 1] + scores[n / 2]) / 2; // Average of two middle values
    } else {
        return scores[n / 2]; // Middle value
    }
}

int RBT::get_percentile(rbt_node* node, int score) {
    if (node == nullptr) return -1; // Return -1 if tree is empty
    vector<int> scores = get_all_scores(node);
    int count = 0;
    for (int s : scores) {
        if (s < score) {
            count++;
        } else {
            break;
        }
    }
    return (count * 100) / scores.size(); // Return percentile rank
}

vector<int> RBT::get_top_k_scores(rbt_node* node, int k) {
    vector<int> top_k;
    if (node == nullptr) return top_k; // Return empty vector if tree is empty
    vector<int> scores = get_all_scores(node);
    sort(scores.begin(), scores.end(), greater<int>()); // Sort in descending order
    int count = 0;
    for (int s : scores) {
        if (count >= k) break;
        top_k.push_back(s);
        count++;
    }
    return top_k;
}

vector<int> RBT::get_bottom_k_scores(rbt_node* node, int k) {
    vector<int> bottom_k;
    if (node == nullptr) return bottom_k; // Return empty vector if tree is empty
    vector<int> scores = get_all_scores(node);
    int count = 0;
    for (int s : scores) {
        if (count >= k) break;
        bottom_k.push_back(s);
        count++;
    }
    return bottom_k;
}
