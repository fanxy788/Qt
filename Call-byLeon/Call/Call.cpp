#include "Call.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define USE_SQLITE_OEPN     (0)

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i=0; i<argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


SqlController::SqlController(){
    db = NULL;
}

SqlController::~SqlController(){
    if(db)
        sqlite3_close(db);
}

void SqlController::CreatDatabase()
{
    const char *sql;
    char *zErrMsg = 0;
    int rc;

    //sqlite3_open()返回值SQLITE_OK
    rc = sqlite3_open("test.db", &db);

    if(rc) //数据库打开失败
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    else  //打开成功
    {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    //判断是否已经存在表
    sql = "CREATE TABLE if not exists test("  \
          "id INT PRIMARY KEY     NOT NULL," \
          "name           TEXT    NOT NULL," \
          "telephone      TEXT    NOT NULL);";

    /* Execute SQL statement */
    //回调函数在insert和delete时可以设为NULL
    rc = sqlite3_exec(db, sql, NULL, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Table created successfully\n");
    }
}

//打开数据库
void SqlController::OpenDatabase()
{
    int rc;

    //sqlite3_open()返回值SQLITE_OK
    rc = sqlite3_open("test.db", &db);

    if(rc) //数据库打开失败
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    else  //打开成功
    {
        fprintf(stderr, "Opened database successfully\n");
    }
}

//关闭数据库
void SqlController::closeDatabase()
{
    sqlite3_close(db);
}

//添加数据
int SqlController::addData(int id, string name,string telephone)
{
    char *zErrMsg = 0;
    char sql[100];
    int rc;

    /* Create SQL statement */
    snprintf(sql, 100, "INSERT INTO test VALUES(%d, '%s', '%s');", id, name.c_str(), telephone.c_str());
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }

    return 1;
}

int SqlController::deleteid(int id)
{
    char *zErrMsg = 0;
    int rc;
    char sql[50];
    const char* data = "Callback function called";

    /* Create merged SQL statement */
    sprintf(sql, "DELETE from test where ID = %d", id);

    cout << sql << endl;
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    }
    else
    {
        fprintf(stdout, "Operation done successfully\n");
    }

    return 1;
}

int SqlController::select(int id)
{
    int rc;
    char sql[50];
    char *zErrMsg = 0;

    sprintf(sql, "select *from test where id=%d", id);
    rc = sqlite3_exec(db, sql, callback, NULL, &zErrMsg);
    if(rc != SQLITE_OK)
    {
        printf("select is error: %s\n", zErrMsg);
    }

    return 1;
}

int SqlController::update(int id, string name, string telephone)
{
    char *zErrMsg = 0;
    int rc;
    char sql[100];

    /* Create SQL statement */
    snprintf(sql, 100, "UPDATE test set name = '%s', telephone = '%s' where id = %d;",name.c_str(), telephone.c_str(), id);

    cout << sql << endl;
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 0;
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }

    return 1;
}

void SqlController::show()
{
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    const char* data = "Callback function called";

    /* Create SQL statement */
    sql = "SELECT * from test";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, NULL, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Operation done successfully\n");
    }

}

