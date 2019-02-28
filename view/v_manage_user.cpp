#include "v_manage_user.h"

// CONSTRUCTOR
VManageUser::VManageUser(User *us, User *usMod):us(us),userToEdit(usMod)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    setWindowFlags(windowFlags()& ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Gestione Utente");
    setFixedWidth(300);
    addLayout();
    setModal(1);
}

// CLASS METHODS
void VManageUser::addLayout()
{

    lName=new QLabel("Nome");
    lSurname=new QLabel("Cognome");
    lUsername=new QLabel("Username");
    lPassword=new QLabel("Password");
    lType=new QLabel("Tipo");

    lMyType=new QLabel(userToEdit->getType());
    cName=new QLineEdit();
    cName->setValidator(new QRegExpValidator(QRegExp("([A-Za-z]{1,15}[ ]){1,3}")));
    cSurname=new QLineEdit();
    cSurname->setValidator(new QRegExpValidator(QRegExp("([A-Za-z]{1,15}[ ]){1,3}")));
    tUsername=new QLineEdit();
    tUsername->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));
    tPassword=new QLineEdit();

    cType=new QComboBox();

    cType->addItem("Base");
    cType->addItem("Gold");

    cType->setCurrentText(userToEdit->getType());

    cName->setPlaceholderText("Inserisci il nome");
    cSurname->setPlaceholderText("Inserisci il cognome");
    tUsername->setPlaceholderText("Inserisci l'username");
    tPassword->setPlaceholderText("Inserisci la password");

    cName->setText(userToEdit->getName());
    cSurname->setText(userToEdit->getSurname());
    tUsername->setText(userToEdit->getUsername());
    tPassword->setText(userToEdit->getPassword());

    pSaveEdit=new QPushButton("SALVA");
    pSaveEdit->setStyleSheet("background-color: green;  color: white;  border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");
    pDelete=new QPushButton("ELIMINA");
    pDelete->setStyleSheet("background-color: red;  color: white;  border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");
    pCreate=new QPushButton("AGGIUNGI");
    pCreate->setStyleSheet("background-color: black;  color: white;  border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");

    userGrid=new QGridLayout;
    userGrid->addWidget(lName, 0,0);
    userGrid->addWidget(lSurname,1,0);
    userGrid->addWidget(lUsername,2,0);
    userGrid->addWidget(lPassword,3,0);

    userGrid->addWidget(cName, 0,1);
    userGrid->addWidget(cSurname,1,1);
    userGrid->addWidget(tUsername,2,1);
    userGrid->addWidget(tPassword,3,1);

    userGrid->addWidget(lType,4,0);
    userGrid->addWidget(cType,4,1);
    userGrid->addWidget(lMyType,4,1);
    userGrid->addWidget(pDelete,6,0);
    userGrid->addWidget(pSaveEdit,6,1);
    userGrid->addWidget(pCreate,7,0,1,2,Qt::AlignHCenter);

    userLayout=new QVBoxLayout();
    userLayout->addLayout(userGrid);

    connect(pSaveEdit,SIGNAL(clicked()),this,SLOT(saveEditUser()));
    connect(pCreate,SIGNAL(clicked()),this,SLOT(saveCreateUser()));
    connect(pDelete,SIGNAL(clicked()),this,SLOT(saveDeleteUser()));

    setLayout(userLayout);
}

void VManageUser::setLayoutCreate()
{
    pCreate->show();
    pDelete->hide();
    pSaveEdit->hide();
    lMyType->hide();
    cType->show();
    this->empty();
}

void VManageUser::setLayoutEdit()
{
    pCreate->hide();
    if(us->hasManagement() && us->getUsername()!=userToEdit->getUsername()){
        lMyType->hide();
    }
    else{
        cType->hide();
        pDelete->hide();
    }
}

void VManageUser::resetUsername()
{
    tUsername->clear();
    tUsername->setText(userToEdit->getUsername());
}

void VManageUser::empty()
{
    tPassword->clear();
    tUsername->clear();
    cName->clear();
    cSurname->clear();
}


// SLOTS
void VManageUser::saveCreateUser()
{
  if(cName->text()!=""&&cSurname->text()!=""&&tUsername->text()!=""&&tPassword->text()!=""){
     User *tmpUser=nullptr;
     if(cType->currentText()=="Gold"){
        tmpUser= new GoldUser(cName->text(),cSurname->text(), tUsername->text(),tPassword->text());
     }
     else if(cType->currentText()=="Base"){
         tmpUser= new BaseUser(cName->text(),cSurname->text(), tUsername->text(),tPassword->text());
     }
     emit sendCreateUser(tmpUser);
 }
 else{
     QMessageBox::warning(0,"Attenzione","È necessario riempire tutti i campi dati");
 }
}

void VManageUser::saveEditUser()
{
    if(cName->text()!=""&&cSurname->text()!=""&&tUsername->text()!=""&&tPassword->text()!=""){
        if(userToEdit->getType()=="admin"){
            emit sendEditUser(userToEdit,cName->text(),cSurname->text(), tUsername->text(), tPassword->text(), lMyType->text());
        }
        else{
            emit sendEditUser(userToEdit,cName->text(),cSurname->text(),tUsername->text(), tPassword->text(), cType->currentText());
        }
    }
    else{
        QMessageBox::warning(0,"Modifiche fallite","Compilare tutti i campi");
    }
}

void VManageUser::saveDeleteUser()
{
    emit sendDeleteUser(userToEdit);
    if(us==userToEdit){
        emit logout();
    }
    this->close();
}
