#include <iostream>
#include <queue>

using namespace std;

class node{
    public:
    node*left;
    node* right;
    node* parent;
    int *num;
    node(int *num){
        left=nullptr;
        right=nullptr;
        parent=nullptr;
        this->num=num;
    
    }
};



class heap{       /* maxheap*/
    public:
     node *root;
        queue <node*> q;
        heap(){

        root=nullptr;


     }
     bool isempty(){
        return root==nullptr;
        }
        void pushmax(int *num){
            node *newnode=new node(num);
        if(isempty()){
            
            root=newnode;
            q.push(root);
        }
        else{
           node *current=q.front();
            if(q.front()->left==nullptr){
                current->left=newnode;
                newnode->parent=current;
                q.push(current->left);
                heapup(current->left);
            }
            else if(q.front()->right==nullptr){
                current->right=newnode;
                q.push(current->right);
                newnode->parent=current;
                heapup(current->right);
                q.pop();

            }

           


        
        }
        }


         void pushmin(int *num){
            node *newnode=new node(num);
        if(isempty()){
            
            root=newnode;
            q.push(root);
        }
        else{
           node *current=q.front();
            if(q.front()->left==nullptr){
                current->left=newnode;
                newnode->parent=current;
                q.push(current->left);
                heapupmin(current->left);
            }
            else if(q.front()->right==nullptr){
                current->right=newnode;
                q.push(current->right);
                newnode->parent=current;
                heapupmin(current->right);
                q.pop();

            }

           


        
        }
        }
        void heapup(node *childrennode){
            node* current =childrennode;
            
            
            while(current->parent!=nullptr&&*(current->num)>*(current->parent->num)){
                swap(current->num,current->parent->num);
                current=current->parent;

            }


        }

         void heapupmin(node *childrennode){
            node* current =childrennode;
            
            
            while(current->parent!=nullptr&&*(current->num)<*(current->parent->num)){
                swap(current->num,current->parent->num);
                current=current->parent;

            }


        }
        void swap(int *a, int *b){

            int temp=*a;
            *a=*b;
            *b=temp;


        }




        void levelorder(){
            queue <node*> t;
            if(isempty()){
                cerr<<"error"<<endl;
            }
            else{
                t.push(root);
                while(!t.empty()){
                    if(t.front()->left!=nullptr){
                        t.push(t.front()->left);
                    }
                     if(t.front()->right!=nullptr){
                        t.push(t.front()->right);
                    }
                    
                    
                   cout<<*(t.front()->num)<<endl;
                   t.pop();

                }


            }







        }




    

};






int main(){

heap *hp=new heap();
int a=10;
int b=40;
int c=20;
int d=50;
hp->pushmin(&a);
hp->pushmin(&b);
hp->pushmin(&c);
hp->pushmin(&d);
hp->levelorder();








}