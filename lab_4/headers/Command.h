#ifndef LAB_4_COMMAND_H
#define LAB_4_COMMAND_H

#include <iostream>

// Базовый класс команд кнопок
class Command {
public:
    virtual void execute() = 0;
};

// Команда напечатать цифру 1
class TypeDigit1 : public Command {
public:
    void execute() override {
        std::cout << "1";
    }
};

// Команда напечатать цифру 2
class TypeDigit2 : public Command {
public:
    void execute() override {
        std::cout << "2";
    }
};

// Команда напечатать цифру 3
class TypeDigit3 : public Command {
public:
    void execute() override {
        std::cout << "3";
    }
};

// Команда удалить
class BackspaceCommand : public Command {
public:
    void execute() override {
        std::cout << "\b \b";
    }
};



#endif //LAB_4_COMMAND_H
