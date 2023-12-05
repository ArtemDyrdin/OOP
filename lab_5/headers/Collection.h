#ifndef LAB_5_COLLECTION_H
#define LAB_5_COLLECTION_H

#include <vector>
#include <functional>
#include "CollectionChange.h"

// Класс с реализацией INotifyCollectionChanged
class Collection : public INotifyCollectionChanged {
private:
    std::vector<int> data; // массив чисел
    std::vector<std::function<void(CollectionChangeStatus)>> collectionChangedListeners; // массив функций-слушателей изменения коллекции

public:
    // Метод добавления элемента в коллекцию
    void Add(int value) {
        data.push_back(value);

        // Последовательный вызов функций-слушателей
        for (const auto& listener : collectionChangedListeners)
            listener(CollectionChangeStatus::Added);
    }

    // Метод удаления элемента из коллекции
    void Remove(int value) {
        for (auto it = data.begin(); it != data.end(); ++it)
            if (*it == value) {
                data.erase(it);

                // Последовательный вызов функций-слушателей
                for (const auto& listener : collectionChangedListeners)
                    listener(CollectionChangeStatus::Removed);
                break;
            }
    }

    // Метод изменения элемента коллекции
    void ChangeItem(int oldValue, int newValue) {
        for (int & it : data)
            if (it == oldValue) {
                it = newValue;

                // Последовательный вызов функций-слушателей
                for (const auto& listener : collectionChangedListeners)
                    listener(CollectionChangeStatus::ItemChanged);
                break;
            }
    }

    // Метод добавления функции-слушателя в коллекцию
    void AddInotifyCollectionChangedListener(std::function<void(CollectionChangeStatus)> listener) override {
        collectionChangedListeners.push_back(listener);
    }

    // Метод удаления функции-слушателя из коллекции
    void RemoveInotifyCollectionChangedListener(std::function<void(CollectionChangeStatus)> listener) override {
        auto it = std::find_if(collectionChangedListeners.begin(), collectionChangedListeners.end(),
                               [&listener](const std::function<void(CollectionChangeStatus)>& func) {
                                   return func.target<void(CollectionChangeStatus)>() == listener.target<void(CollectionChangeStatus)>();
                               });

        if (it != collectionChangedListeners.end())
            collectionChangedListeners.erase(it);
    }
};


#endif //LAB_5_COLLECTION_H
