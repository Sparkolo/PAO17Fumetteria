#include "user.h"

// CONSTRUCTOR
User::User(QString nam, QString surn, QString usern, QString pass):
    name(nam), surname(surn), username(usern), password(pass){}

// GET METHODS
QString User::getName()const{
    return name;
}
QString User::getSurname()const{
    return surname;
}
QString User::getUsername()const{
    return username;
}
QString User::getPassword()const{
    return password;
}

// SET METHODS
void User::setUsername(const QString &newUsername){
    username=newUsername;
}

void User::setName(const QString &newName){
    name=newName;
}

void User::setSurname(const QString &newSurname){
    surname=newSurname;
}

void User::setPassword(const QString &newPass){
    password=newPass;
}

// CLASS METHODS
void User::saveUser(QXmlStreamWriter &xmlWriter){
    xmlWriter.writeTextElement("nome",getName());
    xmlWriter.writeTextElement("cognome",getSurname());
    xmlWriter.writeTextElement("username",getUsername());
    xmlWriter.writeTextElement("password",getPassword());
}

void User::loadUser(QXmlStreamReader &xmlReader){
    xmlReader.readNextStartElement();
    if(xmlReader.name()=="nome") {
        setName(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name()=="cognome") {
        setSurname(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name()=="username") {
        setUsername(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
    if(xmlReader.name()=="password") {
        setPassword(xmlReader.readElementText());
        xmlReader.readNextStartElement();
    }
}

