#include <fstream>

#include "log4cpp/Appender.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Priority.hh"

using namespace log4cpp;

// 四个核心组件
// 日志目的地   (Appender)
// 日志布局     (Layout)
// 日志记录器   (Category)
// 日志优先级   (Priority)

int main(int argc, char** argv) {
    // 准备好目的地和布局
    OstreamAppender* appender1 = new OstreamAppender("console", &std::cout);
    appender1->setLayout(new BasicLayout());

    // OstreamAppender 也可以往文件中写内容
    std::ofstream ofs("program3.log");
    OstreamAppender* appender3 = new OstreamAppender("file", &ofs);
    appender3->setLayout(new BasicLayout());

    // 又准备了一个目的地，采用了同样的布局
    auto appender2 = new FileAppender("default", "program2.log");
    appender2->setLayout(new BasicLayout());

    // getRoot创建出root级别的Category对象（记录器对象）
    Category& root = Category::getRoot();
    root.setPriority(Priority::WARN);
    root.addAppender(appender1);

    Category& sub1 = Category::getInstance(std::string("sub1"));
    sub1.setPriority(Priority::INFO);
    sub1.addAppender(appender2);
    // 不继承root的目的地
    sub1.setAdditivity(false);

    Category& sub2 = Category::getInstance(std::string("sub2"));
    sub2.addAppender(appender3);
    sub2.error("sub2 error msg");

    // 创建sub1下一级的叶子结点
    Category& sub11 = Category::getInstance(std::string("sub1.sub11"));
    sub11.info("sub11 info msg");

    // use of functions for logging messages
    root.error("root error");
    root.info("root info");
    sub1.error("sub1 error");
    sub1.warn("sub1 warn");
    sub1.info("sub1 info");

    // print-style for logging variables
    root.warn("%d + %d == %s ?", 1, 1, "two");

    // use of streams for logging messages
    root << Priority::ERROR << "Streamed root error";
    root << Priority::INFO << "Streamed root info";
    sub1 << Priority::ERROR << "Streamed sub1 error";
    sub1 << Priority::WARN << "Streamed sub1 warn";

    // or this way:
    root.errorStream() << "Another streamed error";

    return 0;
}