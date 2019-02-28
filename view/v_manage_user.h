#ifndef  MANAGE_USER_V_H
#define MANAGE_USER_V_H
#include<QDialog>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QString>
#include<QComboBox>
#include"model/database_user.h"

class VManageUser:public QDialog{
private:
    Q_OBJECT
    User *us;
    User *userToEdit;

    // LABEL
    QLabel *lUsername;
    QLabel *lName;
    QLabel *lSurname;
    QLabel *lPassword;
    QLabel *lType;
    QLabel *lMyType;

    // USER
    QLineEdit *cName;
    QLineEdit* cSurname;
    QLineEdit* tUsername;
    QLineEdit* tPassword;
    QComboBox *cType;

    // BUTTONS
    QPushButton*pSaveEdit;
    QPushButton*pDelete;
    QPushButton*pCreate;

    QVBoxLayout *userLayout;
    QGridLayout * userGrid;

public:
    VManageUser(User * us, User *usMod);

    void addLayout();
    void setLayoutCreate();
    void setLayoutEdit();
    void resetUsername();
    void empty();

public slots:
    void saveCreateUser();
    void saveEditUser();
    void saveDeleteUser();

signals:
    void sendCreateUser(User*);
    void sendEditUser(User*,QString,QString,QString,QString, QString);
    void sendDeleteUser(User*);
    void logout();
};

#endif // MANAGE_USER_V_H
