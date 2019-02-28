#ifndef DATABASE_USER_H
#define DATABASE_USER_H
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<iostream>
#include<QString>
#include<list>
#include"admin.h"
#include"gold_user.h"
#include"base_user.h"

using std::list;

class DatabaseUser{
private:
    static QString filename;
    list<User *> dbUser;
public:
    DatabaseUser();
    ~DatabaseUser();

    void load();
    void saveClose();
    bool isEmpty() const;
    void addElementUser(User*u);
    void removeElementUser(User*u);
    User* getUser(const QString &us);
    const list<User*> getAllUser()const;
    bool findUsername(const QString &usern);
    User *checkUser(const QString& us, const QString&pass);
    void changeUserType(User *u, QString newType);
};

#endif // DATABASE_USER_H
