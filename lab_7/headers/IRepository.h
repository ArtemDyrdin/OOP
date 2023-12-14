#ifndef LAB_7_IREPOSITORY_H
#define LAB_7_IREPOSITORY_H

#include <vector>

// Шаблон интерфейса IRepository
template<class T>
class IRepository
{
public:
    virtual void Add(const T* item) = 0;

    virtual void Update(T* oldItem, T* newItem) = 0;

    virtual void Delete(T* item) = 0;

    virtual std::vector<T*> Get() = 0;
};


#endif //LAB_7_IREPOSITORY_H
