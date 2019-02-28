#include "base_user.h"

// CONSTRUCTOR
BaseUser::BaseUser(QString nam, QString surn, QString usern, QString pass):User(nam,surn,usern,pass){}

// PURE VIRTUAL
QString BaseUser::getType()const{return "Base";}

bool BaseUser::hasStarred() const{
    return false;
}

bool BaseUser::hasUserList() const{
    return false;
}

bool BaseUser::hasManagement() const{
    return false;
}

// VIRTUAL
void BaseUser::saveUser(QXmlStreamWriter & r){
    r.writeStartElement("base");
    User::saveUser(r);
}
