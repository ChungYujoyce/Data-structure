#include <iostream>
#include "function.h"
#include <bits/stdc++.h>
using namespace std;

Node* Implement::constructTree(std::string treeStr){
    Node* node=new Node();
    if(treeStr[0]=='('&&treeStr[1]==')') return NULL;
    int cnt=0,sign=1,sum=0,idx=1;
    if(treeStr[idx]=='-'){
        sign=-1;
        idx++;
    }
    while(treeStr[idx]>='0'&&treeStr[idx]<='9'){
        sum = sum*10 + treeStr[idx]-'0';
        idx++;
    }
    node->weight=sum*sign;
    for(int i=idx;i<treeStr.length()-1;i++){
        if(treeStr[i]=='(') cnt++;
        else if(treeStr[i]==')') cnt--;
        if(cnt==0){
            string l="";
            for(int j=idx;j<=i;j++)
                l+=treeStr[j];
            node->left=constructTree(l);
            string r="";
            for(int j=i+1;j<treeStr.length()-1;j++)
                r+=treeStr[j];
            node->right=constructTree(r);
            break;
        }
    }
    return node;
}
void Implement::Inorder_traversal(Node *root){
    if(!root) return;
    Inorder_traversal(root->left);
    cout << root->weight << ' ';
    Inorder_traversal(root->right);
}
void Implement::Preorder_traversal(Node *root){
    if(!root) return;
    cout << root->weight << ' ';
    Preorder_traversal(root->left);
    Preorder_traversal(root->right);
}
void Implement::Postorder_traversal(Node *root){
    if(!root) return;
    Postorder_traversal(root->left);
    Postorder_traversal(root->right);
    cout << root->weight << ' ';
}
void Implement::Levelorder_traversal(Node *root){ /// use queue
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(q.size()){
        Node* cur=q.front();
        q.pop();
        cout << cur->weight <<' ';
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
}
Node* Implement::deleteTree(Node *root){
    if(!root) return NULL;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    return root;
}
int Implement::TreeHeight( Node *root){
    if(!root) return 0;
	int leftH=0,rightH=0;
    leftH= TreeHeight(root->left);
    rightH= TreeHeight(root->right);
    return max(leftH,rightH)+1;
}
int Implement::TreeWeightSum( Node *root){
    if(!root) return 0;
    int leftSum=0;
    int rightSum=0;
    leftSum += TreeWeightSum(root->left);
    rightSum += TreeWeightSum(root->right);
    return leftSum+rightSum+root->weight;/// don't forget root weight
}

int Implement::MaximumPathSum(Node *root){
    if(!root) return 0;
    int sum=0;
    sum = max(sum,MaximumPathSum(root->left)); ///can't write +=
    sum = max(sum,MaximumPathSum(root->right));
    return sum+root->weight;
}
Node* Implement::Invert(Node *root){
    if(!root) return NULL;
    if(root->left)
        root->left=Invert(root->left);
    if(root->right)
        root->right=Invert(root->right);
    Node *temp=root->left;
    root->left=root->right;
    root->right=temp;
    return root;
}
