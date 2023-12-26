#ifndef LAB_6_COMBOBOX_H
#define LAB_6_COMBOBOX_H

#include <iostream>
#include <string>
#include <vector>

#include "../../Control.h"

// Класс ComboBox, наследующийся от Control
class ComboBox : public Control {
protected:
    int selectedIndex{}; // выбранный индекс
    std::vector<std::string> m_items; // массив элементов

public:
    // Получить выбранный индекс
    virtual int getSelectedIndex() = 0;

    // Установить выбранный индекс
    virtual void setSelectedIndex(int index) = 0;

    // Установить элементы
    virtual void setItems(const std::vector<std::string>& items) = 0;

    // Получить элементы
    virtual std::vector<std::string> getItems() = 0;
};


#endif //LAB_6_COMBOBOX_H
