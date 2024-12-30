#include <string>
#include <iostream>
using namespace std;
class Contact
{
    private:
        string firstname;
        string lastname;
        string nickname;
        int phonenumber;
        int darkestsecret;
    public:
        Contact()
        {
            firstname = "";
            lastname = "";
            nickname = "";
            phonenumber = 0;
            darkestsecret = 0;
        }
        Contact(string firstname,string lastname,string nickname,int phonenumber,int darkestsecret)
        {
            this->firstname = firstname;
            this->lastname = lastname;
            this->nickname = nickname;
            this->phonenumber = phonenumber;
            this->darkestsecret =darkestsecret;
        }
}