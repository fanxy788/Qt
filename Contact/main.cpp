#include <iostream>
#include "ContactManager.h"

ContactManager manager;

void test_base_operation(){
    ContactItem a;
    ContactItem b;
    ContactItem c;
    ContactItem res;

    std::string name;
    std::string tel;

    std::cin >> name >> tel;
    a.setName(name);
    a.setTel(tel);

    std::cin >> name >> tel;
    b.setName(name);
    b.setTel(tel);

    std::cin >> name >> tel;
    c.setName(name);
    c.setTel(tel);

    manager.insert(a);
    manager.insert(b);
    manager.insert(c);

    std::cout << "manager size:" << manager.size() << std::endl;
    manager.printAll();

    if(manager.insert(a) != ENO_EXISTED){
        std::cout << "detect a failed [failed] " << std::endl;;
    }else{
        std::cout << "detect a failed [passed] " << std::endl;;
    }

    if(manager.search(b.getName(),res) == ENO_OK){
        std::cout << "search b [passed] " << res.serlize() << std::endl;
    }else{
        std::cout << "search b [passed] " << std::endl;
    }

    manager.save();

    manager.remove(b.getName());

    if(manager.search(b.getName(),res) == ENO_NOT_EXISTED){
        std::cout << "search b [passed] " << std::endl;
    }else{
        std::cout << "search b [failed] " << res.getName() << " " << res.getTel() << std::endl;
    }

    std::cout << "manager size:" << manager.size() << std::endl;
    manager.printAll();
}

void test_load(){
    manager.load();
    manager.printAll();
}

int main(){
    //test_base_operation();
    test_load();
    return 0;
}
