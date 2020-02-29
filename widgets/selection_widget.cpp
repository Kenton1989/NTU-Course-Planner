#include "selection_widget.h"
#include "ui_selectionwidget.h"

SelectionWidget::SelectionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectionWidget)
{
    ui->setupUi(this);
}

SelectionWidget::~SelectionWidget()
{
    delete ui;
}
