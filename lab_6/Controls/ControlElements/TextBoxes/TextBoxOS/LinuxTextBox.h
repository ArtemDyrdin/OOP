//
// Created by User on 06.12.2023.
//

#ifndef LAB_6_LINUXTEXTBOX_H
#define LAB_6_LINUXTEXTBOX_H


#include "../TextBox.h"

class LinuxTextBox : public TextBox {
public:

    // Установить позицию
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла TextBox в Linux" << std::endl;
    }

    // Получить позицию
    std::pair<int, int> getPosition(int i, int i1) override {
        std::cout << "Вызван метод getPosition у контролла TextBox в Linux" << std::endl;
        return std::make_pair(0, 0);
    }

    // Установить текст
    void setText(const std::string& text) override {
        this->m_text = text;
        std::cout << "Установлен текст TextBox в Linux" << std::endl;
    }

    // Получить текст
    std::string getText() override {
        std::cout << "Получен текст TextBox в Linux" << std::endl;
        return m_text;
    }

    // Значение изменено...
    void onValueChanged() override {
        std::cout << "Вызван метод onValueChanged у контролла TextBox в Linux" << std::endl;
    }
};

#endif //LAB_6_LINUXTEXTBOX_H
