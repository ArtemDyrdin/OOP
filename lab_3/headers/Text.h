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
        font::Font m_font; // �����
        COORD m_coord; // ����������
        Color m_color; // ����
        int m_fontSize; // ������ ������
        std::string m_newText; // ������, ������� ����������� ����� �������
        std::vector<std::string> m_fText; // ����� ������
        std::vector<int> m_letter_indices; // ������ � ��������� ���� ���������� �����
        HANDLE m_hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // ������, ���������� �� ����� � �������

    public:
        // �������������� ���������� ������ � ��������� ������� ���� ���������� �����
        Text(std::string& defText, int fontSize, COORD coord, Color color) : m_font(fontSize),
                        m_newText(defText), m_fontSize(fontSize), m_coord(coord), m_color(color)
        {
            setIndex(); // ��������� ������� ���� �����
        }

        // ������� ����� � �������
        void Print()
        {
            SetConsoleTextAttribute(m_hStdOut, (int)m_color);
            SetConsoleCursorPosition(m_hStdOut, m_coord);

            if (m_fontSize != 1) {
                int width = m_font.GetWidth(); // ������ ����� ����� � ������
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
        // ���������� ������� ���� ���������� �����
        void setIndex()
        {
            for (char i : m_newText)
                m_letter_indices.push_back(static_cast<int>(i) - static_cast<int>('A'));
        }
	};
}
