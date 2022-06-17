#include "mainwindow.h"
#include "montgomery.h"
#include "qmessagebox.h"
#include "QWidget"
#include "./ui_mainwindow.h"






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnCalc_clicked()
{
    int mod= ui->LeMod->text().toInt(nullptr,10);
    int pow= ui->LePow->text().toInt(nullptr,10);
    int base= ui->LeBase->text().toInt(nullptr,10);
    QString a;
    QString b;
    if (mod == 0 || (mod & 1) == 0) {
        QMessageBox msgBox;
        msgBox.setText("Mod should be more than zero and odd!");
        msgBox.exec();
 }

   Montgomery x{};
   a=QString::number(x.MontPow(base,pow,mod));
   b=QString::number(power(base,pow,mod));
   ui->res->setText(a);
   ui->res_2->setText(b);
}

