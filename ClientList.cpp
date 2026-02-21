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
Client* ClientList::getFirst()
{
    if(head != nullptr)
    {
        return &(head->data);
    }
    return nullptr;
}
Client* ClientList::getLast()
{
    if(tail != nullptr)
    {
        return &(tail->data);
    }
    return nullptr;
}
void ClientList::insertAfter(const Client& target, const Client& c)
{
    Node* current = head;
    while(current != nullptr)
    {
        if(current->data.name == target.name || current->data.age == target.age || current->data.gender == target.gender)
        {
            break; //Node located
        }
        current = current->next;
    }
    if(current == nullptr)
    {
        return; //No matching node
    }
    Node* newNode = new Node(c);
    newNode->next = current->next; //New node points to current's next
    newNode->prev = current; //New node points back to current
    if(current->next != nullptr)
    {
        current->next->prev = newNode; //Old next points back to new node
    }
    current->next = newNode;
    if(newNode->next == nullptr) //Updates tail if necessary
    {
        tail = newNode;
    }
}
Client* ClientList::removeMostRecent()
{
    if(tail == nullptr)
    {
        return nullptr;
    }
    Node* oldTail = tail;
    Client* clientData = &(oldTail->data);
    tail = tail->prev;
    if(tail != nullptr)
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete oldTail;
    return clientData;
}
Client* ClientList::removeOldest()
{
    if(head == nullptr)
    {
        return nullptr;
    }
    Node* oldHead = head;
    Client* clientData = &(oldHead->data);
    head = head->next;
    if(head != nullptr)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }
    delete oldHead;
    return clientData;
}