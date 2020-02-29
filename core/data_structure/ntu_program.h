#ifndef NTUPROGRAM_H
#define NTUPROGRAM_H

#include <cstring>
#include <QString>
#include <QVector>
#include "ntu_course.h"


class NtuProgram
{
public:
    using ProgramCode = QString;
    using CourseList = QVector<NtuCourse>;

    NtuProgram(const QString &code, const QString &name) : code_(code), name_(name) {}
    NtuProgram(QString &&code, QString &&name): code_(code), name_(name) {}

    const QString& code() const { return code_; }
    void set_code(const QString &code) { code_ = code; }
    const QString& name() const { return name_; }
    void set_name(const QString &name) { name_ = name; }
    QString name_code() const { return QString("%1(%2)").arg(name_).arg(code_); }
    void set_name_code(const QString& name, const QString& code) {
        name_ = name; code_ = code;
    }

    CourseList& courses() { return courses_; }
    const CourseList& courses() const { return courses_; }

    CourseList::size_type course_num() const { return courses_.size(); }

    QString toString() const { return name_+" ("+code_+")"; }

private:
    ProgramCode code_;
    QString name_;
    CourseList courses_;
};

#endif // NTUPROGRAM_H
