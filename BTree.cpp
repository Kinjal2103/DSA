#include<bits/stdc++.h>
using namespace std;

class Btree{
public:
    vector<int> keys;
    vector<Btree*> child;
    bool isleaf;
    int m;
    Btree (int order ,bool leaf){
        m=order;
        isleaf=leaf;
    }
};
void splitchild(Btree *parent ,int i){
    Btree *fullChild=parent->child[i];
    int mid=fullChild->keys.size()/2;

    Btree *newChild=new Btree(fullChild->m,fullChild->isleaf);
    newChild->keys.assign(fullChild->keys.begin()+mid+1,fullChild->keys.end());
    fullChild->keys.resize(mid);

    if(!fullChild->isleaf){
        newChild->child.assign(fullChild->child.begin()+mid+1,fullChild->child.end());
        fullChild->child.resize(mid+1);
    }
    parent->keys.insert(parent->keys.begin() + i, fullChild->keys[mid]);
    parent->child.insert(parent->child.begin() + i + 1, newChild);
}
void insertNonFull(Btree *node,int key){
    int i=node->keys.size()-1;
    if(node->isleaf){
        node->keys.push_back(0);
        while(i>=0 && key<node->keys[i]){
            node->keys[i+1]=node->keys[i];
            i--;
        }
        node->keys[i+1]=key;
    }
    else{
        while (i >= 0 && key < node->keys[i]) i--;
        i++;
        if(node->child[i]->keys.size()==node->m-1){
            splitchild(node,i);
            if(key>node->keys[i]) i++;
        }
        insertNonFull(node->child[i],key);
    }
}
Btree * insertNode(Btree * root,int key,int m){
    if(!root) return new Btree(m,true);

    if(root->keys.size()==m-1){
        Btree* newRoot = new Btree(m, false);
        newRoot->child.push_back(root);
        splitchild(newRoot, 0);
        insertNonFull(newRoot, key);
        return newRoot;
    }
    else{
        insertNonFull(root,key);
        return root;
    }
}

void traverse(Btree* node) {
    if (!node) return;
    for (int i = 0; i < node->keys.size(); i++) {
        if (!node->isleaf) traverse(node->child[i]);
        cout << node->keys[i] << " ";
    }
    if (!node->isleaf) traverse(node->child[node->keys.size()]);
}

int main(){
    int m = 3; 
    Btree* root = nullptr;

    vector<int> vals = {10, 20, 5, 6, 12, 30, 7, 17};
    for (int x : vals) root = insertNode(root, x, m);

    traverse(root);
}