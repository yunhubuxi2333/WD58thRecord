#include <signal.h>
#include <wfrest/HttpServer.h>
#include <workflow/WFFacilities.h>

#include <iostream>
using std::cout;
using std::map;
using std::string;

static WFFacilities::WaitGroup waitGroup(1);

void sighandler(int signum) {
    cout << "done!\n";  // 尽量避免使用endl
    waitGroup.done();
}

int main() {
    signal(SIGINT, sighandler);
    wfrest::HttpServer server;
    // server.GET("/hello",[](const wfrest::Re){

    // })
}
