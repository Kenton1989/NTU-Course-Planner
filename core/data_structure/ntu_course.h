#ifndef NTUCOURSE_H
#define NTUCOURSE_H

#include "ntu_group.h"
#include <cstring>
#include <QString>
#include <QVector>
#include "common_header.h"

class CourseCode {
public:
    //Constructor
    inline CourseCode() { clean(); }
    CourseCode(const char *code): CourseCode() {
        set_str(code);
    }
    CourseCode(const QString& code): CourseCode() {
        set_str(code.toUtf8().data());
    }
    //Destructor
    ~CourseCode() = default;
    //Copy
    inline CourseCode& operator=(const CourseCode&) = default;
    inline CourseCode& operator=(const char *code) {
        set_str(code);
        return *this;
    }
    inline CourseCode& operator=(const QString& code) {
        set_str(code.toUtf8().data());
        return *this;
    }
    //Comparision
    inline bool operator<(const CourseCode& other) const {
        return code_.num > other.code_.num;
    }
    inline bool operator>(const CourseCode& other) const {
        return code_.num < other.code_.num;
    }
    inline bool operator>=(const CourseCode& other) const {
        return !(*this < other);
    }
    inline bool operator<=(const CourseCode& other) const {
        return !(*this > other);
    }
    inline bool operator==(const CourseCode& other) const {
        return code_.num == other.code_.num;
    }
    inline bool operator!=(const CourseCode& other) const {
        return !(*this == other);
    }
    //Modification
    inline void clean() { code_.num = 0; }
    //Conversion
    inline const char* to_cstr() const { return code_.str; }
    inline QString toString() const { return code_.str; }
private:
    union Data {
        quint64 num;
        char str[8];
    };
    Data code_;

    inline void set_str(const char* str) {
        clean();
        strcpy_s(code_.str, sizeof(code_.str), str);
    }
    inline friend uint qHash(const CourseCode& key, uint seed) {
        return qHash(key.code_.num, seed);
    }
};


class NtuCourse
{
public:
    using GroupList = QVector<NtuGroup>;

    NtuCourse(const QString &code, const QString &name) : code_(code), name_(name) {}
    NtuCourse(QString &&code, QString &&name): code_(code), name_(name) {}

    const CourseCode& code() const { return code_; }
    void set_code(const CourseCode &code) { code_ = code; }
    const QString& name() const { return name_; }
    void set_name(const QString &name) { name_ = name; }
    QString name_code() const { return QString("%1: %2").arg(code_.to_cstr()).arg(name_); }
    void set_name_code(const QString& name, const QString& code) {
        name_ = name; code_ = code;
    }

    GroupList& groups() { return groups_; }
    const GroupList& groups() const { return groups_; }

    GroupList::size_type group_num() { return groups_.size(); }

    QString toString() { return code_.toString()+": "+name_; }
private:
    CourseCode code_;
    QString name_;
    GroupList groups_;
};

#endif // NTUCOURSE_H
