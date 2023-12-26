#ifndef LAB_6_TEXTBOX_H
#define LAB_6_TEXTBOX_H

#include <iostream>
#include <string>

#include "../../Control.h"

// Класс TextBox, наследующийся от Control
class TextBox : public Control {
protected:
    std::string m_text; // текст

public:
    // Установить текст
    virtual void setText(const std::string& text) = 0;

    // Получить текст
    virtual std::string getText() = 0;

    // Значение изменено...
    virtual void onValueChanged() = 0;
};


#endif //LAB_6_TEXTBOX_H
