#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Symulator.h"
#include <QMainWindow>
#include "arxwindow.h"

#include <QTimer>

#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_Sin_Button_clicked();

    void on_Square_Button_clicked();

    void on_spinBOX_WzmocK_editingFinished();

    void on_spinBOX_Amplituda_editingFinished();

    void on_spinBOX_Czstotliwosc_editingFinished();

    void on_spinBOX_Td_editingFinished();

    void on_spinBOX_Ti_editingFinished();

    void on_spinBOX_Interwal_editingFinished();

    void on_radio_przed_toggled(bool checked);

    void on_radio_pod_toggled(bool checked);

    void on_Reset_d_clicked();

    void on_Reset_i_clicked();

    void on_START_Button_clicked();



    void on_Konf_ARX_Button_clicked();

    void onStartClicked() {
        symulator.krokSymulacji();                  // wykonaj krok symulacji

        qDebug() << "k = " << symulator.getKrok();
    }





private:
    Ui::MainWindow *ui;

    ARXwindow *arxwindow = nullptr;

    SymulatorUAR symulator;

    QLineSeries *seriaP;
    QLineSeries *seriaI;
    QLineSeries *seriaD;
    QLineSeries *seriaUchyb;
    QLineSeries *seriaRegulator;
    QLineSeries *seriaRegulowana;
    QLineSeries *seriaZad;


    QLineSeries *seriaY;      // y(k) → getWyjscie()
    QLineSeries *seriaW;    // w(k) → getWartoscZadana()

    QTimer *timer;
    double T;   // okres próbkowania [s]


};
#endif // MAINWINDOW_H
