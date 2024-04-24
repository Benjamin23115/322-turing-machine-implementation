#include "abstract.h"
char upperCase(char c)
{
    // Check if the character is lowercase
    if (c >= 'a' && c <= 'z')
    {
        // Convert to uppercase by subtracting the ASCII difference
        return c - ('a' - 'A');
    }
    else
    {
        // Return unchanged if it's not a lowercase character
        return c;
    }
}