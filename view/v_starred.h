#ifndef  STARRED_V_H
#define STARRED_V_H
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include"model/database_stuff.h"
#include"model/database_user.h"
#include"model/user.h"
#include"view/v_manage_user.h"
#include"view/v_starred_ask.h"

class VStarred:public QDialog{
 private:
    Q_OBJECT
    User *us;
    DatabaseStuff* stuffList;

    QTableWidget *myList;
    QVBoxLayout * stuffLayout;
    QGridLayout * stuffGrid;
    VStarredAsk * askStar;

public:
    VStarred(User *us,DatabaseStuff *st,QWidget *parent=0);

    void addItemStuff(int r, NerdStuff *st);
    void addListAllStuff(User *u);

public slots:
    void doubleClick(int x);
    void refreshList();

signals:
    void disableMainWindow();
};

#endif // STARRED_V_H
