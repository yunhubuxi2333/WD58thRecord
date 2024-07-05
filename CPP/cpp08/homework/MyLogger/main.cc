#include <iostream>
#include <string>

#include "myLogger.hpp"

using std::cout;
using std::endl;
using std::string;

void test0() {
    // 第一步，完成单例模式的写法
    Mylogger* log = Mylogger::getInstance();

    log->error("The log is error message");
    log->warn("The log is warn message");
    log->info("The log is info message");
    log->debug("The log is debug message");

    Mylogger::getInstance()->error("The log is error message");
    Mylogger::getInstance()->warn("The log is warn message");
    Mylogger::getInstance()->info("The log is info message");
    Mylogger::getInstance()->debug("The log is debug message");

    Mylogger::destroy();
}

void test1() {
    printf("hello,world\n");
    // 第二步，像使用printf一样
    // 只要求能输出纯字符串信息即可，不需要做到格式化输出
    LogInfo("The log is info message");
    LogError("The log is error message");
    LogWarn("The log is warn message");
    LogDebug("The log is debug message");
}
int main() {
    test0();
    test1();
    return 0;
}