#include "v_main_window.h"

// CONSTRUCTOR
VMainWindow::VMainWindow(DatabaseStuff *dbSt, DatabaseUser *dbUser, User *us, QWidget *parent):
    QMainWindow(parent), StuffList(dbSt),UserList(dbUser), loggedUser(us){
   this->setAttribute(Qt::WA_DeleteOnClose);
   setWindowTitle("QtComicStore");
   setFixedHeight(650);
   setFixedWidth(1000);
   QRect wmainPosition = geometry();
   wmainPosition.moveCenter(QApplication::desktop()->availableGeometry().center());
   setGeometry(wmainPosition);
   addOptionMenu();
   vSearch=nullptr;
   star=nullptr;
   vManageUser=nullptr;
   vManageStuff=nullptr;
   addSearch();

   QPixmap bkgnd("./images/background.jpg");
   bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
   QPalette palette;
   palette.setBrush(QPalette::Background, bkgnd);
   this->setPalette(palette);
}

// CLASS METHODS
void VMainWindow::addOptionMenu(){
    userMenu=new QMenu("Opzioni",this);
    mStarred=new QAction("Gestione Preferiti",this);
    mManageProfile=new QAction("Modifica impostazioni account",this);
    mLogout=new QAction("Logout",this);

    userMenu->addAction(mStarred);
    userMenu->addAction(mManageProfile);
    userMenu->addAction(mLogout);

   if(!loggedUser->hasStarred()){
      mStarred->setVisible(false);
    }

    connect(mStarred,SIGNAL(triggered(bool)),this,SLOT(openStarred()));
    connect(mLogout,SIGNAL(triggered(bool)),this,SLOT(disconnection()));
    connect(mManageProfile,SIGNAL(triggered(bool)),this,SLOT(openEditProfile()));

    menuBar()->addMenu(userMenu);

    if(loggedUser->hasManagement()){
        managementMenu=new QMenu("Database",this);
        mUserAdd=new QAction("Aggiungi utenti",this);
        mStuffAdd=new QAction("Aggiungi articoli",this);

        managementMenu->addAction(mUserAdd);
        managementMenu->addAction(mStuffAdd);

        connect(mUserAdd,SIGNAL(triggered(bool)),this,SLOT(openAddUser()));
        connect(mStuffAdd,SIGNAL(triggered(bool)),this,SLOT(openAddStuff()));
        menuBar()->addMenu(managementMenu);
    }
}

void VMainWindow::addSearch(){
    vSearch=new VSearchWindow(StuffList,UserList,loggedUser);
    connect(vSearch,SIGNAL(disableMainWindow()),this,SLOT(disableWindow()));

    connect(vSearch, SIGNAL(saveEditUser(VManageUser*)),this,SLOT(refreshUser(VManageUser *)));
    connect(vSearch,SIGNAL(saveEditStuff(VManageStuff*)),this,SIGNAL(refreshManageStuff(VManageStuff*)));
    setCentralWidget(vSearch);
}

void VMainWindow::openManageUser(){
    vManageUser=new VManageUser(loggedUser,loggedUser);
    disableWindow();
    connect(vManageUser,SIGNAL(finished(int)),this,SLOT(disableWindow()));
    emit(refreshManageUser(vManageUser));
    connect(vManageUser,SIGNAL(logout()),this,SLOT(disconnection()));

    vSearch->removeCurrentList();
}

// SLOTS
void VMainWindow::disconnection(){
    emit tryLogout();
    this->close();
}

void VMainWindow::openAddUser(){
    openManageUser();
    vManageUser->setLayoutCreate();
    vManageUser->show();
}


void VMainWindow::openEditProfile(){
    openManageUser();
    vManageUser->setLayoutEdit();
    vManageUser->show();
}

void VMainWindow::openAddStuff(){
    vManageStuff=new VManageStuff(loggedUser);
    disableWindow();
    connect(vManageStuff,SIGNAL(finished(int)),this,SLOT(disableWindow()));

    emit(refreshManageStuff(vManageStuff));
    vManageStuff->setLayoutCreate();
    vManageStuff->show();
    vSearch->removeCurrentList();
}

void VMainWindow::openStarred()
{
        star=new VStarred(loggedUser, StuffList);
        star->show();
}

void VMainWindow::refreshUser(VManageUser *vMUs){
    connect(vMUs, SIGNAL(logout()),this,SLOT(disconnection()));
    emit refreshManageUser(vMUs);
}

void VMainWindow::disableWindow(){
    if(isEnabled()){
        this->setEnabled(0);
    }
    else{
        this->setEnabled(1);
    }
}
