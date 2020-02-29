#ifndef COURSEUPDATER_H
#define COURSEUPDATER_H

#include <QObject>

class CourseUpdater : public QObject
{
    Q_OBJECT
public:
    explicit CourseUpdater(QObject *parent = nullptr);

signals:

public slots:


private:
    void get_course_html();
    void get_classes_html();
};

#endif // COURSEUPDATER_H
