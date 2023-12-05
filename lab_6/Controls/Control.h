#ifndef LAB_6_CONTROL_H
#define LAB_6_CONTROL_H

#include <iostream>

// Базовый класс Control
class Control {
public:
    // Установить позицию
    virtual void setPosition(int x, int y) = 0;
    // Получить позицию
    [[maybe_unused]] virtual std::pair<int, int> getPosition() = 0;
};


#endif //LAB_6_CONTROL_H
