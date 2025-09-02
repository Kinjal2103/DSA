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
Node *findSuccessor(Node *root){
    while(root && root->left){
        root=root->left;
    }
    return root;
}
Node *deleteNode(Node *root,int d){
    if(!root) return root;
    if(d<root->data){
        root->left=deleteNode(root->left,d);
    }else if(d>root->data){
        root->right=deleteNode(root->right,d);
    }
    else{
        if(!root->left){
            Node* temp=root->right;
            delete root;
            return temp;
        }else if(!root->right){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        Node *temp=findSuccessor(root);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
}
Node *insert(Node *root, int d){
    if(root==NULL) return new Node(d);
    if(root->data >=d) root->left=insert(root->left,d);
    else root->right=insert(root->right,d);
    return root;
}

void inOrder(Node *root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
int main(){
    int n,i;
    cin>>n;
    Node *root=NULL;
    while(n--){
        cin>>i;
        root=insert(root,i);
    }
    cout<<"Inorder before Deletion"<<endl;
    inOrder(root);
    cout << endl;

    root=deleteNode(root,10);

    cout<<"Inorder after Deletion"<<endl;
    inOrder(root);
    cout << endl;
}