#pragma once
//#include <cpprest/http_client.h>
//#include <cpprest/json.h>
#include <iostream>
//
//using namespace web;
//using namespace web::http;
//using namespace web::http::client;
//
//class Casablanca
//{
//public:
//    int Connect() {
//        // Create an HTTP client
//        http_client client(U("https://api.example.com"));
//
//        // Prepare request URI and headers
//        uri_builder builder(U("/api/resource"));
//        builder.append_query(U("param1"), U("value1"));
//        builder.append_query(U("param2"), U("value2"));
//
//        // Build HTTP request
//        http_request request(methods::GET);
//        request.set_request_uri(builder.to_string());
//        request.headers().add(U("Authorization"), U("Bearer <your_access_token>"));
//
//        // Send HTTP request asynchronously
//        client.request(request).then([](http_response response) {
//            if (response.status_code() == status_codes::OK) {
//                // Parse response body as JSON
//                return response.extract_json();
//            }
//            else {
//                throw std::runtime_error("Received non-OK status code from server");
//            }
//            }).then([](json::value jsonResponse) {
//                // Process JSON response
//                std::cout << "Response received: " << jsonResponse.serialize() << std::endl;
//                }).wait(); // Wait for the asynchronous operation to complete
//
//                return 0;
//    }
//};

