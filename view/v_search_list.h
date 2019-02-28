#ifndef  SEARCH_LIST_V_H
#define SEARCH_LIST_V_H
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include"model/database_stuff.h"
#include"model/database_user.h"
#include"view/v_manage_user.h"

class VSearchList:public QTableWidget{
private:
    Q_OBJECT
    DatabaseStuff * stuffList;
    DatabaseUser * userList;

public:
    VSearchList(DatabaseStuff *dbSt, DatabaseUser*dbUs, QWidget *parent=0);

    void viewUser();
    void addListAllUser(QString tex, QString typ);
    void addItemUser(int row, User *us);

    void viewStuff();
    void addListAllStuff(QString tex, QString o1, QString o2);
    void addItemStuff(int r, NerdStuff *st);
};

#endif // SEARCH_LIST_V_H
