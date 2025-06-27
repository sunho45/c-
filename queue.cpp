#include <iostream>
using namespace std;
class node{
    public:
        node *prev;
        node *next;
        int num;
        node(int num){
            prev=next=nullptr;
            this->num=num;
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
    void enqueue(int num){
        node *newnode= new node(num);
        if(isempty()){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;


            tail=newnode;



        }



    }
    int dequeue(){
        int num=head->num;
        head=head->next;
        delete head->prev;

        return
        
        
        num;
    }
    void print(){
        node *current=head;
        while(current!=nullptr){
            cout<<current->num<<endl;
            current=current->next;
            


        }



    }

};




int main(){

queue *qu=new queue();
qu->enqueue(5);
qu->enqueue(7);
qu->enqueue(8);
qu->print();




    
}