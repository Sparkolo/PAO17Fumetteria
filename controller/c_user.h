#ifndef USER_C_H
#define USER_C_H
#include<QObject>
#include<QMessageBox>
#include"model/database_user.h"
#include"view/v_manage_user.h"


class CUser:public QObject
{
private:
    Q_OBJECT
    DatabaseUser * UserList;
    VManageUser * vUser;

public:
    CUser(DatabaseUser * dbUs, QObject* parent=0);
    void refreshVUser(VManageUser * vGUs);

public slots:
    void receiveCreateUser(User *u);
    void receiveEditUser(User*u, QString name, QString surname, QString username, QString pass, QString type);
    void receiveDeleteUser(User *u);
};

#endif // USER_C_H
