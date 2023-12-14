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
    void setText(const std::string& text) {
        this->m_text = text;
    }

    // Получить текст
    [[nodiscard]] std::string getText() const {
        return m_text;
    }

    // Click
    virtual void click() = 0;

    // Установить позицию...
    void setPosition(int x, int y) override {}

    // Получить позицию...
    std::pair<int, int> getPosition() override {}
};


#endif //LAB_6_BUTTON_H
