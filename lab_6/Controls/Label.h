#ifndef LAB_6_LABEL_H
#define LAB_6_LABEL_H

#include <iostream>
#include <string>

#include "Control.h"

// Класс Label, наследующийся от Control
class Label : public Control {
private:
    std::string m_text;

public:
    void setText(const std::string& text) {
        this->m_text = text;
    }

    std::string getText() {
        return m_text;
    }

    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла Label" << std::endl;
    }

    std::pair<int, int> getPosition() override {
        std::cout << "Вызван метод getPosition у контролла Label" << std::endl;
        return std::make_pair(0, 0);
    }
};


#endif //LAB_6_LABEL_H
