#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    this->resize(900, 500);
    layout = new QGridLayout(this);
        layout->addWidget(edit = new QLineEdit(this), 0, 0, 1, 1);
        layout->addWidget(button = new QPushButton("Выбрать", this), 0, 1, 1, 1);
        layout->addWidget(w = new DataWidget(this), 1, 0, 1, 2);
    this->setLayout(layout);
    connect(button, SIGNAL(clicked(bool)), this, SLOT(buttonClicked(bool)));
    edit->setText("C:/Users/mongr/Documents/build-ArduinoManager-Desktop_Qt_6_1_2_MSVC2019_64bit-Debug/debug/logs/2022.01.08-03_52_58-Комната.log");
    loadFile();
}

int MainWindow::loadFile()
{
    QFile* f = new QFile(edit->text());
    if(!f->open(QIODevice::ReadOnly))
    {
        qDebug() << "Cannot open " << edit->text();
        return 0;
    }

    QTextStream s(f);
    while(!s.atEnd())
    {
        QStringList strl = s.readLine().split(" ");
        if (strl.size() < 4)
            continue;
        bool ok = false;
        float f = strl[3].toFloat(&ok);
        if (ok == true)
            w->addData(f);
        else
            w->addData(w->data[w->data.size()-1]);
        w->addTime(strl[1]);
    }
    w->analyzeData();
    return 1;
}

void MainWindow::buttonClicked(bool)
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::currentPath(),
                                "Logs (*.log);");
   edit->setText(fileName);
   w->clear();
   loadFile();
}
