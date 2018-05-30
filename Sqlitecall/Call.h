#ifndef CALL_H_INCLUDED
#define CALL_H_INCLUDED

#include "sqlite3.h"
#include <string>

using namespace std;

//�ص�����
int callback(void *NotUsed, int argc, char **argv, char **azColName);

class SqlController
{
private:
    sqlite3 *db;

public:
    SqlController();
    ~SqlController();

    //�������ݿ⣬��ʼ����
    void CreatDatabase();
    //�������
    int addData(int id, string name,string telephone);
    //ɾ��
    int deleteid(int id);
    //����
    int select(int id);
    //����
    int update(int id, string name, string telephone);
    //��ʾ����
    void show();

};



#endif // CALL_H_INCLUDED
