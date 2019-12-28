#include<iostream>
using namespace std;

struct LlItem{
    int data;
    LlItem* pNext;
    LlItem(int data){
        this->data = data;
        this->pNext = NULL;
    }
};

class Queue{
    private:
        LlItem* pHead;
        LlItem* pTail;
        
    public:
        Queue(){
           pHead = pTail = NULL;
        }
        bool isEmpty(){
            return pTail == NULL;
        }
        void enQueue(int data){
            LlItem* newNode = new LlItem(data);
            if(isEmpty()){
                pHead = pTail  = newNode;
            }
            else{
                pTail->pNext = newNode;
                pTail = newNode;
            }
        }
        void deQueue(){
            if(isEmpty()){
                cout << "Queue is empty";
            }
            else{
                LlItem* temp = pHead;
                pHead = pHead->pNext;
                delete temp;
            }
        }    
        int size(){
            LlItem* temp = pHead;
            int size = 0;
            while(temp != pTail){
                temp = temp->pNext;
                size++;
            }
            return size;
        }
        void clear(){
            pHead = pTail = NULL;
        }
        void print(){
            LlItem* temp = pHead;
            while(temp){
                cout << temp->data << " ";
                temp = temp->pNext;
            }
        }
        int head(){
            return pHead ? pHead->data : -1;
        }
        int tail(){
            return pTail ? pTail->data : -1;
        }
};

int main(){
    Queue newQueue;
    newQueue.enQueue(1);
    newQueue.enQueue(2);
    newQueue.enQueue(3);
    newQueue.enQueue(4);
    newQueue.enQueue(5);
    cout << "newQueue Element: ";
    newQueue.print();
    newQueue.deQueue();
    cout << "\nAfter deQueue: ";
    newQueue.print();
    cout << "\npHead: "<< newQueue.head();
    cout << "\npTail: " << newQueue.tail();
}