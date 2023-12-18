#include <iostream>
#include "palindrome.h"

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is 'racecar' a palindrome ? " << isPalindrome("racecar") << std::endl;
    std::cout << "Is 'hello' a palindrome ? " << isPalindrome("hello") << std::endl;
    return 0;
}

