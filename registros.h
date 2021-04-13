#ifndef REGISTROS_H
#define REGISTROS_H


#include <iostream>
#include <manejador_archivos.h>
#include <QWidget>

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

private:
    Ui::registros *ui;
    manejador_archivos gestorArchivos;

};

#endif // REGISTROS_H
