#ifndef VISOR_H
#define VISOR_H

#define RESOLUTION_WIDTH  640
#define RESOLUTION_HEIGHT 480

#include <stdio.h>
#include <stdlib.h>

#include <QDir>
#include <QFile>
#include <QTimer>
#include <QLabel>
#include <QVector>
#include <QKeyEvent>
#include <QMouseEvent>

#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
using namespace std;

class Visor : public QLabel  {
    Q_OBJECT

private:
    VideoCapture *videoCapture;
    QTimer *sceneTimer;
    cv::Mat frame;

public:
    Visor( QWidget *parent = 0 );
    ~Visor();

    // Si es 0 -> Se muestra la camara
    // Si es 1 -> Se muestra un gato
    // Si es 2 -> Se muestra un perro
    // Si es 3 -> Se muestra un perro y un gato
    int seVisualiza;

protected:
    void keyPressEvent( QKeyEvent *event );

private slots:
    void slot_procesar();

};

#endif // VISOR_H
