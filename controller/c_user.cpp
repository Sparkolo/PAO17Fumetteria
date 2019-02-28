#include "c_user.h"

// CONSTRUCTOR
CUser::CUser(DatabaseUser *dbUs, QObject *parent):QObject(parent),UserList(dbUs) {
    vUser=nullptr;
}

// CLASS METHOD
void CUser::refreshVUser(VManageUser *vGUs){
    vUser=vGUs;
    connect(vUser,SIGNAL(sendCreateUser(User*)),this,SLOT(receiveCreateUser(User*)));
    connect(vUser,SIGNAL(sendEditUser(User*,QString,QString,QString,QString,QString)),
            this,SLOT(receiveEditUser(User*,QString,QString,QString,QString,QString)));
    connect(vUser,SIGNAL(sendDeleteUser(User*)),this,SLOT(receiveDeleteUser(User*)));
}

// SLOTS
void CUser::receiveCreateUser(User *u){
    vUser->empty();
    UserList->addElementUser(u);
}

void CUser::receiveEditUser(User * u, QString name, QString surname, QString username, QString pass, QString type){
    if(u->getUsername()!=username && UserList->findUsername(username)){
        vUser->resetUsername();
        QMessageBox::information(0,"Errore", "Username non disponibile.");

    }
    else{
        bool modified=0;

        if(u->getName()!=name){
            u->setName(name);
            modified=1;
        }
        if(u->getSurname()!=surname){
            u->setSurname(surname);
            modified=1;
        }
        if(u->getUsername()!=username){
            u->setUsername(username);
            modified=1;
        }
        if(u->getPassword()!=pass){
            u->setPassword(pass);
            modified=1;
        }
        if(u->getType()!=type){
            UserList->changeUserType(u,type);
            modified=1;
        }
        if(modified==1){
            QMessageBox::warning(0,"Modifica Utente","Modifiche salvate con successo!");
            vUser->close();
        }
        else
            QMessageBox::warning(0,"Errore","Nessuna modifica rilevata.");
    }
}

void CUser::receiveDeleteUser(User *u){
    UserList->removeElementUser(u);
}
