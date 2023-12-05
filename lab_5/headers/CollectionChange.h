#ifndef LAB_5_COLLECTIONCHANGE_H
#define LAB_5_COLLECTIONCHANGE_H

#include <functional>

// Тип изменения свойства
enum class CollectionChangeStatus {
    Added, // добавление
    Removed, // изменения
    ItemChanged // изменения элемента в коллекции
};

// Интерфейс добавления и удаления функций-слушателей изменения коллекции
class INotifyCollectionChanged {
public:
    // Метод добавления функции-слушателя
    virtual void AddInotifyCollectionChangedListener(std::function<void(CollectionChangeStatus)> listener) = 0;
    // Метод удаления функции-слушателя
    [[maybe_unused]]
    virtual void RemoveInotifyCollectionChangedListener(std::function<void(CollectionChangeStatus)> listener) = 0;
};


#endif //LAB_5_COLLECTIONCHANGE_H
