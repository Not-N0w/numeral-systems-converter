#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_convertButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_from_textEdited(const QString &arg1);

    void on_to_textEdited(const QString &arg1);

    void on_from_editingFinished();

    void on_to_cursorPositionChanged(int arg1, int arg2);

    void on_to_editingFinished();

    void on_from_cursorPositionChanged(int arg1, int arg2);

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_from_inputRejected();

    void on_pushButton_clicked();

    void on_from_returnPressed();

    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_2_sliderReleased();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
