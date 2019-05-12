//Queue Implementation using an array of custom object

#include <iostream>
#include <string>

using namespace std;

#define SIZE 10

class Entry
{
  int id;
  string name;
  
  public:
  Entry()
  {
  }
  
  Entry(int id, string name)
  {
      this->setId(id);
      this->setName(name);
  }
  
  int getId()
  {
      return this->id;
  }
  
  string getName()
  {
      return this->name;
  }
  
  void setId(int id)
  {
      this->id = id;
  }
  
  void setName(string name)
  {
      this->name = name;
  }
  
};

class queue
{
    Entry* arr;
    int capacity;
    int count; 
    int front;
    int rear;
    
public:
    queue(int size = SIZE);
    void dequeue();
    void enqueue(int id, string name);
    int size();
    bool isFull();
    bool isEmpty();
    Entry peek();
};

queue::queue(int size)
{
    arr = new Entry[size];
    capacity = size;
    count = 0;
    front = 0;
    rear = -1;
}

int queue::size()
{
    cout << "Current Size: " << count << endl;
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

Entry queue::peek()
{
    cout << "Peek now, id: " << arr[front].getId() << " & name: " << arr[front].getName() << endl;
    return arr[front];
}

void queue::enqueue(int id, string name)
{
    if(isFull())
    {
        cout << "Queue is Full" << endl;
        return;
    }
    cout << "Inserting id: " << id << " & name: " << name << endl;
    rear = (rear + 1) % capacity;
    arr[rear].setId(id);
    arr[rear].setName(name);
    count++;
}

void queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is already empty" << endl;
        return;
    }
    cout << "Removing id: " << arr[front].getId() << " & name: " << arr[front].getName() << endl;
    front = (front + 1) % capacity;
    count--;
}

int main()
{
    //cout<<"Hello World";
    queue qs(10);
    qs.dequeue();
    qs.enqueue(1, "Jon");
    qs.enqueue(3, "Josh");
    qs.enqueue(2, "Alex");
    qs.peek();
    qs.dequeue();
    qs.peek();
    qs.enqueue(4, "Kevin");
    qs.enqueue(5, "Martin");
    qs.enqueue(6, "Greg");
    qs.size();
    qs.peek();
    qs.enqueue(20, "Michael");
    qs.enqueue(9, "Tom");
    qs.enqueue(8, "Tony");
    qs.peek();
    qs.enqueue(12, "Edward");
    qs.enqueue(7, "Ben");
    qs.enqueue(11, "Victor");
    qs.size();
    qs.peek();
    qs.enqueue(13, "Aaron");
    qs.dequeue();
    qs.dequeue();
    qs.peek();
    return 0;
}
