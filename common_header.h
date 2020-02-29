#ifndef COMMOM_HEADER_H
#define COMMOM_HEADER_H

#include <stddef.h>
#include <QString>
#include <QMessageBox>

typedef uint64_t Uint64;
typedef uint32_t Uint32;
typedef uint16_t Uint16;
typedef uint8_t Uint8;

inline void show_err(QString err_msg) {
    QMessageBox::warning(nullptr, "Error", err_msg + "\n"
                         "You may contect WEIK0003@e.ntu.edu.sg"
                         "to report this problem.");
}

#endif // COMMOM_HEADER_H
