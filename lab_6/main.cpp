#include <iostream>
#include <vector>
#include <windows.h>

#include "Factories/ControlFactory.h"
#include "Factories/FactoryOS/WindowsControlFactory.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Создание фабрики контроллов для Windows
    ControlFactory* windowsFactory = new WindowsControlFactory();

    // Создание формы и контроллов
    Form* form = windowsFactory->createForm();
    Label* label = windowsFactory->createLabel();
    TextBox* textBox = windowsFactory->createTextBox();
    ComboBox* comboBox = windowsFactory->createComboBox();
    Button* button = windowsFactory->createButton();

    // Добавление контроллов на форму
    form->addControl(label);
    form->addControl(textBox);
    form->addControl(comboBox);
    form->addControl(button);

    // Вызов методов контроллов
    form->setPosition(100, 100);
    label->setText("Hello");
    std::cout << label->getText() << std::endl;
    textBox->setText("World");
    std::cout << textBox->getText() << std::endl;
    comboBox->setSelectedIndex(1);
    std::cout << comboBox->getSelectedIndex() << std::endl;
    button->setText("Click me");
    std::cout << button->getText() << std::endl;
    Button::click();

    // Освобождение памяти
    delete windowsFactory;
    delete form;
    delete label;
    delete textBox;
    delete comboBox;
    delete button;

    return 0;
}
