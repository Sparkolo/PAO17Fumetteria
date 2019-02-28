#ifndef NERDSTUFF_C_H
#define NERDSTUFF_C_H
#include<QObject>
#include<QMessageBox>
#include"model/database_stuff.h"
#include"view/v_manage_stuff.h"


class CNerdStuff:public QObject {
private:
    Q_OBJECT
    DatabaseStuff * StuffList;
    VManageStuff * vStuff;

public:
  CNerdStuff(DatabaseStuff * dbStuff, QObject* parent=0);
  void refreshVStuff(VManageStuff* vSt);

 public slots:
  void receiveCreateStuff(NerdStuff*t);
  void receiveEditComicBook(ComicBook * t, bool lim, double pr, QString tit, QString aut, QString typ, int vol, int pag);
  void receiveEditDVD(Dvd * t, bool lim, double pr, QString tit, QString pro, QString typ, int len, bool res);
  void receiveEditActionFigure(ActionFigure * t, bool lim, double pr, QString nam, QString manuf, int w, int h, int d);
  void receiveDeleteStuff(NerdStuff*t);
};
#endif // NERDSTUFF_C_H
