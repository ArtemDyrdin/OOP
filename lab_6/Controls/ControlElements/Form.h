#ifndef LAB_6_FORM_H
#define LAB_6_FORM_H

#include <iostream>
#include <vector>

#include "../Control.h"

// Класс Form, наследующийся от Control
class Form : public Control {
private:
    std::vector<Control*> controls; // массив контроллов

public:
    // Добавить контролл
    void addControl(Control* control) {
        controls.push_back(control);
    }

    // Установить позицию
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла Form" << std::endl;
    }

    // Получить позицию
    std::pair<int, int> getPosition() override {
        std::cout << "Вызван метод getPosition у контролла Form" << std::endl;
        return std::make_pair(0, 0);
    }
};


#endif //LAB_6_FORM_H
