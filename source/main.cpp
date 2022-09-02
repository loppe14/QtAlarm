#include <QApplication>
#include <QPixmap>
#include <QLabel>
#include <QFileInfo>
#include "alarmwindow.h"
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    AlarmWindow w;
    w.show();
    return app.exec();
}