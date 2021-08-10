#include "picaria.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Picaria w;
    w.setWindowIcon(QIcon(":/icon"));
    w.show();
    return a.exec();
}
