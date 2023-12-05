#ifndef LAB_5_PERSON_H
#define LAB_5_PERSON_H

#include <functional>
#include <string>
#include "Property.h"

// Класс с реализацией INotifyPropertyChanged и INotifyPropertyChanging
class Person : public INotifyPropertyChanged, public INotifyPropertyChanging {
private:
    std::string name; // имя
    int age; // возраст

    std::vector<std::function<void()>> propertyChangedListeners; // массив функций-слушателей после изменения
    std::vector<std::function<void(const std::string&, const std::string&)>> propertyChangingListeners; // массив функций-слушателей во время изменения

public:
    // Конструктор
    Person(std::string name, int age) : name(std::move(name)), age(age) {}

    // Метод получения имени
    [[maybe_unused]] [[nodiscard]]
    std::string GetName() const {
        return name;
    }

    // Метод получения возраста
    [[maybe_unused]] [[nodiscard]]
    int GetAge() const {
        return age;
    }

    // Метод установки нового имени
    void SetName(const std::string& newName) {
        // Выполняем функции-слушатели во время изменения
        for (const auto& listener : propertyChangingListeners)
            listener("Имя", newName);

        name = newName; // изменяем имя

        // Выполняем функции-слушатели после изменения
        for (const auto& listener : propertyChangedListeners)
            listener();
    }

    // Метод установки нового возраста
    void SetAge(int newAge) {
        // Выполняем функции-слушатели во время изменения
        for (const auto& listener : propertyChangingListeners)
            listener("Возраст", std::to_string(newAge));

        age = newAge; // меняем возраст

        // Выполняем функции-слушатели после изменения
        for (const auto& listener : propertyChangedListeners)
            listener();
    }

    // Метод добавления функции-слушателя после изменения
    void AddInotifyPropertyChangedListener(std::function<void()> listener) override {
        propertyChangedListeners.push_back(listener);
    }

    // Метод удаления функции-слушателя после изменения
    void RemoveNotifyPropertyChangedListener(std::function<void()> listener) override {
        auto it = std::find_if(propertyChangedListeners.begin(), propertyChangedListeners.end(),
                               [&listener](const std::function<void()>& func) {
                                   return func.target<void()>() == listener.target<void()>();
                               });

        if (it != propertyChangedListeners.end())
            propertyChangedListeners.erase(it);
    }

    // Метод добавления функции-слушателя во время изменения
    void AddInotifyPropertyChangingListener(std::function<void(const std::string&, const std::string&)> listener) override {
        propertyChangingListeners.push_back(listener);
    }

    // Метод удаления функции-слушателя во время изменения
    void RemoveNotifyPropertyChangingListener(std::function<void(const std::string&, const std::string&)> listener) override {
        auto it = std::find_if(propertyChangingListeners.begin(), propertyChangingListeners.end(),
                               [&listener](const std::function<void(const std::string&, const std::string&)>& func) {
                                   return func.target<void(const std::string&, const std::string&)>() == listener.target<void(const std::string&, const std::string&)>();
                               });

        if (it != propertyChangingListeners.end())
            propertyChangingListeners.erase(it);
    }
};


#endif //LAB_5_PERSON_H
