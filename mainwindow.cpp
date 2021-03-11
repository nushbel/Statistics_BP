#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Math/modeling.h>
#include "histogram.h"
#include "plot.h"
#include "Math/SampleBernoulli.h"
#include "Math/SampleInverseTransform.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <Math/ChiSquare.h>

int my_flag = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    painter_flag = false;
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Sample size" << "Power");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    auto x = this->width();
    auto y = this->height();
    QString out = QString::number(x) + '\n' + QString::number(y);
    if (my_flag == 1) {
        createHistogram(sample_size, x, y, painter, &chisq);
    }

    else if (my_flag == 2)
    {
        QString color = "black";
        createPlot(pvalue, iter_num, x, y, painter, color);
    }

}

//гистограмма
void MainWindow::on_pushButton_clicked()
{
    p = ui->lineEdit_p->text().toDouble();
    k = ui->lineEdit_k->text().toInt();
    sample_size = ui->lineEdit_SS->text().toInt();

    QString combobox = ui->comboBox->currentText();
    int type;
    if (combobox == "Bernoulli")
    {
        type = 1;
    }
    else
    {
        type = 2;
    }

    Modeling mymodel(k, p, sample_size, k, p);
    chisq = mymodel.modelingDist(type);
    ui->label->setText("Chi-squared statistics: " + QString::number(chisq.ChiSq_statistics) + "\nDegrees of freedom: " + QString::number(chisq.df) + "\nP-value: " + QString::number(chisq.pvalue));
    painter_flag = true;
    my_flag = 1;
    update();
}


void MainWindow::on_tabWidget_tabBarClicked(int )
{
    ui->label->setText("");
    ui->label_7->setText("");

    painter_flag = false;
    my_flag = 0;
    update();
}

void MainWindow::sortArr(double* arr, int size)
{
    double temp = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//график для p-value
void MainWindow::on_pushButton_plot_clicked()
{
    p = ui->lineEdit_p_2->text().toDouble();
    k = ui->lineEdit_k_2->text().toInt();
    alt_p = ui->lineEdit_p_alt->text().toDouble();
    alt_k = ui->lineEdit_k_alt->text().toInt();
    sample_size = ui->lineEdit_SS_2->text().toInt();
    iter_num = ui->lineEdit_iter->text().toInt();
    pvalue = new double[iter_num + 1] {0};
    double power = 0;
    double alpha = 0.05;
    for (int i = 0;i < iter_num ;++i ) {
        QString combobox = ui->comboBox_2->currentText();
        int type;
        if (combobox == "Bernoulli")
        {
            type = 1;
        }
        else
        {
            type = 2;
        }

        Modeling mymodel(k, p, sample_size, alt_k, alt_p);
        chisq = mymodel.modelingDist(type);
        pvalue[i] = chisq.pvalue;
        if (chisq.pvalue < alpha)
        {
            ++power;
        }
    }
    power = power / iter_num;
    std::vector<double> pvalue_vector (pvalue, pvalue+iter_num);
    sortArr(pvalue, iter_num);
    double max1 = pvalue[0];
        for (int i = 1; i < iter_num; i++)
        {
            if (pvalue[i] > max1)
            {
                max1 = pvalue[i];
            }
        }
        if (p == alt_p && k == alt_k)
        {
            ui->label_7->setText("Заданный уровень значимости:\n 0.05 \nИстинный уровень значимости:\n " + QString::number(power));
        }
        else
        {
             ui->label_7->setText("Уровень значимости: 0.05 \nМощность: " + QString::number(power));
        }


    my_flag = 2;
    update();
}

//таблица для мощности
void MainWindow::on_pushButton_plot_2_clicked()
{
    sample_size = 100;
    for (int i = 0; i < 10 ; ++i) {
        p = ui->lineEdit_p_3->text().toDouble();
        k = ui->lineEdit_k_3->text().toInt();
        alt_p = ui->lineEdit_p_alt_2->text().toDouble();
        alt_k = ui->lineEdit_k_alt_2->text().toInt();
        iter_num = ui->lineEdit_iter_2->text().toInt();
        double power = 0;
        double alpha = 0.05;
        for (int j = 0; j < iter_num ;++j ) {
            QString combobox = ui->comboBox_3->currentText();
            int type;
            if (combobox == "Bernoulli")
            {
                type = 1;
            }
            else
            {
                type = 2;
            }

            Modeling mymodel(k, p, sample_size, alt_k, alt_p);
            chisq = mymodel.modelingDist(type);

            if (chisq.pvalue < alpha)
            {
                ++power;
            }
        }
        power = power / iter_num;
        QTableWidgetItem *itm_l = new QTableWidgetItem(tr("%1").arg(sample_size));
        QTableWidgetItem *itm_r = new QTableWidgetItem(tr("%1").arg(power));
        ui->tableWidget->setItem(i, 0, itm_l);
        ui->tableWidget->setItem(i, 1, itm_r);
        sample_size += 100;
    }
}
