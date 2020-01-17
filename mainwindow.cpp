#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "typewindow.h"
#include "newwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QApplication>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , table(5,5)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(20);
    ui->tableWidget->setColumnCount(8);
    for(int i = 0; i<20;++i){
        for(int j = 0; j<8;++j){
            QTableWidgetItem *newItem = new QTableWidgetItem(tr(""));
            newItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ui->tableWidget->setItem(i,j,newItem);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_table(int _rows, int _columns){
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(_rows);
    ui->tableWidget->setColumnCount(_columns);
    for(int i = 0; i<_rows;++i){
        for(int j = 0; j<_columns;++j){
            QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(QString::fromStdString(table.get_cell(i,j))));
            newItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            ui->tableWidget->setItem(i,j,newItem);
        }
    }

}


void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_actionSave_triggered()
{
    // вызываем диалог сохранения файла
        QString fileName=
                QFileDialog::getSaveFileName( this,
                                              tr("Сохранить файл как"),
                                              "report",
                                              tr("TXT(*.txt)")
                                              );
        // Если указали путь, сохраняем
        if(!fileName.isEmpty())
        {
            table.write_file(fileName.toUtf8().constData());
        }
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName=
            QFileDialog::getOpenFileName(this);
    // Если указали путь, загружаем
    if(!fileName.isEmpty())
    {
        table.read_file(fileName.toUtf8().constData());
        for(int i = 0; i<table.size().first;++i){
            for(int j = 0; j<table.size().second;++j){
            }
        }
        this->update_table(table.size().first,table.size().second);
    }
}
//void MainWindow::closeEvent(QCloseEvent *event)
//{
//    //Здесь код
//    event->accept();
//}
void MainWindow::on_actionNew_triggered()
{
    NewWindow *newWindow = new NewWindow(this,&table);
    newWindow->setModal(true);
    newWindow->exec();
    this->update_table(table.size().first,table.size().second);
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    TypeWindow window(this,&table,row,column,ui->tableWidget->item(row,column)->text(), ui->tableWidget->item(row,column));
    window.setModal(true);
    window.exec();
}
