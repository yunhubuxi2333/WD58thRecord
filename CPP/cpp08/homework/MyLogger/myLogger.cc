#include "myLogger.hpp"

#include <iostream>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
using std::cout;
using std::endl;
using namespace log4cpp;

Mylogger * Mylogger::_pInstance = nullptr;

Mylogger::Mylogger()
:_mycat(Category::getRoot().getInstance("mycat")){
    auto ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] ")
}