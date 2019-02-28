#include "nerd_stuff.h"

// STATIC FIELD
double NerdStuff::IVA=0.22;

// CONSTRUCTOR & DESTRUCTOR
NerdStuff::NerdStuff(QString cod,bool lim, double pr):  inventoryID(cod), isLimited(lim), basePrice(pr){}

NerdStuff::~NerdStuff(){}

// GET METHODS
QString NerdStuff::getInventory()const{ return inventoryID; }
bool NerdStuff::getLimited()const{ return isLimited; }
double NerdStuff::getBasePrice() const { return basePrice; }
double NerdStuff::getIVA() const {return IVA; }

// SET METHODS
void NerdStuff::setInventory(QString nuovoCod){ inventoryID=nuovoCod; }
void NerdStuff::setLimited(bool nuovoOcc){ isLimited=nuovoOcc; }
void NerdStuff::setBasePrice(double nuovoPr){ basePrice=nuovoPr; }

// CLASS METHODS
void NerdStuff::loadStuff(QXmlStreamReader & r){
    r.readNextStartElement();
    if(r.name()=="inventory")this->setInventory(r.readElementText());
    r.readNextStartElement();
    if(r.name()=="limited")this->setLimited(r.readElementText().toInt());
    r.readNextStartElement();
    if(r.name()=="baseprice")this->setBasePrice(r.readElementText().toDouble());
}

void NerdStuff::saveStuff(QXmlStreamWriter & w){
    w.writeTextElement("inventory",getInventory());
    w.writeTextElement("limited",QString::number(getLimited()));
    w.writeTextElement("baseprice",QString::number(getBasePrice()));
}
