// WaitGroup 让某个线程处于等待状态
#include <workflow/WFFacilities.h>
// WFTaskFactory.h文件里面包含了所有创建任务相关的函数
#include <workflow/WFTaskFactory.h>
// HttpUtil.h 文件包含了处理HTTP的工具
#include <signal.h>
#include <workflow/HttpUtil.h>

#include <iostream>
#include <string>
using std::cerr;
using std::cout;
using std::string;
static WFFacilities::WaitGroup waitGroup(1);
void sigHandler(int signum) {  // 处理信号
    cout << "done!\n";
    waitGroup.done();
}
void httpCallback(WFHttpTask* httpTask) {
    // 检查报错
    int state = httpTask->get_state();  // 获取状态
    int error = httpTask->get_error();  // 获取errno
    switch (state) {
        case WFT_STATE_SYS_ERROR:
            cerr << "system error: " << strerror(error) << "\n";  // 系统错误
            break;
        case WFT_STATE_DNS_ERROR:
            cerr << "DNS error: " << gai_strerror(error)
                 << "\n";  // dns解析错误
            break;
        case WFT_STATE_SSL_ERROR:
            cerr << "SSL error: " << error << "\n";  // 处理ssl连接时出了问题
            break;
        case WFT_STATE_TASK_ERROR:
            cerr << "Task error: " << error << "\n";  // 处理任务时出了问题
            break;
        case WFT_STATE_SUCCESS:  // 成功
            break;
    }
    if (state != WFT_STATE_SUCCESS) {
        cerr << "Failed. Press Ctrl-C to exit.\n";  // 状态不是成功时直接返回
        return;
    }
    // 请求的信息
    protocol::HttpRequest* req = httpTask->get_req();
    cout << "http request method = " << req->get_method() << "\n";
    cout << "http request uri = " << req->get_request_uri() << "\n";
    cout << "http request version = " << req->get_http_version() << "\n";
    // 遍历首部字段
    protocol::HttpHeaderCursor reqCursor(req);
    string key, value;
    while (reqCursor.next(key, value)) {
        cout << "key = " << key << " value = " << value << "\n";  // 打印键值对
    }
    // 响应的信息
    cout << "--------------------------------------------------\n";
    protocol::HttpResponse* resp = httpTask->get_resp();
    cout << "http response version = " << resp->get_http_version() << "\n";
    cout << "http response status code = " << resp->get_status_code() << "\n";
    cout << "http response reason phrase = " << resp->get_reason_phrase()
         << "\n";
    protocol::HttpHeaderCursor respCursor(resp);
    while (respCursor.next(key, value)) {
        cout << "key = " << key << " value = " << value << "\n";
    }

    // workflow框架里面 http报文头和报文体不在一起
    const void* body;  // 不可修改指向的内容，可以修改指向
    size_t size;
    resp->get_parsed_body(&body, &size);
    cout << static_cast<const char*>(body) << "\n";
}
int main() {
    signal(SIGINT, sigHandler);
    WFHttpTask* httpTask = WFTaskFactory::create_http_task(  // 创建任务
        "http://www.baidu.com",                              // url
        10,  // 重定向次数上限
        10,  // 重试次数
        // nullptr); //回调函数
        httpCallback);  // 新的回调函数
    // 在启动任务之前，设置任务的属性
    // 只能改请求，不能改响应
    protocol::HttpRequest* req = httpTask->get_req();
    req->add_header_pair("key1", "value1");
    // 启动任务
    httpTask->start();
    waitGroup.wait();
    cout << "finished!\n";
    return 0;
}