#ifndef REGISTROS_H
#define REGISTROS_H


#include <iostream>
#include <manejador_archivos.h>
#include <QWidget>
#include <QDate>
#include <QDateTime>
#include <random>

using namespace std;
namespace Ui {
class registros;
}

class registros : public QWidget
{
    Q_OBJECT

public:
    explicit registros(QWidget *parent = nullptr);
    ~registros();

private slots:
    void on_pushButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

private:
    Ui::registros *ui;
    manejador_archivos gestorArchivos;
    QString fecha_elejida;

};

#endif // REGISTROS_H
