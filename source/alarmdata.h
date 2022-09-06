#pragma once
#include <QTime>
class AlarmData 
{
public:
    enum Status{
        Inactive,
        Active
    };
private:
    QTime  _time;
    Status _status;
public:

    AlarmData():_time(QTime()),_status(Inactive){}
    AlarmData(const QTime &time_,Status status_)
        :_time(time_),
        _status(status_)
    {}
    constexpr QTime time()const{return _time;}
    constexpr Status status()const {return _status;}
    void setTime(const QTime &time){_time = time;}    
    void invertStatus(){
        if(_status==Active)_status=Inactive;
        else _status=Active;}
    bool operator<(const AlarmData &other){
        return _time < other.time()?true:false;
    }
    bool operator>(const AlarmData &other){
        return _time > other.time()?true:false;
    }
};
Q_DECLARE_METATYPE(AlarmData);