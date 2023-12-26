//
// Created by User on 06.12.2023.
//

#ifndef LAB_6_WINDOWSCOMBOBOX_H
#define LAB_6_WINDOWSCOMBOBOX_H

#include "../ComboBox.h"

class WindowsComboBox : public ComboBox {
public:
    // Установить позицию
    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла ComboBox в Windows" << std::endl;
    }

    // Получить позицию
    std::pair<int, int> getPosition(int x, int y) override {
        std::cout << "Вызван метод getPosition у контролла ComboBox в Windows" << std::endl;
        return std::make_pair(0, 0);
    }

    // Получить выбранный индекс
    int getSelectedIndex() override {
        std::cout << "Получен выбранный индекс ComboBox в Windows" << std::endl;
        return selectedIndex;
    }

    // Установить выбранный индекс
    void setSelectedIndex(int index) override {
        std::cout << "Установлен индекс ComboBox в Windows" << std::endl;
        selectedIndex = index;
    }

    // Установить элементы
    void setItems(const std::vector<std::string>& items) override {
        std::cout << "Установлены элементы ComboBox в Windows" << std::endl;
        this->m_items = items;
    }

    // Получить элементы
    std::vector<std::string> getItems() override {
        std::cout << "Получены элементы ComboBox в Windows" << std::endl;
        return m_items;
    }
};


#endif //LAB_6_WINDOWSCOMBOBOX_H
