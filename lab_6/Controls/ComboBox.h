#ifndef LAB_6_COMBOBOX_H
#define LAB_6_COMBOBOX_H

#include <iostream>
#include <string>
#include <vector>

#include "Control.h"

// Класс ComboBox, наследующийся от Control
class ComboBox : public Control {
private:
    int selectedIndex{};
    std::vector<std::string> m_items;

public:
    [[nodiscard]] int getSelectedIndex() const {
        return selectedIndex;
    }

    void setSelectedIndex(int index) {
        selectedIndex = index;
    }

    void setItems(const std::vector<std::string>& items) {
        this->m_items = items;
    }

    std::vector<std::string> getItems() {
        return m_items;
    }

    void setPosition(int x, int y) override {
        std::cout << "Вызван метод setPosition у контролла ComboBox" << std::endl;
    }

    std::pair<int, int> getPosition() override {
        std::cout << "Вызван метод getPosition у контролла ComboBox" << std::endl;
        return std::make_pair(0, 0);
    }
};


#endif //LAB_6_COMBOBOX_H
