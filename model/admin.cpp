#include "admin.h"

// CONSTRUCTOR
Admin::Admin(QString nam, QString surn, QString usern, QString pass):User(nam,surn,usern,pass){}

// PURE VIRTUAL
QString Admin::getType()const{return "admin";}

bool Admin::hasStarred() const{
    return false;
}

bool Admin::hasUserList() const{
    return true;
}

bool Admin::hasManagement() const{
    return true;
}

// VIRTUAL
void Admin::saveUser(QXmlStreamWriter &r){
    r.writeStartElement("admin");
    User::saveUser(r);
}
