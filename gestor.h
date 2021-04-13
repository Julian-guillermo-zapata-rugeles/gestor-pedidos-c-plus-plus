#ifndef GESTOR_H
#define GESTOR_H

#include <QMainWindow>
#include <manejador_archivos.h>
#include <registros.h>

namespace Ui {
class gestor;
}

class gestor : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestor(QWidget *parent = nullptr);
    ~gestor();

private slots:
    void on_btn_nuevo_clicked();

private:
    Ui::gestor *ui;
    manejador_archivos gestorArchivos;
    registros *venta_registros;
};


#endif // GESTOR_H
