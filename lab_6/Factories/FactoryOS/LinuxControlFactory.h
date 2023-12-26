#ifndef LAB_6_LINUXCONTROLFACTORY_H
#define LAB_6_LINUXCONTROLFACTORY_H

#include "../ControlFactory.h"
#include "../../Controls/ControlElements/Forms/FormOS/LinuxForm.h"
#include "../../Controls/ControlElements/Labels/LabelOS/LinuxLabel.h"
#include "../../Controls/ControlElements/TextBoxes/TextBoxOS/LinuxTextBox.h"
#include "../../Controls/ControlElements/ComboBoxes/ComboBoxOS/LinuxComboBox.h"
#include "../../Controls/ControlElements/Buttons/ButtonOS/LinuxButton.h"

// Фабрика для создания контроллов под Linux
class LinuxControlFactory : public ControlFactory {
public:
    // Form
    Form* createForm() override {
        return new LinuxForm();
    }

    // Label
    Label* createLabel() override {
        return new LinuxLabel();
    }

    // TextBox
    TextBox* createTextBox() override {
        return new LinuxTextBox();
    }

    // ComboBox
    ComboBox* createComboBox() override {
        return new LinuxComboBox();
    }

    // Button
    Button* createButton() override {
        return new LinuxButton();
    }
};


#endif //LAB_6_LINUXCONTROLFACTORY_H
