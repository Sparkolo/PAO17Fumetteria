#ifndef  STARRED_ASK_V_H
#define  STARRED_ASK_V_H
#include<QDialog>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QString>
#include<QRegExpValidator>
#include<QMessageBox>
#include"model/gold_user.h"
#include"model/nerd_stuff.h"

class VStarredAsk: public QDialog{
private:
    Q_OBJECT
    GoldUser *us;
    NerdStuff *st;

    QLabel *ask;
    QPushButton *pYes;
    QPushButton *pNo;

    QVBoxLayout *loginLayout;
    QGridLayout * loginGrid;

public:
    VStarredAsk(GoldUser *gu, NerdStuff *st);

    void setAskRemove();

public slots:
    void doAdd();
    void noAdd();
    void deleteStar();

signals:
    void refreshStarredList();
};

#endif //  STARRED_ASK_V_H
