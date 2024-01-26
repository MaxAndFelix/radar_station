#include "pnpwidget.h"
#include "ui_pnpwidget.h"
#include <QPainter>
#include <QPen>
#include <iostream>
#include <QMouseEvent>
#include <QDialog>
#include <QPixmap>
#include <QFileDialog>
#include <QDebug>
#include <QScrollBar>

// #include "opencv2/opencv.hpp"
// #include <iostream>
// #include <vector>

pnpWidget::pnpWidget() :
    ui(new Ui::pnpWidget)
{
    ui->setupUi(this);
    ui->cameraImage->installEventFilter(this);
    QString image_path = "/home/mechax/zyb/radar_station/src/Qt5_displayer/map/test.png";
    //QString image_path = QFileDialog::getOpenFileName(this, "打开图片", ".", "Images (*.png *.xpm *.jpg)");
    cameraimage.load(image_path);
    this->isBeginPoint = false;

    connect(ui->beginPoint,SIGNAL(clicked()),this,SLOT(beginPoint()));
    connect(ui->restartPoint,SIGNAL(clicked()),this,SLOT(restartPoint()));
    connect(ui->beginPnp,SIGNAL(clicked()),this,SLOT(beginPnp()));

    parameter_init();
}

pnpWidget::~pnpWidget()
{
    delete ui;
}

void pnpWidget::parameter_init()
{
    far_CamMatrix_.at<double>(0, 0) = 1474.62545;
    far_CamMatrix_.at<double>(0, 1) = 0.0;
    far_CamMatrix_.at<double>(0, 2) = 367.67245;
    far_CamMatrix_.at<double>(1, 0) = 0.0;
    far_CamMatrix_.at<double>(1, 1) = 1463.59535;
    far_CamMatrix_.at<double>(1, 2) = 274.85727;
    far_CamMatrix_.at<double>(2, 0) = 0.0;
    far_CamMatrix_.at<double>(2, 1) = 0.0;
    far_CamMatrix_.at<double>(2, 2) = 1.0;
    far_distCoeffs_.at<double>(0, 0) = -0.025299;
    far_distCoeffs_.at<double>(0, 1) = -0.874546;
    far_distCoeffs_.at<double>(0, 2) = -0.000261;
    far_distCoeffs_.at<double>(0, 3) = 0.018625;
    far_distCoeffs_.at<double>(0, 4) = 0.0;

    Point3d objectpoint_one;
    objectpoint_one.x = 2350.0;
    objectpoint_one.y = 7000.0;
    objectpoint_one.z = 0.0;
    far_objectPoints.push_back(objectpoint_one);
    Point3d objectpoint_two;
    objectpoint_two.x = 2350.0;
    objectpoint_two.y = 7000.0;
    objectpoint_two.z = 500.0;
    far_objectPoints.push_back(objectpoint_two);
    Point3d objectpoint_three;
    objectpoint_three.x = 4750.0;
    objectpoint_three.y = 6800.0;
    objectpoint_three.z = 500.0;
    far_objectPoints.push_back(objectpoint_three);
    Point3d objectpoint_four;
    objectpoint_four.x = 4750.0;
    objectpoint_four.y = 6800.0;
    objectpoint_four.z = 0.0;
    far_objectPoints.push_back(objectpoint_four);
}

bool pnpWidget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->cameraImage)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                if(isBeginPoint)
                {
                    int pointNum = this->points.size();
                    QString pointText = "第" + QString::number(pointNum + 1) + "个点的坐标为 x:";
                    pointText = pointText + QString::number(mouseEvent->x());
                    pointText = pointText + "      y:" + QString::number(mouseEvent->y());
                    mapMessageDisplay(pointText);
                    /*if(pointNum < 5)
                    {
                        lastPos = mousePos;
                        mousePos = mouseEvent->pos();
                        points.push_back(mousePos);
                        ui->cameraImage->update();
                    }
                    else
                    {
                        mapMessageDisplay("Too many points");
                    }*/
                    switch (pointNum)
                    {
                    case 0:
                        lastPos = mousePos;
                        mousePos = mouseEvent->pos();
                        points.push_back(mousePos);
                        ui->cameraImage->update();
                        mapMessageDisplay("请点击第二个标定点");
                        break;
                    case 1:
                        lastPos = mousePos;
                        mousePos = mouseEvent->pos();
                        points.push_back(mousePos);
                        ui->cameraImage->update();
                        mapMessageDisplay("请点击第三个标定点");
                        break;
                    case 2:
                        lastPos = mousePos;
                        mousePos = mouseEvent->pos();
                        points.push_back(mousePos);
                        ui->cameraImage->update();
                        mapMessageDisplay("请点击第四个标定点");
                        break;
                    case 3:
                        lastPos = mousePos;
                        mousePos = mouseEvent->pos();
                        points.push_back(mousePos);
                        ui->cameraImage->update();
                        mapMessageDisplay("选点完成，请选择是否开始pnp解算");
                        isBeginPoint = false;
                        break;
                    default:
                        mapMessageDisplay("够了够了，不要点了");
                    }
                }
            }
        }
        if(event->type() == QEvent::Paint)
        {
            QPainter painter(ui->cameraImage);
            painter.setPen(QPen(Qt::black,2));
            QRect rect(0,0,ui->cameraImage->width(),ui->cameraImage->height());
            //std::cout << "绘画camerimage" << std::endl;
            painter.drawPixmap(rect,cameraimage);
            //qDebug() << "x: " << ui->cameraImage->x() << "y: " << ui->cameraImage->y();
            //qDebug() << "width: " << ui->cameraImage->width() << "height: " << ui->cameraImage->height();

            int pointNum = this->points.size();
            if(pointNum == 0)
            {

            }
            else if(pointNum == 1)
            {
                painter.drawEllipse(mousePos,5,5);
            }
            else
            {
                for(int i = 0;i<pointNum;i++)
                {
                    painter.drawEllipse(points[i],5,5);
                    if(i == 3)
                    {
                        painter.drawLine(points[i],points[0]);
                    }
                    if(i != pointNum - 1)
                    {
                        painter.drawLine(points[i],points[i+1]);
                    }
                }
            }
            //qDebug() << "x: " << mousePos.x() << "y: " << mousePos.y();
            return true;
        }
        return false;
    }
    return QWidget::eventFilter(obj,event);
}

void pnpWidget::beginPoint()
{
    this->points.clear();
    this->isBeginPoint = true;
    mapMessageDisplay("开始标点，请点击第一个标定点");
}

void pnpWidget::restartPoint()
{
    if(points.size() == 0)
    {
        mapMessageDisplay("还没有点的数据，请点击开始标点!");
        return;
    }
    this->points.clear();
    ui->cameraImage->update();
    this->isBeginPoint = true;
    mapMessageDisplay("请重新选择第一个点");
}

void pnpWidget::beginPnp()
{
    if(points.size() == 4)
    {
        mapMessageDisplay("开始解算");
        std::vector<Point2d> image_points;
        Point2d p1(points[0].x(),points[0].y());
        Point2d p2(points[1].x(),points[1].y());
        Point2d p3(points[2].x(),points[2].y());
        Point2d p4(points[3].x(),points[3].y());
        image_points.push_back(p1);
        image_points.push_back(p2);
        image_points.push_back(p3);
        image_points.push_back(p4);
        cout << "image_points.size():" << image_points.size() << endl;
        cout << "far_objectPoints.size():" << far_objectPoints.size() << endl;
        solvePnP(far_objectPoints,image_points,far_CamMatrix_,far_distCoeffs_,far_Rjacob,far_T);
        cout << "solvePnP" << endl;
        Rodrigues(far_Rjacob, far_R);
        cout << "Rodrigues" << endl;
        QString farR_message = "旋转矩阵:" + QString::number(far_R.at<double>(0,0)) + " " + QString::number(far_R.at<double>(0,1)) + " " + QString::number(far_R.at<double>(0,2)) + "\n"
                + QString::number(far_R.at<double>(1,0)) + " " + QString::number(far_R.at<double>(1,1)) + " " + QString::number(far_R.at<double>(1,2)) + "\n"
                + QString::number(far_R.at<double>(2,0)) + " " + QString::number(far_R.at<double>(2,1)) + " " + QString::number(far_R.at<double>(2,2));
        cout << "farR_message" << endl;
        QString farT_message = "平移矩阵:" + QString::number(far_T.at<double>(0,0)) + "\n" + QString::number(far_T.at<double>(1,0)) + "\n" + QString::number(far_T.at<double>(2,0));
        cout << "farT_message" << endl;
        mapMessageDisplay("解算完成");
        mapMessageDisplay(farR_message);
        mapMessageDisplay(farT_message);
        cout << "message" <<endl;
        points.clear();
        ui->cameraImage->update();
        Q_EMIT pnpFinished();
        cout << "end" << endl;
    }
    else
    {
        mapMessageDisplay("老哥点不够!");
    }
}

void pnpWidget::mapMessageDisplay(QString text)
{
     QPlainTextEdit *messageEdit = ui->message;
     if(!messageEdit->isReadOnly())
     {
         messageEdit->setReadOnly(true);
     }
     //messageEdit->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
     if(messageEdit->toPlainText().size() > 1024)
     {
         messageEdit->clear();
     }
     //messageEdit->insertPlainText(text);
     messageEdit->appendPlainText(text);
     QScrollBar * scrollbar = messageEdit->verticalScrollBar();
     if(scrollbar)
     {
         scrollbar->setSliderPosition(scrollbar->maximum());
     }
}

