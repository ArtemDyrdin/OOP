#include <windows.h>
#include <chrono>
#include <thread>

#include "headers/VirtualKeyboard.h"
#include "headers/Command.h"


int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    virtual_keyboard::VirtualKeyboard keyboard;

    // Назначение действий клавиш (сочетаний клавиш)
    keyboard.assignAction("1", std::make_unique<TypeDigit1>());
    keyboard.assignAction("2", std::make_unique<TypeDigit2>());
    keyboard.assignAction("3", std::make_unique<TypeDigit3>());
    keyboard.assignAction("Backspace", std::make_unique<BackspaceCommand>());

    // Workflow из нажатий клавиш с задержкой между нажатиями
    for (int i = 0; i < 3; i++) {
        keyboard.pressKey("1");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        keyboard.pressKey("2");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        keyboard.pressKey("3");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    for (int i = 0; i < 2; i++) {
        keyboard.pressKey("Backspace");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Переназначение действий клавиш
    keyboard.assignAction("3", std::make_unique<TypeDigit1>());
    keyboard.assignAction("1", std::make_unique<TypeDigit3>());

    // Workflow из нажатий клавиш с задержкой между нажатиями
    keyboard.pressKey("3");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    keyboard.pressKey("1");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    keyboard.undo("Backspace"); // удаляем действие для "Backspace"
    keyboard.pressKey("Backspace"); // проверка
    keyboard.undo(); // удаляем действия всех заданных ключей

    return 0;
}