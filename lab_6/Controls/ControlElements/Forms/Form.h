#ifndef LAB_6_FORM_H
#define LAB_6_FORM_H

#include <iostream>
#include <vector>

#include "../../Control.h"

// Класс Form, наследующийся от Control
class Form : public Control {
protected:
    std::vector<Control*> controls; // массив контроллов

public:
    // Добавить контролл
    virtual void addControl(Control* control) = 0;
};


#endif //LAB_6_FORM_H
