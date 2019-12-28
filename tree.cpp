#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this->data = data;
        this->right = this->left = NULL;
    }
};

class BST{
    private:
        Node* root;
     
        bool insert(Node* &root, int data){
            Node* newNode = new Node(data);
            if(!root){
                root = newNode;
                return true;
            }
            else if(data < root->data){
               return insert(root->left, data);
            }
            else if(data > root->data){
                return insert(root->right, data);
            
            }
        }
        void traverse(Node* root){
            if(root){
                traverse(root->left);
                cout << root->data << " ";
                traverse(root->right);
            }
        } 
        void NodeTheMang(Node*&a, Node*&b){
          while(b->left){
            b = b->left;
          }
          a->data = b->data;
          a = b;
          b = b->right;
        }
        void remove(Node* &root, int data){
          if(!root){
            return;
          }
          else if(root->data> data){
            remove(root->left, data);
          }
          else if(root-> data < data){
            remove(root->right, data);
          }
          else{
            Node* p = root;
            if(root->left == NULL){
              root = root->right;
            }
            else if( root->right == NULL){
              root = root->left;
            }
            else{
              NodeTheMang(p, root->right);
            }
          }
        }
        int height(Node* root){
          static int left = 0, right = 0;
         if(!root){
           return  0;
         }
         else{
           if(root->left){
              left = height(root->left);
           }
           else if(root->right){
              right = height(root->right);
           }
           return left > right ? left  +1 : right + 1;
         }
        }
        int numberOfNode(Node* root){
          if(root){
            return numberOfNode(root->left) + numberOfNode(root->right) + 1;
          }
          else{
            return 0;
          }
        }
    public: 
        bool insertB(int data){
            return insert(root, data);
        }    
        bool print(){
            traverse(root);
            return true;
        }   
        bool remove(int data){
          remove(root, data);
          return true;
        }
        int height(){
          return height(root);
        }
        int numberOfNode(){
          return numberOfNode(root);
        }
};

int main(){
    BST tree;
    tree.insertB(1);
    tree.insertB(2);
    tree.insertB(3);
    cout << "Print: ";
    tree.print();
    tree.remove(3);
    cout << "\nPrint: ";
    tree.print();
    tree.insertB(4);
    tree.insertB(5);
    tree.insertB(6);
    cout << "\nPrint: ";
    tree.print();
    cout <<"\nHeight: " << tree.height();
    cout << "\nNumber of nodes: " << tree.numberOfNode();

}