#include "v_manage_stuff.h"

// CONSTRUCTOR
VManageStuff::VManageStuff(User *u, NerdStuff *st):us(u),stuffToEdit(st){
    this->setAttribute(Qt::WA_DeleteOnClose);

    setWindowFlags(windowFlags()  & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Gestione Articoli");
    setFixedWidth(300);
    addLayout();
    setModal(1);
}

// CLASS METHODS
void VManageStuff::addLayout(){
    // LABEL NERD STUFF
    lInventary=new QLabel("ID");
    lLimited=new QLabel("Ed. limitata");
    lBasePrice=new QLabel("Prezzo base");
    lType=new QLabel("Tipologia");
    // LABEL COMIC BOOKS
    lComicTitle= new QLabel("Titolo");
    lComicAuthor = new QLabel("Autore");
    lComicType = new QLabel("Tipo");
    lComicVolNum = new QLabel("Volume");
    lComicPagNum = new QLabel("Pagine");
    // LABEL DVD
    lDVDTitle= new QLabel("Titolo");
    lDVDProducer = new QLabel("Regista");
    lDVDType = new QLabel("Tipo");
    lDVDLength = new QLabel("Durata");
    lDVDAge = new QLabel("V.M.18");
    // LABEL DVD
    lActionName= new QLabel("Nome");
    lActionManufacturer = new QLabel("Produttore");
    lActionWidth = new QLabel("Larghezza");
    lActionHeight = new QLabel("Altezza");
    lActionDepth = new QLabel("Profondità");

    // NERD STUFF BEHAVIOUR
    tInventory=new QLineEdit();
    tInventory->setValidator(new QRegExpValidator(QRegExp("[A-Z][A-Z][0-9]{4}")));
    tInventory->setPlaceholderText("Inserisci un ID");

    cLimited=new QComboBox();
    cLimited->addItem("No");
    cLimited->addItem("Sì");

    sBasePrice = new QDoubleSpinBox();
    sBasePrice-> setRange(0,1000);
    sBasePrice->setSingleStep(0.01);
    sBasePrice->setSuffix(" €");

    cType=new QComboBox();
    cType->addItem("Fumetto");
    cType->addItem("DVD");
    cType->addItem("Action Figure");

    // COMIC BOOK STUFF BEHAVIOUR
    tComicTitle=new QLineEdit();
    tComicTitle->setValidator(new QRegExpValidator(QRegExp("([A-Za-z0-9]{1,30}[ ]){1,5}")));
    tComicTitle->setPlaceholderText("Inserisci il titolo");

    tComicAuthor=new QLineEdit();
    tComicAuthor->setValidator(new QRegExpValidator(QRegExp("([A-Za-z0-9]{1,15}[ ]){1,6}")));
    tComicAuthor->setPlaceholderText("Inserisci l'autore");

    cComicType=new QComboBox();

    cComicType->addItem("Comic");
    cComicType->addItem("Franco-Belga");
    cComicType->addItem("Italiano");
    cComicType->addItem("Manga");

    tComicVolNum=new QLineEdit();
    tComicVolNum->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
    tComicVolNum->setPlaceholderText("Inserisci il #volume");

    tComicPagNum=new QLineEdit();
    tComicPagNum->setValidator(new QRegExpValidator(QRegExp("[0-9]{4}")));
    tComicPagNum->setPlaceholderText("Inserisci il #pagine");

    // DVD STUFF BEHAVIOUR
    tDVDTitle=new QLineEdit();
    tDVDTitle->setValidator(new QRegExpValidator(QRegExp("([A-Za-z0-9]{1,30}[ ]){1,5}")));
    tDVDTitle->setPlaceholderText("Inserisci il titolo");

    tDVDProducer=new QLineEdit();
    tDVDProducer->setValidator(new QRegExpValidator(QRegExp("([A-Za-z0-9]{1,15}[ ]){1,6}")));
    tDVDProducer->setPlaceholderText("Inserisci l'autore");

    cDVDType=new QComboBox();
    cDVDType->addItem("Animazione");
    cDVDType->addItem("Live Action");

    sDVDLength=new QDoubleSpinBox();
    sDVDLength-> setRange(0,300);
    sDVDLength->setSingleStep(1);
    sDVDLength->setDecimals(0);
    sDVDLength->setSuffix(" min");

    cDVDAge=new QComboBox();
    cDVDAge->addItem("No");
    cDVDAge->addItem("Sì");

    // ACTION FIGURES STUFF BEHAVIOUR
    tActionName=new QLineEdit();
    tActionName->setValidator(new QRegExpValidator(QRegExp("([A-Za-z0-9]{1,30}[ ]){1,5}")));
    tActionName->setPlaceholderText("Inserisci il nome");

    tActionManufacturer=new QLineEdit();
    tActionManufacturer->setValidator(new QRegExpValidator(QRegExp("([A-Za-z0-9]{1,30}[ ]){1,5}")));
    tActionManufacturer->setPlaceholderText("Inserisci il produttore");

    sActionWidth = new QSpinBox;
    sActionWidth-> setRange(0,200);
    sActionWidth->setSingleStep(1);
    sActionWidth->setSuffix(" cm");

    sActionHeight = new QSpinBox;
    sActionHeight-> setRange(0,200);
    sActionHeight->setSingleStep(1);
    sActionHeight->setSuffix(" cm");

    sActionDepth = new QSpinBox;
    sActionDepth-> setRange(0,200);
    sActionDepth->setSingleStep(1);
    sActionDepth->setSuffix(" cm");

    // BUTTONS BEHAVIOUR
    pSaveEdit=new QPushButton("SALVA");
    pSaveEdit->setStyleSheet("background-color: green;  color: white;  border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");
    pDelete=new QPushButton("ELIMINA");
    pDelete->setStyleSheet("background-color: red;  color: white;  border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");
    pCreate=new QPushButton("AGGIUNGI");
    pCreate->setStyleSheet("background-color: black;  color: white; border-radius:10px; font: bold 14px; min-width: 5em; padding: 6px");

    stuffGrid=new QGridLayout;

    // ADD NERD STUFF
    stuffGrid->addWidget(lInventary, 0,0);
    stuffGrid->addWidget(tInventory,0,1);
    stuffGrid->addWidget(lLimited,1, 0);
    stuffGrid->addWidget(cLimited,1,1);
    stuffGrid->addWidget(lBasePrice,2, 0);
    stuffGrid->addWidget(sBasePrice,2,1);
    stuffGrid->addWidget(lType,3,0);
    stuffGrid->addWidget(cType,3,1);
    // ADD COMIC BOOK STUFF
   stuffGrid->addWidget(lComicTitle,4,0);
    stuffGrid->addWidget(tComicTitle,4,1);
    stuffGrid->addWidget(lComicAuthor,5,0);
    stuffGrid->addWidget(tComicAuthor,5,1);
    stuffGrid->addWidget(lComicType,6,0);
    stuffGrid->addWidget(cComicType,6,1);
    stuffGrid->addWidget(lComicVolNum,7,0);
    stuffGrid->addWidget(tComicVolNum,7,1);
    stuffGrid->addWidget(lComicPagNum,8,0);
    stuffGrid->addWidget(tComicPagNum,8,1);
    // ADD DVD STUFF
    stuffGrid->addWidget(lDVDTitle,4,0);
    stuffGrid->addWidget(tDVDTitle,4,1);
    stuffGrid->addWidget(lDVDProducer,5,0);
    stuffGrid->addWidget(tDVDProducer,5,1);
    stuffGrid->addWidget(lDVDType,6,0);
    stuffGrid->addWidget(cDVDType,6,1);
    stuffGrid->addWidget(lDVDLength,7,0);
    stuffGrid->addWidget(sDVDLength,7,1);
    stuffGrid->addWidget(lDVDAge,8,0);
    stuffGrid->addWidget(cDVDAge,8,1);
    // ADD ACTION FIGURE STUFF
    stuffGrid->addWidget(lActionName,4,0);
    stuffGrid->addWidget(tActionName,4,1);
    stuffGrid->addWidget(lActionManufacturer,5,0);
    stuffGrid->addWidget(tActionManufacturer,5,1);
    stuffGrid->addWidget(lActionWidth,6,0);
    stuffGrid->addWidget(sActionWidth,6,1);
    stuffGrid->addWidget(lActionHeight,7,0);
    stuffGrid->addWidget(sActionHeight,7,1);
    stuffGrid->addWidget(lActionDepth,8,0);
    stuffGrid->addWidget(sActionDepth,8,1);
    // ADD BUTTONS
    stuffGrid->addWidget(pDelete,9,0);
    stuffGrid->addWidget(pSaveEdit,9,1);
    stuffGrid->addWidget(pCreate,10,0,1,2,Qt::AlignHCenter);


    stuffLayout=new QVBoxLayout();
    stuffLayout->addLayout(stuffGrid);

    connect(cType,SIGNAL(currentTextChanged(QString)),this,SLOT(changeType(QString)));
    connect(pSaveEdit,SIGNAL(clicked(bool)),this,SLOT(saveEditStuff()));

    connect(pDelete,SIGNAL(clicked(bool)),this,SLOT(saveDeleteStuff()));

    connect(pCreate,SIGNAL(clicked(bool)),this,SLOT(saveCreateStuff()));

    setLayout(stuffLayout);
    changeType(cType->currentText());
}

void VManageStuff::setLayoutCreate(){
    pSaveEdit->hide();
    pDelete->hide();
}

void VManageStuff::setLayoutEdit(){
    if(stuffToEdit){
         tInventory->setText(stuffToEdit->getInventory());
         if(stuffToEdit->getLimited())
             cLimited->setCurrentText("Sì");
         else cLimited->setCurrentText("No");
         sBasePrice->setValue(stuffToEdit->getBasePrice());

          if(stuffToEdit->getType()=="Fumetto"){
              cType->setCurrentText("Fumetto");
              tComicTitle->setText(static_cast<ComicBook*>(stuffToEdit)->getTitle());
              tComicAuthor->setText(static_cast<ComicBook*>(stuffToEdit)->getAuthor());
              cComicType->setCurrentText(static_cast<ComicBook*>(stuffToEdit)->getComicType());
              tComicVolNum->setText(QString::number(static_cast<ComicBook*>(stuffToEdit)->getVolNumber()));
              tComicPagNum->setText(QString::number(static_cast<ComicBook*>(stuffToEdit)->getPageNumber()));

              hideDVD();
              hideActionFigure();
          }
          if(stuffToEdit->getType()=="DVD"){
              cType->setCurrentText("DVD");
              tDVDTitle->setText(static_cast<Dvd*>(stuffToEdit)->getTitle());
              tDVDProducer->setText(static_cast<Dvd*>(stuffToEdit)->getProducer());
              cDVDType->setCurrentText(static_cast<Dvd*>(stuffToEdit)->getDVDType());
              sDVDLength->setValue(static_cast<Dvd*>(stuffToEdit)->getFilmLength());
              cDVDAge->setCurrentText(QString::number(static_cast<Dvd*>(stuffToEdit)->getAgeRes()));

              hideComicBook();
              hideActionFigure();
          }
          if(stuffToEdit->getType()=="Action Figure"){
              cType->setCurrentText("Action Figure");
              tActionName->setText(static_cast<ActionFigure*>(stuffToEdit)->getName());
              tActionManufacturer->setText(static_cast<ActionFigure*>(stuffToEdit)->getManufacturer());
              sActionWidth->setValue(static_cast<ActionFigure*>(stuffToEdit)->getWidth());
              sActionHeight->setValue(static_cast<ActionFigure*>(stuffToEdit)->getHeight());
              sActionDepth->setValue(static_cast<ActionFigure*>(stuffToEdit)->getDepth());

              hideComicBook();
              hideDVD();
          }
          tInventory->setEnabled(false);
          cType->setEnabled(false);
    }
    pCreate->hide();
}

void VManageStuff::resetStuffID(){
    tInventory->clear();
    if(stuffToEdit)
        tInventory->setText(stuffToEdit->getInventory());
}

bool VManageStuff::checkNoEmpty() {
    QString s="";
    if(cType->currentText()=="Fumetto"){
        if(tComicTitle->text()=="") {
            s+="\n > Titolo";
        }
        if(tComicAuthor->text()=="") {
            s+="\n > Autore";
        }
        if(tComicVolNum->text()=="") {
            s+="\n > Numero del volume";
        }
        if(tComicPagNum->text()=="") {
            s+="\n > Numero di pagine";
        }
    }

    if(cType->currentText()=="DVD"){
            if(tDVDTitle->text()=="") {
                s+="\n > Titolo";
            }
            if(tDVDProducer->text()=="") {
                s+="\n > Regista";
            }
        }

            if(cType->currentText()=="Action Figure"){
                if(tActionName->text()=="") {
                    s+="\n > Nome";
                }
                if(tActionManufacturer->text()=="") {
                    s+="\n > Produttore";
                }
            }

            if(s!="") {
                QMessageBox::warning(0,"Attenzione","I seguenti campi non possono essere vuoti:"+s);
                return false;
            }
            return true;
}

// SHOW
void VManageStuff::showComicBook(){
    lComicTitle->show();
    lComicAuthor->show();
    lComicType->show();
    lComicVolNum->show();
    lComicPagNum->show();
    tComicTitle->show();
    tComicAuthor->show();
    cComicType->show();
    tComicVolNum->show();
    tComicPagNum->show();
}

void VManageStuff::showDVD(){
    lDVDTitle->show();
    lDVDProducer->show();
    lDVDType->show();
    lDVDLength->show();
    lDVDAge->show();
    tDVDTitle->show();
    tDVDProducer->show();
    cDVDType->show();
    sDVDLength->show();
    cDVDAge->show();
}

void VManageStuff::showActionFigure(){
    lActionName->show();
    lActionManufacturer->show();
    lActionWidth->show();
    lActionHeight->show();
    lActionDepth->show();
    tActionName->show();
    tActionManufacturer->show();
    sActionWidth->show();
    sActionHeight->show();
    sActionDepth->show();
}

// HIDE
void VManageStuff::hideComicBook(){
    lComicTitle->hide();
    lComicAuthor->hide();
    lComicType->hide();
    lComicVolNum->hide();
    lComicPagNum->hide();
    tComicTitle->hide();
    tComicAuthor->hide();
    cComicType->hide();
    tComicVolNum->hide();
    tComicPagNum->hide();
}

void VManageStuff::hideDVD(){
    lDVDTitle->hide();
    lDVDProducer->hide();
    lDVDType->hide();
    lDVDLength->hide();
    lDVDAge->hide();
    tDVDTitle->hide();
    tDVDProducer->hide();
    cDVDType->hide();
    sDVDLength->hide();
    cDVDAge->hide();
}

void VManageStuff::hideActionFigure(){
    lActionName->hide();
    lActionManufacturer->hide();
    lActionWidth->hide();
    lActionHeight->hide();
    lActionDepth->hide();
    tActionName->hide();
    tActionManufacturer->hide();
    sActionWidth->hide();
    sActionHeight->hide();
    sActionDepth->hide();
}


// SLOTS
void VManageStuff::saveCreateStuff(){
    if(tInventory->text()==""){
         QMessageBox::warning(0,"Errore","Inserire un ID valido per l'articolo.");
    }
    else if(checkNoEmpty()) {
        NerdStuff * tmp=nullptr;
        if(cType->currentText()=="Fumetto"){
            tmp=new ComicBook(tInventory->text(), cLimited->currentText().toInt(), sBasePrice->value(), tComicTitle->text(), tComicAuthor->text(),cComicType->currentText(), tComicVolNum->text().toInt(), tComicPagNum->text().toInt());
        }
        else if (cType->currentText()=="DVD"){
            tmp=new Dvd(tInventory->text(), cLimited->currentText().toInt(), sBasePrice->value(), tDVDTitle->text(), tDVDProducer->text(), cDVDType->currentText(), sDVDLength->value(), cDVDAge->currentText().toInt());
        }
        else if (cType->currentText()=="Action Figure"){
            tmp=new ActionFigure(tInventory->text(), cLimited->currentText().toInt(), sBasePrice->value(), tActionName->text(), tActionManufacturer->text(), sActionWidth->value(), sActionHeight->value(), sActionDepth->value());
        }
        emit sendCreateStuff(tmp);
    }
}

void VManageStuff::saveEditStuff(){
    if(checkNoEmpty()){
        bool tmp=true;
        if(cLimited->currentText()=="No")
            tmp=false;
        if(cType->currentText()=="Fumetto")
            emit sendEditComicBook(static_cast<ComicBook*>(stuffToEdit),tmp,sBasePrice->value(),tComicTitle->text(),tComicAuthor->text(),cComicType->currentText(),(tComicVolNum->text()).toInt(),(tComicPagNum->text()).toInt());
        else if(cType->currentText()=="DVD"){
            bool tmp2=true;
            if(cDVDAge->currentText()=="No")
                tmp2=false;
            emit sendEditDVD(static_cast<Dvd*>(stuffToEdit),tmp,sBasePrice->value(),tDVDTitle->text(),tDVDProducer->text(),cDVDType->currentText(),sDVDLength->value(),tmp2);
        }
        else if(cType->currentText()=="Action Figure")
            emit sendEditActionFigure(static_cast<ActionFigure*>(stuffToEdit),tmp,sBasePrice->value(),tActionName->text(),tActionManufacturer->text(),sActionWidth->value(),sActionHeight->value(),sActionDepth->value());
    }
}

void VManageStuff::saveDeleteStuff(){
    emit sendDeleteStuff(stuffToEdit);
}

void VManageStuff::changeType(QString type){
    if(type=="Fumetto"){
        showComicBook();
        hideDVD();
        hideActionFigure();
    }
    else if(type=="DVD"){
        hideComicBook();
        showDVD();
        hideActionFigure();
    }
    else if(type=="Action Figure"){
        hideComicBook();
        hideDVD();
        showActionFigure();
    }
}

void VManageStuff::disableMiddleWindow(){
    if(isEnabled()){
        this->setEnabled(0);
    }
    else{
        this->setEnabled(1);
    }
}
