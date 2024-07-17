#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/RollingFileAppender.hh>
using std::cout;
using std::endl;
using namespace log4cpp;

void test0() {
    // 1、设置布局
    PatternLayout* ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout* ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout* ptn3 = new PatternLayout();
    ptn3->setConversionPattern("%d %c [%p] %m%n");

    // 2、设置目的地(有一个目的地就得有一个布局)
    OstreamAppender* pos = new OstreamAppender("console", &cout);
    // 目的地绑定布局
    pos->setLayout(ptn1);
    // 目的地与布局必须一对一绑定（非常容易出错，注意！！！）
    auto pfile = new FileAppender("file", "wd.log");
    pfile->setLayout(ptn2);
    auto rolling =
        new RollingFileAppender("rollingFile", "rollingwd.log", 5 * 1024, 9);
    rolling->setLayout(ptn3);

    // 3、创建记录器
    Category& cat = Category::getInstance("cate");
    // 记录器设置优先级
    cat.setPriority(Priority::DEBUG);
    // 记录器设置目的地
    cat.addAppender(pos);
    cat.addAppender(pfile);
    cat.addAppender(rolling);

    // 4、写入日志
    int count = 100;
    while (count > 0) {
        cat.emerg("this is an emerg msg");
        cat.fatal("this is an fatal msg");
        cat.alert("this is an alert msg");
        cat.crit("this is an crit msg");
        cat.error("this is an error msg");
        cat.warn("this is an warn msg");
        cat.notice("this is an notice msg");
        cat.info("this is an info msg");
        cat.debug("this is an debug msg");
        count--;
    }
    // 5、回收资源
    Category::shutdown();
}

int main(void) {
    test0();
    return 0;
}