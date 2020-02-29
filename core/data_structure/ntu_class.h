#ifndef NTUCLASS_H
#define NTUCLASS_H

#include <QString>
#include "common_header.h"

class NtuClass
{
    enum class Type { sp, LEC, TUT, LAB, SEM, PRJ, DES };
    enum class Day { sp, MON, TUS, WED, THU, FRI, SAT, SUN };
    enum class Remark { Unknown, None, TeachingWk, Online, SelfPaced, NotInTeachingWk };

    class Time {
    public:

        friend Time combine(const Time &time1, const Time &time2);
        friend bool is_overlapped(const Time &time1, const Time &time2);
    private:
    };

public:
    struct Info {
        QString type,
                group,
                days,
                time,
                venue,
                remark;
    };

    explicit NtuClass(Info info);
    Info info();
    Time class_time();

    friend bool is_overlapped();
private:
    Type type_;
    QString group_;
    Time time_;
};

#endif // NTUCLASS_H
