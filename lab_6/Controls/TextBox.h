#ifndef LAB_6_TEXTBOX_H
#define LAB_6_TEXTBOX_H

#include <iostream>
#include <string>

#include "Control.h"

// Класс TextBox, наследующийся от Control
class TextBox : public Control {
private:
    std::string m_text;

public:
    void setText(const std::string& text) {
        this->m_text = text;
    }

    std::string getText() {
        return m_text;
    }

    static void onValueChanged() {
        std::cout << "Вызван метод onValueChanged у контролла TextBox" << std::endl;
    }

    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла TextBox" << std::endl;
    }

    std::pair<int, int> getPosition() override {
        std::cout << "Вызван метод getPosition у контролла TextBox" << std::endl;
        return std::make_pair(0, 0);
    }
};


#endif //LAB_6_TEXTBOX_H
