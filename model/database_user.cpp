#include "database_user.h"

// STATIC FIELD
QString DatabaseUser::filename="databaseutenti.xml";

// CONSTRUCTOR
DatabaseUser::DatabaseUser(){
    load();
    if(this->isEmpty()){
        User * newAdmin=new Admin("Gestore","della Fumetteria","admin","admin");
        dbUser.push_back(newAdmin);
        QMessageBox::information(0,"Attenzione", "Nessun utente rilevato, verrà generato un amministratore");
    }
}

// DESTRUCTOR
DatabaseUser::~DatabaseUser(){
    auto it=dbUser.begin();
    for(;it!=dbUser.end();++it)
    {
        delete *it;
        it=dbUser.erase(it);
        it--;
    }
}

// CLASS METHODS
void DatabaseUser::load() {
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly)){
        QXmlStreamReader xmlReader(&file);
        xmlReader.readNextStartElement();

        while(!xmlReader.atEnd())
        {
            User* us=nullptr;
            if(xmlReader.name()=="admin") us=new Admin;
            else if(xmlReader.name()=="gold") us=new GoldUser;
            else if(xmlReader.name()=="base") us=new BaseUser;

            if(us)
            {
                us->loadUser(xmlReader);
                dbUser.push_back(us);
            }
            xmlReader.readNextStartElement();
        }
    }
    else{
        QMessageBox::warning(0,"File mancanti","Creazione file di default");
    }
}

void DatabaseUser::saveClose(){
    QFile file(filename);
    file.open(QFile::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("utenti");

    auto it=dbUser.begin();
    for(;it!=dbUser.end();++it){
        (*it)->saveUser(xmlWriter);
        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
}

bool DatabaseUser::isEmpty() const{
    if(dbUser.size()==0) return true;
    return false;
}

void DatabaseUser::addElementUser(User *u){
  User * newUser=getUser(u->getUsername());
  if(newUser){
      QMessageBox::warning(0,"Errore inserimento utente", "L'username deve essere unico, username già presente");
      delete u;
      u=nullptr;
  }
  else{
     dbUser.push_back(u);
     QMessageBox::information(0,"Inserimento utente", "Inserimento avvenuto correttamente");
  }
}

void DatabaseUser::removeElementUser(User *u){
    auto it=dbUser.begin();
    for(;it!=dbUser.end();++it){
        if((*it)->getUsername()==u->getUsername()){
            delete *it;
            it=dbUser.erase(it);
            it--;
        }
    }
}

User *DatabaseUser::getUser(const QString &us) {
    auto it=dbUser.begin();
    User *tmp=nullptr;
    for(;it!=dbUser.end();++it){
       if((*it)->getUsername()==us){
          tmp= *it;
       }
    }
    return tmp;
}

const list<User *> DatabaseUser::getAllUser() const{
    list<User*> tmpUser;
    for(auto it=dbUser.begin();it!=dbUser.end();++it){
        tmpUser.push_back(*it);
    }
    return tmpUser;
}

bool DatabaseUser::findUsername(const QString &usern){
 bool found=false;

 auto it=dbUser.begin();
 for(;it!=dbUser.end()&&!found;++it){
     if((*it)->getUsername()==usern){
         found=true;
     }
 }
 return found;
}

User* DatabaseUser::checkUser(const QString &us, const QString &pass){
    User* loggedUser=nullptr;
    auto it=dbUser.begin();
    bool foundAdmin=0;

    for(;it!=dbUser.end();++it){
        if(((*it)->getUsername()==us)&&((*it)->getPassword()==pass)){
            loggedUser=(*it);
        }
        if((*it)->getType()=="admin"){
            foundAdmin=1;
        }
    }
    if(!foundAdmin){

        if(("admin"==us)&&("admin"==pass)){
            loggedUser=new Admin("admin","admin","admin","admin");
            dbUser.push_back(loggedUser);
        }
    }
    return loggedUser;
}

void DatabaseUser::changeUserType(User *u, QString newType){
    User *tmpUser=nullptr;
    if(newType=="admin"){
        tmpUser=new Admin(u->getName(),u->getSurname(),u->getUsername(),u->getPassword());
    }
    else{
        if(newType=="Gold"){
            tmpUser=new GoldUser(u->getName(),u->getSurname(),u->getUsername(),u->getPassword());
        }
        else if(newType=="Base"){
            tmpUser=new BaseUser(u->getName(),u->getSurname(),u->getUsername(),u->getPassword());
        }
    }

    if(tmpUser){
        removeElementUser(u);
        dbUser.push_back(tmpUser);
    }
}
