#ifndef LAB_6_COMBOBOX_H
#define LAB_6_COMBOBOX_H

#include <iostream>
#include <string>
#include <vector>

#include "../../Control.h"

// Класс ComboBox, наследующийся от Control
class ComboBox : public Control {
private:
    int selectedIndex{}; // выбранный индекс
    std::vector<std::string> m_items; // массив элементов

public:
    // Получить выбранный индекс
    [[nodiscard]] int getSelectedIndex() const {
        return selectedIndex;
    }

    // Установить выбранный индекс
    void setSelectedIndex(int index) {
        selectedIndex = index;
    }

    // Установить элементы
    [[maybe_unused]] void setItems(const std::vector<std::string>& items) {
        this->m_items = items;
    }

    // Получить элементы
    [[maybe_unused]] std::vector<std::string> getItems() {
        return m_items;
    }

    // Установить позицию
    void setPosition(int x, int y) override  {
        std::cout << "Вызван метод setPosition у контролла ComboBox" << std::endl;
    }

    // Получить позицию
    std::pair<int, int> getPosition() override {
        std::cout << "Вызван метод getPosition у контролла ComboBox" << std::endl;
        return std::make_pair(0, 0);
    }
};


#endif //LAB_6_COMBOBOX_H
