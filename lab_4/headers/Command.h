#ifndef LAB_4_COMMAND_H
#define LAB_4_COMMAND_H

#include <iostream>
#include "VirtualKeyboard.h"

// Базовый класс команд кнопок
class Command {
public:
    virtual int getValue() = 0;
    virtual void execute() = 0;
    virtual void cancel() = 0;
};

// Команда напечатать цифру 1
class Digit1Command : public Command {
public:
    int m_value = 1; // значение вывода
public:
    int getValue() override {
        return m_value;
    }
    void execute() override {
        std::cout << m_value;
    }
    void cancel() override {
        std::cout << "\b \b";
    }
};

// Команда напечатать цифру 2
class Digit2Command : public Command {
public:
    int m_value = 2; // значение вывода
public:
    int getValue() override {
        return m_value;
    }
    void execute() override {
        std::cout << m_value;
    }
    void cancel() override {
        std::cout << "\b \b";
    }
};

// Команда напечатать цифру 3
class Digit3Command : public Command {
public:
    int m_value = 3; // значение вывода
public:
    int getValue() override {
        return m_value;
    }
    void execute() override {
        std::cout << m_value;
    }
    void cancel() override {
        std::cout << "\b \b";
    }
};

// Команда удалить
class BackspaceCommand : public Command {
public:
    int m_value{}; // стертый символ
public:
    int getValue() override {
        return m_value;
    }
    void setValue(int value) {
        m_value = value;
    }
    void execute() override {
        std::cout << "\b \b";
    }
    void cancel() override {
        std::cout << m_value;
    }
};

#endif //LAB_4_COMMAND_H
