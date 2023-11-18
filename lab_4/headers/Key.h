#ifndef LAB_4_KEY_H
#define LAB_4_KEY_H

#include <iostream>
#include <memory>

#include "Command.h"

// Ключ
class Key {
public:
    std::string m_key_name; // название клавиши (комбинации клавиш)
    std::shared_ptr<Command> m_command; // умный указатель на команду клавиши (комбинации клавиш)
public:
    // Инициализируем поля
    Key(std::string key_name, std::shared_ptr<Command> command) : m_key_name(std::move(key_name)), m_command(std::move(command)) {}
};

#endif //LAB_4_KEY_H
