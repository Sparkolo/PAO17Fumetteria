#ifndef ADMIN_H
#define ADMIN_H
#include"user.h"
#include"database_user.h"
#include"database_stuff.h"

class DatabaseUser;

class Admin: public User{
public:
    Admin(QString nam="",QString surn="",QString usern="",QString pass="");

    QString getType()const;

    virtual bool hasStarred() const;
    virtual bool hasUserList()const;
    virtual bool hasManagement()const;

    virtual void saveUser(QXmlStreamWriter& r);
};

#endif // ADMIN_H
