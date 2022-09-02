#include "alarmwindow.h"

AlarmWindow::AlarmWindow(QWidget *parent)
    :QWidget(parent),
    view(new QListView)
{
    QHBoxLayout *layout =new QHBoxLayout;
    layout->addWidget(view);
    view->setModel(&model);
    view->setItemDelegate(new AlarmItemDelegate);
    
    AlarmData data(QTime::currentTime(),AlarmData::Active),data2(QTime::currentTime(),AlarmData::Inactive);
    QStandardItem *item = new QStandardItem();
    QStandardItem *item2 = new QStandardItem();
    item2->setData(QVariant::fromValue(data2),0);
    item->setData(QVariant::fromValue(data),0);
    model.setItem(0,0,item);
    model.setItem(1,0,item2);
    setLayout(layout);
    
}
