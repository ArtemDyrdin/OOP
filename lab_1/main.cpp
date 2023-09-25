#include <iostream>
#include <cmath>
#include <windows.h>
#include "derivatives.h"

using namespace derivatives;

// примерная функция f(x) = x^2
double exampleFunction(double x) {
    return pow(x, 2);
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    double step = 0.01; // шаг

    RightDerivative rightDerivative(step); // правая производная
    LeftDerivative leftDerivative(step); // левая производная
    MiddleDerivative midpointDerivative(step); // средняя производная

    double point = 2.5; // точка

    std::cout << "Правая производная: " << rightDerivative.derivative(exampleFunction, point) << std::endl;
    std::cout << "Левая производная: " << leftDerivative.derivative(exampleFunction, point) << std::endl;
    std::cout << "Средняя производная: " << midpointDerivative.derivative(exampleFunction, point) << std::endl;

    return 0;
}