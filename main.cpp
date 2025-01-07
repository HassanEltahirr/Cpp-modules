#include <string>
#include "Contact.hpp"
#include "Phonebook.hpp"
void addcontact()
{
    PhoneBook p1;
    string fname;
    string lname;
    string nickname;
    int phonenumber;
    int darkestsecret;
    std::cout << "Enter all fields" << "\n";
    std::cin>>fname;
    std::cin>>lname;
    std::cin>>nickname;
    std::cin >> phonenumber;
    std::cin >> darkestsecret;
    // p1.contacts[0].setFirstName()
    Contact(fname,lname,nickname,phonenumber,darkestsecret);
}
int main()
{
    while(1)
    {
        PhoneBook p1;
        Contact c1;
        string option;
        std::cout << "Enter your desired option" << "\n";
        std::cin>>option;
        // std::cout<<option;
        if(!option.compare("ADD"))
        {
            addcontact();
            break;
        }
    }
}