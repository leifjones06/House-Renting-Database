#include "ClientList.hpp"
ClientList::ClientList() //Constructor
{
    head = nullptr;
    tail = nullptr;
}
ClientList::~ClientList() //Destructor
{
    Node* current = head;
    while(current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
void ClientList::insertAtBeginning(const Client& c)
{
    Node* newNode = new Node(c);
    if(head == nullptr) //Handles empty list
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head; //New node points to old head
        head->prev = newNode; //Old head points back to new node
        head = newNode; //Updates pointer
    }
}
void ClientList::insertAtEnd(const Client& c) //Similar structure to insertAtBeginning, but allowing for end insertion
{
    Node* newNode = new Node(c);
    if(tail == nullptr)
    {
        tail = head = newNode;
    }
    else
    {
        tail->next = newNode; //Old tail points to new node
        newNode->prev = tail; //New node points back to old tail
        tail = newNode; //Updates pointer
    }
}