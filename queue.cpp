#include <iostream>
#include "queue.h"
using namespace std;
class node{
    public:
        node *prev;
        node *next;
        treenode *nodes;
        node(treenode *trnode){
            prev=next=nullptr;
            nodes=trnode;
        }
};

class queue{
    public:   
    node *head,*tail;
    queue(){
        head=tail=nullptr;

    } 
    bool isempty(){
        return head==nullptr&&tail==nullptr;

    }  
    void enqueue(treenode *trnode){
        node *newnode= new node(trnode);
        if(isempty()){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;


            tail=newnode;



        }



    }
    treenode dequeue(){
        treenode treenodes=*(head->nodes);
        head=head->next;
        delete head->prev;

        return treenodes;
    }
    

};




int main(){

queue *qu=new queue();




    
}