#include <alibabacloud/oss/OssClient.h>

#include <iostream>
#include <string>
using std::cerr;
using std::cout;
using std::string;
using namespace AlibabaCloud::OSS;

struct OSSInfo {
    string AccessKeyID = "";
    string AccessKeySecret = "";
    string EndPoint = "oss-cn-wuhan-lr.aliyuncs.com";
    string Bucket = "58huwentao-test";
};

int main(void) {
    // 初始化 账户信息、OSS的网址
    OSSInfo ossInfo;
    // 申请网络操作的内存
    InitializeSdk();
    // 创建一个OssClient对象
    ClientConfiguration conf;
    OssClient client(ossInfo.EndPoint, ossInfo.AccessKeyID,
                     ossInfo.AccessKeySecret, conf);
    // EndPoint 是OSSDE网址
    // AccessKey ID Secret 用户 密码
    // conf 客户端属性

    time_t now = time(nullptr);
    time_t expires = now + 600;
    StringOutcome outcome =
        client.GeneratePresignedUrl(ossInfo.Bucket, "AccessKey.txt", expires);
    if (outcome.isSuccess()) {
        cout << "url = " << outcome.result() << "\n";
    } else {
        cerr << "fail, message = " << outcome.error().Message() << "\n";
    }

    // 释放内存
    ShutdownSdk();
    return 0;
}