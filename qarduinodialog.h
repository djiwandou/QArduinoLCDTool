#ifndef QARDUINODIALOG_H
#define QARDUINODIALOG_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QList>
#include <QStringList>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QListIterator>
#include <QMessageBox>

namespace Ui {
class QArduinoDialog;
}

class QArduinoDialog : public QWidget
{
    Q_OBJECT

public:
    explicit QArduinoDialog(QWidget *parent = 0);
    ~QArduinoDialog();

private slots:
    void on_baudRateComboBox_currentIndexChanged(const QString &arg1);

    void on_comportComboBox_currentIndexChanged(const QString &arg1);

    void on_portStatusButton_clicked();

    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

    void on_sendTextButton_clicked();

    void on_getLCDDimensionButton_clicked();

    void on_clearLCDButton_clicked();

    void on_pushButton_clicked();

public slots:
    QString readArduino(void);

private:
    Ui::QArduinoDialog *ui;

    const QString commTabText;
    const QString lcdTabText;
    const qint32 defaultBaudRate;



    //Ports related
    QSerialPort *arduino;
    QString currentPort;
    QList <QSerialPortInfo> portInfoList;
    QStringList baudRateList;

    qint32 currentBaudRate;
    QString currentBaudRateString;

};

#endif // QARDUINODIALOG_H
