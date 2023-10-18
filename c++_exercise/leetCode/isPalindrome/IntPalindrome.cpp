class IntPalindrome {
public:
    bool isPalindrome(int x) {
        
        bool tORf;
        int mod, quotient = 0, baseTen = 100;
        int* numbersArray = new int[100];

        for (int i = 0; baseTen >= 1; i++)
        {
            mod = x % baseTen;
            quotient = x / baseTen;
            x -= baseTen;
            baseTen /= 10;

            numbersArray[i] = quotient;
        }

        int size = sizeof(numbersArray)/sizeof(numbersArray[0]);
        for (int i = 0, j = size; i <= size  && j >= 0; i++, j--)
        {
            if (numbersArray[i] != numbersArray[j])
            {
                tORf = false;
                break;
            }
            else
            {
                tORf = true;
            }
        }
        return tORf;
    }
};

int main(void)
{
    IntPalindrome intPlaindrome;
    intPlaindrome.isPalindrome(121);
}