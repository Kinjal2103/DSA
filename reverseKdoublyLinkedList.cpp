#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        data=d;
        next=nullptr;
        prev=nullptr;
    }
};

class Solution{
public:
    Node* reverseK(Node *head,int k ){
        if(head==nullptr || k<=1) return head;

        Node* curr=head;
        Node* newHead=nullptr;
        Node* prevGroup=nullptr;

        while(curr){
            Node* groupHead=curr;
            Node* prev=nullptr;
            int cnt=0;

            while(curr && cnt<k){
                Node* nxt=curr->next;
                curr->next=prev;
                curr->prev=nxt;

                prev=curr;
                curr=nxt;

                cnt++;
            }

            if(!newHead){
                newHead=prev;
            }if(prevGroup){
                prevGroup->next=prev;
                prev->prev=prevGroup;
            }
            prevGroup=groupHead;
        }
        return newHead;
    }
};