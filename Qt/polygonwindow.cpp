#include "polygonwindow.h"
#include "ui_polygonwindow.h"
#define PI (3.14159265359)

polygonwindow::polygonwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::polygonwindow)
{
    ui->setupUi(this);
}

polygonwindow::~polygonwindow()
{
    delete ui;
}



void polygonwindow::paintEvent(QPaintEvent *e)
{
    Xcenter = width()/2;
    Ycenter = (height()/2)-20;
    if(aletzis)
    {
        QTransform center;
        center.translate(Xcenter, Ycenter);
        transforms.push_back(center);
        aletzis = false;
    }
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);
    std::string opcion = ui->comboBox->currentText().toStdString();
    if(opcion == "Polygon")
    {
        lados = ui->ladosPoligono->text().toInt();
        double radio = (float)100;
        double angulo = (double)360.0/(double)lados;
        angulo *= PI/(float)180;
        puntos.clear();

        for(int i=0; i<transforms.size(); ++i)
        {
            painter.setTransform(transforms[i],true);
            for(int j = 0; j<lados; j++)
            {
                QPoint puntillos((radio * cos(angulo*j)), (radio * sin(angulo*j)));
                puntos << puntillos;
            }
            painter.drawPolygon(puntos);
        }
    }
    else if(opcion == "Cube")
    {
        for(int i =0; i < transforms.size(); i++)
        {
            painter.setTransform(transforms[i], true);
            paintCube(painter);
        }
    }
    else if(opcion == "Rectangular Prism")
    {
        for(int i=0; i<transforms.size(); ++i)
        {
            painter.setTransform(transforms[i],true);
            paintPrismaR(painter);
        }
    }
    else if(opcion == "Triangular Prism")
    {
        for(int i=0; i<transforms.size(); ++i)
        {
            painter.setTransform(transforms[i],true);
            paintPrismT(painter);
        }
    }
    else if(opcion == "Cone")
    {
        for(int i=0; i<transforms.size(); ++i)
        {
            painter.setTransform(transforms[i],true);
            paintCone(painter);
        }
    }
    else if(opcion == "Arch")
    {
        for(int i=0; i<transforms.size(); ++i)
        {
            painter.setTransform(transforms[i],true);
            paintArch(painter);
        }
    }
}

void polygonwindow::paintPrismaR(QPainter & painter)
{
    int x0 = 0;
    int y0 = 50;
    int x1 = 50;
    int y1 = 50;
    int x2 = 0;
    int y2 = -100;
    int x3 = 50;
    int y3 = -100;
     //Se ponen los puntos de las esquinas de el otro rectángulo
    int x4 = x0+30;
    int y4 = y0-50;
    int x5 = x1+30;
    int y5 = y1-50;
    int x6 = x2+30;
    int y6 = y2-50;
    int x7 = x3+30;
    int y7 = y3-50;

    painter.drawLine(x0,y0,x1,y1);
    painter.drawLine(x2,y2,x3,y3);
    painter.drawLine(x2,y2,x0,y0);
    painter.drawLine(x3,y3,x1,y1);
    painter.drawLine(x4,y4,x5,y5);
    painter.drawLine(x6,y6,x7,y7);
    painter.drawLine(x6,y6,x4,y4);
    painter.drawLine(x7,y7,x5,y5);
    //Se unen los rectángulos
    painter.drawLine(x0,y0,x4,y4);
    painter.drawLine(x1,y1,x5,y5);
    painter.drawLine(x2,y2,x6,y6);
    painter.drawLine(x3,y3,x7,y7);
}

void polygonwindow::paintCube(QPainter &painter)
{
    int x1 = -25;
    int y1 = 25;
    int x2 = 25;
    int y2 = 25;
    int x3 = -25;
    int y3 = -25;
    int x4 = 25;
    int y4 = -25;
    int distProp = (x2-x1)/2;
    int _x1 = x1+distProp;
    int _y1 = y1-distProp;
    int _x2 = x2+distProp;
    int _y2 = y2-distProp;
    int _x3 = x3+distProp;
    int _y3 = y3-distProp;
    int _x4 = x4+distProp;
    int _y4 = y4-distProp;

      //Pone las lineas entre los dos cuadrados
    painter.drawLine(x1, y1, x2, y2);
    painter.drawLine(x1, y1, x3, y3);
    painter.drawLine(x2, y2, x4, y4);
    painter.drawLine(x3, y3, x4, y4);
    painter.drawLine(_x1, _y1, _x2, _y2);
    painter.drawLine(_x1, _y1, _x3, _y3);
    painter.drawLine(_x2, _y2, _x4, _y4);
    painter.drawLine(_x3, _y3, _x4, _y4);
    painter.drawLine(x1, y1, _x1, _y1);
    painter.drawLine(x2, y2, _x2, _y2);
    painter.drawLine(x3, y3, _x3, _y3);
    painter.drawLine(x4, y4, _x4, _y4);
}

void polygonwindow::paintPrismT(QPainter &painter)
{
    int x1 = 0;
     int y1 = -50;
     int x2 = -25;
     int y2 = -70;
     int x3 = 25;
     int y3 = -70;
     int _x1 = 0;
     int _y1 = -50+50;
     int _x2 = -25;
     int _y2 = -70+50;
     int _x3 = 25;
     int _y3 = -70+50;

     //Se unen los triángulos con lineas
     painter.drawLine(x1,y1,x2,y2);
     painter.drawLine(x1,y1,x3,y3);
     painter.drawLine(x2,y2,x3,y3);
     painter.drawLine(_x1,_y1,_x2,_y2);
     painter.drawLine(_x1,_y1,_x3,_y3);
     painter.drawLine(_x2,_y2,_x3,_y3);
     painter.drawLine(x1,y1,_x1,_y1);
     painter.drawLine(x2,y2,_x2,_y2);
     painter.drawLine(_x3,_y3,x3,y3);
}

void polygonwindow::paintCone(QPainter &painter)
{
    painter.drawEllipse(-25,-17,50,25);
    int x1 = 0;
    int y1 = 40;
    painter.drawLine(x1,y1,-25,0);
    painter.drawLine(x1,y1,25,0);
}

void polygonwindow::paintArch(QPainter &painter)
{
    int arcSize = ui->Arc->text().toInt();
    int radius = ui->Radius->text().toInt();
    QRect box(QPoint(-arcSize/2, -arcSize/2), QSize(arcSize, arcSize));
    int startAngle = 0 * 16;
    radius *= 16;
    painter.drawArc(box, startAngle, radius);
}





void polygonwindow::on_paintPolygon_clicked()
{
    qDebug() << "hi";
    transforms.clear();
    aletzis = true;
    update();
}

void polygonwindow::on_Translate_clicked()
{
    QString transX = ui->transX->text();
    QString transY = ui->transY->text();

    if(!transX.isEmpty() && !transY.isEmpty())
    {
        qDebug() << "entro";
        float _transX = transX.toInt();
        float _transY = transY.toInt();
        QTransform translate;
        translate.translate(_transX, _transY);
        transforms.push_back(translate);
    }

    update();
}

void polygonwindow::on_ReflectY_clicked()
{
    QTransform reflectY;
    reflectY.scale(-1,1);
    transforms.push_back(reflectY);
    update();
}

void polygonwindow::on_ReflectX_clicked()
{
    QTransform reflectX;
    reflectX.scale(1,-1);
    transforms.push_back(reflectX);
    update();
}

void polygonwindow::on_Scale_clicked()
{
    float scalaX = ui->scaleX->text().toFloat();
    float scalaY = ui->scaleY->text().toFloat();
    QTransform escala;
    escala.scale(scalaX, scalaY);
    transforms.push_back(escala);
    update();
}

void polygonwindow::on_rotateButton_clicked()
{
    float rotateAngle = ui->rotate->text().toFloat();
    QTransform rota;
    rota.rotate(rotateAngle);
    transforms.push_back(rota);
    update();
}
