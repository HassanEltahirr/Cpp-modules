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
        Contact();
        Contact(string firstname,string lastname,string nickname,int phonenumber,int darkestsecret);
        void setFirstName(std::string name);
        std::string getFirstName();
        void setLastName(std::string name);
        std::string getNickName();
        int getDarkestSecret();
        void setDarkestSecret(int secret);
        std::string getLastName();
        void setNickName(std::string name);
        void setPhoneNumber(int number);
        int getPhoneNumber();
};