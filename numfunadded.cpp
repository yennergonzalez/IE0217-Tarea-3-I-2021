#include <cctype>
#include <sstream>
#include <iostream>

using namespace std;

// averigua si una cadena es número
bool isNumber(const std::string &number)
{
    int pointCount = 0;
    const std::string::const_iterator end = number.end();
    std::string::const_iterator i = number.begin();
    while (i != end)
    {
        if (std::isdigit(*i) == 0)
        {
            if (*i != '.')
            {
                return false;
            }
            else
            {
                ++pointCount;
                if (pointCount >= 2)
                {
                    return false;
                }
            }
        }
        ++i;
    }
    return true;
}

// convierte cadena a número
double toNumber(const std::string &number)
{
    double value = 0.0f;
    if (isNumber(number))
    {
        istringstream iss(number);
        iss >> value;
    }
    return value;
}

int main()
{
    cout << isNumber("123.549") << endl;
    cout << toNumber("123.549") << endl;
    return 0;
}
