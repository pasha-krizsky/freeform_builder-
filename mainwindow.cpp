#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "approximation.h"
#include "lagrange_polynomial.h"
#include "bezier_curves.h"
#include "linear_interpolation.h"
#include "quadratic_interpolation.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    isBezier    = false;
    isLinear    = false;
    isQuadratic = false;
    isLagrange  = false;
    isApproximate = false;

    ui->setupUi(this);

    ui->linearInterpolationCheckBox->setStyleSheet("color: rgb(236, 107, 33)");
    ui->quadraticInterpolationCheckBox->setStyleSheet("color: rgb(16, 119, 198)");
    ui->lagrangeInterpolationCheckBox->setStyleSheet("color: rgb(247, 45, 173)");
    ui->bezierCheckBox->setStyleSheet("color: rgb(45, 110, 67)");

    ui->scrollArea->setVisible(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_calculateButton_clicked() {

    ui->widget->clearGraphs();

    // Linear
    ui->widget->addGraph();
    // Quadratic
    ui->widget->addGraph();
    // Lagrange
    ui->widget->addGraph();
    // Bezier
    ui->widget->addGraph();
    // Just points
    ui->widget->addGraph();
    // approximation
    ui->widget->addGraph();
    ui->widget->addGraph();

    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    double minX = 0,
           maxX = 0;

    double minY = 0,
           maxY = 0;

    if (isApproximate) {
        Approximation* a = new Approximation();

        vector<int> powers;
        powers.clear();
        for (int i = 0; i < boxes.size(); i++) {
            powers.push_back(boxes[i]->text().toInt());
        }
        ui->widget->graph(6)->setData(a->GetStartX(), a->GetStartY());
        ui->widget->graph(6)->setPen(QColor(236, 17, 23, 255));
        ui->widget->graph(6)->setLineStyle(QCPGraph::lsNone);
        ui->widget->graph(6)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));

        a->approximate(powers);

        ui->widget->graph(5)->setData(a->GetX(), a->GetY());
        ui->widget->graph(5)->setPen(QColor(26, 127, 23, 255));

        if (minX > a->GetMinX()) minX = a->GetMinX();
        if (maxX < a->GetMaxX()) maxX = a->GetMaxX();
        if (minY > a->GetMinY()) minY = a->GetMinY();
        if (maxY < a->GetMaxY()) maxY = a->GetMaxY();
    }

    if (isLinear) {
        Linear_interpolation* linear = new Linear_interpolation();
        linear->Interpolate();

        ui->widget->graph(3)->setData(linear->GetX(), linear->GetY());
        ui->widget->graph(3)->setPen(QColor(236, 107, 33, 255));

        ui->widget->graph(1)->setData(linear->GetData()->GetX(), linear->GetData()->GetY());

        if (minX > linear->GetMinX()) minX = linear->GetMinX();
        if (maxX < linear->GetMaxX()) maxX = linear->GetMaxX();
        if (minY > linear->GetMinY()) minY = linear->GetMinY();
        if (maxY < linear->GetMaxY()) maxY = linear->GetMaxY();
    }

    if (isQuadratic) {
        Quadratic_interpolation* quadratic = new Quadratic_interpolation();
        quadratic->Interpolate();
        ui->widget->graph(4)->setData(quadratic->GetX(), quadratic->GetY());
        ui->widget->graph(4)->setPen(QColor(16, 119, 198, 255));

        ui->widget->graph(1)->setData(quadratic->GetData()->GetX(), quadratic->GetData()->GetY());

        if (minX > quadratic->GetMinX()) minX = quadratic->GetMinX();
        if (maxX < quadratic->GetMaxX()) maxX = quadratic->GetMaxX();
        if (minY > quadratic->GetMinY()) minY = quadratic->GetMinY();
        if (maxY < quadratic->GetMaxY()) maxY = quadratic->GetMaxY();
    }

    if (isLagrange) {
        Lagrange_polynomial* polynomial = new Lagrange_polynomial();
        polynomial->Interpolate();
        polynomial->OutputResult();
        polynomial->CalculateXandY(0.001);

        if (minX > polynomial->GetMinX()) minX = polynomial->GetMinX();
        if (maxX < polynomial->GetMaxX()) maxX = polynomial->GetMaxX();
        if (minY > polynomial->GetMinY()) minY = polynomial->GetMinY();
        if (maxY < polynomial->GetMaxY()) maxY = polynomial->GetMaxY();

        ui->widget->graph(0)->setData(polynomial->GetX(), polynomial->GetY());
        ui->widget->graph(0)->setPen(QColor(247, 45, 173, 255));

        ui->widget->graph(1)->setData(polynomial->GetData()->GetX(), polynomial->GetData()->GetY());
    }

    if (isBezier) {
        Bezier_curve* bezier = new Bezier_curve();
        bezier->Interpolate();
        ui->widget->graph(2)->setData(bezier->GetX(), bezier->GetY());
        ui->widget->graph(2)->setPen(QColor(45, 110, 67, 255));

        ui->widget->graph(1)->setData(bezier->GetData()->GetX(), bezier->GetData()->GetY());

        if (minX > bezier->GetMinX()) minX = bezier->GetMinX();
        if (maxX < bezier->GetMaxX()) maxX = bezier->GetMaxX();
        if (minY > bezier->GetMinY()) minY = bezier->GetMinY();
        if (maxY < bezier->GetMaxY()) maxY = bezier->GetMaxY();
    }

    ui->widget->graph(1)->setPen(QColor(247, 45, 173, 255));
    ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));

    maxY += 1;
    maxX += 1;
    minY -= 1;
    minX -= 1;

    ui->widget->xAxis->setRange(minX, maxX);
    ui->widget->yAxis->setRange(minY, maxY);
    ui->widget->replot();
}

void MainWindow::on_linearInterpolationCheckBox_clicked() {
    isLinear = !isLinear;
}

void MainWindow::on_quadraticInterpolationCheckBox_clicked() {
    isQuadratic = !isQuadratic;
}

void MainWindow::on_lagrangeInterpolationCheckBox_clicked() {
    isLagrange = !isLagrange;
}

void MainWindow::on_bezierCheckBox_clicked() {
    isBezier = !isBezier;
}

void MainWindow::on_approximateCheckBox_clicked() {
    isApproximate = !isApproximate;
}

void MainWindow::on_addPowersButton_clicked()
{
    ui->scrollArea->setVisible(true);
    if (isApproximate) {
        // remove old widgets from vertical layout
        for (int i = 0; i < ui->verticalLayout->count(); ++i) {
            QLayoutItem* item = ui->verticalLayout->itemAt(i);
            if (item) {
                ui->verticalLayout->removeItem(item);
                QWidget* widget = item->widget();
                if (widget) {
                    ui->verticalLayout->removeWidget(widget);
                    delete widget;
                }
                delete item;
                --i;
            }
        }
        QString s = ui->lineEdit_N->text();
        int count = s.toInt();

        boxes.resize(count);
        boxes.clear();
        labels.resize(count);
        labels.clear();

        ui->scrollArea->setLayout(ui->verticalLayout);
        int height = 10;
        for (int i = 0; i < count; i++) {
            boxes.push_back(new QLineEdit());
            QString p;
            p = "Power " + QString::number(i) + ":";
            labels.push_back(new QLabel);
            labels[i]->setText(p);
            ui->verticalLayout->addWidget(labels[i]);
            ui->verticalLayout->addWidget(boxes[i]);
            height += 50;
            ui->scrollArea->setGeometry(15, 290, 160, height);
        }

    }
}
