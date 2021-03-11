#include "plot.h"
#include <vector>
#include <QtGui/QPainter>
#include <QPen>


void createPlot(double* p_dist, int iter_num, int win_w, int win_h, QPainter &painter, QString color){

    double *p;
    p = &p_dist[0];

    int i;
    QPen pen;
    int length = 10;

    double step_x = 5 * win_w / 110;
   // double step_y = 6 * win_h / 110;
    double step_y = 5 * win_h / 110;

    /** draw expected **/

        pen.setWidth(2);
        pen.setColor("violet");
        painter.setPen(pen);
        painter.drawLine(win_w / 11, 10 * win_h / 11,  win_w / 11 + step_x * 10 , 10 * win_h / 11 - step_y * 10);


    /*Draw plot*/
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);

    pen.setColor(color);
    painter.setPen(pen);

    //double height = 10 * step_y;
    double width = 10*step_x;
    i = 0;

    double divisor = iter_num / 10;
    for (i = 1; i < iter_num; i++){
        //painter.drawLine( win_w / 11 + step_x * i/divisor, 10 * win_h / 11 - height * p[i - 1] ,  win_w / 11 + step_x * (i + 1)/divisor, 10 * win_h / 11 - height * p[i] );
        painter.drawLine( win_w / 11 + width * p[i -1 ], 10 * win_h / 11 - step_y * i/divisor ,  win_w / 11 + width * p[i], 10 * win_h / 11 - step_y * (i+ 1)/divisor );

    }
    painter.drawLine( win_w / 11 + width * p[i -1 ], 10 * win_h / 11 - step_y * i/divisor , win_w / 11 + step_x * 10 , 10 * win_h / 11 - step_y * 10);




    for (i = 1; i < length + 2; i++) {

       painter.drawLine( win_w / 11 - 3, 10 * win_h / 11 - (i-1) * step_y,  win_w / 11 + 3, 10 * win_h / 11 - (i-1) * step_y);
       painter.drawText(win_w / 11 - 40, 10 * win_h / 11 - (i-1) * step_y, QString::number((double)(i - 1)/10));

        painter.drawLine( win_w / 11 + (i-1) * step_x, 10 * win_h / 11 + 3,  win_w / 11 + (i-1) * step_x, 10 * win_h / 11 - 3);
        painter.drawText(win_w / 11 + (i-1) * step_x, 10 * win_h / 11 + 20, QString::number((double)(i - 1)/10));
    }


    pen.setWidth(2);
    pen.setColor(QColor(221, 196, 221));

    painter.setPen(pen);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11, 10 * win_h / 11 - step_y * 10);
    painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11 + step_x * 10 , 10 * win_h / 11);

}
