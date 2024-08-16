#include "Hash.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    Hash hash("Makefile");
    cout << hash.sha1() << " Makefile " << endl;
    return 0;
}

