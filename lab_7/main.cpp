#include <vector>
#include <iostream>
#include <windows.h>
#include "headers/MemoryUserRepository.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Создаем пользователя №1
    User* user1 = new User;
    user1->setCity("Калининград");
    user1->setEmail("post1@mail.ru");
    user1->setGender(Gender::Male);
    user1->setId(1);
    user1->setName("Артём");
    user1->setPhone("8-800-555-5535");

    // Создаем пользователя №2
    User* user2 = new User;
    user2->setCity("Томск");
    user2->setEmail("post2@mail.ru");
    user2->setGender(Gender::Male);
    user2->setId(2);
    user2->setName("Денис");
    user2->setPhone("8-900-491-6609");

    // Создаем пользователя №3
    User* user3 = new User;
    user3->setCity("Минск");
    user3->setEmail("post3@mail.ru");
    user3->setGender(Gender::Female);
    user3->setId(3);
    user3->setName("София");
    user3->setPhone("8-950-842-1337");

    // Сохраняем пользователей в репозиторий
    MemoryUserRepository repository;
    repository.Add(user1);
    repository.Add(user2);
    repository.Add(user3);

    // Получаем пользователя 1 по Id
    User* gotUser1 = repository.getById(1);
    std::cout << "User 1 через ID: " << gotUser1->getName() << std::endl;

    // Получаем пользователя 2 по почте
    User* gotUser2 = repository.getByEmail("post2@mail.ru");
    std::cout << "User 2 через почту: " << gotUser2->getName() << std::endl;

    // Получаем пользователей по имени
    std::vector<User *> name_Sofya_Users = repository.getByName("София");
    std::cout << "Пользователи по имени София:" << std::endl;
    for(auto & user : name_Sofya_Users)
        std::cout << user->getName() << "\t";
    std::cout << std::endl;


    // Получаем пользователей по городу
    std::vector<User *> city_Minsk_Users = repository.getByCity("Минск");
    std::cout << "Пользователи из города Минск:" << std::endl;
    for(auto & user : city_Minsk_Users)
        std::cout << user->getName() << "\t";
    std::cout << std::endl;

    // Получаем пользователей мужского пола
    std::vector<User *> male_Male_Users = repository.getByGender(Gender::Male);
    std::cout << "Пользователи мужского пола:" << std::endl;
    for(auto & user : male_Male_Users)
        std::cout << user->getName() << "\t";
    std::cout << std::endl;

    // Удаляем, обновляем пользователей
    repository.Delete(user1);
    repository.Update(user2, user3);

    // Получаем репозиторий пользователей
    std::vector<User *> users = repository.Get();
    std::cout << "Пользователи после преобразования репозитория:" << std::endl;
    for(auto & user : users)
        std::cout << user->getName() << "\t";
    std::cout << std::endl;

    // Чистим хип
    delete user1;
    delete user2;
    delete user3;

    return 0;
}
