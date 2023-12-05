#ifndef LAB_6_BUTTON_H
#define LAB_6_BUTTON_H

#include <string>

#include "Control.h"

// Класс Button, наследующийся от Control
class Button : public Control {
private:
    std::string m_text;

public:
    void setText(const std::string& text) {
        this->m_text = text;
    }

    std::string getText() {
        return m_text;
    }

    static void click() {
        std::cout << "Вызван метод click у контролла Button" << std::endl;
    }

    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла Button" << std::endl;
    }

    std::pair<int, int> getPosition() override {
        std::cout << "Вызван метод getPosition у контролла Button" << std::endl;
        return std::make_pair(0, 0);
    }
};


#endif //LAB_6_BUTTON_H
