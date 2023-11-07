#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace font
{
	class Font
	{
	private:
		std::vector<std::string> m_font; // массив строк символов шрифта
		int m_fontSize; // шрифт
		std::ifstream m_fontFile; // файл шрифта

	public:
		explicit Font(int fontSize) : m_fontSize(fontSize)
		{
			if (fontSize != 1) {
                m_fontFile.open("fonts/" + std::to_string(m_fontSize) + ".txt");

                // выкидываем ошибки, если файл не открылся
                if (!m_fontFile.is_open()) {
                    std::cerr << "fonts/" + std::to_string(m_fontSize) + ".txt doesn't open...";
                    exit(1);
                }

                while (!m_fontFile.eof()) {
                    std::string alphabet_str; // строка символов шрифта
                    std::getline(m_fontFile, alphabet_str);
                    m_font.push_back(alphabet_str); // добавляем строки символов шрифта в один массив
                }
            }
        }

        // деструктор
		~Font() {
            m_fontFile.close(); // закрываем файл
        }

        // получить ширину буквы заданного шрифта
		int GetWidth()
		{
			int check = 0; // счетчик символов до пробела
			int fontWidth = 0; // ширина строки

            while (true)
            {
                for (int i = 0; i < m_fontSize; i++)
                    if (m_font[i][fontWidth] != ' ')
                    {
                        check = 0;
                        break;
                    }
                    else check++;

                if (check == m_fontSize)
                    break;

                fontWidth++;
            }
            return fontWidth;
		}

		std::vector<std::string>& GetFont()
		{
			return m_font;
		}
	};
}
