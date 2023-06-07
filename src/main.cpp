#include <QApplication>
#include "MainWindow.h"

Theme theme;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru");
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return a.exec();
}


