#include<bits/stdc++.h>
using namespace std;



class Mway{
public:
    vector<int> keys;
    vector<Mway *> child;
    int m;
    bool isleaf;
    Mway(  int order,bool leaf=true){
        m=order;
        isleaf=leaf;
        keys.reserve(m-1);
        child.assign(m,nullptr);
    }
};




void insertNode(Mway *&root,int key,int m){
    if(!root) {
        root=new Mway(m,true);
        root->keys.push_back(key);
        return;
    }
    int i=0;
    while(i<root->keys.size() && key>root->keys[i]) i++;
    if(root->isleaf){
        if(root->keys.size()<m-1){
            root->keys.insert(root->keys.begin()+i,key);
        }
        else{
            if(!root->child[i]) {
                root->child[i]=new Mway(m,true);
                root->isleaf=false;
            }
            insertNode(root->child[i],key,m);
        }
    }
    else{
        if(!root->child[i]) {
            root->child[i]=new Mway(m,true);
            root->isleaf=false;
        }
        insertNode(root->child[i],key,m);
    }
}





void search(Mway *root,int key){
    if(!root){
        cout<<"Not found"<<endl;
        return;
    }
    int i=0;
    while(i<root->keys.size() && key>root->keys[i]) i++;
    if(i<root->keys.size() && key==root->keys[i]){
        cout<<"Found"<<endl;
        return;
    }
    if(root->isleaf){
        cout<<"Not found"<<endl;
        return;
    }
    return search(root->child[i],key);
}


bool isLeaf(Mway* node) {
    for (auto c : node->child) if (c) return false;
    return true;
}




void deleteNode(Mway *&root,int key){
    if(!root) return;
    int i=0;
    while(i<root->keys.size() && key>root->keys[i]) i++;
    if(i<root->keys.size() && key==root->keys[i]){
        if(isLeaf(root)){
            root->keys.erase(root->keys.begin()+i);
            return;
        }else{
            if (root->child[i] && !root->child[i]->keys.empty()) {
                int pred = root->child[i]->keys.back();       
                root->keys[i] = pred;
                deleteNode(root->child[i], pred);
                return;
            }
            else if (root->child[i+1] && !root->child[i+1]->keys.empty()) {
                int succ = root->child[i+1]->keys.front();   
                root->keys[i] = succ;
                deleteNode(root->child[i+1], succ);
                return;
            }
            else {
            
                root->keys.erase(root->keys.begin()+i);
                return;
            }
        }
    }
    if(root->isleaf){
        return;
    }
    deleteNode(root->child[i],key);
    return;
}




void levelTraversal(Mway *root){
    queue<Mway*>q;
    q.push(root);

    while(!q.empty()){
        Mway *curr=q.front();
        q.pop();

        for(int key:curr->keys){
            cout<<key<<" ";
        }
        for(Mway *node: curr->child){
            if(node) q.push(node);
        }
    }
    cout<<endl;
}




int main(){
    Mway *root=nullptr;

    vector<int> a={5,8,9,3,6,4,0,7,1,11,12,13,14,15};
    for(int v:a){
        insertNode(root,v,5);
    }
    levelTraversal(root);
    // int x;
    // cin>>x;
    // search(root,x);

    deleteNode(root,9);
    cout<<"Deleted"<<endl;
    levelTraversal(root);

}