//
//  main.cpp
//  BCS-370-Module-6
//
//  Created by Nick Jakobczyk on 11/22/20.
//

/*
* Unsorted Singly Linked List
* Nicholas Jakobczyk
* Partner Kiernan Kolano
*/

#include <iostream>
using std::cout;


struct Node {
    int data;
    Node* link;

    Node(int data = 0, Node* p = nullptr) { //Note, this constructor combines both default and parameterized constructors. You may modify the contructor to your needs
        this->data = data;
        link = p;
    }
};

class linked_list
{
private:
    Node* head, * current;
public:
    //constructor
    linked_list() {
        head = nullptr;//the head pointer
        current = nullptr;//acts as the tail of the list
    }

    //destructor - IMPORTANT
    ~linked_list() {
        current = head;
        while (current != nullptr) {//the loop stops when both current and head are NULL
            head = head->link;
            delete current;
            current = head;
        }
    }

    void addFirst(int n)
    {
        Node* temp = new Node(n);
        temp->link = head;
        head = temp;
        if (current == nullptr)
            current = head;
    }

    int pop()
    {
        if (head == nullptr)
            return NULL;
        Node* temp = head;
        head = head->link;
        if (head == nullptr)
            current = NULL;
        int data = temp->data;
        delete temp;
        return data;
    }

    bool contains(int data)
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp->data == data)
                return true;
            temp = temp->link;
        }
        return false;
    }

    void update(int oldData, int newData)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == oldData)
            {
                temp->data = newData;
                break;
            }
            temp = temp->link;
        }
    }

    int size()
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
                temp = temp->link;
        }
        return count;
    }

    void remove(int data)
    {
        if (contains(data))
        {
            Node* temp = head, * pre = nullptr;
            while (temp != nullptr)
            {
                if (temp->data == data)
                    break;
                pre = temp;
                temp = temp->link;
            }
            if (pre == nullptr)
                pop();
            else
            {
                pre->link = temp->link;
                delete temp;
            }
        }
    }
    void insertAfter(int n, int data)
    {
        Node* node = new Node(data);
        if (size() <= n)
            addLast(data);
        else
        {
            Node* temp = head, * pre;
            while (n > 0)
            {
                n--;
                pre = temp;
                temp = temp->link;
            }
            pre->link = node;
            node->link = temp;
        }

    }

    void merge(const linked_list& linkedList)
    {
        if (head == nullptr)
            head = linkedList.head;
        else
        {
            Node* temp = head;
            while (temp->link != nullptr)
                temp = temp->link;
            temp->link = linkedList.head;
        }
    }



    void addLast(int n) {// to add a node at the end of the list
        if (head == nullptr) {
            head = new Node(n);
            current = head;
        }
        else {
            if (current->link != nullptr)
                current = current->link;
            current->link = new Node(n);
            current = current->link;//You may decide whether to keep this line or not for the function
        }
    }

    void print() { // to display all nodes in the list
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << std::endl;
            tmp = tmp->link;
        }
    }
};

int main() {
    linked_list a;
    a.addLast(1);
    a.addLast(2);
    a.addFirst(3);

    a.print();

    return 0;
}


