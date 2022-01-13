#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class DataWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DataWidget(QWidget *parent = nullptr);

    QList<QString> times;
    QList<float> data;
    float max = -1000;
    float min = 1000;

    void clear() { data.clear(); times.clear(); }
    void addData(float d) { data.append(d); }
    void addTime(QString s) { times.append(s); }
    void analyzeData();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:



};

#endif // DATAWIDGET_H
