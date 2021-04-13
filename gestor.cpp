#include "gestor.h"
#include "ui_gestor.h"

gestor::gestor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestor)
{
    ui->setupUi(this);
    gestorArchivos.checkFileExist();
    ui->textos->setHtml("<center><table border=\"1\" width=\"100%\"> <tr> <th> ID </th> <th> ENTREGA </th>  <th> NOMBRE </th> <th> PRODUCTO </th> <th> CANTIDAD </th> <th> PRECIO C/U </th>  <th> TOTAL </th> </tr></table>");
}

gestor::~gestor()
{
    delete ui;
}

void gestor::on_btn_nuevo_clicked()
{
    venta_registros =  new registros();
    venta_registros->show();
}
