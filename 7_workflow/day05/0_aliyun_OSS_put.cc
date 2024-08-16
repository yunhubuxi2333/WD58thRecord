#include <alibabacloud/oss/OssClient.h>

#include <iostream>
#include <string>
using std::cerr;
using std::cout;
using std::string;
using namespace AlibabaCloud::OSS;

struct OSSInfo {
    string AccessKeyID = "LTAI5tQr5nUfy6E5zuSVAG6w";
    string AccessKeySecret = "dJtH44eQ6FiEwtDrtYnhlcNbu78Vwe";
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

    // 调用对象的方法 PutObject 是上传文件
    PutObjectOutcome outcome =
        client.PutObject(ossInfo.Bucket, "tmp/test.txt", "file1.txt");
    // Bucket 网盘的名字
    // key "tmp/test.txt" 在OSS的路径
    // file "file1.txt" 在本地的路径

    // 检查报错
    if (outcome.isSuccess()) {
        cerr << "Success!\n";
    } else {
        cerr << "Fail, message = " << outcome.error().Message() << "\n";
    }
    // 释放内存
    ShutdownSdk();
    return 0;
}