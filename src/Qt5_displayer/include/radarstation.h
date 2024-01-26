#ifndef RADARSTATION_H
#define RADARSTATION_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QMutex>
#include "pnpwidget.h"
#include "qtnode.h"
#include "std_msgs/msg/float32_multi_array.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class radarStation; }
QT_END_NAMESPACE

class radarStation : public QMainWindow
{
    Q_OBJECT

public:
    radarStation(QWidget * parent = nullptr);
    ~radarStation();

    void mousePressEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *event);

    void drawCircle();

    void mapMessageDisplay(QString text);

    void init();
public Q_SLOTS:
    void changeToMapWidget();

    void changeToPnpWidget();

    void farImageUpdate();

    void depthImageUpdate();

    void publishPnpResult();
private:
    Ui::radarStation *ui;
    qtNode qtnode;
    mutable QMutex qimage_mutex;

    QPoint pos;
};
#endif // RADARSTATION_H
