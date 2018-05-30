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

    //sqlite3_open()����ֵSQLITE_OK
    rc = sqlite3_open("test.db", &db);

    if(rc) //���ݿ��ʧ��
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }
    else  //�򿪳ɹ�
    {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    //�ж��Ƿ��Ѿ����ڱ�
    sql = "CREATE TABLE if not exists test("  \
          "id INT PRIMARY KEY     NOT NULL," \
          "name           TEXT    NOT NULL," \
          "telephone      TEXT    NOT NULL);";

    /* Execute SQL statement */
    //�ص�������insert��deleteʱ������ΪNULL
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


//�������
int SqlController::addData(int id, string name,string telephone)
{
    char *zErrMsg = 0;
    char sql[100];
    int rc;

    /* Create SQL statement */
    snprintf(sql, 100, "INSERT INTO test VALUES(%d, '%s', '%s');", id, name.c_str(), telephone.c_str());
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
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
//    const char* data = "Callback function called";

    /* Create merged SQL statement */
    sprintf(sql, "DELETE from test where ID = %d", id);

    cout << sql << endl;
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
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
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
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
//    const char* data = "Callback function called";

    /* Create SQL statement */
    sql = "SELECT * from test";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, NULL, &zErrMsg);
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

