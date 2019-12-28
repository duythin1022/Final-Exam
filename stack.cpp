#include<iostream>
using namespace std;

struct LlItem{
    int data;
    LlItem* pNext;
    //LlItem() : pNext(nullptr);
    LlItem(int a){
        data = a;
        pNext = NULL;
    }
};

class stack{
    private:
        LlItem* pTop;
    public:
        stack(){
            this->pTop = NULL;
        }
        LlItem* createNode(int data){
            LlItem* newNode = new LlItem(data);
            return newNode;
        }
        void push(int data){
            LlItem* newNode =  createNode(data);            
            newNode->pNext = pTop;
            pTop = newNode;
        }
        int top(){
            if(pTop == NULL){
                return -1;
            }
            else{
                return pTop->data;
            }
        }
        void pop(){
            if(pTop == NULL){
                cout << "Stack is empty!";
            }
            else{
                LlItem* temp = pTop;
                pTop = pTop->pNext;
                delete temp;
            }
        }
        bool isEmpty(){
            return pTop;
        }
        int size(){
            int size = 0;
            LlItem* temp = pTop;
            while(temp){
                temp = temp->pNext;
                size++; 
            } //Can than doan nay, khi chay doan nay thi pTop se chay theo, nen ta se tao ra 1 bien tam
            return size;
        }

};

int main(){
    stack* newStack = new stack();
    newStack->push(1);
    newStack->push(2);
    newStack->push(3);
    newStack->push(4);
    newStack->push(5);
    cout << "\nTop: "<<newStack->top();
    cout << "\nSizeL " << newStack->size();
}