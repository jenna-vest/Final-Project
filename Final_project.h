#ifndef RBT_H__
#define RBT_H__

#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <ranges>

using namespace std;

struct rbt_node {
    int score;
    int id;
    bool color; // 0 for red, 1 for black
    int level; // Level of the node in the tree
    rbt_node *left, *right, *parent;
};

class RBT {
public:
    RBT();

    ~RBT(); 
    
    rbt_node* initialize_node(int id, int score);

    void insert(rbt_node* new_node);

    void insert_data(int id, int score);

    void rotate_left(rbt_node* node);

    void rotate_right(rbt_node* node);

    void fix_tree(rbt_node* node);

    void remove(int id);

    void check_invariance(rbt_node* node);

    bool contains_id(rbt_node* node, int id);

    rbt_node* get_node(rbt_node* node, int id);

    void pre_order_traversal(rbt_node* node);

    int size(rbt_node* node);

    void to_vector(rbt_node* node, vector<int>& vec);

    rbt_node* get_root();

    void set_root(rbt_node** node);

    int get_score(rbt_node* node, int id);

    vector<int> inorder(rbt_node* node, vector<int>& scores)

    vector<int> get_all_scores(rbt_node* node);

    int get_max_score(rbt_node* node);

    int get_min_score(rbt_node* node);

    int get_average_score(rbt_node* node);

    int get_median_score(rbt_node* node);

    int get_percentile(rbt_node* node, int score);

    vector<int> get_top_k_scores(rbt_node* node, int k);

    vector<int> get_bottom_k_scores(rbt_node* node, int k);

private:
    rbt_node** root;
};

#endif // RBT_H__
