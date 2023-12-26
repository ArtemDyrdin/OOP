//
// Created by User on 06.12.2023.
//

#ifndef LAB_6_LINUXLABEL_H
#define LAB_6_LINUXLABEL_H

#include "../Label.h"

class LinuxLabel : public Label {
public:
    // Установить позицию
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла Label в Linux" << std::endl;
    }

    // Вернуть позицию
    std::pair<int, int> getPosition(int i, int i1) override {
        std::cout << "Вызван метод getPosition у контролла Label в Linux" << std::endl;
        return std::make_pair(0, 0);
    }

    // Установить текст
    void setText(const std::string& text) override {
        this->m_text = text;
        std::cout << "Установлен текст Label в Linux" << std::endl;
    }

    // Получить текст
    std::string getText() override {
        std::cout << "Получен текст Label в Linux" << std::endl;
        return m_text;
    }
};

#endif //LAB_6_LINUXLABEL_H
