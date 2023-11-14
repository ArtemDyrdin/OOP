#ifndef LAB_4_VIRTUALKEYBOARD_H
#define LAB_4_VIRTUALKEYBOARD_H

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include "Key.h"

namespace virtual_keyboard {

    class VirtualKeyboard {
    private:
        std::vector<Key> actions; // массив из клавиш и их переназначений
    public:
        // Нажатие клавиши с выводом ее переназначения
        void pressKey(const std::string& key) {
            bool assign_is = false; // флаг, что назначение клавиши (комбинации клавиш) существует
            for (const auto& action : actions)
                if (action.m_key_name == key) {
                    std::cout << action.m_key_name << " -> ";
                    action.m_command->execute();
                    assign_is = true;
                }
            // Если переназначения клавиши (комбинации клавиш) нет
            if (!assign_is)
                std::cout << "Не существует действия для " << key << std::endl;
        }

        // Назначить клавишу (комбинацию клавиш)
        void assignAction(const std::string& key, std::shared_ptr<Command> command) {
            bool assign_is = false; // флаг, что назначение клавиши (комбинации клавиш) существует
            // Если назначение клавиши (комбинации клавиш) существует
            for (auto & action : actions)
                if (action.m_key_name == key) {
                    action = Key(key, std::move(command));
                    assign_is = true;
                }
            // Если назначения клавиши (комбинации клавиш) не существует
            if (!assign_is)
                actions.emplace_back(key, std::move(command));
        }

        // Откатить действия клавиш (комбинаций клавиш)
        void undo() {
            if (!actions.empty()) {
                for (int i = 0; i < actions.size(); i++)
                    actions.pop_back();
                std::cout << "Откат действий всех заданных клавиш (комбинаций клавиш)" << std::endl;
            }
        }

        // Откатить действие клавиши (комбинации клавиш)
        void undo(const std::string& key) {
            if (!actions.empty())
                for (int i = 0; i < actions.size(); i++)
                    if (actions[i].m_key_name == key) {
                        actions.erase(actions.begin() + i);
                        std::cout << "Откат действия " << key << std::endl;
                    }
        }
    };
} // keyboard

#endif //LAB_4_VIRTUALKEYBOARD_H
