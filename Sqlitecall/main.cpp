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

        //�����˵�
        menu();

        cout << "����������ѡ�";
        int index;
        cin >> index;
        cin.get();

        switch (index)
        {
        case 0:
            ifStop = true;
            break;
        case 1:
            cout << "����id:";
            cin >> id;
            cin.get();
            cout << endl
                 << "��������:";
            getline(cin, name);
            cout << endl
                 << "����绰:";
            getline(cin, telephone);

            cout << id << endl
                 << name << endl
                 << telephone << endl;
            re = controller.addData(id, name, telephone);
            if (re == 0)
                cout << "ERROR! ����δ֪�������ݿ����" << endl;
            else
                cout << "�����Ϣ�ɹ���" << endl;
            break;

        case 2:
            cout << "������id��";
            cin >> id;
            controller.select(id);

            break;
        case 3:
            cout << "��������Ҫ�޸ĵ���Ϣ��id�ţ�";

            cin >> id;
            cin.get();
            cout << endl
                 << "��������:";
            getline(cin, name);
            cout << endl
                 << "����绰:";
            getline(cin, telephone);

            cout << id << endl
                 << name << endl
                 << telephone << endl;
            controller.update(id, name, telephone);

            break;
        case 4:
            cout << "��������Ҫɾ������Ϣ��id�ţ�";
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
    cout << "******ͨѶ¼�˵�*****" << endl;
    cout << "* 1. ¼��һ��ͨѶ��Ϣ" << endl;
    cout << "* 2. ͨ��id��ѯ��Ϣ" << endl;
    cout << "* 3. �޸�һ����Ϣ" << endl;
    cout << "* 4. ɾ��һ����Ϣ" << endl;
    cout << "* 5. �鿴ȫ��ͨѶ¼��Ϣ" << endl;
    cout << "* 6. �������ҵ����˵�" << endl;
    cout << "* 0. �˳�" << endl;
}
