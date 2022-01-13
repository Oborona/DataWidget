#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QFileDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QTextStream>
#include <QDebug>

#include "datawidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);


private:
    QGridLayout* layout;
    QLineEdit* edit;
    QPushButton* button;
    DataWidget* w;
    int loadFile();

signals:

public slots:
    void buttonClicked(bool);

};

#endif // MAINWINDOW_H
