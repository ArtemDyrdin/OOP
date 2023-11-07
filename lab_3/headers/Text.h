#pragma once
#include "Font.h"
#include <Windows.h>

namespace text 
{
    enum class Color
    {
        BLUE [[maybe_unused]] = 1,
        GREEN [[maybe_unused]] = 2,
        CYAN [[maybe_unused]] = 3,
        RED [[maybe_unused]] = 4,
        PURPLE [[maybe_unused]] = 5,
        YELLOW [[maybe_unused]] = 6,
        WHITE [[maybe_unused]] = 7,
    };

    class Text
    {
    private:
        font::Font m_font; // шрифт
        COORD m_coord; // координаты
        Color m_color; // цвет
        int m_fontSize; // размер шрифта
        std::string m_newText; // строка, которую преобразуем новым шрифтом
        std::vector<std::string> m_fText; // новая строка
        std::vector<int> m_letter_indices; // массив с индексами букв введенного слова
        HANDLE m_hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // объект, отвечающий за текст в консоль

    public:
        // инициализируем переменные класса и сохраняем индексы букв введенного слова
        Text(std::string& defText, int fontSize, COORD coord, Color color) : m_font(fontSize),
                        m_newText(defText), m_fontSize(fontSize), m_coord(coord), m_color(color)
        {
            setIndex(); // сохраняем индексы букв слова
        }

        // вывести слово в консоль
        void Print()
        {
            SetConsoleTextAttribute(m_hStdOut, (int)m_color);
            SetConsoleCursorPosition(m_hStdOut, m_coord);

            if (m_fontSize != 1) {
                int width = m_font.GetWidth(); // ширина одной буквы в шрифте
                for (int i = 0; i < m_fontSize; i++) {
                    for (int j: m_letter_indices) {
                        if (j != -33) {
                            for (int k = 0; k <= width; k++)
                                std::cout << m_font.GetFont()[i][k + width * j + j];
                            std::cout << " ";

                        } else std::cout << "\t";
                    }
                    std::cout << std::endl;
                    m_coord.Y++;
                    SetConsoleCursorPosition(m_hStdOut, m_coord);
                }
            } else {
                std::cout << m_newText;
            }
        }

    private:
        // установить индексы букв введенного слова
        void setIndex()
        {
            for (char i : m_newText)
                m_letter_indices.push_back(static_cast<int>(i) - static_cast<int>('A'));
        }
	};
}
