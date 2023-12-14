#ifndef LAB_6_TEXTBOX_H
#define LAB_6_TEXTBOX_H

#include <iostream>
#include <string>

#include "../../Control.h"

// Класс TextBox, наследующийся от Control
class TextBox : public Control {
private:
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

    // Значение изменено...
    [[maybe_unused]] static void onValueChanged() {
        std::cout << "Вызван метод onValueChanged у контролла TextBox" << std::endl;
    }

    // Установить позицию
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла TextBox" << std::endl;
    }

    // Получить позицию
    std::pair<int, int> getPosition() override {
        std::cout << "Вызван метод getPosition у контролла TextBox" << std::endl;
        return std::make_pair(0, 0);
    }
};


#endif //LAB_6_TEXTBOX_H
