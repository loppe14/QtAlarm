#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QTime>
#include <QPushButton>
#include "alarmdata.h"

class AlarmEditor : public QWidget
{
    Q_OBJECT
    AlarmData alarmData;
    QLineEdit *hLine;
    QLineEdit *mLine;

public:
    AlarmEditor(const AlarmData &,QWidget *parent=nullptr);

    void      setAlarmData(const AlarmData &data){alarmData=data;}
    AlarmData getAlarmData(){return alarmData;}
signals:
    void commitChanges();
    void closeAlarmEditor();
    void deleteAlram();
public slots:
    void updateAlarmTime();
};