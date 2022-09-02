#include <alarmitemdelegate.h>

AlarmItemDelegate::AlarmItemDelegate(QWidget *parent)
    :QStyledItemDelegate(parent),
    blockHeight(100),
    blockOffset(15,15),
    toggleOff  (QPixmap(":/toggle_off.png").scaled(50,50,Qt::KeepAspectRatio)),
    toggleOn   (QPixmap(":/toggle_on.png").scaled(50,50,Qt::KeepAspectRatio)),
    togglePoint(QPoint(-(toggleOff.size().width()+blockOffset.x()),toggleOff.size().height()-35))
    {
    }
void AlarmItemDelegate::paint(QPainter *painter,const QStyleOptionViewItem &option,
                const QModelIndex &index) const
{

    if(index.data().canConvert<AlarmData>()){
        painter->save();
        AlarmData data = qvariant_cast<AlarmData>(index.data());
        QFont font = painter->font();
        font.setPixelSize(48);
        painter->setFont(font);
        painter->setPen(data.status()==AlarmData::Active? Qt::black:Qt::gray);
        painter->setRenderHint( QPainter::Antialiasing, true);
        painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
        QRect textRect = option.rect;
        textRect.translate(blockOffset);
        painter->drawText(textRect,data.time().toString());

        QRect toggleRect(option.rect.topRight()+togglePoint,toggleOff.size());
        painter->drawPixmap(toggleRect,data.status()==AlarmData::Active? toggleOn : toggleOff);
    
    
        painter->restore();
    }
    else
        QStyledItemDelegate::paint(painter, option, index);

}            

QSize AlarmItemDelegate::sizeHint(const QStyleOptionViewItem &option,  
                    const QModelIndex &index) const 
{
    if(index.data().canConvert<AlarmData>()){
        return QSize(option.rect.width(),blockHeight);
    }else
    return QStyledItemDelegate::sizeHint(option,index);

}

QWidget *AlarmItemDelegate::createEditor(QWidget *parent,const QStyleOptionViewItem &option, 
                      const QModelIndex &index) const
{
    if(index.data().canConvert<AlarmData>()){
        AlarmData data(qvariant_cast<AlarmData>(index.data()));
        AlarmEditor *editor = new AlarmEditor(data,parent);
        connect(editor, &AlarmEditor::commitChanges,this,&AlarmItemDelegate::commitDataAlarmEditor);
        connect(editor, &AlarmEditor::closeAlarmEditor, this, &AlarmItemDelegate::closeAlarmEditor);
        return editor;
        
    }

    return QStyledItemDelegate::createEditor(parent,option,index);
}
void AlarmItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index)const
{
    if(index.data().canConvert<AlarmData>()){return;}
    QStyledItemDelegate::setEditorData(editor,index);

}
void AlarmItemDelegate::setModelData(QWidget*editor, QAbstractItemModel *model,const QModelIndex &index) const
{
    if(index.data().canConvert<AlarmData>()){    
        AlarmEditor * alarmEditor =(AlarmEditor *)(editor);
        model->setData(index,QVariant::fromValue(alarmEditor->getAlarmData()));
    }   
    else
        QStyledItemDelegate::setModelData(editor,model,index);
}
bool AlarmItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    qDebug()<<event->type();
    if( event->type()==QEvent::MouseButtonPress) return true;
    if((event->type()==QEvent::MouseButtonRelease || event->type()==QEvent::MouseButtonDblClick) && index.data().canConvert<AlarmData>()){
    
       QMouseEvent *mEvent = (QMouseEvent*)event;
       QRect toggleRect (QPoint(togglePoint+option.rect.topRight()),toggleOff.size());
       if(toggleRect.contains(mEvent->pos())){
            AlarmData data = qvariant_cast<AlarmData>(index.data());
            data.invertStatus();
            model->setData(index,QVariant::fromValue(data));
            return true;

       }
    } 
    return QStyledItemDelegate::editorEvent(event,model,option,index);


}
void AlarmItemDelegate::closeAlarmEditor(){
    closeEditor(qobject_cast<QWidget *>(sender()));
}
void AlarmItemDelegate::commitDataAlarmEditor(){
    commitData(qobject_cast<QWidget *>(sender()));
}
