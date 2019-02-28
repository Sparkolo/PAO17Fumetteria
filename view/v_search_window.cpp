#include "v_search_window.h"

// CONSTRUCTOR
VSearchWindow::VSearchWindow(DatabaseStuff *dbSt, DatabaseUser *dbUs, User *usLog, QWidget *parent):
     QWidget(parent),stuffList(dbSt), userList(dbUs), loggedUser(usLog){
    this->setAttribute(Qt::WA_DeleteOnClose);
    table=nullptr;

    userInfo=nullptr;
    stuffInfo=nullptr;
    addLayout();
}

// CLASS METHODS
void VSearchWindow::addLayout(){
    greetText=new QLabel("Ciao " +loggedUser->getName() + " " + loggedUser->getSurname() + "." + " Cosa stai cercando?");
    greetText->setFixedHeight(40);
    greetText->setStyleSheet("color: black; font: bold 22px;");

    tSearchText=new QLineEdit();
    tSearchText->setPlaceholderText("Cerca per ID, Titolo o Autore");

    cSearchChoice=new QComboBox();
    cSearchChoice->addItem("Articoli");
    cSearchChoice->addItem("Utenti");
    cSearchChoice->setFixedWidth(100);

    cStuffType=new QComboBox();
    cStuffType->addItem("Fumetto");
    cStuffType->addItem("DVD");
    cStuffType->addItem("Action Figure");
    cStuffType->setFixedWidth(150);

    cComicType=new QComboBox();
    cComicType->addItem("Tutti");
    cComicType->addItem("Comic");
    cComicType->addItem("Franco-Belga");
    cComicType->addItem("Italiano");
    cComicType->addItem("Manga");
    cComicType->setFixedWidth(150);

    cDVDType=new QComboBox();
    cDVDType->addItem("Tutti");
    cDVDType->addItem("Animazione");
    cDVDType->addItem("Live Action");
    cDVDType->setFixedWidth(150);

    cActionSize=new QComboBox();
    cActionSize->addItem("Tutte");
    cActionSize->addItem("Piccola");
    cActionSize->addItem("Media");
    cActionSize->addItem("Grande");
    cActionSize->setFixedWidth(150);

    cUserType = new QComboBox();
    cUserType->addItem("Tutti");
    cUserType->addItem("Base");
    cUserType->addItem("Gold");
    cUserType->setFixedWidth(150);

    pSearch=new QPushButton("CERCA");
    pSearch->setStyleSheet("background-color: black;  color: white;  border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");
    pSearch->setFixedWidth(70);

    table= new VSearchList(stuffList, userList,this);
    connect(table,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(doubleClick(int)));

    searchGrid=new QGridLayout();

    searchGrid->addWidget(greetText,0,0,1,3);

    searchGrid->addWidget(cSearchChoice,1,0);
    searchGrid->addWidget(tSearchText,1,1);
    searchGrid->addWidget(cStuffType,1,2);
    searchGrid->addWidget(cComicType,1,3);
    searchGrid->addWidget(cDVDType,1,3);
    searchGrid->addWidget(cActionSize,1,3);
    searchGrid->addWidget(cUserType,1,2,1,2);
    searchGrid->addWidget(pSearch,1,4);

    searchGrid->addWidget(table,2,0,2,8);

    searchLayout=new QVBoxLayout();
    searchLayout->addLayout(searchGrid);

    connect(pSearch,SIGNAL(clicked(bool)),this,SLOT(searchItem()));
    connect(cStuffType,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeStuffType()));

    connect(cSearchChoice,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeSearchType()));

    setLayout(searchLayout);
    cDVDType->hide();
    cActionSize->hide();
    cUserType->hide();

    if(!loggedUser->hasUserList())
        cSearchChoice->hide();

    table->close();
}

// SLOTS
void VSearchWindow::changeSearchType()
{
    table->close();
    if(cSearchChoice->currentText()=="Utenti"){
        cComicType->hide();
        cDVDType->hide();
        cActionSize->hide();
        cStuffType->hide();
        cUserType->show();

        tSearchText->setPlaceholderText("Cerca per Username, Nome o Cognome");
    }
    else{
        if(cSearchChoice->currentText()=="Articoli"){
            cComicType->show();
            cDVDType->hide();
            cActionSize->hide();
            cStuffType->show();
            cUserType->hide();

            cStuffType->setCurrentIndex(0);
            tSearchText->setPlaceholderText("Cerca per ID, Titolo o Autore");
        }
    }
}

void VSearchWindow::changeStuffType()
{
   if(cStuffType->currentText()=="Fumetto"){
       cComicType->show();
       cDVDType->hide();
       cActionSize->hide();
       cUserType->hide();
       tSearchText->setPlaceholderText("Cerca per ID, Titolo o Autore");
   }
   if(cStuffType->currentText()=="DVD"){
       cComicType->hide();
       cDVDType->show();
       cActionSize->hide();
       cUserType->hide();
       tSearchText->setPlaceholderText("Cerca per ID, Titolo o Regista");
   }
   if(cStuffType->currentText()=="Action Figure"){
       cComicType->hide();
       cDVDType->hide();
       cActionSize->show();
       cUserType->hide();
       tSearchText->setPlaceholderText("Cerca per ID, Nome o Produttore");
   }
}

void VSearchWindow::searchItem(){
    QString rText=tSearchText->text();
    QString option1;
    table->clear();
    if(cSearchChoice->currentText()=="Utenti"){
        option1=cUserType->currentText();
        table->viewUser();
        table->addListAllUser(rText, option1);
    }
    else{
        if(cSearchChoice->currentText()=="Articoli"){
            QString option2;
            option1=cStuffType->currentText();
            if(option1=="Fumetto")
                option2=cComicType->currentText();
            else if(option1=="DVD")
                option2=cDVDType->currentText();
            else if(option1=="Action Figure")
                option2=cActionSize->currentText();
            table->viewStuff();
            table->addListAllStuff(rText, option1, option2);
         }
    }
    table->show();
}

void VSearchWindow::doubleClick(int x){
   if(table->horizontalHeaderItem(0)->text()=="Username"&&loggedUser->getType()=="admin"){

       User *ut_modificare=userList->getUser((table->item(x,0))->text());
       userInfo=new VManageUser(loggedUser,ut_modificare);

       emit disableMainWindow();

       connect(userInfo,SIGNAL(sendEditUser(User*,QString,QString,QString,QString,QString)),this,SLOT(updateCurrentListUser(User*,QString, QString, QString, QString, QString)));
       connect(userInfo,SIGNAL(sendDeleteUser(User*)),this,SLOT(removeCurrentList()));
       connect(userInfo,SIGNAL(finished(int)),this,SIGNAL(disableMainWindow()));
       userInfo->setLayoutEdit();
       userInfo->show();
       emit saveEditUser(userInfo);
    }
else
   if(table->horizontalHeaderItem(0)->text()=="ID" && loggedUser->hasManagement()){

       stuffInfo=new VManageStuff(loggedUser, stuffList->getStuff((table->item(x,0))->text()));

       emit disableMainWindow();

       connect(stuffInfo,SIGNAL(sendEditComicBook(ComicBook*,bool, double, QString, QString, QString, int, int)),this,SLOT(updateCurrentListComicBook(ComicBook*,bool,double,QString,QString,QString,int,int)));
       connect(stuffInfo,SIGNAL(sendEditDVD(Dvd*,bool,double,QString,QString,QString,int,bool)),this,SLOT(updateCurrentListDVD(Dvd*,bool,double,QString,QString,QString,int,bool)));
       connect(stuffInfo,SIGNAL(sendEditActionFigure(ActionFigure*,bool,double,QString,QString,int,int,int)),this,SLOT(updateCurrentListActionFigure(ActionFigure*,bool,double,QString,QString,int,int,int)));
       connect(stuffInfo,SIGNAL(sendDeleteStuff(NerdStuff*)),this,SLOT(removeCurrentList()));
       connect(stuffInfo,SIGNAL(finished(int)),this,SIGNAL(disableMainWindow()));

       stuffInfo->setLayoutEdit();
       stuffInfo->show();

       emit saveEditStuff(stuffInfo);
   }
   else
      if(table->horizontalHeaderItem(0)->text()=="ID" && loggedUser->hasStarred()){
        NerdStuff *stuff=stuffList->getStuff((table->item(x,0))->text());
        GoldUser *h=dynamic_cast< GoldUser*>(loggedUser);
        if(h->checkStarred(stuff)){
            QMessageBox::warning(0,"Errore","Articolo già presente nella tua lisa dei preferiti.");
        }
        else{
        askStar=new VStarredAsk(h,stuff);
        askStar->show();
       }
      }
}

void VSearchWindow::removeCurrentList(){
    table->removeRow(table->currentRow());
}

void VSearchWindow::updateCurrentListUser(User*, QString q0, QString q1, QString q2, QString, QString q4){
    table->setItem(table->currentRow(),0,new QTableWidgetItem(q2));
    table->setItem(table->currentRow(),1,new QTableWidgetItem(q4));
    table->setItem(table->currentRow(),2,new QTableWidgetItem(q0));
    table->setItem(table->currentRow(),3,new QTableWidgetItem(q1));
}

void VSearchWindow::updateCurrentListComicBook(ComicBook*,bool b,double pr,QString t,QString a,QString ct,int v,int p) {
    table->setItem(table->currentRow(),2,new QTableWidgetItem(QString::number(b)));
    ComicBook* tmp=new ComicBook();
    tmp->setBasePrice(pr);
    table->setItem(table->currentRow(),3,new QTableWidgetItem(QString::number(tmp->getPrice())));
    delete tmp;
    table->setItem(table->currentRow(),4,new QTableWidgetItem(t));
    table->setItem(table->currentRow(),5,new QTableWidgetItem(a));
    table->setItem(table->currentRow(),6,new QTableWidgetItem(ct));
    table->setItem(table->currentRow(),7,new QTableWidgetItem(QString::number(v)));
    table->setItem(table->currentRow(),8,new QTableWidgetItem(QString::number(p)));
}

void VSearchWindow::updateCurrentListDVD(Dvd*,bool b,double pr,QString t,QString p,QString dt,int l,bool r) {
    table->setItem(table->currentRow(),2,new QTableWidgetItem(QString::number(b)));
    Dvd* tmp=new Dvd();
    tmp->setBasePrice(pr);
    table->setItem(table->currentRow(),3,new QTableWidgetItem(QString::number(tmp->getPrice())));
    delete tmp;
    table->setItem(table->currentRow(),4,new QTableWidgetItem(t));
    table->setItem(table->currentRow(),5,new QTableWidgetItem(p));
    table->setItem(table->currentRow(),6,new QTableWidgetItem(dt));
    table->setItem(table->currentRow(),7,new QTableWidgetItem(QString::number(l)));
    table->setItem(table->currentRow(),8,new QTableWidgetItem(QString::number(r)));
}

void VSearchWindow::updateCurrentListActionFigure(ActionFigure*,bool b,double pr,QString n,QString m,int w,int h,int d) {
    table->setItem(table->currentRow(),2,new QTableWidgetItem(QString::number(b)));
    ActionFigure* tmp=new ActionFigure();
    tmp->setBasePrice(pr);
    table->setItem(table->currentRow(),3,new QTableWidgetItem(QString::number(tmp->getPrice())));
    delete tmp;
    table->setItem(table->currentRow(),4,new QTableWidgetItem(n));
    table->setItem(table->currentRow(),5,new QTableWidgetItem(m));
    table->setItem(table->currentRow(),6,new QTableWidgetItem(QString::number(w)));
    table->setItem(table->currentRow(),7,new QTableWidgetItem(QString::number(h)));
    table->setItem(table->currentRow(),8,new QTableWidgetItem(QString::number(d)));
}
