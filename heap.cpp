#include <iostream>
#include <queue>

using namespace std;

class node{
    public:
    node*left;
    node* right;
    int *num;
    node(int *num){
        left=nullptr;
        right=nullptr;
        this->num=num;
    
    }
};



class heap{
    public:
     node *root;
        queue <node*> q;
        heap(){

        root=nullptr;


     }
     bool isempty(){
        return root==nullptr;
        }
        void push(int *num){
            node *newnode=new node(num);
        if(isempty()){
            
            root=newnode;
            q.push(root);
        }
        else{
           node *current=q.front();
            if(q.front()->left==nullptr){
                current->left=new node(num);
                q.push(current->left);
            }
            else if(q.front()->right==nullptr){
                current->right=new node(num);
                q.push(current->right);
                q.pop();
            }

           


        
        }
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
int d=0;
hp->push(&a);
hp->push(&b);
hp->push(&c);
hp->push(&d);
hp->levelorder();








}