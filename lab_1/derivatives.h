#ifndef LAB_1_DERIVATIVES_H
#define LAB_1_DERIVATIVES_H

#include "Calculation.h"

// пространство имен производных
namespace derivatives {

    // правая производная
    class RightDerivative : public Calculation {
    public:
        explicit RightDerivative(double step) : Calculation(step) {}

        // значение правой производной в точке
        double derivative(double (*function)(double), double point) override {
            return (function(point + step) - function(point)) / step; // формула расчета правой производной
        }
    };

    // левая производная
    class LeftDerivative : public Calculation {
    public:
        explicit LeftDerivative(double step) : Calculation(step) {}

        // значение левой производной в точке
        double derivative(double (*function)(double), double point) override {
            return (function(point) - function(point - step)) / step; // формула расчета левой производной
        }
    };

    // средняя производная
    class MiddleDerivative : public Calculation {
    public:
        explicit MiddleDerivative(double step) : Calculation(step) {}

        // значение средней производной в точке
        double derivative(double (*function)(double), double point) override {
            return (function(point + step) - function(point - step)) / (2 * step); // формула расчета средней производной
        }
    };
}

#endif //LAB_1_DERIVATIVES_H
