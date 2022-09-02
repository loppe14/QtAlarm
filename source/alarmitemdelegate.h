#pragma once
#include <QMouseEvent>
#include <QStyledItemDelegate>
#include <QObject>
#include <QPainter>
#include <QEvent>
#include <alarmeditor.h>
class AlarmItemDelegate : public QStyledItemDelegate
{

    Q_OBJECT
    void paint(QPainter *painter,const QStyleOptionViewItem &option,
                const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option,
                    const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent,
                         const QStyleOptionViewItem &option, 
                         const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index)const override;
    void setModelData(QWidget*editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
  
    QPixmap toggleOn;
    QPixmap toggleOff;
    const int blockHeight;
    const QPoint blockOffset;
    const QPoint togglePoint;
public:
    AlarmItemDelegate(QWidget *parent = nullptr);
public slots:
    void closeAlarmEditor();
    void commitDataAlarmEditor();
};