#pragma once

#include <QMainWindow>
#include <table.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

//    void on_tableWidget_cellChanged(int row, int column);

//    void on_tableWidget_cellEntered(int row, int column);

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_actionNew_triggered();

private:
    void update_table(int,int);
    Table table;
    Ui::MainWindow *ui;
};
