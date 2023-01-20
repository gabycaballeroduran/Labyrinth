#ifndef CLOCK_H
#define CLOCK_H

#include "QtCore/qobjectdefs.h"
#include "QtWidgets/qwidget.h"

class Clock
{


public:
    Clock(QWidget *parent = nullptr);

private slots:
    void showTime();
};

#endif // CLOCK_H
