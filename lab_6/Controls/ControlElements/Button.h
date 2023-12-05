#ifndef LAB_6_BUTTON_H
#define LAB_6_BUTTON_H

#include <string>

#include "../Control.h"

// Класс Button, наследующийся от Control
class Button : public Control {
private:
    std::string m_text; // текст

public:
    // Установить текст
    void setText(const std::string& text) {
        this->m_text = text;
    }

    // Получить текст
    [[nodiscard]] std::string getText() const {
        return m_text;
    }

    // Click
    static void click() {
        std::cout << "Вызван метод click у контролла Button" << std::endl;
    }

    // Установить позицию...
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла Button" << std::endl;
    }

    // Получить позицию...
    std::pair<int, int> getPosition() override {
        std::cout << "Вызван метод getPosition у контролла Button" << std::endl;
        return std::make_pair(0, 0);
    }
};


#endif //LAB_6_BUTTON_H
