#include "coursecell.h"
#include "ui_coursecell.h"

CourseCell::CourseCell(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CourseCell)
{
    ui->setupUi(this);
}

CourseCell::~CourseCell()
{
    delete ui;
}
