#pragma once
#include <string>

class IntArray
{
private:
    int m_length{};
    int* m_data{};
public:
    IntArray() = default;
    IntArray(int length);
    ~IntArray() { delete[] m_data; }

    void erase();

    int& operator[](int index);
    int getLength() const;

    void reallocate(int newLength);
    void resize(int newLength);

    IntArray(const IntArray& a);

    IntArray& operator=(const IntArray& a);
    
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
};