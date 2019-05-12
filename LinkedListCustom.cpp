//Linked List with a Custom Class
//Custom Class can have any number of data and can be of any type.

#include <iostream>
#include<string>

using namespace std;

class Entry
{
    int id;
    string name;
    
    public:
    Entry(int id, string name)
    {
        setId(id);
        setName(name);
    }
    //setters and getters
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
    void displayObj()
    {
        cout << "Id: " << this->getId() << " ,Name: " << this->getName();
    }
};

class Node
{
    public:
    Entry* obj;
    Node* next;
    
    Node(int id, string name)
    {
        this->obj = new Entry(id, name);
        this->next = NULL;
    }
};

class EntryList
{
    public:
    Node* head;
    
    EntryList()
    {
        this->head = NULL;
    }
    
    void appendEntry(int id, string name)
    {
        if(head == NULL)
        {
            Node* tmp = new Node(id, name);
            head = tmp;
        }
        else
        {
            Node* current = head;
            while(current->next != NULL)
            {
                current = current->next;
            }
            Node* tmp = new Node(id, name);
            current->next = tmp;
        }
    }
    
    void displayEntryList()
    {
        Node* current = head;
        while(current != NULL)
        {
            current->obj->displayObj();
            cout << endl;
            current = current->next;
        }
    }
};

int main()
{
    EntryList* list = new EntryList();
    list->appendEntry(1, "Tom");
    list->appendEntry(2, "Jack");
    list->displayEntryList();
    return 0;
}
