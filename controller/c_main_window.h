#ifndef MAINWINDOW_C_H
#define MAINWINDOW_C_H
#include<QObject>
#include<QMessageBox>
#include"model/database_stuff.h"
#include"model/database_user.h"
#include"view/v_login.h"
#include"view/v_main_window.h"
#include"c_user.h"
#include"c_nerd_stuff.h"


class CMainWindow:public QObject {
private:
    Q_OBJECT
    DatabaseStuff * StuffList;
    DatabaseUser *UserList;
    User* loggedUser;

    VLogin * vLogin;
    VMainWindow * vMainWindow;

    CUser *cUser;
    CNerdStuff *cStuff;

public:
    CMainWindow(QObject *parent =0);
    ~CMainWindow();
    void launchLogin();

public slots:
     void testLogin(const QString&username, const QString&password);
     void refreshLogin();
     void refreshCUser(VManageUser * vGUser);
     void refreshCStuff(VManageStuff * vGStuff);
};

#endif // MAINWINDOW_C_H
