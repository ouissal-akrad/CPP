#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
private:
    std::string f_name;
    std::string l_name;
    std::string n_name;
    std::string p_number;
    std::string darkest;

public:
    void AddContact();
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetNickname() const;
    std::string GetPhoneNumber() const;
    std::string GetDarkestSecret() const;
};

#endif
