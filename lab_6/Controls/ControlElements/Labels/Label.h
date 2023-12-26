#ifndef LAB_6_LABEL_H
#define LAB_6_LABEL_H

#include <iostream>
#include <string>

#include "../../Control.h"

// Класс Label, наследующийся от Control
class Label : public Control {
protected:
    std::string m_text; // текст

public:
    // Установить текст
    virtual void setText(const std::string& text) = 0;

    // Получить текст
    virtual std::string getText() = 0;
};


#endif //LAB_6_LABEL_H
