#include <iostream>

using namespace std;
class node{
    public:
        node *left;
        node *right;
        int num;
        node(int num){
            this->num=num;
        }



};

class tree{
    public:
        node *root;
        tree(){

            root=nullptr;

        }

        node* pushednode(node *root, int num){
            node *newnode=new node(num); 
            if(root==nullptr){
                return newnode;
            }
            else{
                if(root->num>root->left->num){
                    root=pushednode(root->left,num);
                }
                else{
                    root=pushednode(root->right,num);
                }

                return root;
                    

            }


        }
        void preorderset(){}
        
        void preorder(){
            preorderset();





        }





        void push(int num){


            root=pushednode(root,num);



        }







};




int main(){





}