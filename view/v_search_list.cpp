#include "v_search_list.h"

// CONSTRUCTOR
VSearchList::VSearchList(DatabaseStuff *dbSt, DatabaseUser *dbUs, QWidget *parent):
      QTableWidget(parent), stuffList(dbSt), userList(dbUs){

    setSelectionMode(QAbstractItemView::SingleSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);
}

// CLASS METHODS
void VSearchList::viewUser(){
    this->setRowCount(0);
    QStringList tableHeader;
    setColumnCount(4);
    setColumnWidth(0,243);
    setColumnWidth(1,240);
    setColumnWidth(2,240);
    setColumnWidth(3,240);
    setMaximumWidth(985);
    tableHeader<<"Username"<<"Tipo"<<"Nome"<<"Cognome";
    setHorizontalHeaderLabels(tableHeader);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void VSearchList::addListAllUser(QString tex, QString typ){
    int row=0;
    std::list<User*> listUser=userList->getAllUser();
    std::list<User*>::const_iterator it=listUser.begin();

    for(;it!=listUser.end();it++){
        if(typ=="Tutti"){
            if((*it)->getUsername().contains(tex) || (*it)->getName().contains(tex) || (*it)->getSurname().contains(tex)){
                setRowCount(row+1);
                addItemUser(row,*it);
                row++;
            }
        }
        else{

            if( (*it)->getType()==typ  && ((*it)->getUsername().contains(tex) || (*it)->getName().contains(tex) || (*it)->getSurname().contains(tex))){
                setRowCount(row+1);
                addItemUser(row,*it);
                row++;
            }
        }
    }
}

void VSearchList::addItemUser(int row, User*us){
    setItem(row,0,new QTableWidgetItem(us->getUsername()));
    setItem(row,1,new QTableWidgetItem(us->getType()));
    setItem(row,2,new QTableWidgetItem(us->getName()));
    setItem(row,3,new QTableWidgetItem(us->getSurname()));
}

void VSearchList::viewStuff(){
    setRowCount(0);
    setColumnCount(9);
    setColumnWidth(0,60);
    setColumnWidth(1,100);
    setColumnWidth(2,80);
    setColumnWidth(3,80);
    setColumnWidth(4,213);
    setColumnWidth(5,130);
    setColumnWidth(6,100);
    setColumnWidth(7,100);
    setColumnWidth(8,100);
    setMaximumWidth(985);

    setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void VSearchList::addListAllStuff(QString tex, QString o1, QString o2){
    int row=0;
    std::list<NerdStuff*> listStuff=stuffList->getAllStuff();
    std::list<NerdStuff*>::const_iterator it=listStuff.begin();
    QStringList tableHeader;

    if(o1=="Fumetto"){
        tableHeader<<"ID"<<"Tipo"<<"Limited"<<"Prezzo"<<"Titolo"<<"Autore"<<"Tipologia"<<"Volume"<<"Pagine";
        setHorizontalHeaderLabels(tableHeader);

        for(;it!=listStuff.end();it++){
            ComicBook* tmp1=dynamic_cast<ComicBook*>(*it);
            if((*it)->getType()==o1 && (tmp1->getInventory().contains(tex) || tmp1->getTitle().contains(tex) || tmp1->getAuthor().contains(tex))){
                if(o2!="Tutti") {
                    if(tmp1->getComicType()==o2) {
                        setRowCount(row+1);
                        addItemStuff(row,*it);
                        row++;
                    }
                }
                else {
                    setRowCount(row+1);
                    addItemStuff(row,*it);
                    row++;
                }
            }
        }
    }
    else if(o1=="DVD"){
        tableHeader<<"ID"<<"Tipo"<<"Limited"<<"Prezzo"<<"Titolo"<<"Regista"<<"Tipologia"<<"Durata"<<"V.M.18";
        setHorizontalHeaderLabels(tableHeader);

        for(;it!=listStuff.end();it++){
            Dvd* tmp2=dynamic_cast<Dvd*>(*it);
            if((*it)->getType()==o1 && (tmp2->getInventory().contains(tex) || tmp2->getTitle().contains(tex) || tmp2->getProducer().contains(tex))){
                if(o2!="Tutti") {
                    if(tmp2->getDVDType()==o2) {
                        setRowCount(row+1);
                        addItemStuff(row,*it);
                        row++;
                    }
                }
                else {
                    setRowCount(row+1);
                    addItemStuff(row,*it);
                    row++;
                }
            }
        }
    }
    else if(o1=="Action Figure"){
        tableHeader<<"ID"<<"Tipo"<<"Limited"<<"Prezzo"<<"Nome"<<"Produttore"<<"Larghezza"<<"Altezza"<<"Profondità";
        setHorizontalHeaderLabels(tableHeader);

        for(;it!=listStuff.end();it++){
            ActionFigure* tmp3=dynamic_cast<ActionFigure*>(*it);
            if((*it)->getType()==o1 && (tmp3->getInventory().contains(tex) || tmp3->getName().contains(tex) || tmp3->getManufacturer().contains(tex))){
                if(o2!="Tutte") {
                    if(tmp3->getDimension()==o2) {
                        setRowCount(row+1);
                        addItemStuff(row,*it);
                        row++;
                    }
                }
                else {
                    setRowCount(row+1);
                    addItemStuff(row,*it);
                    row++;
                }
            }
        }
    }
}

void VSearchList::addItemStuff(int r, NerdStuff *st){
    setItem(r,0,new QTableWidgetItem(st->getInventory()));
    setItem(r,1,new QTableWidgetItem(st->getType()));

    QTableWidgetItem *lim = new QTableWidgetItem;
    if(st->getLimited()==0)lim->setText("No");
    else lim->setText("Sì");
    setItem(r,2,lim);

    setItem(r,3,new QTableWidgetItem(QString::number(st->getPrice(),'f',2)));

    if(st->getType()=="Fumetto") {
        setItem(r,4,new QTableWidgetItem(static_cast<ComicBook*>(st)->getTitle()));
        setItem(r,5,new QTableWidgetItem(static_cast<ComicBook*>(st)->getAuthor()));
        setItem(r,6,new QTableWidgetItem(static_cast<ComicBook*>(st)->getComicType()));
        setItem(r,7,new QTableWidgetItem(QString::number(static_cast<ComicBook*>(st)->getVolNumber())));
        setItem(r,8,new QTableWidgetItem(QString::number(static_cast<ComicBook*>(st)->getPageNumber())));
    }
    else if(st->getType()=="DVD") {
        setItem(r,4,new QTableWidgetItem(static_cast<Dvd*>(st)->getTitle()));
        setItem(r,5,new QTableWidgetItem(static_cast<Dvd*>(st)->getProducer()));
        setItem(r,6,new QTableWidgetItem(static_cast<Dvd*>(st)->getDVDType()));
        setItem(r,7,new QTableWidgetItem(QString::number(static_cast<Dvd*>(st)->getFilmLength())));
        QTableWidgetItem * ageLim = new QTableWidgetItem;
        if(static_cast<Dvd*>(st)->getLimited()==0)
            ageLim->setText("No");
        else ageLim->setText("Sì");
        setItem(r,8,ageLim);
    }
    else if(st->getType()=="Action Figure") {
        setItem(r,4,new QTableWidgetItem(static_cast<ActionFigure*>(st)->getName()));
        setItem(r,5,new QTableWidgetItem(static_cast<ActionFigure*>(st)->getManufacturer()));
        setItem(r,6,new QTableWidgetItem(QString::number(static_cast<ActionFigure*>(st)->getWidth())));
        setItem(r,7,new QTableWidgetItem(QString::number(static_cast<ActionFigure*>(st)->getHeight())));
        setItem(r,8,new QTableWidgetItem(QString::number(static_cast<ActionFigure*>(st)->getDepth())));
    }
}
