#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool fl=false;
    bool containesKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node *get(char c){
        return links[c-'a'];
    }
    bool setEnd(){
        fl=true;
    }

    bool isEnd(){
        return fl;
    }

};
class Trie{
private: Node *root;
public :
    Trie(){
        root=new Node;
    }

    void insert(string word){
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containesKey(word[i])){
                node->put(word[i],new Node);
            }
            node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containesKey(word[i])){
                return false;
            }
            node->get(word[i]);
        }
        return node->isEnd();  
    }

    bool startswith(string word){
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containesKey(word[i])){
                return false;
            }
            node->get(word[i]);
        }
        return true;
    }
};