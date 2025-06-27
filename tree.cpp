#include <iostream>
#include "queue.h"
using namespace std;
class treenode{
    public:
        treenode *left;
        treenode *right;
        int num;
        treenode(int num){
            this->num=num;
        }



};

class tree{
    public:
        treenode *root;
        tree(){

            root=nullptr;

        }

        treenode* pushednode(treenode *root, int num){
            treenode *newnode=new treenode(num); 
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
        void preorderset(treenode *root){
            cout<<root->num<<endl;
            preorderset(root->left);
            preorderset(root->right);
        }   

        void preorder(){
            preorderset(root);





        }
         void inorderset(treenode *root){
           
            inorderset(root->left);
            cout<<root->num<<endl;
            inorderset(root->right);
        }   

        void inorder(){
            inorderset(root);





        }
         void postorderset(treenode *root){
            
            postorderset(root->left);
            postorderset(root->right);
            cout<<root->num<<endl;
        }   

        void postorder(){
            postorderset(root);





        }

        void levelset(){
            queue *qu=new queue();
            treenode* current=root;
            qu->enqueue(current);
            while(!qu->isempty()){
                treenode deletenode=(qu->dequeue());
                cout<<deletenode.num<<endl;
                if(deletenode.left!=nullptr){
                    qu->enqueue(deletenode.left);
                }
           
               if(deletenode.right!=nullptr){
                    qu->enqueue(deletenode.left);
                }
           
           
           
           
           
            }
           
           
            








            
        }






        void push(int num){


            root=pushednode(root,num);



        }







};




int main(){





}