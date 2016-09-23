#pragma once

#include <string>

#include "ez/http/HttpRequestHandler.h"

namespace ez {
namespace http {

class HttpFileHandler : public HttpRequestHandler {
  public:
    explicit HttpFileHandler(const std::string &root);

    virtual bool handleRequest(const HttpRequest &req,
                               HttpResponse &res) override;

    bool setFileNotFoundPage(const std::string &errorPath);

  private:
    std::string determine_mime_type(const std::string &extension);

    std::string root_;
    std::string errorPage_;
};

} // namespace http
} // namespace ez
