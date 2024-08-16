#include <signal.h>
#include <workflow/HttpUtil.h>
#include <workflow/WFFacilities.h>
#include <workflow/WFTaskFactory.h>

#include <iostream>
#include <string>
using std::cerr;
using std::cout;
using std::string;
static WFFacilities::WaitGroup waitGroup(1);
void sigHandler(int signum) {
    cout << "done!\n";
    waitGroup.done();
}
void httpCallback(WFHttpTask* httpTask) {  // 检查报错
    int state = httpTask->get_state();     // 获取状态
    int error = httpTask->get_error();     // 获取errno
    switch (state) {
        case WFT_STATE_SYS_ERROR:
            cerr << "system error: " << strerror(error) << "\n";
            break;
        case WFT_STATE_DNS_ERROR:
            cerr << "DNS error: " << gai_strerror(error) << "\n";
            break;
        case WFT_STATE_SSL_ERROR:
            cerr << "SSL error: " << error << "\n";
            break;
        case WFT_STATE_TASK_ERROR:
            cerr << "Task error: " << error << "\n";
            break;
        case WFT_STATE_SUCCESS:
            break;
    }
    if (state != WFT_STATE_SUCCESS) {
        cerr << "Failed. Press Ctrl-C to exit.\n";
        return;
    }

    // 请求的信息
    protocol::HttpRequest* req = httpTask->get_req();  // 获取请求
    cout << "http request method = " << req->get_method() << "\n";
    cout << "http request uri = " << req->get_request_uri() << "\n";
    cout << "http request version = " << req->get_http_version() << "\n";

    // 遍历首部字段
    protocol::HttpHeaderCursor reqCursor(
        req);  // HttpHeaderCursor 是一个可以访问全部字段的迭代器
    string key, value;
    while (reqCursor.next(
        key, value)) {  // next是取出下一个首部字段，配合while循环使用
        cout << "key = " << key << "\tvalue = " << value << "\n";
    }

    // 响应的信息

    cout << "--------------------------------------------------\n";
    protocol::HttpResponse* resp = httpTask->get_resp();  // 响应的信息
    cout << "http response version = " << resp->get_http_version() << "\n";
    cout << "http responses tatus code = " << resp->get_status_code() << "\n";
    cout << "http response reason phrase = " << resp->get_reason_phrase()
         << "\n";

    protocol::HttpHeaderCursor respCursor(resp);  // 遍历首部字段
    while (respCursor.next(key, value)) {
        cout << "key = " << key << "\tvalue = " << value << "\n";
    }

    // workflow框架里面 http报文头和报文体不在一起
    const void* body;

    size_t size;
    resp->get_parsed_body(&body, &size);
    cout << static_cast<const char*>(body) << "\n";
}

int main() {
    signal(SIGINT, sigHandler);

    WFHttpTask* httpTask = WFTaskFactory::create_http_task(
        "http://www.baidu.com", 10, 10, httpCallback);

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