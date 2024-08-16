#include "CloudiskServer.h"
#include <iostream>

int main()
{
    CloudiskServer cloudiskServer(1);
    cloudiskServer.loadModules();
    cloudiskServer.start(1234);
    return 0;
}

