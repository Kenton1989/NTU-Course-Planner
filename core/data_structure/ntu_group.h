#ifndef NTUGROUP_H
#define NTUGROUP_H

#include <QVector>
#include <QString>
#include "common_header.h"
#include "ntu_class.h"

class NtuGroup
{
public:
    using Index = int;
    using ClassList = QVector<NtuClass>;

    NtuGroup(Index index) :index_(index) {}

    const Index& index() const { return index_; }
    void set_index(Index &index) { index_ = index; }

    const ClassList& classes() const { return classes_; }
    ClassList& classes() { return classes_; }
private:
    Index index_;
    ClassList classes_;
};

#endif // NTUGROUP_H
