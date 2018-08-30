#ifndef CALL_H_INCLUDED
#define CALL_H_INCLUDED

#include "sqlite3.h"
#include <string>

using namespace std;

//回调函数
int callback(void *NotUsed, int argc, char **argv, char **azColName);

class SqlController
{
private:
    sqlite3 *db;

public:
    SqlController();
    ~SqlController();

    //创建数据库，初始化表
    void CreatDatabase();
    //打开数据库
    void OpenDatabase();
    //关闭数据库
    void closeDatabase();
    //添加数据
    int addData(int id, string name,string telephone);
    //删除
    int deleteid(int id);
    //查找
    int select(int id);
    //更新
    int update(int id, string name, string telephone);
    //显示数据
    void show();

};



#endif // CALL_H_INCLUDED
