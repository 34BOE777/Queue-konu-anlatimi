#include <iostream>
using namespace std;

struct Node{
string data;
Node* next;
};

class Queue{
private:
Node* front;
Node* rear;
int count;
public:
Queue(){
front = NULL;
rear = NULL;
count = 0;
}
bool isEmpty();// bos mu
void enqueue(string);// sona ekle
void dequeue();// bastan sil
void peek();// son goster
void displayCount(); // kac eleman var
};


bool Queue::isEmpty(){
return rear == NULL;
}


void Queue::enqueue(string val){
Node* newNode = new Node;
newNode->data = val;
newNode->next = NULL;
if (isEmpty()){
front = rear = newNode;
count++;
}
else{
rear->next = newNode;
rear = newNode;
count++;
}
}


void Queue::dequeue(){
if (front == NULL){
cout << "Queue bombos" << endl;
}
else{
Node* temp = front;
string data = temp->data;
// bir eleman varsa onu sil
if (front == rear){
front = rear = NULL;
delete(temp);
}
else{
//bir den fazla elemanlar varsa
front = front->next;
delete(temp);
}
cout << "\nSilinen eleman :" << data << endl;
count--;
}
}



void Queue::displayCount(){
cout << "\nKuyruktakiler: " << count << endl;
}
void Queue::peek(){
if (!isEmpty()){
cout << "\nBastaki eleman :" << front->data << endl;
}
}




int main(){
Queue q;
q.dequeue();
q.enqueue("to");
q.enqueue("be");
q.enqueue("or");
q.enqueue("not");
q.peek();
q.enqueue("to");
q.enqueue("be");
q.displayCount();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
q.displayCount();
return 0;
}
