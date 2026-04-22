#include <iostream>
#include "Final_project.h"
#include "Final_project.cpp"

int main() {
    //RBT tree;
    RBT* tree = new RBT();
    tree->insert_data(1, 90);
    tree->insert_data(2, 80);
    tree->insert_data(3, 85);
    tree->insert_data(4, 95);
    tree->insert_data(5, 62);
    tree->insert_data(6, 75);
    tree->insert_data(7, 88);
    tree->insert_data(8, 92);
    tree->insert_data(9, 78);
    tree->insert_data(10, 82);
    tree->insert_data(11, 91);
    tree->insert_data(12, 31);
    tree->insert_data(13, 57);
    tree->insert_data(14, 77);
    tree->insert_data(15, 83);
    tree->insert_data(16, 87);
    tree->insert_data(17, 93);
    tree->insert_data(18, 62);
    tree->insert_data(19, 81);
    tree->insert_data(20, 79);
    tree->insert_data(21, 43);
    tree->insert_data(22, 68);
    tree->insert_data(23, 74);
    tree->insert_data(24, 89);
    tree->insert_data(25, 94);
    tree->insert_data(26, 55);
    tree->insert_data(27, 66);
    tree->insert_data(28, 72);
    tree->insert_data(29, 84);
    tree->insert_data(30, 90);
    tree->insert_data(31, 77);
    tree->insert_data(32, 85);
    tree->insert_data(33, 91);
    tree->insert_data(34, 42);
    tree->insert_data(35, 69);
    tree->insert_data(36, 29);
    tree->insert_data(37, 73);
    tree->insert_data(38, 88);
    tree->insert_data(39, 99);
    tree->insert_data(40, 65);
    tree->check_invariance(tree->get_root());
    cout << "What would you like to do? (Please select a number from the menu below)" << endl;
    cout << "1. Create a new empty tree" << endl;
    cout << "2. Insert or update a score" << endl;
    cout << "3. Remove a score by ID" << endl;
    cout << "4. Check tree invariance" << endl;
    cout << "5. Get score by ID" << endl;
    cout << "6. Get all scores" << endl;
    cout << "7. Get maximum score" << endl;
    cout << "8. Get minimum score" << endl;
    cout << "9. Get average score" << endl;
    cout << "10. Get median score" << endl;
    cout << "11. Get percentile of a score" << endl;
    cout << "12. Get top K scores" << endl;
    cout << "13. Get bottom K scores" << endl;
    cout << "14. Exit" << endl;
    int choice = 0;
    cin >> choice;
    while (choice != 14) {
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number from the menu." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(); // Discard invalid input
            cin >> choice; // Try to read input again
            continue;
        }
        if (choice > 14 | choice < 1) {
            cout << "Invalid input. Please enter a number from the menu." << endl;
            cin >> choice; // Try to read input again
            continue;
        } else {
            if (choice == 1) {
                delete tree; // Delete the existing tree
                tree = new RBT(); // Create a new tree
                cout << "New tree created. You can now insert scores." << endl;
            } else if (choice == 2) {
                cout << "Enter ID and score to insert or update: ";
                int id, score;
                cin >> id >> score;
                tree->insert_data(id, score);
                cout << "Score inserted/updated successfully." << endl;
            } else if (choice == 3) {
                cout << "Enter ID of score to remove: ";
                int id;
                cin >> id;
                tree->remove(id);
            } else if (choice == 4) {
                cout << "Checking tree invariance. If there are no messages, the tree is valid." << endl;
                tree->check_invariance(tree->get_root());
            } else if (choice == 5) {
                cout << "Enter ID to get score: ";
                int id;
                cin >> id;
                int score = tree->get_score(tree->get_root(), id);
                if (score != -1) {
                    cout << "Score of ID " << id << ": " << score << endl;
                } else {
                    cout << "ID not found." << endl;
                }
            } else if (choice == 6) {
                vector<int> scores = tree->get_all_scores(tree->get_root());
                if (scores.empty()) {
                    cout << "Tree is empty." << endl;
                } else {
                    cout << "All Scores: ";
                    for (int score : scores) {
                        cout << score << " ";
                    }
                    cout << endl;
                }
            } else if (choice == 7) {
                int max_score = tree->get_max_score(tree->get_root());
                if (max_score != -1) {
                    cout << "Maximum Score: " << max_score << endl;
                } else {
                    cout << "Tree is empty." << endl;
                }
            } else if (choice == 8) {
                int min_score = tree->get_min_score(tree->get_root());
                if (min_score != -1) {
                    cout << "Minimum Score: " << min_score << endl;
                } else {
                    cout << "Tree is empty." << endl;
                }
            } else if (choice == 9) {
                int average_score = tree->get_average_score(tree->get_root());
                if (average_score != -1) {
                    cout << "Average Score: " << average_score << endl;
                } else {
                    cout << "Tree is empty." << endl;
                }
            } else if (choice == 10) {
                int median_score = tree->get_median_score(tree->get_root());
                if (median_score != -1) {
                    cout << "Median Score: " << median_score << endl;
                } else {
                    cout << "Tree is empty." << endl;
                }
            } else if (choice == 11) {
                cout << "Enter score to get percentile: ";
                int score;
                cin >> score;
                int percentile = tree->get_percentile(tree->get_root(), score);
                if (percentile != -1) {
                    cout << "Percentile of Score " << score << ": " << percentile << "%" << endl;
                } else {
                    cout << "Tree is empty." << endl;
                }
            } else if (choice == 12) {
                cout << "Enter K to get top K scores: ";
                int k;
                cin >> k;
                vector<int> top_k = tree->get_top_k_scores(tree->get_root(), k);
                if (top_k.empty()) {
                    cout << "Tree is empty." << endl;
                } else {
                    cout << "Top " << k << " Scores: ";
                    for (int score : top_k) {
                        cout << score << " ";
                    }
                    cout << endl;
                }
            } else if (choice == 13) {
                cout << "Enter K to get bottom K scores: ";
                int k;
                cin >> k;
                vector<int> bottom_k = tree->get_bottom_k_scores(tree->get_root(), k);
                if (bottom_k.empty()) {
                    cout << "Tree is empty." << endl;
                } else {
                    cout << "Bottom " << k << " Scores: ";
                    for (int score : bottom_k) {
                        cout << score << " ";
                    }
                    cout << endl;
                }
            }
        }
        cout << "Press any key to continue..." << endl;
        cin.ignore();
        cin.get();
        cout << endl;
        cout << "What would you like to do next? (Please select a number from the menu)" << endl;
        cout << "1. Create a new empty tree" << endl;
        cout << "2. Insert or update a score" << endl;
        cout << "3. Remove a score by ID" << endl; 
        cout << "4. Check tree invariance" << endl;
        cout << "5. Get score by ID" << endl;
        cout << "6. Get all scores" << endl;
        cout << "7. Get maximum score" << endl;
        cout << "8. Get minimum score" << endl;
        cout << "9. Get average score" << endl;
        cout << "10. Get median score" << endl;
        cout << "11. Get percentile of a score" << endl;
        cout << "12. Get top K scores" << endl;
        cout << "13. Get bottom K scores" << endl;
        cout << "14. Exit" << endl;
        cin >> choice;
    }
    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}