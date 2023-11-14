#ifndef LAB_4_COMMAND_H
#define LAB_4_COMMAND_H

#include <iostream>

// Базовый класс команд кнопок
class Command {
public:
    virtual void execute() = 0;
};

// Команда скопировать
class CopyCommand : public Command {
public:
    void execute() override {
        std::cout << "Команда СКОПИРОВАТЬ" << std::endl;
    }
};

// Команда вставить
class PasteCommand : public Command {
public:
    void execute() override {
        std::cout << "Команда ВСТАВИТЬ" << std::endl;
    }
};

// Команда вырезать
class CutCommand : public Command {
public:
    void execute() override {
        std::cout << "Команда ВЫРЕЗАТЬ" << std::endl;
    }
};


#endif //LAB_4_COMMAND_H
