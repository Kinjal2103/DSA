#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int d;
    Node *left;
    Node *right;
    Node (int data){
        d=data;
        left=NULL;
        right=NULL;
    }
};

void levelOrder(Node *root){
    queue<Node *> q;
    q.push(root);
    Node *curr=NULL;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        cout<<curr->d<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout<<endl;
}
Node* leftRotate(Node *x){
    Node *y=x->right;
    Node *T=y->left;

    y->left=x;
    x->right=T;

    return y;

}
Node *rightRotate(Node *x){
    Node *y=x->left;
    Node *T=y->right;

    y->right=x;
    x->left=T;

    return y;
}
int height(Node *root){
    if(!root) return -1;
    return 1+max(height(root->left),height(root->right));
}
int getBalance(Node *root){
    return height(root->left)-height(root->right);
}
Node *findMin(Node *root){
    while( root && root->left){
        root=root->left;
    }
    return root;
}
Node *insert(Node *root,int d){
    if(!root) return new Node(d);
    if(root->d>d) root->left=insert(root->left,d);
    else if(root->d<d) root->right=insert(root->right,d);
    else return root;

    int balance=getBalance(root);

    if(balance>1 && d<root->left->d ){
        return rightRotate(root);
    }
    if(balance<-1 && d>root->right->d){
        return leftRotate(root);
    }
    if(balance>1 && d>root->left->d){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance <-1 && d<root->right->d){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
Node *deleteNode(Node *root,int d){
    if(!root) return root;
    if(d<root->d) root->left=deleteNode(root->left,d);
    else if(d>root->d) root->right =deleteNode(root->right,d);
    else{
        if(!root->left){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            Node * temp=root->left;
            delete root;
            return temp;
        }
        Node *temp=findMin(root->right);
        root->d=temp->d;
        root->right=deleteNode(root->right,temp->d);
    }
    if(!root) return root;
    int balance =getBalance(root);

    if(balance>1){
        int childBalance=getBalance(root->left);
        if (childBalance == 0) // R0
            return rightRotate(root);

        if (childBalance == 1) // R1
            return rightRotate(root);

        if (childBalance == -1) { // R–1
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balance < -1) {
        int childBalance = getBalance(root->right);

        if (childBalance == 0) // R0 mirror
            return leftRotate(root);

        if (childBalance == -1) // R1 mirror
            return leftRotate(root);

        if (childBalance == 1) { // R–1 mirror
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}
int main(){
    int n,i;
    //cin>>n;
    Node *root=NULL;
    vector<int> values= {37,26,41,18,28,39,16};
    for (int v : values)
    root = insert(root, v);

    levelOrder(root);

    root=deleteNode(root,39);
    levelOrder(root);
}