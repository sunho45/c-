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
        void heapdown() {
    node* current = root;

    while (true) {
        node* smallest = current;

        if (current->left && *(current->left->num) < *(smallest->num)) {
            smallest = current->left;
        }

        if (current->right && *(current->right->num) < *(smallest->num)) {
            smallest = current->right;
        }

        if (smallest == current) break;  // 자식 중 더 작은 게 없으면 정지

        swap(current->num, smallest->num);
        current = smallest;
    }
}



    void heapdownmax() {
    node* current = root;

    while (true) {
        node* biggest = current;

        if (current->left && *(current->left->num) > *(biggest->num)) {
            biggest = current->left;
        }

        if (current->right && *(current->right->num) > *(biggest->num)) {
            biggest = current->right;
        }

        if (biggest == current) break;  // 자식 중 더 작은 게 없으면 정지

        swap(current->num, biggest->num);
        current = biggest;
    }
}


        int pop(){


            int num=*(root->num);
            node * re=root;
            node *    roots=getlastnode();
            root->num=roots->num;
            if(roots->parent->left==roots){
                roots->parent->left=nullptr;
            }
            else if(roots->parent->right==roots){
                roots->parent->right=nullptr;
            }




            delete roots;
            heapdown();


                







            return num;














        }
        int popmax(){


            int num=*(root->num);
            node * re=root;
            node *    roots=getlastnode();
            root->num=roots->num;
            if(roots->parent->left==roots){
                roots->parent->left=nullptr;
            }
            else if(roots->parent->right==roots){
                roots->parent->right=nullptr;
            }




            delete roots;
            heapdown();


                







            return num;

        }







        node* getlastnode(){
            queue <node*> q;
            q.push(root);
            node *current=nullptr;



            while(!q.empty()){

                current=q.front();

                
                if(q.front()->left!=nullptr){
                    q.push(q.front()->left);
                    


                }
                if(q.front()->right!=nullptr){
                    q.push(q.front()->right);
                    
                    
                }
                q.pop();

            } 



            return current;

            

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

cout<<hp->pop()<<endl;
cout<<hp->pop()<<endl;
cout<<hp->pop()<<endl;










}