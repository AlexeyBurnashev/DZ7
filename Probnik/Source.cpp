#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    try
    {
        IntArray array(10);

        for (int i = 0; i < 10; ++i)
        {
            array[i] = i + 1;
        }

        array.resize(8);

        array.insertBefore(20, 0);

        array.remove(3);

        array.insertAtEnd(30);

        array.insertAtBeginning(40);

        for (int i = 0; i < array.getLength(); ++i)
        {
            cout << array[i] << ' ';
        }
        cout << endl;
    }

    catch (exception& exception)
    {
        cout << exception.what() << endl;
    }

    return 0;
}