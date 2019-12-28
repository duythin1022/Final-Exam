#include<iostream>
using namespace std;

struct LlItem{
    char data;
    LlItem* pNext;
    LlItem(char data){
        this->data = data;
        this->pNext = NULL;
    }
};


class Stack{
    private:
        LlItem* pTop;
    public:
        Stack(){
            pTop = NULL;
        }    
        void push(char data){
            LlItem* newNode = new LlItem(data);
            newNode->pNext = pTop;
            pTop = newNode;
        }
        void pop(){
            if(!pTop){
                cout << "Stack is empty!";
            }
            else{
                LlItem* temp = pTop;
                pTop = pTop->pNext;
                delete temp;
            }
        }

        char top(){
            return pTop ? pTop->data : -1;
        }

        int size(){
            LlItem* temp = pTop;
            int count = 0;
            while(temp){
                count++;
                temp = temp->pNext;
            }
            return count;
        }
        void print(){
            LlItem* temp = pTop;
            while(temp){
                cout << temp->data << " ";
                temp = temp->pNext;
            }
        }
};

int main(){
    Stack* newStack = new Stack();
    newStack->push('a');
    newStack->push('b');
    newStack->push('c');
    newStack->push('d');
    newStack->push('e');
    newStack->print();

    Stack* postFix = new Stack();
    char post[] = {1,2, '/', 3, 4, '*', '+'};
    int size =sizeof(post) / sizeof(post[0]);
    for(int i = 0; i < size; i++){
        if(post[i] <=9 && post[i] >= 0 ){
            postFix->push(post[i]);
        }
        else{
            int top1 = postFix->top();
            postFix->pop();
            int top2 = postFix->top();
            postFix->pop();
            int result;
            switch (post[i]){
                case '+':
                     result = top1 + top2;
                     break;
                case '-':
                     result = top1 - top2;
                    break;
                case '/':
                     result = top1 / top2;
                     break;
                case '*':
                    result = top1 * top2;
                    break;     
            }
            char resultCh = (char)result;
            postFix->push(resultCh);
        }
    }
    cout << "\nResult: "; postFix->print();

}