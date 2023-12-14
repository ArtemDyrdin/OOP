#ifndef LAB_6_LINUXCONTROLFACTORY_H
#define LAB_6_LINUXCONTROLFACTORY_H

#include "../ControlFactory.h"
#include "../../Controls/ControlElements/Forms/Form.h"
#include "../../Controls/Labels/Label.h"
#include "../../Controls/ControlElements/TextBoxes/TextBox.h"
#include "../../Controls/ControlElements/ComboBoxes/ComboBox.h"
#include "../../Controls/ControlElements/Buttons/Button.h"

// Фабрика для создания контроллов под Linux
class [[maybe_unused]] LinuxControlFactory : public ControlFactory {
public:
    // Form
    Form* createForm() override {
        return new Form();
    }

    // Label
    Label* createLabel() override {
        return new Label();
    }

    // TextBox
    TextBox* createTextBox() override {
        return new TextBox();
    }

    // ComboBox
    ComboBox* createComboBox() override {
        return new ComboBox();
    }

    // Button
    Button* createButton() override {
        return new Button();
    }
};


#endif //LAB_6_LINUXCONTROLFACTORY_H
