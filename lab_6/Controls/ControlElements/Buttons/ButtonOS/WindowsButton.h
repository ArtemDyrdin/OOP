#ifndef LAB_6_WINDOWSBUTTON_H
#define LAB_6_WINDOWSBUTTON_H

#include "../Button.h"
// Класс Button, наследующийся от Control
class WindowsButton : public Button {
public:
    // Установить позицию
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла Button в Windows" << std::endl;
    }

    // Получить позицию
    std::pair<int, int> getPosition(int x, int y) override {
        std::cout << "Вызван метод getPosition у контролла Button в Windows" << std::endl;
        return std::make_pair(0, 0);
    }

    // CLick
    void click() override {
        std::cout << "Вызван метод click у контролла Button в Windows" << std::endl;
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


#endif //LAB_6_WINDOWSBUTTON_H
