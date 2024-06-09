#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "num.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_convertButton_clicked()
{
    Num numi;
    QString textIn = ui->NumIn->text();
    QString from = ui->from->text();
    QString to = ui->to->text();



    std::string sIn = textIn.toStdString();
    numi.setNumber(sIn, std::stoi(from.toStdString()));
    numi.toNumeralSystem(std::stoi(to.toStdString()));
    QString out;
    for(int i= 0; i < numi.num.size(); ++i) {
        out += (numi.num[i] < 10 ? QString::number(numi.num[i]) : QString(char(numi.num[i] - 10 + 'A')));
    }
    if(numi.period.size() + numi.pred.size() > 0 && !(numi.period.size() == 0 && numi.pred.size() == 1 && numi.pred[0] == 0)) {
        out += ',';
        for(int i= 0; i < numi.pred.size(); ++i) {
            out += (numi.pred[i] < 10 ? QString::number(numi.pred[i]) : QString(char(numi.pred[i] - 10 + 'A')));
        }
        if(numi.period.size() > 0) {
            out += QString('(');
            for(int i= 0; i < numi.period.size(); ++i) {
                out += (numi.period[i] < 10 ? QString::number(numi.period[i]) : QString(char(numi.period[i] - 10 + 'A')));
            }
            out += QString(')');
        }
    }
    ui->resultLabel->setText(out);
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(focusWidget() != ui->from) {
        ui->from->setText(QString::number(ui->horizontalSlider->value()));
    }
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    if(focusWidget() != ui->to) {
        ui->to->setText(QString::number(ui->horizontalSlider_2->value()));
    }
}


void MainWindow::on_from_textEdited(const QString &arg1)
{
    ui->horizontalSlider->setValue((ui->from->text()).toInt());
}


void MainWindow::on_to_textEdited(const QString &arg1)
{
    ui->horizontalSlider_2->setValue((ui->to->text()).toInt());
}


void MainWindow::on_from_editingFinished()
{
    if(((ui->from->text()).toInt() == 0 && ((ui->from->text()).size() != 0)) || (ui->from->text()).toInt() < 2) {
        ui->from->setText("2");
    }
    if((ui->from->text()).toInt() > 36) {
        ui->from->setText("36");
    }
}


void MainWindow::on_to_editingFinished()
{
    if(((ui->to->text()).toInt() == 0 && ((ui->to->text()).size() != 0)) || (ui->to->text()).toInt() < 2) {
        ui->to->setText("2");
    }
    if((ui->to->text()).toInt() > 36) {
        ui->to->setText("36");
    }
}


void MainWindow::on_from_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_to_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_checkBox_stateChanged(int arg1)
{

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->to->setText("2");
    ui->from->setText("10");
    ui->resultLabel->setText("");
    ui->NumIn->setText("");
    ui->horizontalSlider->setValue((ui->from->text()).toInt());
    ui->horizontalSlider_2->setValue((ui->to->text()).toInt());
}


void MainWindow::on_pushButton_3_clicked()
{
    QString tmp = ui->NumIn->text();
    ui->NumIn->setText(ui->resultLabel->toPlainText());
    ui->resultLabel->setText(tmp);
    tmp = ui->from->text();
    ui->from->setText(ui->to->text());
    ui->to->setText(tmp);
    ui->horizontalSlider->setValue((ui->from->text()).toInt());
    ui->horizontalSlider_2->setValue((ui->to->text()).toInt());
}


void MainWindow::on_from_inputRejected()
{

}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_from_returnPressed()
{

}


void MainWindow::on_horizontalSlider_sliderReleased()
{
   // ui->from->setText(QString::number(ui->horizontalSlider->value()));
}


void MainWindow::on_horizontalSlider_2_sliderReleased()
{
   // ui->to->setText(QString::number(ui->horizontalSlider_2->value()));
}

