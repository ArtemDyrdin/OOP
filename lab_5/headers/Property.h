#ifndef LAB_5_PROPERTY_H
#define LAB_5_PROPERTY_H

#include <functional>
#include <string>

// Интерфейс добавления и удаления функций-слушателей изменения свойства после изменения
class INotifyPropertyChanged {
public:
    // Метод добавления функции-слушателя
    virtual void AddInotifyPropertyChangedListener(std::function<void()> listener) = 0;
    // Метод удаления функции-слушателя
    [[maybe_unused]]
    virtual void RemoveNotifyPropertyChangedListener(std::function<void()> listener) = 0;
};

// Интерфейс добавления и удаления функций-слушателей изменения свойства перед его изменением
class INotifyPropertyChanging {
public:
    // Метод добавления функции-слушателя
    virtual void AddInotifyPropertyChangingListener(std::function<void(const std::string&, const std::string&)> listener) = 0;
    // Метод удаления функции-слушателя
    [[maybe_unused]]
    virtual void RemoveNotifyPropertyChangingListener(std::function<void(const std::string&, const std::string&)> listener) = 0;
};


#endif //LAB_5_PROPERTY_H
