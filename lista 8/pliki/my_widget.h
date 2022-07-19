#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <vector>

class MyWidget : public QWidget
{
    Q_OBJECT
  public:
    constexpr static double DEFAULT_RADIUS = 75.0;

    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    //zadania 1 i 2
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

    struct Circle
    {
        QPointF center;
        double radius;
    };

    private:
    std::vector<Circle> circles;
};

#endif  // MYWIDGET_H
