#include <iostream>
using namespace std;

// node structure
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
private:
    Node *headNode;
    Node *lastNode;

    void emptyListHandle(int newData)
    {
        Node *newNode = new Node();
        newNode->data = newData;

        headNode = newNode;
        lastNode = newNode;
    }

public:
    LinkedList()
    {
        headNode = NULL;
        lastNode = NULL;
    }

    // Add new element at the start of the list
    void push_front(int newData)
    {
        if (headNode == NULL)
            emptyListHandle(newData);
            
        else
        {
            Node *newNode = new Node();
            newNode->data = newData;

            newNode->next = headNode;
            headNode->prev = newNode;
            headNode = newNode;
        }
    }

    // Add new element at the end of the list
    void push_back(int newData)
    {
        if (headNode == NULL)
            emptyListHandle(newData);

        else
        {
            Node *newNode = new Node();
            newNode->data = newData;

            newNode->prev = lastNode;
            lastNode->next = newNode;
            lastNode = newNode;
        }
    }

    // display the content of the list
    void PrintList()
    {
        Node *temp = headNode;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
};

// test the code
int main()
{
    LinkedList MyList;

    // Add three elements at the start of the list.
    MyList.push_front(10);
    MyList.push_front(20);
    MyList.push_front(30);
    MyList.push_back(40);
    MyList.push_back(50);
    MyList.push_back(60);
    MyList.PrintList();

    return 0;
}