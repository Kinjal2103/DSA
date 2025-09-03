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

int height(Node *root){
    if(!root) return -1;
    return 1+max(height(root->left),height(root->right));
    
}
int getBalance(Node *root){
    return height(root->left)-height(root->right);
}

Node *rightRotate(Node *x){
    Node* y=x->left;
    Node *T=y->right;

    y->right=x;
    x->left=T;

    return y;
}
Node *leftRotate(Node *x){
    Node* y=x->right;
    Node *T=y->left;

    y->left=x;
    x->right=T;

    return y;
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
    cout<<endl;
}
Node *insert(Node *root, int d){
    if(root==NULL) return new Node(d);
    if(root->data >d) root->left=insert(root->left,d);
    else if(root->data <d)root->right=insert(root->right,d);
    else return root;

    int balance=getBalance(root);

    if(balance>1 && d<root->left->data) {
        return rightRotate(root);
    }
    if(balance<-1 && d>root->right->data){
        return leftRotate(root);
    }
    if(balance >1 && d>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance <-1 && d<root->left->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


int main(){
    int n,i;
    cin>>n;
    Node *root=NULL;
    while(n--){
        cin>>i;
        root=insert(root,i);
        levelOrder(root);
    }
    
}