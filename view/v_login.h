#ifndef  LOGIN_V_H
#define  LOGIN_V_H
#include<QDialog>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QString>
#include<QRegExpValidator>
#include<QMessageBox>

class VLogin: public QDialog{
private:
    Q_OBJECT
    QGridLayout * gridLogin;
    QLineEdit * tUsername;
    QLineEdit * tPassword;
    QLabel * lUsername;
    QLabel *lPassword;
    QPushButton *pLogin;
    QVBoxLayout *layoutLogin;

public:
    VLogin();
    void clearFields();

public slots:
    void login();

signals:
    void tryLogin(const QString&, const QString&);
};

#endif //  LOGIN_V_H
