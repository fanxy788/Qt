#include "ContactItem.h"
#include "type.h"

#include <sstream>

std::string ContactItem::getName() const
{
    return name;
}

void ContactItem::setName(const std::string &value)
{
    name = value;
}

std::string ContactItem::getTel() const
{
    return tel;
}

void ContactItem::setTel(const std::string &value)
{
    tel = value;
}

std::string ContactItem::serlize()
{
    return this->getName() + "," + this->getTel();
}

int ContactItem::unserlize(std::string line)
{
    std::string name;
    std::string tel;
    std::string counter;
    const char delimStr = ',';
    std::string token;

    std::istringstream iss(line);

    if(!std::getline(iss, counter, delimStr)){
        return ENO_FAILED;
    }

    if(!std::getline(iss, name, delimStr)){
        return ENO_FAILED;
    }

    if(!std::getline(iss, tel, delimStr)){
        return ENO_FAILED;
    }

    this->setName(name);
    this->setTel(tel);
    return ENO_OK;
}

ContactItem::ContactItem()
{
    ContactItem("","");
}

ContactItem::ContactItem(std::string m_name, std::string m_tel)
    :name(m_name),
      tel(m_tel)
{
}
