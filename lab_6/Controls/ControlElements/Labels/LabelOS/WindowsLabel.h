//
// Created by User on 06.12.2023.
//

#ifndef LAB_6_WINDOWSLABEL_H
#define LAB_6_WINDOWSLABEL_H

#include "../Label.h"

class WindowsLabel : public Label {
public:
    // Установить позицию
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла Label в Windows" << std::endl;
    }

    // Вернуть позицию
    std::pair<int, int> getPosition(int i, int i1) override {
        std::cout << "Вызван метод getPosition у контролла Label в Windows" << std::endl;
        return std::make_pair(0, 0);
    }

    // Установить текст
    void setText(const std::string& text) override {
        this->m_text = text;
        std::cout << "Установлен текст Label в Windows" << std::endl;
    }

    // Получить текст
    std::string getText() override {
        std::cout << "Получен текст Label в Windows" << std::endl;
        return m_text;
    }
};


#endif //LAB_6_WINDOWSLABEL_H
