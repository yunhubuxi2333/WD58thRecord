#ifndef __WD_CloudiskServer_HPP__
#define __WD_CloudiskServer_HPP__

#include <wfrest/HttpMsg.h>
#include <wfrest/HttpServer.h>
#include <workflow/WFFacilities.h>

class CloudiskServer {
   public:
    CloudiskServer(int cnt) : _waitGroup(cnt) {}
    ~CloudiskServer() {}
    void start(unsigned short port);
    void loadModules();
    void loadUserRegisterModulelambda(const wfrest::HttpReq* req,
                                      wfrest::HttpResp* resp,
                                      SeriesWork* series);
    void loadUserLoginModulelambda(const wfrest::HttpReq* req,
                                   wfrest::HttpResp* resp, SeriesWork* series);
    void loadUserInfoModulelambda(const wfrest::HttpReq* req,
                                  wfrest::HttpResp* resp, SeriesWork* series);
    void loadFileQueryModulelambda(const wfrest::HttpReq* req,
                                   wfrest::HttpResp* resp, SeriesWork* series);
    void loadFileUploadModulelambda(const wfrest::HttpReq* req,
                                    wfrest::HttpResp* resp, SeriesWork* series);

   private:
    // 模块化的思维方式写代码
    void loadStaticResourceModule();
    void loadUserRegisterModule();
    void loadUserLoginModule();
    void loadUserInfoModule();
    void loadFileQueryModule();
    void loadFileUploadModule();
    void loadFileDownloadModule();

   private:
    WFFacilities::WaitGroup _waitGroup;
    wfrest::HttpServer _httpserver;
};

#endif
