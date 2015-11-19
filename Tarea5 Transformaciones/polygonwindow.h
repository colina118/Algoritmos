#ifndef POLYGONWINDOW_H
#define POLYGONWINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QDebug>
namespace Ui {
class polygonwindow;
}

class polygonwindow : public QDialog
{
    Q_OBJECT

public:
    explicit polygonwindow(QWidget *parent = 0);
    ~polygonwindow();

private slots:
    void on_paintPolygon_clicked();

    void on_Translate_clicked();

    void on_ReflectY_clicked();

    void on_ReflectX_clicked();

    void on_Scale_clicked();

    void on_rotateButton_clicked();

private:
    Ui::polygonwindow *ui;
    int lados;
    double Xcenter;
    bool aletzis = true;
    double Ycenter;
    QPolygon puntos;
    QVector<QTransform> transforms;


protected:

    void paintEvent(QPaintEvent *e);
    void paintPrismaR(QPainter &painter);
    void paintCube(QPainter &painter);
    void paintPrismT(QPainter &painter);
    void paintCone(QPainter &painter);
    void paintArch(QPainter &painter);
    void translate();
    void rotate();
    void scale();
    void reflection();
};

#endif // POLYGONWINDOW_H
