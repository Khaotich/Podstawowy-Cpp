#include "my_widget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>


MyWidget::MyWidget(QWidget* parent) : QWidget(parent) {setFocus();}

void MyWidget::paintEvent([[maybe_unused]] QPaintEvent* event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor(Qt::GlobalColor::darkMagenta)));
    auto r = this->rect();
    painter.drawRect(r);

    painter.setBrush(QBrush(QColor(Qt::GlobalColor::darkYellow)));
    for (const auto& circ : circles)
    {
        QPointF point(circ.center.x() * r.width(), circ.center.y() * r.height());
        painter.drawEllipse(point, circ.radius, circ.radius);
    }
}

void MyWidget::mousePressEvent(QMouseEvent* event)
{
    auto pos = event->localPos();
    auto rec = rect();
    Circle c;
    c.radius = DEFAULT_RADIUS;
    c.center.setX(pos.x() / rec.width());
    c.center.setY(pos.y() / rec.height());
    circles.push_back(c);
    repaint();
}

//zadanie 1 (ctrl+z)
void MyWidget::keyPressEvent(QKeyEvent *event)
{
    if(event -> matches(QKeySequence :: Undo))
    {
        if(circles.size() > 0)
        {
            MyWidget::circles.pop_back();
            repaint();
        }
    }
}

//zadanie 2 (scroll myszki zmienia rozmiar kółek)
void MyWidget::wheelEvent(QWheelEvent *event)
{
    if(event -> delta() > 0)
    {
        for(unsigned int i = 0; i < circles.size(); i++)
        {
            circles[i].radius *= 3;
        }
    }
    else
    {
        for(unsigned i = 0; i < circles.size(); i++)
        {
            circles[i].radius /= 3;
        }
    }
    repaint();
}
