#ifndef LAB_7_MEMORYUSERREPOSITORY_H
#define LAB_7_MEMORYUSERREPOSITORY_H

#include "IUserRepository.h"
#include "MemoryRepository.h"

// Класс MemoryUserRepository
class MemoryUserRepository : public IUserRepository, public MemoryRepository<User>
{
public:
    // Добавить пользователя
    void Add(const User* item) override
    {
        MemoryRepository<User>::Add(item);
    }

    // Обновить пользователя
    void Update(User* oldItem, User* newItem) override
    {
        MemoryRepository<User>::Update(oldItem, newItem);
    }

    // Удалить пользователя
    void Delete(User* item) override
    {
        MemoryRepository<User>::Delete(item);
    }

    // Получить пользователя
    std::vector<User*> Get() override
    {
        return MemoryRepository<User>::Get();
    }

    // Получить пользователя по Id
    User* getById(int id) override
    {
        for (auto user : m_Repository)
        {
            if (user->getId() == id)
                return user;
        }
        return nullptr;
    }

    // Получить пользователя по имени
    std::vector<User*> getByName(const std::string& name) override
    {
        std::vector<User*> Users;
        for (auto user : m_Repository)
        {
            if (user->getName() == name)
                Users.push_back(user);
        }
        return Users;
    }

    // Получить пользователя по почте
    User* getByEmail(const std::string& email) override
    {
        for (auto user : m_Repository)
        {
            if (user->getEmail() == email)
                return user;
        }
        return nullptr;
    }

    // Получить пользователя по городу
    std::vector<User*> getByCity(const std::string& city) override
    {
        std::vector<User*> Users;
        for (auto user : m_Repository)
        {
            if (user->getCity() == city)
                Users.push_back(user);
        }
        return Users;
    }

    // Получить пользователя по полу
    std::vector<User*> getByGender(Gender gender) override
    {
        std::vector<User*> Users;
        for (auto user : m_Repository)
        {
            if (user->getGender() == gender)
                Users.push_back(user);
        }
        return Users;
    }
};


#endif //LAB_7_MEMORYUSERREPOSITORY_H
