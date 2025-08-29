#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
Node *insert(Node *root, int d){
    if(root==NULL) return new Node(d);
    if(root->data >=d) root->left=insert(root->left,d);
    else root->right=insert(root->right,d);
    return root;
}
void levelOrder(Node *root){
    queue<Node *> q;
    q.push(root);
    Node *curr=NULL;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
Node *findNode(Node * root,int t){
    if(root->data == t) return root;
    else if(root->data > t) return findNode(root->left,t);
    else return findNode(root->right,t);
    return NULL;
}
int height(Node *root){
    if(root==NULL) return -1;
    return 1+ max(height(root->left),height(root->right));
}

int main(){
    int n,i;
    cin>>n;
    Node *root=NULL;
    while(n--){
        cin>>i;
        root=insert(root,i);
    }
    levelOrder(root);
    int m;
    cin>>m;
    Node *node=NULL;
    int h;
    while(m--){
        cin>>i;
        node=findNode(root,i);
        h=height(node);
        cout<<h<<endl;
    }
}