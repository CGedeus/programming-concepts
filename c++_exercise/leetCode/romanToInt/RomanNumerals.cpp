/**
 * @file RomanNumerals.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class RomanNumerals {
    public:
        int romanToInt(string s) {

            int sum = 0;
            int size = (sizeof(s)/sizeof(s[0])*4);

            vector<int> decNum;
            decNum.reserve(size);

            for (int i = 0; s[i] != '\0'; i++)
            {
                if (s[i] == 'I')
                {
                    decNum[i] = 1;
                }
                else if (s[i] == 'V')
                {
                    decNum[i] = 5;
                }
                else if (s[i] == 'X')
                {
                    decNum[i] = 10;
                }
                else if (s[i] == 'L')
                {
                    decNum[i] = 50;
                }
                else if (s[i] == 'C')
                {
                    decNum[i] = 100;
                }
                else if (s[i] == 'D')
                {
                    decNum[i] = 500;
                }
                else if (s[i] == 'M')
                {
                    decNum[i] = 1000;
                }
                else
                {
                    // Nothing
                }
            }

            for (int i = 0; i <= sizeof(size); i++)
            {
                if (decNum[i] < decNum[i + 1])
                {
                    sum += decNum[i + 1] - decNum[i];
                    i++;
                }
                else
                {
                    sum += decNum[i];
                }
            }
            return sum;
        }
};

int main(void)
{
    RomanNumerals romanToInteger;
    int decimal;

    decimal = romanToInteger.romanToInt("LVIII");
    cout << decimal << endl;

    return 0;
}