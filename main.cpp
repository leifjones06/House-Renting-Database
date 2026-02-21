#include <iostream>
#include "ClientList.hpp"
int main()
{
    ClientList clients;
    std::cout << "First Manager Tests:\n";
    //Sample Clients
    Client a; a.name = "Alice"; a.age = 30; a.gender = 'F'; a.familyMembers = 2; a.dateOfBirth = "1995-01-15";
    Client b; b.name = "Bob";   b.age = 25; b.gender = 'M'; b.familyMembers = 1; b.dateOfBirth = "2000-03-20";
    Client c; c.name = "Charlie"; c.age = 40; c.gender = 'M'; c.familyMembers = 4; c.dateOfBirth = "1984-08-02";
    Client d; d.name = "Dana";  d.age = 28; d.gender = 'F'; d.familyMembers = 3; d.dateOfBirth = "1997-06-10";
    Client e; e.name = "Eve";   e.age = 22; e.gender = 'F'; e.familyMembers = 1; e.dateOfBirth = "2003-11-05";
    //First Manager tests
    clients.insertAtEnd(a);
    clients.insertAtBeginning(c);
    clients.insertAtEnd(d);
    clients.insertAfter(a, e);

    std::cout << "Current list:\n";
    clients.printList();

    Client* found = clients.getClient("Eve");
    if (found) std::cout << "Found by name: " << found->name << ", age " << found->age << "\n";

    Client* foundAge = clients.getClient("", 25);
    if (foundAge) std::cout << "Found by age: " << foundAge->name << "\n";
    else std::cout << "No client with age 25 found.\n";
    Client* foundGender = clients.getClient("", -1, 'M');
    if (foundGender) std::cout << "Found by gender: " << foundGender->name << "\n";

    //Second Manager tests
    std::cout << "\nSecond Manager Tests:\n";

    Client* recent = clients.removeMostRecent();
    if (recent) std::cout << "Removed most recent: " << recent->name << "\n";
    std::cout << "List after removing most recent:\n";
    clients.printList();

    //Third Manager tests
    std::cout << "\nThird Manager Tests\n";
    Client* oldest = clients.removeOldest();
    if (oldest) std::cout << "Removed oldest: " << oldest->name << "\n";
    std::cout << "List after removing oldest:\n";
    clients.printList();
    return 0;
}