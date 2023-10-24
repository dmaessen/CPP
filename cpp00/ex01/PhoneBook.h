#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class PhoneBook
{
private:
    int m_year{};
    int m_month{};
    int m_day{};

public:
    Date(int year, int month, int day);

    void SetDate(int year, int month, int day);

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
};

#endif