#include "dvd.h"

// CONSTRUCTOR
Dvd::Dvd(QString cod, bool lim, double pr, QString tit, QString prod, QString dt, int len, bool res): NerdStuff(cod,lim,pr), title(tit),producer(prod),dvdType(dt),filmLength(len),isAgeRes(res){}

// GET METHODS
QString Dvd::getTitle()const{return title;}
QString Dvd::getProducer()const{return producer;}
QString Dvd::getDVDType()const{return dvdType;}
int Dvd::getFilmLength()const{return filmLength;}
bool Dvd::getAgeRes()const{return isAgeRes;}

//SET METHODS
void Dvd::setTitle(QString newTitle){ title=newTitle; }
void Dvd::setProducer(QString newProducer){ producer=newProducer; }
void Dvd::setDVDType(QString newType){ dvdType=newType; }
void Dvd::setFilmLength(int newPiano){ filmLength=newPiano; }
void Dvd::setAgeRes(bool newRes){ isAgeRes=newRes; }

// PURE VIRTUAL
QString Dvd::getType() const{
    return "DVD";
}

double Dvd::getPrice()const{
   return (getBasePrice()+0.99)*(1+getIVA()+0.1);
}

// CLASS METHODS
void Dvd::loadStuff(QXmlStreamReader & r){
    NerdStuff::loadStuff(r);
    r.readNextStartElement();
    if(r.name()=="title")this->setTitle(r.readElementText());
    r.readNextStartElement();
    if(r.name()=="producer")this->setProducer(r.readElementText());
    r.readNextStartElement();
    if(r.name()=="dvdtype")this->setDVDType(r.readElementText());
    r.readNextStartElement();
    if(r.name()=="filmlength")this->setFilmLength(r.readElementText().toInt());
    r.readNextStartElement();
    if(r.name()=="ageres")this->setAgeRes(r.readElementText().toInt());
}

void Dvd::saveStuff(QXmlStreamWriter & w){
    w.writeStartElement("dvd");
    NerdStuff::saveStuff(w);
    w.writeTextElement("title", getTitle());
    w.writeTextElement("producer", getProducer());
    w.writeTextElement("dvdtype", getDVDType());
    w.writeTextElement("filmlength", QString::number(getFilmLength()));
    w.writeTextElement("ageres", QString::number(getAgeRes()));
    w.writeEndElement();
}
