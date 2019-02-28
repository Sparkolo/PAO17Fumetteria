#include "v_starred_ask.h"

// CONSTRUCTOR
VStarredAsk::VStarredAsk(GoldUser *gu, NerdStuff *st):us(gu),st(st)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Preferiti");
    setWindowFlags(windowFlags()  & ~Qt::WindowContextHelpButtonHint);

    ask=new QLabel("Vuoi aggiungere questo articolo ai tuoi preferiti?");

    pYes=new QPushButton("Si");
    pYes->setStyleSheet("background-color: green;  color: white;  border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");
    pNo=new QPushButton("No");
    pNo->setStyleSheet("background-color: red;  color: white;  border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");

    loginGrid=new QGridLayout;
    loginGrid->addWidget(ask,0,0,1,2,Qt::AlignHCenter);

    loginGrid->addWidget(pYes,1,0);
    loginGrid->addWidget(pNo,1,1);


    loginLayout=new QVBoxLayout();
    loginLayout->addLayout(loginGrid);
    setLayout(loginLayout);

    connect(pYes,SIGNAL(clicked()),this,SLOT(doAdd()));
    connect(pNo,SIGNAL(clicked()),this,SLOT(noAdd()));
}

// CLASS METHODS
void VStarredAsk::setAskRemove()
{
    ask->setText("Vuoi davvero rimuovere l'articolo selezionato dai preferiti?");

    connect(pYes,SIGNAL(clicked()),this,SLOT(deleteStar()));
    setModal(1);
}

// SLOTS
void VStarredAsk::deleteStar()
{
    us->removeStarred(st->getInventory());
    emit refreshStarredList();
    this->close();
}

void VStarredAsk::doAdd()
{
    us->addStarred(st);
    this->close();
}

void VStarredAsk::noAdd()
{
    this->close();
}

