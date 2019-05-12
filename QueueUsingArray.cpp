//Queue implementation using an Array.

#include <iostream>
#include <string>

using namespace std;

#define SIZE 10

class queue
{
    int* arr;
    int capacity;
    int count; 
    int front;
    int rear;
    
public:
    queue(int size = SIZE);
    void dequeue();
    void enqueue(int val);
    int size();
    bool isFull();
    bool isEmpty();
    int peek();
};

queue::queue(int size)
{
    arr = new int[size];
    capacity = size;
    count = 0;
    front = 0;
    rear = -1;
}

int queue::size()
{
    return count;
}

bool queue::isFull()
{
    return (size() == capacity);
}

bool queue::isEmpty()
{
    return (size() == 0);
}

int queue::peek()
{
    return arr[front];
}

void queue::enqueue(int val)
{
    if(isFull())
    {
        cout << "Queue is Full" << endl;
        return;
    }
    cout << "Inserting val: " << val << endl;
    rear = (rear + 1) % capacity;
    arr[rear] = val;
    count++;
}

void queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is already empty" << endl;
        return;
    }
    cout << "Removing val: " << arr[front] << endl;
    front = (front + 1) % capacity;
    count--;
}

int main()
{
    //cout<<"Hello World";
    queue qs(10);
    qs.dequeue();
    qs.enqueue(1);
    qs.enqueue(3);
    qs.enqueue(2);
    cout << "Peek now: " << qs.peek() << endl;
    qs.dequeue();
    cout << "Peek now: " << qs.peek() << endl;
    qs.enqueue(4);
    qs.enqueue(5);
    qs.enqueue(6);
    cout << "Current Size: " << qs.size() << endl;
    cout << "Peek now: " << qs.peek() << endl;
    qs.enqueue(20);
    qs.enqueue(9);
    qs.enqueue(8);
    cout << "Peek now: " << qs.peek() << endl;
    qs.enqueue(12);
    qs.enqueue(7);
    qs.enqueue(11);
    cout << "Current Size: " << qs.size() << endl;
    cout << "Peek now: " << qs.peek() << endl;
    qs.enqueue(13);
    qs.dequeue();
    qs.dequeue();
    cout << "Peek now: " << qs.peek() << endl;
    return 0;
}
