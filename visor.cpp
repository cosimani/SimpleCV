#include "visor.h"
#include <QApplication>

#include <QMessageBox>
#include <QFileInfo>
#include <QDebug>

Visor::Visor( QWidget *parent ) : QLabel( parent ),
                                  videoCapture ( new cv::VideoCapture( 0 ) ),
                                  sceneTimer ( new QTimer( this ) )
{
    sceneTimer->start( 10 );
    connect( sceneTimer, SIGNAL( timeout() ), SLOT( slot_procesar() ) );
}

Visor::~Visor()
{
    videoCapture->release();
}

void Visor::slot_procesar()  {

    if ( seVisualiza == 0 )  {
        videoCapture->operator >>( frame );
    }
    else if ( seVisualiza == 1 )  {
        frame = cv::imread( "../SimpleCV/imagenes/gato.jpg" );
        Size size( 640, 480 );
        cv::resize( frame, frame, size );
    }
    else if ( seVisualiza == 2 )  {
        frame = cv::imread( "../SimpleCV/imagenes/perro.jpg" );
        Size size(640,480);
        cv::resize( frame, frame, size );
    }
    else if ( seVisualiza == 3 )  {
        frame = cv::imread( "../SimpleCV/imagenes/perro_gato.jpg" );
        Size size( 640, 480 );
        cv::resize( frame, frame, size );
    }
    else  {
        videoCapture->operator >>( frame );
    }

    cvtColor(frame, frame, CV_BGR2RGB);



    // Procesar aqui





    QPixmap pixmap = QPixmap::fromImage( QImage( frame.data,
                                                 frame.cols,
                                                 frame.rows,
                                                 frame.step,
                                                 QImage::Format_RGB888
                                               ).scaled( this->width(), this->height() )
                                       );
    this->setPixmap( pixmap );
}

void Visor::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() )
    {
    case Qt::Key_C:
        this->seVisualiza = 0;
        break;

    case Qt::Key_1:
        this->seVisualiza = 1;
        break;

    case Qt::Key_2:
        this->seVisualiza = 2;
        break;

    case Qt::Key_3:
        this->seVisualiza = 3;
        break;

    case Qt::Key_Escape:
        videoCapture->release();
        qApp->quit();
        break;

    default:;
    }
}








