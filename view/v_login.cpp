#include "v_login.h"

// CONSTRUCTOR
VLogin::VLogin(){
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Autenticazione");
    setFixedHeight(120);
    setFixedWidth(270);
    setWindowFlags(windowFlags()  & ~Qt::WindowContextHelpButtonHint);

    lUsername=new QLabel("Username");
    lPassword=new QLabel("Password");
    tUsername=new QLineEdit();
    tPassword=new QLineEdit();

    tUsername->setPlaceholderText("Inserisci l'username");
    tPassword->setPlaceholderText("Inserisci la password");

    tUsername->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,15}")));

    tPassword->setEchoMode(QLineEdit::Password);

    pLogin=new QPushButton("ACCEDI");
    pLogin->setStyleSheet("background-color: black;  color: white;  border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");

    gridLogin=new QGridLayout;
    gridLogin->addWidget(lUsername, 0,0);
    gridLogin->addWidget(tUsername,0,1);
    gridLogin->addWidget(lPassword,1,0);
    gridLogin->addWidget(tPassword,1,1);
    gridLogin->addWidget(pLogin,2,1);

    layoutLogin=new QVBoxLayout();
    layoutLogin->addLayout(gridLogin);
    setLayout(layoutLogin);

    connect(pLogin,SIGNAL(clicked()),this,SLOT(login()));
}

// CLASS METHODS
void VLogin::clearFields(){
    tPassword->clear();
    tUsername->clear();
    tUsername->setFocus();
}

// SLOT
void VLogin::login(){
    emit tryLogin(tUsername->text(),tPassword->text());
}
