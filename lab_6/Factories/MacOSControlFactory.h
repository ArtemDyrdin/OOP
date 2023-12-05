#ifndef LAB_6_MACOSCONTROLFACTORY_H
#define LAB_6_MACOSCONTROLFACTORY_H

#include "ControlFactory.h"
#include "../Controls/Form.h"
#include "../Controls/Label.h"
#include "../Controls/TextBox.h"
#include "../Controls/ComboBox.h"
#include "../Controls/Button.h"

// Фабрика для создания контроллов под MacOS
class MacOSControlFactory : public ControlFactory {
public:
    Form* createForm() override {
        return new Form();
    }

    Label* createLabel() override {
        return new Label();
    }

    TextBox* createTextBox() override {
        return new TextBox();
    }

    ComboBox* createComboBox() override {
        return new ComboBox();
    }

    Button* createButton() override {
        return new Button();
    }
};


#endif //LAB_6_MACOSCONTROLFACTORY_H
