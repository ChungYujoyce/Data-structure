#include "function.h"
#include <iostream>
#include <queue>
#include <string.h>
#include <stdlib.h>
using namespace std;

Node* Implement::constructTree(std::string treeStr) {
//  cout << treeStr << endl;
    Node *node = new Node();
    if (treeStr[0] == '(' && treeStr[1] == ')')
        return NULL;
    int sum = 0;
    int sign = 1;
    int idx = 1;
    if (treeStr[idx] == '-') {
        sign = -1;
        idx++;
    }
    while (treeStr[idx] >= '0' && treeStr[idx] <= '9')
        sum = sum * 10 + treeStr[idx++] - '0';
    node->weight = sum * sign;///!!!!!!!!!!!!
//  cout << "Constructure: " << treeStr << ' ' << node->weight << endl;
    int cnt = 0;
    for (int i = idx; i < treeStr.length() - 1; i++) {
        if (treeStr[i] == '(')
            cnt++;
        else if (treeStr[i] == ')')
            cnt--;
        if (cnt == 0) {
            string l = "";
            for (int j = idx; j <= i; j++)
                l += treeStr[j];
            node->left = constructTree(l);
            string r = "";
            for (int j = i + 1; j < treeStr.length() - 1; j++)
                r += treeStr[j];
            node->right = constructTree(r);
            break;
        }
    }
    return node;
}

void Implement::Inorder_traversal(Node *root) {
    if (!root)
        return ;
    Inorder_traversal(root->left);
    cout << root->weight << ' ';
    Inorder_traversal(root->right);
}

void Implement::Preorder_traversal(Node *root) {
    if (!root)
        return ;
    cout << root->weight << ' ';
    Preorder_traversal(root->left);
    Preorder_traversal(root->right);
}

void Implement::Postorder_traversal(Node *root) {
    if (!root)
        return ;
    Postorder_traversal(root->left);
    Postorder_traversal(root->right);
    cout << root->weight << ' ';
}

void Implement::Levelorder_traversal(Node *root) {
    if (!root)
        return ;
    queue<Node *> q;
    q.push(root);
    while (q.size()) {
        Node *u = q.front();
        q.pop();
        cout << u->weight << ' ';
        if (u->left)
            q.push(u->left);
        if (u->right)
            q.push(u->right);
    }
}

Node* Implement::deleteTree(Node *root) {
    if (!root)
        return NULL;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    return root;
}

int Implement::TreeHeight(Node *root) {
    if (!root)
        return 0;
    int height = 0;
    height = max(height, TreeHeight(root->left));
    height = max(height, TreeHeight(root->right));
    return height + 1;
}

int Implement::TreeWeightSum(Node *root) {
    if (!root)
        return 0;
    int sum = 0;
    sum += TreeWeightSum(root->left);
    sum += TreeWeightSum(root->right);
    return sum + root->weight;
}

int Implement::MaximumPathSum(Node *root) {
    if (!root)
        return 0;
    int sum = -0x3f3f3f3f;
    sum = max(sum, MaximumPathSum(root->left));
    sum = max(sum, MaximumPathSum(root->right));
    return sum + root->weight;
}

Node* Implement::Invert(Node *root) {
    if (!root)
        return NULL;
    if (root->left)
        root->left = Invert(root->left);
    if (root->right)
        root->right = Invert(root->right);
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}
