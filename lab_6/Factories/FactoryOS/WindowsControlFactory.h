#ifndef LAB_6_WINDOWSCONTROLFACTORY_H
#define LAB_6_WINDOWSCONTROLFACTORY_H

#include "../ControlFactory.h"
#include "../../Controls/ControlElements/Forms/FormOS/WindowsForm.h"
#include "../../Controls/ControlElements/Labels/LabelOS/WindowsLabel.h"
#include "../../Controls/ControlElements/TextBoxes/TextBoxOS/WindowsTextBox.h"
#include "../../Controls/ControlElements/ComboBoxes/ComboBoxOS/WindowsComboBox.h"
#include "../../Controls/ControlElements/Buttons/ButtonOS/WindowsButton.h"

// Фабрика для создания контроллов под Windows
class WindowsControlFactory : public ControlFactory {
public:
    // Form
    Form* createForm() override {
        return new WindowsForm();
    }

    // Label
    Label* createLabel() override {
        return new WindowsLabel();
    }

    // TextBox
    TextBox* createTextBox() override {
        return new WindowsTextBox();
    }

    // ComboBox
    ComboBox* createComboBox() override {
        return new WindowsComboBox();
    }

    // Button
    Button* createButton() override {
        return new WindowsButton();
    }
};


#endif //LAB_6_WINDOWSCONTROLFACTORY_H
