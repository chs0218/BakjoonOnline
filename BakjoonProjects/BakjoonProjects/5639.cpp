#include <iostream>
using namespace std;
struct Node {
    int value = 0;
    Node* left = NULL;
    Node* right = NULL;

    void insert(int v) {
        if (v < value) {
            if (left != NULL) left->insert(v);
            else {
                left = new Node;
                left->value = v;
            }
        }
        else {
            if (right != NULL) right->insert(v);
            else {
                right = new Node;
                right->value = v;
            }
        }
    }

    void del() {
        if (left != NULL) {
            left->del();
            delete left;
        }
        if (right != NULL) {
            right->del();
            delete right;
        }
    }

    void print() {
        if (left != NULL) {
            left->print();
        }
        if (right != NULL) {
            right->print();
        }
        cout << value << "\n";
    }
};
int main()
{
    int n = 0;
    cin >> n;

    Node* root = new Node;
    root->value = n;

    while (cin >> n) root->insert(n);

    root->print();
    root->del();
}