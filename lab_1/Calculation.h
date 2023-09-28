#ifndef LAB_1_CALCULATION_H
#define LAB_1_CALCULATION_H

// базовый класс для расчетов
class Calculation {
protected:
    double step;
public:
    // конструктор принимает шаг в качестве параметра
    explicit Calculation(double step) : step(step) {}

    // общая функция для взятия производной с параметрами: функция и точка
    virtual double derivative(double (*function)(double), double point) = 0;
};

#endif //LAB_1_CALCULATION_H
