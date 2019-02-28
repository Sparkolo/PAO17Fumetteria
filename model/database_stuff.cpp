#include "database_stuff.h"

// STATIC FIELD
QString DatabaseStuff::filename="databasestuff.xml";

// CONSTRUCTOR
DatabaseStuff::DatabaseStuff(){load();}

// DESTRUCTOR
DatabaseStuff::~DatabaseStuff(){
    auto it=dbStuff.begin();
    for(;it!=dbStuff.end();++it)
    {
        delete *it;
        it=dbStuff.erase(it);
        it--;
    }
}

// CLASS METHODS
void DatabaseStuff::load(){
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly)){
        QXmlStreamReader xmlReader(&file);
        xmlReader.readNextStartElement();

        while(!xmlReader.atEnd()){
            NerdStuff * t=nullptr;
            if(xmlReader.name()=="comicbook"){t=new ComicBook;}
            else if(xmlReader.name()=="dvd"){t=new Dvd;}
            else if(xmlReader.name()=="actionfigure"){t=new ActionFigure;}
            if(t){
                t->loadStuff(xmlReader);
                xmlReader.readNextStartElement();
                dbStuff.push_back(t);
            }
            xmlReader.readNextStartElement();
        }
    }
}

void DatabaseStuff::saveClose(){

    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("nerdstuff");

    for(auto it=dbStuff.begin();it!=dbStuff.end();++it){
        (*it)->saveStuff(xmlWriter);
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
}

bool DatabaseStuff::isEmpty() const {
    return dbStuff.size();
}

void DatabaseStuff::addElementStuff(NerdStuff *st)
{
       dbStuff.push_back(st);
}

void DatabaseStuff::removeElementStuff(NerdStuff *st){
    auto it=dbStuff.begin();
    for(;it!=dbStuff.end();++it)
    {
        if((*it)->getInventory()==st->getInventory())
        {
            delete *it;
            it=dbStuff.erase(it);
            it--;
        }
    }
}

NerdStuff* DatabaseStuff::getStuff(QString ID)const{
    auto it=dbStuff.begin();
    NerdStuff *st=nullptr;
    for(;it!=dbStuff.end();++it){
       if((*it)->getInventory()==ID){
          st= *it;
       }
    }
    return st;
}

const std::list<NerdStuff *> DatabaseStuff::getAllStuff() const{
    std::list<NerdStuff*> tmpSt;
    for(auto it=dbStuff.begin();it!=dbStuff.end();++it){
        tmpSt.push_back(*it);
    }
    return tmpSt;
}
