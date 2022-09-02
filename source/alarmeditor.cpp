#include "alarmeditor.h"


AlarmEditor::AlarmEditor(const AlarmData &data,QWidget *parent)
    :QWidget(parent),
    alarmData(data),
    hLine(new QLineEdit(QString::number(alarmData.time().hour()))),
    mLine(new QLineEdit(QString::number(alarmData.time().minute())))

{
    qDebug()<<parent->rect();
    setAutoFillBackground(true);
    setMouseTracking(true);
    QTime alarmTime = alarmData.time();

    QHBoxLayout *timeLayout =new QHBoxLayout;

    timeLayout->addWidget(hLine,Qt::AlignRight);
    timeLayout->addWidget(new QLabel(":"),Qt::AlignCenter);
    timeLayout->addWidget(mLine,Qt::AlignLeft);

    QPushButton *okPbt     = new QPushButton("OK");
    QPushButton *cancelPbt = new QPushButton("Cancel");
    QPushButton *deletePbt = new QPushButton("Delete");

    connect(cancelPbt, &QPushButton::clicked,this,&AlarmEditor::closeAlarmEditor);
    connect(okPbt, &QPushButton::clicked, this, [=](){emit commitChanges(); emit closeAlarmEditor();});
    connect(hLine, &QLineEdit::textChanged, this, &AlarmEditor::updateAlarmTime);
    connect(mLine, &QLineEdit::textChanged, this, &AlarmEditor::updateAlarmTime);
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(timeLayout,0,0);
    mainLayout->addWidget(deletePbt,2,0);
    mainLayout->addWidget(okPbt,3,0);
    mainLayout->addWidget(cancelPbt,3,1);

    setLayout(mainLayout);

}
void AlarmEditor::updateAlarmTime(){
    alarmData.setTime(QTime(hLine->text().toInt(), mLine->text().toInt()));
    qDebug()<<alarmData.time();
}
