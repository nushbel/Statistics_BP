#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include "Math/SampleBernoulli.h"
#include "Math/SampleInverseTransform.h"
#include "Math/ChiSquare.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool painter_flag;

    int comp1 (const void * a, const void * b);

    void sortArr(double* arr, int size);

    void qsortRecursive(double* mas, int size);

private slots:
    void on_pushButton_clicked();

   // void on_pushButton_2_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_plot_clicked();


    void on_pushButton_plot_2_clicked();

private:
    Ui::MainWindow *ui;
    double p = 0;
    int k = 0;
    double alt_p = 0;
    int alt_k = 0;
    int sample_size = 100;
    int iter_num = 1000;
    double* pvalue;
    ChiSquare chisq;

protected:
    //void paintEvent(QPaintEvent *e);
    void paintEvent(QPaintEvent* );
};
#endif // MAINWINDOW_H
