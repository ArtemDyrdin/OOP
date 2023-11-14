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
    keyboard.assignAction("Ctr+C", std::make_unique<CopyCommand>());
    keyboard.assignAction("Ctr+V", std::make_unique<PasteCommand>());
    keyboard.assignAction("Ctr+X", std::make_unique<CutCommand>());

    // Workflow из нажатий клавиш с задержкой между нажатиями
    keyboard.pressKey("Ctr+C");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    keyboard.pressKey("Ctr+V");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    keyboard.pressKey("Ctr+X");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Переназначение действий клавиш
    keyboard.assignAction("Ctr+C", std::make_unique<CutCommand>());
    keyboard.assignAction("Ctr+V", std::make_unique<CutCommand>());

    // Workflow из нажатий клавиш с задержкой между нажатиями
    keyboard.pressKey("Ctr+C");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    keyboard.pressKey("Ctr+V");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    keyboard.undo("Ctr+C"); // удаляем действие для Ctr+C
    keyboard.pressKey("Ctr+C");

    keyboard.undo(); // удаляем действия всех заданных клавиш

    return 0;
}