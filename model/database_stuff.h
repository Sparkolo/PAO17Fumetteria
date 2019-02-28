#ifndef DATABASE_STUFF_H
#define DATABASE_STUFF_H
#include<QMessageBox>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>
#include<iostream>
#include<QFile>
#include<QXmlStreamReader>
#include<list>
#include"nerd_stuff.h"
#include"comic_book.h"
#include"dvd.h"
#include"action_figure.h"

class DatabaseStuff{
private:
    static QString filename;
    std::list<NerdStuff *> dbStuff;

public:
    DatabaseStuff();
    ~DatabaseStuff();

    void load();
    void saveClose();
    bool isEmpty() const;
    void addElementStuff(NerdStuff*st);
    void removeElementStuff(NerdStuff*st);
    NerdStuff* getStuff(QString ID)const;
    const std::list<NerdStuff *> getAllStuff()const;
};

#endif // DATABASE_STUFF_H
