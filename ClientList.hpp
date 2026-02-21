#ifndef CLIENTLIST_HPP
#define CLIENTLIST_HPP
#include "Client.hpp"
class ClientList
{
    private:
    struct Node
    {
        Client data;
        Node* next;
        Node* prev;
        Node(const Client& c) : data(c), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
    public:
    ClientList();
    ~ClientList();
    void insertAtBeginning(const Client& c);
    void insertAtEnd(const Client& c);
    void insertAfter(const Client& target, const Client& c); //Search by name/age/gender
    Client* getFirst();
    Client* getLast();
    Client* getClient(const std::string& name = "", int age = -1, char gender = '\0');
    Client* removeMostRecent();
    Client* removeOldest();
    void printList(); //Test method
};
#endif