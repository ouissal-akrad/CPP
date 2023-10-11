#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact
{
public:
    std::string f_name;
    std::string l_name;
    std::string n_name;
    std::string p_number;
	std::string darkest;

public:
    void AddContact();
};

#endif
