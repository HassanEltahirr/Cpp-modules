#include <string>
#include "Contact.hpp"

    Contact::Contact()
        {
            firstname = "";
            lastname = "";
            nickname = "";
            phonenumber = 0;
            darkestsecret = 0;
        }
    Contact::Contact(string firstname,string lastname,string nickname,int phonenumber,int darkestsecret)
        {
            this->firstname = firstname;
            this->lastname = lastname;
            this->nickname = nickname;
            this->phonenumber = phonenumber;
            this->darkestsecret =darkestsecret;
        }
    void Contact::setFirstName(std::string name) 
    {
        firstname = name;
    }

    std::string Contact::getFirstName()  
    {
        return firstname;
    }
    void Contact::setLastName(std::string name) 
    {
        lastname = name;
    }
    std::string Contact::getLastName()
    {
        return lastname;
    }
    void Contact::setNickName(std::string name) 
    {
        nickname = name;
    }
    std::string Contact::getNickName()
    {
        return nickname;
    }
    void Contact::setPhoneNumber(int number) 
    {
        phonenumber = number;
    }
    int Contact::getPhoneNumber()
    {
        return phonenumber;
    }
    void Contact::setDarkestSecret(int secret) {
        darkestsecret = secret;
    }
    int Contact::getDarkestSecret()
    {
        return darkestsecret;
    }
