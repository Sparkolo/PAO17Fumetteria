#ifndef  SEARCH_WINDOW_V_H
#define SEARCH_WINDOW_V_H
#include<QDialog>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QString>
#include<QComboBox>
#include<QHeaderView>
#include"model/database_stuff.h"
#include"model/database_user.h"
#include"view/v_search_list.h"
#include"view/v_starred_ask.h"
#include"view/v_manage_stuff.h"

class VSearchWindow:public QWidget{
private:
    Q_OBJECT

    DatabaseStuff * stuffList;
    DatabaseUser * userList;
    User * loggedUser;

    VManageUser * userInfo;
    VManageStuff * stuffInfo;
    VStarredAsk *askStar;
    VSearchList * table;

    QLabel * greetText;
    QLineEdit * tSearchText;
    QComboBox * cSearchChoice;
    QComboBox * cStuffType;
    QComboBox * cComicType;
    QComboBox * cDVDType;
    QComboBox * cActionSize;
    QComboBox * cUserType;

    QPushButton * pSearch;

    QGridLayout * searchGrid;
    QVBoxLayout * searchLayout;

public:
    VSearchWindow(DatabaseStuff * dbSt=0, DatabaseUser *dbUs=0, User * usLog=0, QWidget *parent =0);

    void addLayout();


public slots:
    void changeSearchType();
    void changeStuffType();
    void searchItem();
    void doubleClick(int x);
    void removeCurrentList();
    void updateCurrentListUser(User*, QString, QString, QString, QString, QString);
    void updateCurrentListComicBook(ComicBook*, bool, double, QString, QString, QString, int, int);
    void updateCurrentListDVD(Dvd*,bool,double,QString,QString,QString,int,bool);
    void updateCurrentListActionFigure(ActionFigure*,bool,double,QString,QString,int,int,int);

signals:
    void saveEditStuff(VManageStuff*);
    void saveEditUser(VManageUser*);
    void disableMainWindow();
};

#endif // SEARCH_WINDOW_V_H
