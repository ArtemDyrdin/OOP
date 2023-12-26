#ifndef LAB_6_CONTROLFACTORY_H
#define LAB_6_CONTROLFACTORY_H

#include "../Controls/ControlElements/Forms/Form.h"
#include "../Controls/ControlElements/Labels/Label.h"
#include "../Controls/ControlElements/TextBoxes/TextBox.h"
#include "../Controls/ControlElements/ComboBoxes/ComboBox.h"
#include "../Controls/ControlElements/Buttons/Button.h"

// Абстрактная фабрика для создания контроллов
class ControlFactory {
public:
    virtual Form* createForm() = 0; // для Form
    virtual Label* createLabel() = 0; // для Label
    virtual TextBox* createTextBox() = 0; // для TextBox
    virtual ComboBox* createComboBox() = 0; // для ComboBox
    virtual Button* createButton() = 0; // для Button

    virtual ~ControlFactory() = default; // виртуальный деструктор
};


#endif //LAB_6_CONTROLFACTORY_H
