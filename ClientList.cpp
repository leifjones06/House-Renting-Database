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