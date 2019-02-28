#ifndef NERDSTUFF_H
#define NERDSTUFF_H
#include<QString>
#include<QMessageBox>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include"user.h"

class NerdStuff{
private:
    static double IVA;

    QString inventoryID;
    bool isLimited;
    double basePrice;

public:
    NerdStuff(QString cod ="", bool lim =false, double pr=0);

    virtual ~NerdStuff();
    virtual QString getType()const=0;
    virtual double getPrice() const=0;

    QString getInventory()const;
    bool getLimited()const;
    double getBasePrice() const;
    double getIVA() const;

    void setInventory(QString nuovoCod);
    void setLimited(bool nuovoOcc);
    void setBasePrice(double nuovoPr);

    virtual void loadStuff(QXmlStreamReader & r);
    virtual void saveStuff(QXmlStreamWriter & w);
};

#endif // NERDSTUFF_H
