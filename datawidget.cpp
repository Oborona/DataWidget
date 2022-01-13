#include "datawidget.h"

DataWidget::DataWidget(QWidget *parent) : QWidget(parent)
{
    //resize(400, 300);
}

void DataWidget::analyzeData()
{
    for (long i = 0; i < data.size(); i++)
    {
        if (data[i] < min)
            min = data[i];
        if (data[i] > max)
            max = data[i];
    }
}

void DataWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    float w = width();
    float h = height();

    QPainter p(this);
    QPen pen(Qt::green, h/200);
    p.setPen(pen);
    p.setBrush(Qt::black);
    p.drawRect(0, 0, w, h);
    p.drawLine(w*0.02, h*0.05, w*0.02, h*0.95);
    p.drawLine(w*0.02, h*0.95, w*0.98, h*0.95);

    QFont font;
    font.setPixelSize(h*0.04);
    p.setFont(font);


    float coeff = data.size()/(w*0.96);
    float diff = max - min;

    for(int i = 0; i < (h*0.93)/10; i++)
        p.drawText(w*0.02, h*0.02 + ((h*0.93)/10)*i, QString("%1").arg(max-(diff/10)*i));
    for(int i = 0; i <= 5; i++)
        p.drawText(w*0.02 + ((w*0.93)/5)*i, h*0.98, times[(times.size()/5)*i]);

    QPoint p1;
    QPoint p2;
    for (float i = 1; i < (w*0.96); i++)
    {
        pen.setWidth(h/400);
        p.setPen(pen);
        p1.setX(w*0.02 + i-1);
        float d = data[coeff*(i-1)];
        p1.setY(h*0.02 + (max-d)/diff*h*0.93);
        p2.setX(w*0.02 + i);
        d = data[coeff*i];
        p2.setY(h*0.02 + (max-d)/diff*h*0.93);
        p.drawLine(p1, p2);
    }
}

void DataWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    update();
}
