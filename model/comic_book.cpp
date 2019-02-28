#include "comic_book.h"


// CONSTRUCTOR
ComicBook::ComicBook(QString cod,  bool lim, double pr, QString tit, QString aut, QString ct, int vol, int pag):NerdStuff(cod,lim,pr),title(tit),author(aut),comicType(ct),volumeNumber(vol),pageNumber(pag){}

// GET METHODS
QString ComicBook::getTitle()const{ return title;}
QString ComicBook::getAuthor()const{return author;}
QString ComicBook::getComicType()const{return comicType;}
int ComicBook::getVolNumber()const{return volumeNumber;}
int ComicBook::getPageNumber()const{return pageNumber;}

// SET METHODS
void ComicBook::setTitle(QString newTitle){ title=newTitle; }
void ComicBook::setAuthor(QString newAuth){ author=newAuth;  }
void ComicBook::setComicType(QString newType){ comicType=newType; }
void ComicBook::setVolNumber(int newVol){ volumeNumber=newVol; }
void ComicBook::setPageNumber(int newPage){ pageNumber=newPage;}

// PURE VIRTUAL
QString ComicBook::getType() const{
    return "Fumetto";
}

double ComicBook::getPrice()const{
   return (getBasePrice()+2.5)*(1+getIVA());
}

// CLASS METHODS
void ComicBook::loadStuff(QXmlStreamReader & r){
    NerdStuff::loadStuff(r);
    r.readNextStartElement();
    if(r.name()=="title")this->setTitle(r.readElementText());
    r.readNextStartElement();
    if(r.name()=="author")this->setAuthor(r.readElementText());
    r.readNextStartElement();
    if(r.name()=="comictype")this->setComicType(r.readElementText());
    r.readNextStartElement();
    if(r.name()=="volumenumber")this->setVolNumber(r.readElementText().toInt());
    r.readNextStartElement();
    if(r.name()=="pagenumber")this->setPageNumber(r.readElementText().toInt());
}

void ComicBook::saveStuff(QXmlStreamWriter & w){
    w.writeStartElement("comicbook");
    NerdStuff::saveStuff(w);
    w.writeTextElement("title",getTitle());
    w.writeTextElement("author",getAuthor());
    w.writeTextElement("comictype",getComicType());
    w.writeTextElement("volumenumber",QString::number(getVolNumber()));
    w.writeTextElement("pagenumber",QString::number(getPageNumber()));
    w.writeEndElement();
}
