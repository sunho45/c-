#include <iostream>
using namespace std;
class node{
    public :
    int data;
    node* next;
    node* prev;
    node(int *val){

        data = *val;
        next = NULL;
        prev = NULL;
    }

};

class Linkedlist{

    public:
    node *head;
    node *tail;
    Linkedlist(){
        head=NULL;
        tail=NULL;
    }
    bool isempty(){
        return head==NULL&&tail==NULL;
    }
    void insert(int *val, int pos){
        if(isempty()){
            node *newnode=new node(val);
            head=tail=newnode;
        }
       else{
          node *newnode=new node(val); 
          node *current=head; 
          int i=0;
          while(i<pos&&current!=nullptr){
              current=current->next; /* 삽입시킬 위치로 이동*/
              i++;
          }
          
          if(current==nullptr){
             tail->next=newnode;
             newnode->prev=tail;
              
              tail=newnode;
          }
          
        
           else if(current->prev==nullptr){
            
              
              
               newnode->next=current;
              current->prev=newnode;
              head=newnode;
          }
          
          
          
          
          
          
          else{
              
               current->prev->next=newnode;
              newnode->prev=current->prev;
              newnode->next=current;
              current->prev=newnode;
              
              
          }   
           
           
       }






    }
    void print(){
        node *current=head;
        while(current!=nullptr){
            cout<<current->data<<endl;
            current=current->next;


        }

    }



};

int main(){


Linkedlist *Li=new Linkedlist();

int arr[5];

arr[0]=0;
arr[1]=5;
arr[2]=9;
arr[3]=14;
arr[4]=23;


    
    Li->insert(arr,0);
    Li->insert(arr+1,1);
     Li->insert(arr+2,0);
     Li->insert(arr+3,2);
 

    Li->print();




}