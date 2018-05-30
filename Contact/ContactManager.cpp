#include "ContactManager.h"

#include <iostream>
#include <fstream>

ContactManager::ContactManager()
{

}

ContactManager::~ContactManager()
{
    this->manager.clear();
}

unsigned int ContactManager::size()
{
    return manager.size();
}

int ContactManager::insert(ContactItem &item)
{
    ContactItemMap::iterator it = manager.find(item.getName());
    if(it == manager.end()){
        manager.insert(ContactItemPair(item.getName(), item));
    }else{
        return ENO_EXISTED;
    }
    return ENO_OK;
}

int ContactManager::remove(const std::string &name)
{
    ContactItemMap::iterator it = manager.find(name);
    if(it == manager.end()){
        return ENO_NOT_EXISTED;
    }else{
        manager.erase(name);
    }
    return ENO_OK;

}

int ContactManager::search(const std::string &name, ContactItem& item)
{
    ContactItemMap::iterator it = manager.find(name);
    if(it == manager.end()){
        return ENO_NOT_EXISTED;
    }
    item = (*it).second;
    return ENO_OK;
}

void ContactManager::printAll()
{
    int counter = 0;
    for(ContactItemMap::iterator iter = manager.begin(); iter != manager.end(); iter++, counter++){
        std::cout << counter << " => " << (*iter).second.getName() << " " << (*iter).second.getTel() << std::endl;
    }
}


bool ContactManager::load()
{
    std::string line;
    std::ifstream ifs;
    ifs.open("data.txt", std::ifstream::in);

    while(std::getline(ifs, line)){
        ContactItem item;
        if(ENO_OK == item.unserlize(line))
            this->insert(item);
        else
            std::cerr << "parsed error" << std::endl;
    }

    return true;
}

bool ContactManager::save()
{
    int counter = 0;

    std::ofstream ofs;
    ofs.open("data.txt",std::ofstream::out | std::ofstream::app);
    for(ContactItemMap::iterator iter = manager.begin(); iter != manager.end(); iter++, counter++){
        ofs << counter << "," << (*iter).second.serlize() << std::endl;
    }
    ofs.close();

    return true;
}
