#include "my_widget.h"

#include <QPainter>

MyWidget :: MyWidget(QWidget* parent) : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget :: paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    //ustawiam czcionkę na rysowanego plusa
    QFont font = painter.font();
    font.setPointSize(40);
    painter.setFont(font);

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::magenta)));
    painter.translate(rect().width() / 2.0, rect().height() / 2.0);

    //plus
    painter.drawText(-20, 0, "+");

    auto side = std::min(rect().width(), rect().height());
    painter.scale(side / 200.0, side / 200.0);

    //gradienty
    QRadialGradient rg(QPointF(52.5, 52.5), 10);
    rg.setColorAt(1, QColor(209, 139, 211));
    rg.setColorAt(0, Qt::GlobalColor::darkMagenta);
    painter.setBrush(rg);
    painter.setPen(Qt::NoPen);

    for (int i = 0; i < num_disks; i++)
    {
        if (i != hidden)
        {
            painter.drawEllipse(40, 40, 25, 25);
        }
        painter.rotate(360.0 / num_disks);
    }
}

void MyWidget :: on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}

void MyWidget :: toggle_animation()
{
    if(timer.isActive())
    {
        timer.stop();
    }
    else
    {
        timer.start(timer_interval);
    }
}
