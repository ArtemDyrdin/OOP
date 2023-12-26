#ifndef LAB_6_CONTROL_H
#define LAB_6_CONTROL_H

#include <iostream>
#include <vector>

class Control {
public:
    // Получить позицию
    virtual std::pair<int, int> getPosition(int x, int y) = 0;
    // Установить позицию
    virtual void setPosition(int x, int y) = 0;
    // Деструктор
    virtual ~Control() = default;
};



#endif //LAB_6_CONTROL_H
