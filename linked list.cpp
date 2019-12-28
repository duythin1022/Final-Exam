#include<iostream>
using namespace std;
//Trong moi node bao gom: data va con tro. Va khoi tao Node
class LinkedListNode{
    public:
        int data;
        LinkedListNode *pNext;
        LinkedListNode(int data){
            this->data = data;
            this->pNext = NULL;
        }
        
};
//Trong List thi bao gom cac node
class LinkedList{
    public:
        LinkedListNode* head;
        LinkedList(){
            this->head = NULL;
        }
        void insertLast(int data){
            if(head == NULL){
                LinkedListNode* newNode = new LinkedListNode(data);
                head = newNode;
            }
            else{
                LinkedListNode* newNode = new LinkedListNode(data);
                LinkedListNode* temp = head;
                while(temp && temp->pNext){
                    temp = temp->pNext;
                }
                temp->pNext = newNode;
            }
        }
        void insertAt(int data, int pos){
            LinkedListNode* newNode = new LinkedListNode(data);
            if(head == NULL || pos == 0){
                head = newNode;
            }
            else{
                int count = 0;
                LinkedListNode* temp = head;
                while(temp && temp->pNext && count < pos - 1){
                    temp =temp->pNext;
                    count++;
                }
                LinkedListNode* tam = temp->pNext;
                temp->pNext = newNode;
                newNode->pNext = tam;
            }
        }
};

void print(LinkedListNode* node){
    while(node){
        cout << node->data << " ";
        node = node->pNext;
    }
}
void input(LinkedList*& head, int size){
    for(int i = 0; i <size; i++){
        cout << "Nhap: ";
        int temp;
        cin >> temp;
        head->insertLast(temp);
    }

}
int main(){
    LinkedList* newList = new LinkedList();
    cout << "Enter size: ";
    int size; cin >> size;
    input(newList, size);
    print(newList->head);
    newList->insertAt(1000, 2);
}

