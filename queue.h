


#pragma once

class node{

node *prev;
        node *next;
        int num;
        node(int num){}
        


};
class treenode{
    public:
        node *prev;
        node *next;
        treenode *nodes;
        treenode(){
           
        }
};

class queue{
    public:   
    node *head,*tail;
    queue(){
    } 
    bool isempty(){
    }  
    void enqueue(treenode *trnode){
        } 
    treenode dequeue(){
       
    }
    
};
