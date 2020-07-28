#include <iostream>
using namespace std;

int my_atoi(char* number)
{
    int returnNumber = 0;
    int sign = 1;

    if(*number == '\n')
        return 0;
    if(*number == '-')
        sign = -1;

    while(*number)
    {
        if(*number >= '0' && *number <= '9')
            returnNumber = returnNumber * 10 + (*number - '0');
        number++;
    }
    return returnNumber * sign;
}

int main(void) {
    // your code goes here
    cout << my_atoi("-123") << endl;
    cout << my_atoi("1234");
    return 0;
}
