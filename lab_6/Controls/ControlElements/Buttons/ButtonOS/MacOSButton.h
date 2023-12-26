#ifndef LAB_6_MACOSBUTTON_H
#define LAB_6_MACOSBUTTON_H

#include "../Button.h"

class MacOSButton : public Button {
    // CLick
    void click() override {
        std::cout << "Вызван метод click у контролла Button в MacOS" << std::endl;
    }

    // Установить позицию
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла Button в MacOS" << std::endl;
    }

    // Получить позицию
    std::pair<int, int> getPosition(int x, int y) override {
        std::cout << "Вызван метод getPosition у контролла Button в MacOS" << std::endl;
        return std::make_pair(0, 0);
    }

    // Установить текст
    void setText(const std::string& text) override {
        this->m_text = text;
    }
    // Получить текст
    [[nodiscard]] std::string getText() override {
        return m_text;
    }
};


#endif //LAB_6_MACOSBUTTON_H
