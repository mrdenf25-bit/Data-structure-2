#include <iostream>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Duplicates are not allowed: left < node < right.
// minNode and maxNode are the ancestors that limit this node (nullptr = no limit).
bool isValidHelper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
    if (node == nullptr) {
        return true;
    }
    if (minNode != nullptr && node->val <= minNode->val) {
        return false;
    }
    if (maxNode != nullptr && node->val >= maxNode->val) {
        return false;
    }
    return isValidHelper(node->left, minNode, node) &&
           isValidHelper(node->right, node, maxNode);
}

// Time: O(n), Space: O(h) where h is the height of the tree
bool isValidBST(TreeNode* root) {
    return isValidHelper(root, nullptr, nullptr);
}

int main() {
    TreeNode a(5), b(1), c(8), d(4), e(9);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    assert(!isValidBST(&a));

    d.val = 6;
    assert(isValidBST(&a));

    assert(isValidBST(nullptr));

    TreeNode single(10);
    assert(isValidBST(&single));

    TreeNode x(5), y(5);
    x.left = &y;
    assert(!isValidBST(&x));

    cout << "All Challenge 8 tests passed." << endl;
    return 0;
}
