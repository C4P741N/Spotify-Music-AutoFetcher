#pragma once

#include <string>
#include <iostream>

class UserInfoManager
{
public:
    UserInfoManager(const std::string& username, const std::string& password)
        : username(username), password(password), loginSuccess(false) {
        loginSuccess = !username.empty() && !password.empty();
    }
    bool isLoginSuccess() const {
        return loginSuccess;
    }

private:
    std::string username;
    std::string password;
    bool loginSuccess;
};
