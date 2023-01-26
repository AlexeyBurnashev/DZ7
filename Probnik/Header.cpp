#include "Header.h"
#include "ArrayException.h"

IntArray::IntArray(int length) : m_length(length)  // конструктор
{
    if(length <= 0)
    {
        throw Bad_Length();
    }

    else
    {
        m_data = new int[length];
    }      
}

void IntArray::erase()  //  функция которая сотрет массив и установит длину в 0
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int& IntArray::operator[](int index) // перегрузка оператора [], чтобы получить доступ к элементам массива.
{
    if (index >= 0 && index < m_length)
    {
        return m_data[index];
    }
}

int IntArray::getLength() const // функция доступа для возврата длины массива
{ 
    return m_length; 
}

void IntArray::reallocate(int newLength) //функция, уничтожит все существующие элементы в массиве при изменении его размера
{
    erase();

    if (newLength <= 0)
    {
        return;
    }
    m_data = new int[newLength];
    m_length = newLength;
}

void IntArray::resize(int newLength) // функция, сохранит все существующие элементы в массиве при изменении его размера
{
    if (newLength == m_length)
    {
        return;
    }
    if (newLength <= 0)
    {
        throw Bad_resize(); 
        erase();
        return;
    }

    if (newLength > m_length)
    {
        throw Bad_range();
    }

    int* data = new int[newLength];

    if (m_length > 0)
    {
        int elementsToCopy = (newLength > m_length) ? m_length : newLength;

        for (int index = 0; index < elementsToCopy; ++index)
        {
            data[index] = m_data[index];
        }
                
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

IntArray::IntArray(const IntArray& a) // конструктор копирования
{
    reallocate(a.getLength());

    for (int index = 0; index < m_length; ++index)
    {
        m_data[index] = a.m_data[index];
    }     
}

IntArray& IntArray::operator = (const IntArray& a) //  оператор присваивания, чтобы мы могли копировать массив
{
    if (&a == this)
    {
        return *this;
    }

    reallocate(a.getLength());

    for (int index = 0; index < m_length; ++index)
    {
        m_data[index] = a.m_data[index];
    }
    return *this;
}

void IntArray::insertBefore(int value, int index) //  функции вставки
{
    if (index <= 0 || index >= m_length)
    {
        throw Bad_insertBefore(); 
    }

    int* data = new int[m_length + 1];

    for (int before = 0; before < index; ++before)
    {
        data[before] = m_data[before];
    }

    data[index] = value;

    for (int after = index; after < m_length; ++after)
    {
        data[after + 1] = m_data[after];
    }

    delete[] m_data;
    m_data = data;
    ++m_length;
}

void IntArray::remove(int index) //  функция удаления
{
    if (index <= 0 || index >= m_length)
    {
        throw Bad_remove();    
    }

    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data = new int[m_length - 1];

    for (int before = 0; before < index; ++before)
    {
        data[before] = m_data[before];
    }
        
    for (int after = index + 1; after < m_length; ++after)
    {
        data[after - 1] = m_data[after];
    }
    delete[] m_data;
    m_data = data;
    --m_length;
}

void IntArray::insertAtBeginning(int value)
{
    insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value)
{
    insertBefore(value, m_length);
}