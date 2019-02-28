#include "gold_user.h"

// CONSTRUCTOR
GoldUser::GoldUser(QString nam, QString surn, QString usern, QString pass):User(nam,surn,usern,pass){}

// DESTRUCTOR
GoldUser::~GoldUser()
{
    auto it=starFirst.begin();
    for(;it!=starFirst.end();++it){
            it=starFirst.erase(it);
            it--;
    }
}

// PURE VIRTUAL
QString GoldUser::getType()const{return "Gold";}

bool GoldUser::hasStarred() const{
    return true;
}

bool GoldUser::hasUserList() const{
    return false;
}

bool GoldUser::hasManagement() const{
    return false;
}

// CLASS METHODS
void GoldUser::removeStarred(QString IDst){
    auto it=starFirst.begin();
    for(;it!=starFirst.end();++it){
        if(IDst==(*it)->getInventory()){

            it=starFirst.erase(it);
            it--;
        }
    }
}
void GoldUser::addStarred(NerdStuff *st){
   if(st){
      starFirst.push_back(st);
   }
}

bool GoldUser::checkStarred(NerdStuff *c)
{
    bool b=false;
    auto it=starFirst.begin();
    for(;it!=starFirst.end() && !b;++it){
        if(c->getInventory()==(*it)->getInventory()){
            b=true;
        }
    }
    return b;
}
std::list<NerdStuff *> GoldUser::getStarredStuff(){
    std::list<NerdStuff*> tmpCons;
    for(auto it=starFirst.begin();it!=starFirst.end();++it){
        tmpCons.push_back(*it);
    }
    return tmpCons;
}


// VIRTUAL
void GoldUser::saveUser(QXmlStreamWriter &r){
    r.writeStartElement("gold");
    User::saveUser(r);
}
