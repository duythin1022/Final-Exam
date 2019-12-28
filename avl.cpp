#include<iostream>

using namespace std;

struct Node{
    int data;
    int balance = 0;
    int height;
    Node* left, *right;
    Node(int _data){
        this->data = _data;
        this->right = NULL;
        this->left = NULL;
        this->height = 0;
    }
};

class AVL{
    private:
        Node* root;
    
    AVL(){
        root = NULL;
    }
    int max(int a, int b){
        return a > b ? a : b;
    }

    int height(Node* root){
        static int l, r;
        if(!root){
            return 0;
        }
        else{
            if(root->left){
                l = height(root->left) + 1;
            }
            else if(root->right){
                r = height(root->right) + 1; 
            }
            return l > r ? l + 1:r+1;
        }
    }

    int getBalance(Node* root){
        return height(root->left) - height(root->right);
    }
        
    Node* rotateLeft(Node* root){
        Node* subRight = root->right;
        Node*subSubRight = subRight ->left;
        
        subRight->left = root;
        root->right = subSubRight;

        subRight->height = max(height(subRight->left), height(subRight->right));
        root->height = max(height(root->left), height(root->right));
        return subRight;
    } 

    Node*  rotateRight(Node*& root) {
		Node* tempLeft = root->left;
	   Node* subTempLeft = tempLeft->right;
		
		tempLeft->right = root;
		root->left = subTempLeft;
		
		tempLeft->height = max(height(tempLeft->left), height(tempLeft->right)) + 1;
		root->height = max(height(root->left), height(root->right)) + 1;
		return tempLeft;
	} 
    //Tuong tu rotateRight

    Node* add(Node* root, int data){
        //Se add xong, sau do can bang sau
        Node* newNode = new Node(data);
        if(!root){
            return root = newNode;
        }
        else if(data > root->data){
           root->right = add(root->right, data);
        }
        else if(data < root->data){
            root->left = add(root->left, data);
        }
        else{
            return root;
        }

        //Sau khi them vao thi cap nhat lai chieu cao
        root->height = max(height(root->left), height(root->right));
        int bal = getBalance(root);

        if(bal > 1 && data < root->left->data){
           return root = rotateRight(root);
        }
        if(bal > 1 && data > root->left->data){
            root->left = rotateLeft(root->left);
            return root = rotateRight(root);
        }
        if (bal < -1 && data > root->right->data) {
			return rotateLeft(root);
		}
		if (bal < -1 && data < root->right->data) {
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
		return root;
    }

    void NLR(Node* root){
        if(root){
            cout << root->data << " ";
            NLR(root->left);
            NLR(root->right);
        }
    }

};

int main(){
}