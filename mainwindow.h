#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_calculateButton_clicked();
    void on_linearInterpolationCheckBox_clicked();
    void on_quadraticInterpolationCheckBox_clicked();
    void on_lagrangeInterpolationCheckBox_clicked();
    void on_bezierCheckBox_clicked();
    void on_approximateCheckBox_clicked();
    void on_addPowersButton_clicked();

private:
    Ui::MainWindow *ui;
    bool isBezier;
    bool isLinear;
    bool isQuadratic;
    bool isLagrange;
    bool isApproximate;
    std::vector<QLineEdit*> boxes;
    std::vector<QLabel*> labels;
};

#endif // MAINWINDOW_H
