#pragma once

#include <map>

#include "evpp/inner_pre.h"
#include "evpp/event_loop.h"
#include "evpp/slice.h"

struct evhttp_request;
namespace evpp {
    namespace httpc {
        class Request;
        class EVPP_EXPORT Response {
        public:
            typedef std::map<evpp::Slice, evpp::Slice> Headers;
            Response(Request* r, struct evhttp_request* evreq);
            ~Response();

            int http_code() const { return http_code_; }
            const evpp::Slice& body() { return body_; }
            const Request* request() const { return request_; }
            const Headers& header() const { return headers_; }
        private:
            Request* request_;
            struct evhttp_request* evreq_;
            int http_code_;
            evpp::Slice body_;
            Headers headers_;
        };
    } // httpc
} // evpp