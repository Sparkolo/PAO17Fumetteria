#include "c_nerd_stuff.h"

// COSTRUTTORE
CNerdStuff::CNerdStuff(DatabaseStuff *dbTav, QObject *parent):  QObject(parent),StuffList(dbTav) {}

// CLASS METHOD
void CNerdStuff::refreshVStuff(VManageStuff *vSt){
    vStuff=vSt;

    connect(vStuff,SIGNAL(sendCreateStuff(NerdStuff*)),this,SLOT(receiveCreateStuff(NerdStuff*)));

    connect(vStuff,SIGNAL(sendEditComicBook(ComicBook*, bool, double, QString, QString, QString, int, int)),
            this,SLOT(receiveEditComicBook(ComicBook*,bool,double,QString,QString,QString,int,int)));

    connect(vStuff,SIGNAL(sendEditDVD(Dvd*,bool, double, QString, QString, QString, int, bool)),
            this,SLOT(receiveEditDVD(Dvd*, bool, double, QString, QString, QString, int, bool)));

    connect(vStuff,SIGNAL(sendEditActionFigure(ActionFigure*,bool,double, QString, QString, int, int, int)),
            this,SLOT(receiveEditActionFigure(ActionFigure*, bool, double, QString, QString, int, int, int)));

    connect(vStuff,SIGNAL(sendDeleteStuff(NerdStuff*)),this,SLOT(receiveDeleteStuff(NerdStuff*)));
}

// SLOTS
void CNerdStuff::receiveCreateStuff(NerdStuff *t){

    if(StuffList->getStuff(t->getInventory())){
        QMessageBox::warning(0,"Errore","Impossibile aggiungere l'articolo', esiste già un articolo con lo stesso ID in inventario.");
        delete t;
        t=nullptr;
        vStuff->resetStuffID();
    }
    else{
        StuffList->addElementStuff(t);
        vStuff->resetStuffID();
        QMessageBox::information(0,"Inserimento articolo", "Inserimento avvenuto con successo!");
    }
}


void CNerdStuff::receiveEditComicBook(ComicBook * t, bool lim, double pr, QString tit, QString aut, QString typ, int vol, int pag){
  bool modified=0;

  if(t->getLimited()!=lim){
      t->setLimited(lim);
      modified=1;
  }
  if(t->getBasePrice()!=pr){
      t->setBasePrice(pr);
      modified=1;
  }
  if(t->getTitle()!=tit){
      t->setTitle(tit);
      modified=1;
  }
  if(t->getAuthor()!=aut){
      t->setAuthor(aut);
      modified=1;
  }
  if(t->getComicType()!=typ){
      t->setComicType(typ);
      modified=1;
  }
  if(t->getVolNumber()!=vol){
      t->setVolNumber(vol);
      modified=1;
  }
  if(t->getPageNumber()!=pag){
      t->setPageNumber(pag);
      modified=1;
  }
  if(modified==1){
      QMessageBox::warning(0,"Modifica Fumetto","Modifiche salvate con successo!");
      vStuff->close();
  }
  else
      QMessageBox::warning(0,"Errore","Nessuna modifica rilevata.");
}


void CNerdStuff::receiveEditDVD(Dvd * t, bool lim, double pr, QString tit, QString pro, QString typ, int len, bool res){
  bool modifiche=0;

  if(t->getLimited()!=lim){
      t->setLimited(lim);
      modifiche=1;
  }
  if(t->getBasePrice()!=pr){
      t->setBasePrice(pr);
      modifiche=1;
  }
  if(t->getTitle()!=tit){
      t->setTitle(tit);
      modifiche=1;
  }
  if(t->getProducer()!=pro){
      t->setProducer(pro);
      modifiche=1;
  }
  if(t->getDVDType()!=typ){
      t->setDVDType(typ);
      modifiche=1;
  }
  if(t->getFilmLength()!=len){
      t->setFilmLength(len);
      modifiche=1;
  }
  if(t->getAgeRes()!=res){
      t->setAgeRes(res);
      modifiche=1;
  }
  if(modifiche==1){
      QMessageBox::warning(0,"Modifica DVD","Modifiche salvate con successo!");
      vStuff->close();
  }
  else
      QMessageBox::warning(0,"Errore","Nessuna modifica rilevata.");
}


void CNerdStuff::receiveEditActionFigure(ActionFigure * t, bool lim, double pr, QString nam, QString manuf, int w, int h, int d){
  bool modifiche=0;

  if(t->getLimited()!=lim){
      t->setLimited(lim);
      modifiche=1;
  }
  if(t->getBasePrice()!=pr){
      t->setBasePrice(pr);
      modifiche=1;
  }
  if(t->getName()!=nam){
      t->setName(nam);
      modifiche=1;
  }
  if(t->getManufacturer()!=manuf){
      t->setManufacturer(manuf);
      modifiche=1;
  }
  if(t->getWidth()!=w){
      t->setWidth(w);
      modifiche=1;
  }
  if(t->getHeight()!=h){
      t->setHeight(h);
      modifiche=1;
  }
  if(t->getDepth()!=d){
      t->setDepth(d);
      modifiche=1;
  }
  if(modifiche==1){
      QMessageBox::warning(0,"Modifica Action Figure","Modifiche salvate con successo!");
      vStuff->close();
  }
  else
      QMessageBox::warning(0,"Errore","Nessuna modifica rilevata.");
}


void CNerdStuff::receiveDeleteStuff(NerdStuff *t){

    vStuff->close();
    StuffList->removeElementStuff(t);
    QMessageBox::warning(0,"Eliminazione articolo","Articolo eliminato con successo!");

}
