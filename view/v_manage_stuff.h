#ifndef  MANAGE_STUFF_V_H
#define MANAGE_STUFF_V_H
#include<QDialog>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QString>
#include<QComboBox>
#include <QSpinBox>
#include<QDoubleSpinBox>
#include"model/database_stuff.h"

class VManageStuff:public QDialog{
private:
    Q_OBJECT
    User * us;
    NerdStuff * stuffToEdit;

    //LABEL
    QLabel * lInventary;
    QLabel * lLimited;
    QLabel * lBasePrice;
    QLabel * lType;

    QLabel * lComicTitle;
    QLabel * lComicAuthor;
    QLabel * lComicType;
    QLabel * lComicVolNum;
    QLabel * lComicPagNum;

    QLabel * lDVDTitle;
    QLabel * lDVDProducer;
    QLabel * lDVDType;
    QLabel * lDVDLength;
    QLabel * lDVDAge;

    QLabel * lActionName;
    QLabel * lActionManufacturer;
    QLabel * lActionWidth;
    QLabel * lActionHeight;
    QLabel * lActionDepth;

    // STUFF
    QLineEdit * tInventory;
    QComboBox * cLimited;
    QDoubleSpinBox * sBasePrice;
    QComboBox * cType;

    QLineEdit * tComicTitle;
    QLineEdit * tComicAuthor;
    QComboBox * cComicType;
    QLineEdit * tComicVolNum;
    QLineEdit * tComicPagNum;

    QLineEdit * tDVDTitle;
    QLineEdit * tDVDProducer;
    QComboBox * cDVDType;
    QDoubleSpinBox * sDVDLength;
    QComboBox * cDVDAge;

    QLineEdit * tActionName;
    QLineEdit * tActionManufacturer;
    QSpinBox * sActionWidth;
    QSpinBox * sActionHeight;
    QSpinBox * sActionDepth;

    // BUTTONS
    QPushButton * pSaveEdit;
    QPushButton * pDelete;
    QPushButton * pCreate;

    QVBoxLayout * stuffLayout;
    QGridLayout * stuffGrid;

public:
    VManageStuff(User*, NerdStuff* st=nullptr);

    void addLayout();
    void setLayoutCreate();
    void setLayoutEdit();
    void resetStuffID();
    bool checkNoEmpty();

    void showComicBook();
    void showDVD();
    void showActionFigure();

    void hideComicBook();
    void hideDVD();
    void hideActionFigure();

 public slots:
    void saveCreateStuff();
    void saveEditStuff();
    void saveDeleteStuff();
    void changeType(QString type);
    void disableMiddleWindow();

 signals:
    void sendCreateStuff(NerdStuff* );
    void sendEditComicBook(ComicBook*, bool, double, QString, QString, QString, int, int);
    void sendEditDVD(Dvd*, bool, double, QString, QString, QString, int, bool);
    void sendEditActionFigure(ActionFigure*, bool, double, QString, QString, int, int, int);
    void sendDeleteStuff(NerdStuff*);
};

#endif // MANAGE_STUFF_V_H
