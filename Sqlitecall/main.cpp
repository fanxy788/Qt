#include "Call.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void menu();

int main()
{
    SqlController controller;
    controller.CreatDatabase();

    int id, re;
    bool ifStop = false;
    string name, telephone;

    while (!ifStop)
    {

        //弹出菜单
        menu();

        cout << "请输入您的选项：";
        int index;
        cin >> index;
        cin.get();

        switch (index)
        {
        case 0:
            ifStop = true;
            break;
        case 1:
            cout << "输入id:";
            cin >> id;
            cin.get();
            cout << endl
                 << "输入姓名:";
            getline(cin, name);
            cout << endl
                 << "输入电话:";
            getline(cin, telephone);

            cout << id << endl
                 << name << endl
                 << telephone << endl;
            re = controller.addData(id, name, telephone);
            if (re == 0)
                cout << "ERROR! 出现未知错误，数据库错误！" << endl;
            else
                cout << "添加信息成功！" << endl;
            break;

        case 2:
            cout << "请输入id：";
            cin >> id;
            controller.select(id);

            break;
        case 3:
            cout << "请输入您要修改的信息的id号：";

            cin >> id;
            cin.get();
            cout << endl
                 << "输入姓名:";
            getline(cin, name);
            cout << endl
                 << "输入电话:";
            getline(cin, telephone);

            cout << id << endl
                 << name << endl
                 << telephone << endl;
            controller.update(id, name, telephone);

            break;
        case 4:
            cout << "请输入您要删除的信息的id号：";
            cin >> id;
            re = controller.deleteid(id);
            break;
        case 5:
            controller.show();
            break;
        case 6:
            system("cls");
            menu();
            break;
        }
    }

    return 0;
}

void menu()
{
    cout << "******通讯录菜单*****" << endl;
    cout << "* 1. 录入一条通讯信息" << endl;
    cout << "* 2. 通过id查询信息" << endl;
    cout << "* 3. 修改一条信息" << endl;
    cout << "* 4. 删除一条信息" << endl;
    cout << "* 5. 查看全部通讯录信息" << endl;
    cout << "* 6. 清屏并且弹出菜单" << endl;
    cout << "* 0. 退出" << endl;
}
