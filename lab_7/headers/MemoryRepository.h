#ifndef LAB_7_MEMORYREPOSITORY_H
#define LAB_7_MEMORYREPOSITORY_H

#include <vector>
#include "IRepository.h"

// Класс MemoryRepository
template<class T>
class MemoryRepository : public IRepository<T>
{
protected:
    std::vector<T*> m_Repository; // репозиторий

public:
    // Деструктор
    ~MemoryRepository()
    {
        // Удаляем все элементы
        if (!m_Repository.empty())
            for (auto item : m_Repository)
                delete item;
    }

    // Добавить элемент
    void Add(const T* item) override
    {
        T* tmpItem = new T(*item);
        m_Repository.push_back(tmpItem);
    }

    // Обновить элемент
    void Update(T* oldItem, T* newItem) override
    {
        for (int i = 0; i < m_Repository.size(); ++i)
            if (*oldItem == *m_Repository[i])
            {
                delete m_Repository[i];
                T* tmpItem = new T(*newItem);
                m_Repository[i] = tmpItem;
                return;
            }
    }

    // Удалить элемент
    void Delete(T* item) override
    {
        for (int i = 0; i < m_Repository.size(); ++i)
            if (*item == *m_Repository[i])
            {
                delete m_Repository[i];
                m_Repository.erase(m_Repository.begin() + i);
                return;
            }
    }

    // Получить репозиторий
    std::vector<T*> Get() override
    {
        return m_Repository;
    }
};


#endif //LAB_7_MEMORYREPOSITORY_H
