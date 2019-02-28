#ifndef  MAINWINDOW_V_H
#define MAINWINDOW_V_H
#include<QMainWindow>
#include<QMenuBar>
#include<QAction>
#include<QApplication>
#include<QDesktopWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include"model/database_stuff.h"
#include"model/database_user.h"
#include"view/v_search_window.h"
#include"view/v_manage_user.h"
#include"view/v_starred.h"

class VMainWindow:public QMainWindow{
private:
    Q_OBJECT
    DatabaseStuff* StuffList;
    DatabaseUser * UserList;
    User * loggedUser;

    VSearchWindow * vSearch;
    VManageUser * vManageUser;
    VManageStuff * vManageStuff;
    VStarred *star;

    QMenu * userMenu ;
    QAction * mLogout;
    QAction * mManageProfile;
    QAction * mStarred;

    QMenu * managementMenu ;
    QAction * mUserAdd;
    QAction * mStuffAdd;

public:
    VMainWindow(DatabaseStuff * dbSt=0, DatabaseUser *dbUser=0,User *us=0, QWidget *parent =0);
    void addOptionMenu();
    void addSearch();
    void openManageUser();


public slots:
    void disconnection();
    void openAddUser();
    void openEditProfile();
    void openAddStuff();
    void openStarred();
    void refreshUser(VManageUser * vMUs);
    void disableWindow();

signals:
    void tryLogout();
    void refreshManageUser(VManageUser*);
    void refreshManageStuff(VManageStuff*);
};

#endif // MAINWINDOW_V_H
