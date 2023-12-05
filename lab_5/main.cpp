#include <iostream>
#include <windows.h>

#include "headers/Person.h"
#include "headers/Collection.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Person" << std::endl;
    // Создаем объект person для демонстрации функций-слушателей во время и после изменения
    Person person("Сергей", 18);

    // Добавляем функцию-слушатель после изменения
    person.AddInotifyPropertyChangedListener([]() {
        std::cout << "Параметр человека изменен" << std::endl;
    });

    // Добавляем функцию-слушатель во время изменения
    person.AddInotifyPropertyChangingListener([](const std::string& propertyName, const std::string& newValue) {
        std::cout << "Параметр человека изменяется: " << propertyName << " -> " << newValue << std::endl;
    });

    // Изменяем параметры человека
    person.SetName("Мухаммед");
    person.SetAge(28);


    std::cout << std::endl << "Collection" << std::endl;
    // Создаем объект collection для демонстрации функции-слушателя коллекции
    Collection collection;

    // Добавляем адаптивную функцию-слушатель в коллекцию
    collection.AddInotifyCollectionChangedListener([](CollectionChangeStatus status) {
        switch (status) {
            case CollectionChangeStatus::Added:
                std::cout << "Элемент добавлен в коллекцию" << std::endl;
                break;
            case CollectionChangeStatus::Removed:
                std::cout << "Элемент удален из коллекции" << std::endl;
                break;
            case CollectionChangeStatus::ItemChanged:
                std::cout << "Элемент коллекции изменен" << std::endl;
                break;
        }
    });

    collection.Add(10); // добавление элемента в коллекцию
    collection.ChangeItem(10, 30); // меняем элемент коллекции
    collection.Remove(30); // удаляем элемент из коллекции

    return 0;
}
