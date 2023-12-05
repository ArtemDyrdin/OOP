#ifndef LAB_6_CONTROLFACTORY_H
#define LAB_6_CONTROLFACTORY_H

#include "../Controls/Form.h"
#include "../Controls/Label.h"
#include "../Controls/TextBox.h"
#include "../Controls/ComboBox.h"
#include "../Controls/Button.h"

// Абстрактная фабрика для создания контроллов
class ControlFactory {
public:
    virtual Form* createForm() = 0;
    virtual Label* createLabel() = 0;
    virtual TextBox* createTextBox() = 0;
    virtual ComboBox* createComboBox() = 0;
    virtual Button* createButton() = 0;

    virtual ~ControlFactory() = default;
};


#endif //LAB_6_CONTROLFACTORY_H
