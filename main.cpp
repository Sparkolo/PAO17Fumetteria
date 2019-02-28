#include"model/database_stuff.h"
#include"model/database_user.h"
#include"controller/c_main_window.h"
#include<QApplication>
#include"model/database_stuff.h"
#include"model/nerd_stuff.h"
#include"model/comic_book.h"
#include"model/dvd.h"
#include"model/action_figure.h"


 int main(int argc, char *argv[])
{


     QApplication app(argc,argv);
     app.setWindowIcon(QIcon("./images/icon.png"));

    CMainWindow prima;

    prima.launchLogin();

    return app.exec();

 }

