#ifndef CONTACTITEM_H
#define CONTACTITEM_H

#include <string>

// interface
class Serial{
public:
    virtual std::string serlize() = 0;
    virtual int unserlize(std::string str) = 0;
};


/**
 * @brief 通讯录条目
 */
class ContactItem : public Serial
{
private:
    std::string name;
    std::string tel;
public:
    ContactItem();
    ContactItem(std::string m_name, std::string m_tel);

    std::string getName() const;
    void setName(const std::string &value);

    std::string getTel() const;
    void setTel(const std::string &value);

    // Serial interface
public:
    std::string serlize();
    int unserlize(std::string str);
};

#endif // CONTACTITEM_H
