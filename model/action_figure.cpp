#include "action_figure.h"

// CONSTRUCTOR
ActionFigure::ActionFigure(QString cod,  bool lim, double pr, QString nam, QString manuf, int w, int h, int d):NerdStuff(cod,lim,pr), name(nam), manufacturer(manuf) {
    size[0]=w;
    size[1]=h;
    size[2]=d;
}

// GET METHODS
QString ActionFigure::getName()const{ return name;}
QString ActionFigure::getManufacturer()const{return manufacturer;}
int ActionFigure::getWidth()const{return size[0];}
int ActionFigure::getHeight()const{return size[1];}
int ActionFigure::getDepth()const{return size[2];}

// SET METHODS
void ActionFigure::setName(QString newName){ name=newName; }
void ActionFigure::setManufacturer(QString newManufaturer){ manufacturer=newManufaturer;  }
void ActionFigure::setWidth(int newWidth){ size[0]=newWidth; }
void ActionFigure::setHeight(int newHeight){ size[1]=newHeight; }
void ActionFigure::setDepth(int newDepth){ size[2]=newDepth;}

// PURE VIRTUAL
QString ActionFigure::getType() const{
    return "Action Figure";
}

double ActionFigure::getPrice()const{
    return (getBasePrice()+5)*(1+getIVA());
}

// CLASS METHODS
QString ActionFigure::getDimension() const {
    if(size[0]*size[1]*size[2] < 125)
        return "Piccola";
    else if(size[0]*size[1]*size[2] < 1000)
        return "Media";
    else
        return "Grande";
}

void ActionFigure::loadStuff(QXmlStreamReader & r){
    NerdStuff::loadStuff(r);
    r.readNextStartElement();
    if(r.name()=="name")this->setName(r.readElementText());
    r.readNextStartElement();
    if(r.name()=="manufacturer")this->setManufacturer(r.readElementText());
    r.readNextStartElement();
    if(r.name()=="width")this->setWidth(r.readElementText().toInt());
    r.readNextStartElement();
    if(r.name()=="height")this->setHeight(r.readElementText().toInt());
    r.readNextStartElement();
    if(r.name()=="depth")this->setDepth(r.readElementText().toInt());
}

void ActionFigure::saveStuff(QXmlStreamWriter & w){
    w.writeStartElement("actionfigure");
    NerdStuff::saveStuff(w);
    w.writeTextElement("name",getName());
    w.writeTextElement("manufacturer",getManufacturer());
    w.writeTextElement("width",QString::number(getWidth()));
    w.writeTextElement("height",QString::number(getHeight()));
    w.writeTextElement("depth",QString::number(getDepth()));
    w.writeEndElement();
}
