#include "histogram.h"
#include"qmath.h"
#include <QWidget>
#include <Math/ChiSquare.h>

void createHistogram(int sampleSize, int win_w, int win_h, QPainter &painter, ChiSquare* chisq) {


    double *a = chisq->theorFreq;
    double *b = chisq->empiricalFreq;
    int k = chisq->n;


    QPen pen;

    float win_width = (float) win_w / 300;
    float x, width = 20;
    int i;
    QFont *font = new QFont("Helvetica", 13);
    int length = k+1;
    painter.setFont(*font);

    double max1 = a[0];
    for (int i = 1; i < k+1; i++)
    {
        if (a[i] > max1)
        {
            max1 = a[i];
         }
     }
    double max2 = b[0];
    for (int i = 1; i < k+1; i++)
    {
        if (b[i] > max2)
        {
           max2 = b[i];
         }
     }
    double max = max1 > max2 ? max1 : max2;


    double step = max / (sampleSize / 10);
    pen.setWidthF(4);

    pen.setWidthF(2);
    painter.setPen(pen);
    max = roundf(max * 10) / 10;
    if (sampleSize > 100)
    {
        painter.drawText(win_w / 18 - 15, 10 * win_h / 11 - (width * win_width)/ 2 - max/(sampleSize/100) * 10 - 15, QString::number(max));
    }
    else{
        painter.drawText(win_w / 18 - 15, 10 * win_h / 11 - (width * win_width)/ 2 - max * 10 - 15, QString::number(max));
    }



    for (i = 0; i < 13; i++) {
        pen.setWidthF(2);
        painter.setPen(pen);
        double num = i * step;
        num = roundf(num * 10) / 10;
    }
    painter.drawText(3 * win_w / 25 + 20, 105 * win_h / 110, QString::number(0));

    if (sampleSize > 100)
    {
        for(int j = 0; j < k+1; j++)
        {
            a[j] = a[j]/(sampleSize/100);
            b[j] = b[j]/(sampleSize/100);
        }
    }
    QColor col;

    for (i = 0; i < length; i++) {
        x = (i * width * win_width) + i * win_width + 100;

        if (i - 1 >= 0)
        {
           painter.setPen(Qt::black);
           painter.drawText(x, 105 * win_h / 110, QString::number(i));
        }

        //double epsilon = 0.1;
        double epsilon = 0;
        if (a[i] > 0 + epsilon)
        {
            QColor col = QColor(0, 0, 255, 127);
            oneBox(x, 10 * win_h / 11, width * win_width, a[i], painter, col);
        }
            if (b[i]  > 0 + epsilon)
            {
                col = QColor(255, 0, 0, 127);
                oneBox(x, 10 * win_h / 11, width * win_width, b[i], painter, col);
            }


    }

    pen.setWidth(2);
    pen.setColor(QColor(221, 196, 221));
    painter.setPen(pen);
    if (sampleSize > 100)
    {
        painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11, 10 * win_h / 11 - (max/(sampleSize/100) + 10) * 10);
        pen.setWidth(15);
        pen.setColor(QColor(0, 0, 255, 127));
        painter.setPen(pen);
        painter.drawLine(win_w / 11 + 25, 10 * win_h / 11 - (max/(sampleSize/100) + 10) * 10 - 55, win_w / 11 + 25, 10 * win_h / 11 - (max/(sampleSize/100) + 10) * 10 - 55 - 5);
        pen.setColor("black");
        painter.setPen(pen);
        painter.drawText(win_w / 11 + 45, 10 * win_h / 11 - (max/(sampleSize/100) + 10) * 10 - 55, "- теоретические частоты");
        pen.setColor(QColor(255, 0, 0, 127));
        painter.setPen(pen);
        painter.drawLine(win_w / 11 + 25, 10 * win_h / 11 - (max/(sampleSize/100) + 10) * 10 - 25, win_w / 11 + 25, 10 * win_h / 11 - (max/(sampleSize/100) + 10) * 10 - 25 - 5);
        pen.setColor("black");
        painter.setPen(pen);
        painter.drawText(win_w / 11 + 45, 10 * win_h / 11 - (max/(sampleSize/100) + 10) * 10 - 25, "- эмпирические частоты");
    }
    else
    {
        painter.drawLine(win_w / 11, 10 * win_h / 11, win_w / 11, 10 * win_h / 11 - (max + 10) * 10);
        pen.setWidth(15);
        pen.setColor(QColor(0, 0, 255, 127));
        painter.setPen(pen);
        painter.drawLine(win_w / 11 + 25, 10 * win_h / 11 - (max + 10) * 10 - 55, win_w / 11 + 25, 10 * win_h / 11 - (max + 10) * 10 - 55 - 5);
        pen.setColor("black");
        painter.setPen(pen);
        painter.drawText(win_w / 11 + 45, 10 * win_h / 11 - (max+ 10) * 10 - 55, "- теоретические частоты");
        pen.setColor(QColor(255, 0, 0, 127));
        painter.setPen(pen);
        painter.drawLine(win_w / 11 + 25, 10 * win_h / 11 - (max + 10) * 10 - 25, win_w / 11 + 25, 10 * win_h / 11 - (max + 10) * 10 - 25 - 5);
        pen.setColor("black");
        painter.setPen(pen);
        painter.drawText(win_w / 11 + 45, 10 * win_h / 11 - (max + 10) * 10 - 25, "- эмпирические частоты");
    }
    pen.setWidth(2);
    pen.setColor(QColor(221, 196, 221));
    painter.setPen(pen);

    painter.drawLine(win_w / 11, 10 * win_h / 11, (length + 1) * win_w / 13, 10 * win_h / 11);

}

/**
 * UI: Draw histogram box
 * @param x
 * @param y
 * @param width
 * @param height
 * @param painter
 * @param color
 */
void oneBox(float x, float y, float width, float height, QPainter &painter, QColor color) {
    QPen pen;
    pen.setColor(color);
    //pen.setWidth(width);
    painter.setPen(pen);
    //painter.drawLine(x, y - width / 2, x, y - width / 2 - height * 10);
    painter.fillRect(x - 7, y - width / 2 - height * 10, 20, height * 10, color);
    //painter.fillRect()
    if(color == QColor(0, 0, 255, 127))
    {
        pen.setColor("black");
        painter.setPen(pen);
       // painter.drawText(x, y - width / 2 - height * 10, QString::number(height));
    }
    else
    {
        pen.setColor("black");
        painter.setPen(pen);
       // painter.drawText(x, y - width / 2 - height * 10 - 20, QString::number(height));
    }

}





