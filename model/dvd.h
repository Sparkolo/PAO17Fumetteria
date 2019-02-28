#ifndef DVD_H
#define DVD_H
#include<QString>
#include"nerd_stuff.h"


class Dvd: public NerdStuff{
private:
    QString title;
    QString producer;
    QString dvdType;
    int filmLength;
    bool isAgeRes;

public:
    Dvd(QString cod="", bool lim=0, double pr=0, QString tit="", QString prod="", QString dt="", int len=0,  bool res=0);

    virtual double getPrice()const;
    virtual QString getType()const;

    QString getTitle() const;
    QString getProducer() const;
    QString getDVDType() const;
    int getFilmLength() const;
    bool getAgeRes() const;

    void setTitle(QString newTitle);
    void setProducer(QString newProducer);
    void setDVDType(QString newType);
    void setFilmLength(int newPiano);
    void setAgeRes(bool newRes);

    virtual void loadStuff(QXmlStreamReader & r);
    virtual void saveStuff(QXmlStreamWriter & w);
};

#endif // DVD_H
