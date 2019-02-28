#include "v_starred.h"

// CONSTRUCTOR
VStarred::VStarred(User *us, DatabaseStuff *st, QWidget *parent) :
      QDialog(parent),us(us), stuffList(st){
    setWindowFlags(windowFlags()  & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Preferiti");
    setFixedHeight(350);
    setFixedWidth(574);
    stuffLayout=new QVBoxLayout();
    stuffGrid=new QGridLayout;
    myList=new QTableWidget();

    setModal(1);

    myList->setSelectionMode(QAbstractItemView::SingleSelection);
    myList->setSelectionBehavior(QAbstractItemView::SelectRows);
    myList->setRowCount(0);
     QStringList tableHeader;
     myList->setColumnCount(5);
     myList->setColumnWidth(0,60);
     myList->setColumnWidth(1,213);
     myList->setColumnWidth(2,100);
     myList->setColumnWidth(3,80);
     myList->setColumnWidth(4,80);
     myList->setMaximumWidth(554);

     tableHeader<<"ID"<<"Articolo"<<"Tipo"<<"Limited"<<"Prezzo";

     myList->setHorizontalHeaderLabels(tableHeader);

     myList->setEditTriggers(QAbstractItemView::NoEditTriggers);

     stuffGrid->addWidget(myList,0,0);
     stuffLayout->addLayout(stuffGrid);
     setLayout(stuffLayout);
     addListAllStuff(us);

     connect(myList,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doubleClick(int)));
}

// CLASS METHODS
void VStarred::addItemStuff(int r, NerdStuff *st){
    myList->setItem(r,0,new QTableWidgetItem(st->getInventory()));

    if(st->getType()=="Fumetto")
        myList->setItem(r,1,new QTableWidgetItem(static_cast<ComicBook*>(st)->getTitle()));
    else
        if(st->getType()=="DVD")
            myList->setItem(r,1,new QTableWidgetItem(static_cast<Dvd*>(st)->getTitle()));
    else
        if(st->getType()=="Fumetto")
            myList->setItem(r,1,new QTableWidgetItem(static_cast<ActionFigure*>(st)->getName()));

    myList->setItem(r,2,new QTableWidgetItem(st->getType()));

    QTableWidgetItem *lim = new QTableWidgetItem;
    if(st->getLimited()==0)lim->setText("No");
    else lim->setText("Sì");
    myList->setItem(r,3,lim);
    myList->setItem(r,4,new QTableWidgetItem(QString::number(st->getPrice())));
}

void VStarred::addListAllStuff(User *u){
    int row=0;

    std::list<NerdStuff*> lst=dynamic_cast<GoldUser *>(u)->getStarredStuff();
    std::list<NerdStuff*>::const_iterator it=lst.begin();

    if(it==lst.end())
        this->close();

    for(;it!=lst.end();it++){

        if(*it){
            myList->setRowCount(row+1);
            addItemStuff(row,*it);
            row++;
        }
    }
}

// SLOTS
void VStarred::doubleClick(int x)
{

    GoldUser *h= dynamic_cast<GoldUser *>(us);
    askStar=new VStarredAsk(h,stuffList->getStuff((myList->item(x,0))->text()));
    connect(askStar,SIGNAL(refreshStarredList()),this,SLOT(refreshList()));
    askStar->setAskRemove();
    emit disableMainWindow();
    askStar->show();
}

void VStarred::refreshList()
{
  myList->setRowCount(0);
  addListAllStuff(us);
  myList->show();
}
