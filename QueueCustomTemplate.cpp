//Queue using template of a custom object

#include <iostream>
#include <string>

using namespace std;

class Entity
{
    public:
    int val;
    char ch;
    Entity()
    {
        this->val = 0;
        this->ch = '.';
    }
    Entity(int val, char ch)
    {
        this->val = val;
        this->ch = ch;
    }
    void showData()
    {
        cout << "the Int: " << this->val << " the Char: " << this->ch << endl;
    }
};

template <class T>
class Queue
{
    public:
    T* arr;
    int front;
    int rear;
    int size;
    int capacity;
    
    Queue(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        arr = new T[this->capacity];
        this->front = 0;
        this-> rear = -1;
    }
    
    bool isEmpty()
    {
        return (size == 0);
    }
    
    bool isFull()
    {
        return (size == capacity);
    }
    
    T peek()
    {
        if(!isEmpty())
            return arr[front];
        return arr[front];
    }
    
    int getSize()
    {
        return this->size;
    }
    
    void enqueue(T* tmp)
    {
        if(isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = *tmp;
        size++;
    }
    
    void dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        front = (front + 1) % capacity;
        size--;
    }
    
};


int main()
{
    //cout<<"Hello World";
    Entity* e1 = new Entity(10, 'e');
    Queue <Entity> q1(10);
    q1.enqueue(e1);
    Entity e2 = q1.peek();
    e2.showData();
    cout << "Size of Queue: " << q1.getSize() << endl;
    q1.dequeue();
    cout << "Size of Queue: " << q1.getSize() << endl;
    return 0;
}
