#ifndef LAB_6_MACOSCONTROLFACTORY_H
#define LAB_6_MACOSCONTROLFACTORY_H

#include "../ControlFactory.h"
#include "../../Controls/ControlElements/Forms/FormOS/MacOSForm.h"
#include "../../Controls/ControlElements/Labels/LabelOS/MacOSLabel.h"
#include "../../Controls/ControlElements/TextBoxes/TextBoxOS/MacOSTextBox.h"
#include "../../Controls/ControlElements/ComboBoxes/ComboBoxOS/MacOSComboBox.h"
#include "../../Controls/ControlElements/Buttons/ButtonOS/MacOSButton.h"

// Фабрика для создания контроллов под MacOS
class MacOSControlFactory : public ControlFactory {
public:
    // Form
    Form* createForm() override {
        return new MacOSForm();
    }

    // Label
    Label* createLabel() override {
        return new MacOSLabel();
    }

    // TextBox
    TextBox* createTextBox() override {
        return new MacOSTextBox();
    }

    // ComboBox
    ComboBox* createComboBox() override {
        return new MacOSComboBox();
    }

    // Button
    Button* createButton() override {
        return new MacOSButton();
    }
};


#endif //LAB_6_MACOSCONTROLFACTORY_H
