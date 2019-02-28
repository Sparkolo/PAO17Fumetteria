#ifndef ACTION_FIGURE_H
#define ACTION_FIGURE_H
#include "nerd_stuff.h"


class ActionFigure : public NerdStuff
{
private:
    QString name;
    QString manufacturer;
    int size[3];

public:
    ActionFigure(QString cod="",  bool lim =false, double pr=0, QString nam="", QString manuf ="", int w=0, int h=0, int d=0 );

    virtual double getPrice()const;
    virtual QString getType()const;

    QString getName()const;
    QString getManufacturer()const;
    int getWidth()const;
    int getHeight()const;
    int getDepth()const;
    QString getDimension() const;

    void setName(QString newName);
    void setManufacturer(QString newManufacturer);
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    void setDepth(int newDepth);

    virtual void loadStuff(QXmlStreamReader & r);
    virtual void saveStuff(QXmlStreamWriter & w);
};

#endif // ACTION_FIGURE_H
