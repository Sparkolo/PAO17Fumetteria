#include "c_main_window.h"

// CONSTRUCTOR
CMainWindow::CMainWindow(QObject *parent):QObject(parent){
    vLogin=nullptr;
    cUser=nullptr;
    cStuff=nullptr;

    vMainWindow=nullptr;
    StuffList= new DatabaseStuff();
    UserList= new DatabaseUser();
}

// DESTRUCTOR
CMainWindow::~CMainWindow(){
    StuffList->saveClose();
    UserList->saveClose();
    delete StuffList;
    delete UserList;
 }

// CLASS METHODS
void CMainWindow::launchLogin(){
    vLogin=new VLogin();
    connect(vLogin,SIGNAL(tryLogin(QString,QString)),this,SLOT(testLogin(QString,QString)));
    vLogin->show();
    cUser=new CUser(UserList,this);
    cStuff=new CNerdStuff(StuffList,this);
}

// SLOTS
void CMainWindow::testLogin(const QString &username, const QString &password){
    loggedUser=UserList->checkUser(username, password);
    if(!loggedUser){
        QMessageBox::warning(0,"Errore", "Autenticazione fallita.");
        vLogin->clearFields();
    }
    else{
        vMainWindow=new VMainWindow(StuffList,UserList,loggedUser);
        connect(vMainWindow,SIGNAL(tryLogout()),this,SLOT(refreshLogin()));
        connect(vMainWindow,SIGNAL(refreshManageUser(VManageUser*)),this,SLOT(refreshCUser(VManageUser*)));
        connect(vMainWindow,SIGNAL(refreshManageStuff(VManageStuff*)),this,SLOT(refreshCStuff(VManageStuff*)));
       vLogin->close();
        vLogin=nullptr;
        vMainWindow->show();
    }
}

void CMainWindow::refreshLogin(){
    if(!vLogin)vLogin=new VLogin();
    connect(vLogin,SIGNAL(tryLogin(QString,QString)),this,SLOT(testLogin(QString,QString)));
    vLogin->clearFields();
    vLogin->show();
}

void CMainWindow::refreshCUser(VManageUser *vGUser){
    cUser->refreshVUser(vGUser);
}

void CMainWindow::refreshCStuff(VManageStuff *vGStuff){
    cStuff->refreshVStuff(vGStuff);
}


