#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "type.h"
#include "ContactItem.h"
#include <map>

typedef std::map<std::string, ContactItem> ContactItemMap;
typedef std::pair<std::string, ContactItem> ContactItemPair;

class ContactManager
{
private:
    ContactItemMap manager;

public:
    ContactManager();
    ~ContactManager();

    unsigned int size();
    int insert(ContactItem &item);
    int remove(const std::string &name);
    int search(const std::string &name, ContactItem& item);
    void printAll();

    bool load();
    bool save();
};

#endif // CONTACTMANAGER_H
