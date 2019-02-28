
#ifndef COMICBOOK_H
#define COMICBOOK_H
#include<QString>
#include"nerd_stuff.h"

class ComicBook: public NerdStuff{
private:
    QString title;
    QString author;
    QString comicType;
    int volumeNumber;
    int pageNumber;

public:
    ComicBook(QString cod="", bool lim =false, double pr=0, QString tit="", QString aut ="", QString ct="", int vol=0, int pag=0 );

    virtual double getPrice()const;
    virtual QString getType()const;

    QString getTitle()const;
    QString getAuthor()const;
    QString getComicType()const;
    int getVolNumber()const;
    int getPageNumber()const;

    void setTitle(QString newTitle);
    void setAuthor(QString newAuth);
    void setComicType(QString newType);
    void setVolNumber(int newVol);
    void setPageNumber(int newPage);

    virtual void loadStuff(QXmlStreamReader & r);
    virtual void saveStuff(QXmlStreamWriter & w);
};

#endif // COMICBOOK_H
