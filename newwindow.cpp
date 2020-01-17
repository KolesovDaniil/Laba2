#include "newwindow.h"
#include "ui_newwindow.h"
#include <QRegExpValidator>

NewWindow::NewWindow(QWidget *parent, Table* _table) :
    QDialog(parent),
    ui(new Ui::NewWindow),
    table(_table)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp( "\\d{1,4}")));
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp( "\\d{1,4}")));
}

NewWindow::~NewWindow()
{
    delete ui;
}

void NewWindow::on_pushButton_2_clicked()
{
    table->resize(ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt());
    this->close();
}

void NewWindow::on_pushButton_clicked()
{
    this->close();
}
