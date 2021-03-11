#ifndef HISTOGRAM_H
#define HISTOGRAM_H


#pragma once

#include <QtGui/QPainter>
#include <Math/modeling.h>
#include <Math/ChiSquare.h>

//void createHistogram(int k, int sampleSize, int win_w, int win_h, double* exp_freq, double* act_freq, QPainter &painter);
void createHistogram(int sampleSize, int win_w, int win_h, QPainter &painter, ChiSquare* chisq);
void oneBox(float x, float y, float width, float height, QPainter &painter, QColor color);
#endif // HISTOGRAM_H
