#include<bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char c,int f,Node *l=NULL,Node *r=NULL){
        ch=c;
        freq=f;
        left=l;
        right=r;
    }
};

void printCodes(Node *root,string code){
    if(!root) return;
    if(!root->left && !root->right){
        cout<<root->ch<<":"<<code<<endl;
    }
    printCodes(root->left,code+"0");
    printCodes(root->right,code+"1");
}
int main(){
    vector<char> chars={'a','b','c','d','e'};
    vector<int>freq ={5,9,12,13,16};
    int n=5;
    auto cmp = [](Node* a, Node* b){ return a->freq > b->freq; };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);

    for(int i=0;i<n;i++){
        pq.push(new Node(chars[i],freq[i]));
    }

    while(pq.size()>1){
        Node *a=pq.top();
        pq.pop();
        Node *b=pq.top();
        pq.pop();

        Node *parent=new Node('*',a->freq+b->freq,a,b);
        pq.push(parent);
    }
    Node *root=pq.top();
    printCodes(root,"");
}