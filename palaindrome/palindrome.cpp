#include "palindrome.h"
#include <queue>
#include <stack>
#include <cctype>

bool isPalindrome(const string& input) {
    queue<char> charactersQueue;
    stack<char> charactersStack;

    for (char c : input) {
        if (isalpha(c)) {
            charactersQueue.push(tolower(c));
            charactersStack.push(tolower(c));
        }
    }

    while (!charactersQueue.empty() && !charactersStack.empty()) {
        if (charactersQueue.front() != charactersStack.top()) {
            return false;
        }
        charactersQueue.pop();
        charactersStack.pop();
    }

    return charactersQueue.empty() && charactersStack.empty();
}

