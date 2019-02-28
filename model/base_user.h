#ifndef BASE_USER_H
#define BASE_USER_H
#include"user.h"

class BaseUser:public User{
public:  
    BaseUser(QString nam="",QString surn="",QString usern="",QString pass="");

    QString getType()const;

    virtual bool hasStarred() const;
    virtual bool hasUserList()const;
    virtual bool hasManagement()const;

    virtual void saveUser(QXmlStreamWriter& r);
};

#endif // BASE_USER_H
