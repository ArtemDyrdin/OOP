//
// Created by User on 06.12.2023.
//

#ifndef LAB_6_MACOSFORM_H
#define LAB_6_MACOSFORM_H


#include "../Form.h"

class MacOSForm : public Form {
public:
    // Установить позицию
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла Form в MacOS" << std::endl;
    }

    // Получить позицию
    std::pair<int, int> getPosition(int x, int y) override {
        std::cout << "Вызван метод getPosition у контролла Form в MacOS" << std::endl;
        return std::make_pair(0, 0);
    }

    // Добавить контролл
    void addControl(Control* control) override {
        controls.push_back(control);
        std::cout << "Добавлен контролл в Form в Windows" << std::endl;
    }
};


#endif //LAB_6_MACOSFORM_H
