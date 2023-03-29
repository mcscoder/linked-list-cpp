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

    int length = 0;

    void emptyListHandle(int newData)
    {
        Node *newNode = new Node();
        newNode->data = newData;

        headNode = newNode;
        lastNode = newNode;
        length++;
    }

public:
    LinkedList()
    {
        headNode = NULL;
        lastNode = NULL;
    }

    int size()
    {
        return length;
    }

    // Add new element at the start of the list
    void push_front(int newData)
    {
        if (headNode == NULL)
        {
            emptyListHandle(newData);
            return;
        }

        Node *newNode = new Node();
        newNode->data = newData;

        newNode->next = headNode;
        headNode->prev = newNode;
        headNode = newNode;
        length++;
    }

    // Add new element at the end of the list
    void push_back(int newData)
    {
        if (lastNode == NULL)
        {
            emptyListHandle(newData);
            return;
        }

        Node *newNode = new Node();
        newNode->data = newData;

        newNode->prev = lastNode;
        lastNode->next = newNode;
        lastNode = newNode;
        length++;
    }

    // Remove an element at specific position
    void removeAt(int position)
    {
        Node *node = headNode;
        Node *leftNode = NULL;
        Node *rightNode = NULL;

        if (position >= length)
            throw out_of_range("Index out of range");

        for (int i = 0; i < position; i++)
            node = node->next;

        leftNode = node->prev;
        rightNode = node->next;

        // Handle if position at the head node
        if (leftNode == NULL)
            headNode = rightNode;
        else
            leftNode->next = rightNode;

        // Handle if position at the last node
        if (rightNode == NULL)
            lastNode = leftNode;
        else
            rightNode->prev = leftNode;

        // Optimize memory by using `free` or `delete` keyword
        delete node;
        length--;
    }

    // Delete an element from the beginning of the linked list
    void pop_front()
    {
        Node *node = headNode;
        Node *rightNode = headNode->next;
        rightNode->prev = headNode->prev;
        headNode = rightNode;
        delete node;
        length--;
    }
    
    // Delete an element from the ending of the linked list
    void pop_back()
    {
        Node *node = lastNode;
        Node *leftNode = lastNode->prev;
        leftNode->next = lastNode->next;
        lastNode = leftNode;
        delete node;
        length--;
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

    MyList.removeAt(2);
    MyList.PrintList();

    MyList.pop_back();
    MyList.PrintList();

    MyList.pop_front();
    MyList.PrintList();

    return 0;
}