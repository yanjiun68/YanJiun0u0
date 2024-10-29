#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Contact {
    std:: string name;
    std:: string phone;
    std:: string email;
};

void addContact(std:: vector<Contact>& contacts)
{
    Contact newContact;
    std::cout << "Enter name: ";
    std::cin >> newContact.name;
    std::cout << "Enter email: ";
    std::cin >> newContact.email;

    contacts.push_back(newContact);

    std::cout<< "Contact added." <<std::endl;
}

void displayContacts(const std::vector <Contact> &contacts)
{
    for (const auto&contact : contacts)
    {
        std::cout << "Name: " << contact.name << ", Phone: " << contact.phone <<"Email: " << contact.email << std::endl;

    }
}

void searchContact(const std:: vector<Contact> &contacts)
{
    std:: string searchTerm;
    std::cout << "Enter name to serach: ";
    std::cin >> searchTerm;

    bool found = false;
    for (const auto &contact: contacts)
    {
        if(contact.name == searchTerm){
            std::cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << std::endl;

            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Contact not found." << std::endl;
    }
}

void deleteContact(std::vector<Contact>&contacts)
{
    std::string nameToDelete;
    std::cout << "Enter name to delete: ";
    std::cin >> nameToDelete;

    auto it = std::remove_if(contacts.begin(),contacts.end(), [&](const Contact&contact)
    { return contact.name ==nameToDelete; });

    if (it != contacts.end())
    {
        contacts.erase(it,contacts.end());
        std::cout << "Contact deleted." << std::endl;

    }
    else {
        std::cout << "Contact not found." << std::endl;
    }

}

int main ()
{std::vector<Contact> contacts; int choice;

do{
    std::cout << "\nPhone Book Menu\n";
    std::cout << "1. Add Contact\n";
    std::cout << "2. Display Contacts\n";
    std::cout << "3. Search Contact\n";
    std::cout << "4. Delete Contact\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            addContact(contacts);
            break;
        case 2:
            displayContacts(contacts);
            break;
        case 3:
            searchContact(contacts);
            break;
        case 4:
            deleteContact(contacts);
            break;
        case 5:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }
}
while (choice != 5);

return 0;
}
