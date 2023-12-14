#ifndef LAB_7_USER_H
#define LAB_7_USER_H

#include <vector>
#include <string>

// Пол
enum class Gender
{
    Male,
    Female
};

// Класс User
class User
{
private:
    int m_Id{}; // Id
    std::string m_Name{}; // имя
    std::string m_Email{}; // почта
    std::string m_Phone{}; // телефон
    std::string m_City{}; // город
    Gender m_Gender{}; // пол

public:
    // Сеттер Id
    void setId(int id)
    {
        m_Id = id;
    }

    // Геттер Id
    [[nodiscard]] int getId() const {
        return m_Id;
    }

    // Сеттер имени
    void setName(const std::string& name)
    {
        m_Name = name;
    }

    // Геттер имени
    [[nodiscard]] std::string getName() const {
        return m_Name;
    }

    // Сеттер почты
    void setEmail(const std::string& email)
    {
        m_Email = email;
    }

    // Геттер почты
    [[nodiscard]] std::string getEmail() const {
        return m_Email;
    }

    // Сеттер телефона
    void setPhone(const std::string& phone)
    {
        m_Phone = phone;
    }

    // Геттер телефона
    [[nodiscard]] std::string getPhone() const {
        return m_Phone;
    }

    // Сеттер города
    void setCity(const std::string& city)
    {
        m_City = city;
    }

    // Геттер города
    [[nodiscard]] std::string getCity() const {
        return m_City;
    }

    // Сеттер пола
    void setGender(Gender gender)
    {
        m_Gender = gender;
    }

    // Геттер пола
    [[nodiscard]] Gender getGender() const {
        return m_Gender;
    }

    // Оператор "==" через friend
    friend bool operator==(const User& left, const User& right);
};

// Реализация оператора "=="
bool operator==(const User& left, const User& right)
{
    return ((left.m_Id == right.m_Id) && (left.m_Gender == right.m_Gender) && (left.m_City == right.m_City) &&
            (left.m_Phone == right.m_Phone) && (left.m_Email == right.m_Email) && (left.m_Name == right.m_Name));
}


#endif //LAB_7_USER_H
