#ifndef GOLD_USER_H
#define GOLD_USER_H
#include <list>
#include "user.h"
#include "database_stuff.h"
#include "nerd_stuff.h"

class NerdStuff;

class GoldUser: public User{
private:
    std::list<NerdStuff *> starFirst;

public:
    GoldUser(QString nam="",QString surn="",QString usern="",QString pass="");
    virtual ~GoldUser();

    QString getType()const;
    virtual bool hasStarred() const;
    virtual bool hasUserList()const;
    virtual bool hasManagement()const;

    void addStarred(NerdStuff *st);
    void removeStarred(QString IDst);
    bool checkStarred(NerdStuff *c);
    std::list<NerdStuff *> getStarredStuff();

    virtual void saveUser(QXmlStreamWriter& r);
};

#endif // GOLD_USER_H
