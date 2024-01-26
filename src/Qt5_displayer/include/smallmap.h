#ifndef SMALLMAP_H
#define SMALLMAP_H

#include <QObject>
#include <QLabel>

class smallMap : public QLabel
{
    Q_OBJECT
public:
    smallMap(QWidget * parent);
    ~smallMap();

    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

    void wheelEvent(QWheelEvent *event);

    void changeScaleValue(QPoint event, int angle);
public Q_SLOTS:
    void drawCircle(QMouseEvent &e);

public:
    QPointF pos;
    QPixmap image;
    int mapx;
    int mapy;
    int mapcols;
    int maprows;
    QPointF mousePos;
    QPointF drawPos;
    QRect rectPixmap;
    bool isMousePress;
    float scaleValue;

    float SCALL_MAX_VALUE;
    float SCALL_MIN_VALUE;
};

#endif // SMALLMAP_H
