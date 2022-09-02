#pragma once

#include <QWidget>
#include <QTime>
#include <QStandardItemModel>
#include <QListView>
#include "alarmitemdelegate.h"
class AlarmWindow : public QWidget
{
    Q_OBJECT
    QListView *view;
    QStandardItemModel model;
    


public:
    AlarmWindow(QWidget *parent = nullptr);

};
