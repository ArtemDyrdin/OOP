#ifndef LAB_4_VIRTUALKEYBOARD_H
#define LAB_4_VIRTUALKEYBOARD_H

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <Windows.h>

#include "Key.h"
#include "Command.h"

namespace virtual_keyboard {

    // Цвета
    enum class Color {
        BLUE = 1,
        GREEN = 2,
        RED = 4,
        WHITE = 7,
    };

    class VirtualKeyboard {
    private:
        std::vector<Key> m_actions; // массив из клавиш и их переназначений
        HANDLE m_hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // объект, отвечающий за вывод текста в консоль
        COORD m_coord_output = {0, 2}; // координата, в которую выводится символ в консоль
        COORD m_coord_history = {31, 1}; // координата, в которую выводится имя нажатого ключа
    private:
        // Нарисовать интерфейс вывода в консоли
        void drawInterface() {
            // Колонка вывода
            SetConsoleTextAttribute(m_hStdOut, static_cast<int>(Color::WHITE));
            SetConsoleCursorPosition(m_hStdOut, {0, 0});
            std::cout << "Вывод:" << std::endl;
            // Разделительная полоса
            for (int i = 0; i < 2; i++) {
                SetConsoleCursorPosition(m_hStdOut, {30, static_cast<short>(i)});
                std::cout << "|";
            }
            // Колонка с историей нажатий
            SetConsoleCursorPosition(m_hStdOut, {31, 0});
            std::cout << "История нажатий:" << std::endl;
        }

        // Вывести название введенного ключа
        void makeCommandHistory(const std::string& key) {
            SetConsoleTextAttribute(m_hStdOut, static_cast<int>(Color::WHITE));
            SetConsoleCursorPosition(m_hStdOut, {30 , m_coord_history.Y});
            std::cout << "|";
            SetConsoleTextAttribute(m_hStdOut, static_cast<int>(Color::GREEN));
            SetConsoleCursorPosition(m_hStdOut, m_coord_history);
            std::cout << key;
            m_coord_history.Y++;
        }

        // Выполнить команду нажатия
        void executeCommand (const std::shared_ptr<Command>& command) {
            SetConsoleTextAttribute(m_hStdOut, static_cast<int>(Color::BLUE));
            SetConsoleCursorPosition(m_hStdOut, m_coord_output);
            command->execute();
        }

        // Выкинуть ошибку при нажатии ключа
        void throwKeyError(const std::string& error) {
            SetConsoleTextAttribute(m_hStdOut, static_cast<int>(Color::RED));
            SetConsoleCursorPosition(m_hStdOut, m_coord_output);
            std::cout << std::endl << error;
        }

    public:
        VirtualKeyboard () {
            drawInterface(); // рисуем интерфейс при создании объекта
        };

        ~VirtualKeyboard() {
            SetConsoleTextAttribute(m_hStdOut, static_cast<int>(Color::WHITE));
            SetConsoleCursorPosition(m_hStdOut, {0, m_coord_history.Y});
        }

        // Нажатие клавиши с выводом ее переназначения
        void pressKey(const std::string& key) {
            makeCommandHistory(key); // выводим название ключа в историю

            bool assign_is = false; // флаг, что назначение клавиши (комбинации клавиш) существует
            for (const auto& action : m_actions)
                if (action.m_key_name == key) {
                    executeCommand(action.m_command); // выполняем команду ключа
                    assign_is = true;

                    // если команда не BackspaceCommand прибавляем к-ту, иначе убавляем
                    if (!std::dynamic_pointer_cast<BackspaceCommand>(action.m_command))
                        m_coord_output.X++;
                    else
                        m_coord_output.X--;
                }
            // Если переназначения клавиши (комбинации клавиш) нет
            if (!assign_is)
                throwKeyError("Нет команды для " + key);
        }

        // Назначить клавишу (комбинацию клавиш)
        void assignAction(const std::string& key, std::shared_ptr<Command> command) {
            bool assign_is = false; // флаг, что назначение клавиши (комбинации клавиш) существует
            // Если назначение клавиши (комбинации клавиш) существует
            for (auto & action : m_actions)
                if (action.m_key_name == key) {
                    action = Key(key, std::move(command));
                    assign_is = true;
                }
            // Если назначения клавиши (комбинации клавиш) не существует
            if (!assign_is)
                m_actions.emplace_back(key, std::move(command));
        }

        // Откатить действия клавиш (комбинаций клавиш)
        void undo() {
            if (!m_actions.empty()) {
                for (int i = 0; i < m_actions.size(); i++)
                    m_actions.pop_back();
            }
        }

        // Откатить действие клавиши (комбинации клавиш)
        void undo(const std::string& key) {
            if (!m_actions.empty())
                for (int i = 0; i < m_actions.size(); i++)
                    if (m_actions[i].m_key_name == key)
                        m_actions.erase(m_actions.begin() + i);
        }
    };
} // keyboard

#endif //LAB_4_VIRTUALKEYBOARD_H
