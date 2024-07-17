#include "myLogger.hpp"

#include <iostream>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
using std::cout;
using std::endl;
using namespace log4cpp;

Mylogger* Mylogger::_pInstance = nullptr;

Mylogger::Mylogger() : _mycat(Category::getRoot().getInstance("mycat")) {
    auto ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    auto ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    auto pos = new OstreamAppender("console", &cout);
    pos->setLayout(ptn1);

    auto pfile = new FileAppender("fileApp", "wd.log");
    pfile->setLayout(ptn2);

    _mycat.setPriority(Priority::DEBUG);
    _mycat.addAppender(pos);
    _mycat.addAppender(pfile);

    cout << "Mylogger()" << endl;
}

Mylogger::~Mylogger() {
    Category::shutdown();
    cout << "~Mylogger" << endl;
}

Mylogger* Mylogger::getInstance() {
    if (_pInstance == nullptr) {
        _pInstance = new Mylogger();
    }

    return _pInstance;
}

void Mylogger::destroy() {
    if (_pInstance) {
        delete _pInstance;
        _pInstance = nullptr;
    }
}

void Mylogger::warn(const char* msg) { _mycat.warn(msg); }
void Mylogger::error(const char* msg) { _mycat.error(msg); }
void Mylogger::debug(const char* msg) { _mycat.debug(msg); }
void Mylogger::info(const char* msg) { _mycat.info(msg); }