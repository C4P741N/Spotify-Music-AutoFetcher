#pragma once
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <iostream>

//vcpkg.exe integrate install

using namespace web;
using namespace web::http;
using namespace web::http::client;

class Casablanca
{
    //pplx::task<void> HTTPPostAsync() {
    //    http_client client("http://localhost/path/to/file.php");

    //    http_request request(methods::POST);
    //    request.headers().add(L"Content-Type", L"application/x-www-form-urlencoded");
    //    request.headers().add(L"Content-Length", L"21");//length of the submitted data/payload (in bytes)
    //    // request.headers().add("Host", "ericzwar.com");
    //    request.headers().add(L"X-Requested-With", L"Casablanca");
    //    request.set_body("user=john&password=hi");// 21 bytes long

    //    return client.request(request).then([](http_response response) {
    //        // process response here
    //        });
    //}

//private:
//    uri_builder _CreateHeader(http_request request) {
//        // Create a file stream to output file.
//        auto fileStream = std::make_shared<std::ostream>(U("results.html"));
//
//        // Base64 encode the username:password
//        std::string base64EncodedCredentials = conversions::to_base64("username:password");
//
//        // Create http_client with credentials
//        http_client_config config;
//        credentials creds(L"username", L"password");
//        config.set_credentials(creds);
//        http_client client(U("https://api.prosper.com/"), config);
//
//        // Create header
//        http_request req(methods::GET);
//        req.headers().add(L"Authorization", utility::conversions::to_string_t("Basic " + base64EncodedCredentials));
//        req.set_request_uri(L"/api/json/xyz");
//
//        // Send request
//        pplx::task<http_response> responses = client.request(req);
//        pplx::task<web::json::value> jvalue = responses.get().extract_json();
//        std::wcout << jvalue.get().to_string();
//
//        return uri_builder(); // You need to return a uri_builder object, adjust as per your needs
//    }

private:
    const wchar_t* _ConvertFromStringToWchar_t(std::string value) {
        std::wstring widestr = std::wstring(value.begin(), value.end());

        const wchar_t* widecstr = widestr.c_str();

        return widecstr;
    }
private:
    http_client_config _SetUserCredentials(std::string user, std::string pass) {
        // Create a file stream to output file.
        //auto fileStream = std::make_shared<std::ostream>(U("results.html"));
        // Base64 encode the username:password
        //std::string base64EncodedCredentials = conversions::to_base64("username:password");

        // Base64 encode the username:password
        //std::wstring userpass = std::wstring(user) + L":" + pass;
        //std::string base64EncodedCredentials = utility::conversions::to_base64(userpass);

        const wchar_t* widec_Userstr = _ConvertFromStringToWchar_t(user);
        const wchar_t* widec_Paswstr = _ConvertFromStringToWchar_t(pass);

        http_client_config config;
        credentials creds(widec_Userstr, widec_Paswstr);
        config.set_credentials(creds);
        //http_client client(U("https://api.prosper.com/"), config);

        return config;
    }
private:
    uri_builder _CreateHeader(http_request request) {
        uri_builder builder(_url_fetch_all_playlist);
        builder.append_query(U("param1"), U("value1"));
        builder.append_query(U("param2"), U("value2"));

        const int bufferSize = strlen(_bearer) + strlen(_token) + 1;

        utility::string_t concatToken = _ConcatenatedToken();

        //uri access = uri(U("/v1/me/playlists"));

        // Build HTTP request
        //request.set_method(methods::GET);
        request.set_request_uri(builder.to_string());

        request.headers().add(L"Authorization", concatToken);


        return builder;
    }
private:
    utility::string_t _ConcatenatedToken() {

        const int bufferSize = strlen(_bearer) + strlen(_token) + 1;

        char* concatToken = new char[bufferSize];

        strcpy_s(concatToken, bufferSize, _bearer);
        strcpy_s(concatToken, bufferSize, _token);

        utility::string_t token = utility::conversions::to_string_t(concatToken);

        delete[] concatToken;

        return token;
    }
public:
    bool Connect(std::string user, std::string pasw) {

        try {

            /* http_request request(methods::GET);
             request.headers().add(L"id", L"1234567890");
             request.headers().add(L"auth", L"7d8ffbecb05d59459f96d6e3aac8542e");*/

             //curl --request GET \
             //    --url https ://api.spotify.com/v1/me/playlists \
             //  --header 'Authorization: Bearer 1POdFZRZbvb...qqillRxMr2z'

            

             // Create an HTTP client
            http_client_config config = _SetUserCredentials(user, pasw);
            http_client client(_url_spotify, config);

            //// Prepare request URI and headers
            //uri_builder builder(_url_fetch_all_playlist);
            //builder.append_query(U("param1"), U("value1"));
            //builder.append_query(U("param2"), U("value2"));

            //const char* bearer = "Bearer ";

            //const int bufferSize = strlen(_bearer)+ strlen(_token)+1;

            //char* concatToken = ConcatenatedToken();

            ////uri access = uri(U("/v1/me/playlists"));

            // Build HTTP request
            http_request request(methods::GET);
            uri_builder builder = _CreateHeader(request);
            //request.set_request_uri(builder.to_string());
            ////request.headers().add(U("Authorization"), U(concatToken));

            //std::string authorizationHeader = "Authorization: ";
            //authorizationHeader += concatToken;

            //request.headers().add(U(authorizationHeader.c_str()));

            // Send HTTP request asynchronously
            client.request(request).then([](http_response response) {
                if (response.status_code() == status_codes::OK) {
                    // Parse response body as JSON
                    return response.extract_json();
                }
                else {
                    throw std::runtime_error("Received non-OK status code from server");
                }
                }).then([](json::value jsonResponse) {
                    // Process JSON response
                    //std::cout << jsonResponse.serialize().c_str() << std::endl;
                    std::cout << "Response received: " << jsonResponse.serialize().c_str() << std::endl;
                    }).wait(); // Wait for the asynchronous operation to complete


                    //// Send request
                    //pplx::task<http_response> responses = client.request(req);
                    //pplx::task<web::json::value> jvalue = responses.get().extract_json();
                    //std::wcout << jvalue.get().to_string();
        }
        catch (std::exception e) {
            std::cerr << "Error occurred during JSON serialization: " << e.what() << std::endl;
            return false;
        }

        return true;
    }

private:
    const uri _url_spotify = uri(U("api.spotify.com"));
    const uri _url_fetch_all_playlist = uri(U("/v1/me/playlists"));
    const char* _token = "1POdFZRZbvbqqillRxMr2z";
    const char* _bearer = "Bearer ";
    //const std::string _authorizationHeader = "Authorization: ";
};

