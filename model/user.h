#ifndef  USER_H
#define USER_H
#include<QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

class User{
private:
    QString name;
    QString surname;
    QString username;
    QString password;     
public:
    User(QString nam="",QString surn="",QString usern="",QString pass="");
    virtual ~User()=default;

    virtual QString getType() const =0;
    virtual bool hasStarred() const=0;
    virtual bool hasUserList() const=0;
    virtual bool hasManagement()const=0;

    QString getName() const;
    QString getSurname() const;
    QString getUsername() const;
    QString getPassword() const;

    void setName(const QString& newName);
    void setSurname(const QString & newSurname);
    void setUsername(const QString & newUsername);
    void setPassword(const QString & newPass);

    virtual void saveUser(QXmlStreamWriter& xmlWriter);
    void loadUser(QXmlStreamReader& xmlReader);
};

#endif // USER_H
