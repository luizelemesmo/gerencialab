// src/lab-fila/totem_window.h

#ifndef TOTEM_WINDOW_H
#define TOTEM_WINDOW_H

#include <QWidget>

class TotemWindow : public QWidget {
    Q_OBJECT

public:
    explicit TotemWindow(QWidget* parent = nullptr);
};

#endif // TOTEM_WINDOW_H