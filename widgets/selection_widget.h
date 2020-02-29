#ifndef SELECTION_WIDGET_H
#define SELECTION_WIDGET_H

#include <QWidget>

namespace Ui {
class SelectionWidget;
}

class SelectionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectionWidget(QWidget *parent = nullptr);
    ~SelectionWidget();

private:
    Ui::SelectionWidget *ui;
};

#endif // SELECTION_WIDGET_H
