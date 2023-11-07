#include <string>
#include "headers/Text.h"

int main() 
{
    std::string str1 = "HELLO WORLD";
    text::Text text1(str1,1,{8, 2},text::Color::PURPLE);

    std::string str5 = "HELLO";
    text::Text text5(str5,5,{4, 4},text::Color::BLUE);

    std::string str7 = "WORLD";
    text::Text text7(str7,7,{0, 10},text::Color::RED);

    text1.Print();
	text5.Print();
    text7.Print();
}