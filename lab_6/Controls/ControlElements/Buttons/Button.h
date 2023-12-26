#ifndef LAB_6_BUTTON_H
#define LAB_6_BUTTON_H

#include <string>

#include "../../Control.h"

// Базовый класс Button, наследующийся от Control
class Button : public Control {
protected:
    std::string m_text; // текст
public:
    // Установить текст
    virtual void setText(const std::string& text) = 0;
    // Получить текст
    virtual std::string getText() = 0;
    // Click
    virtual void click() = 0;
};


#endif //LAB_6_BUTTON_H
