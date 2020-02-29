#ifndef COURSECELL_H
#define COURSECELL_H

#include <QFrame>

namespace Ui {
class CourseCell;
}

class CourseCell : public QFrame
{
    Q_OBJECT

public:
    explicit CourseCell(QWidget *parent = nullptr);
    ~CourseCell();

private:
    Ui::CourseCell *ui;
};

#endif // COURSECELL_H
