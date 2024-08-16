#include "Token.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    Token token("Jackie", "12345678");
    cout << "token:" << token.genToken() << endl;
    return 0;
}

