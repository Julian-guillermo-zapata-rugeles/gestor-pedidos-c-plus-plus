#include "gestor.h"
#include "ui_gestor.h"

gestor::gestor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestor)
{
    ui->setupUi(this);
    gestorArchivos.checkFileExist();
    on_actualiza_clicked();
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

void gestor::on_actualiza_clicked()
{
    ui->textos->setHtml(gestorArchivos.generateTable());
}
