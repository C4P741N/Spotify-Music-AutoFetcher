#pragma once

#include "Casablanca.h"
#include <string>
#include <iostream>

class UserInfoManager
{
public:
    UserInfoManager(const std::string& username, const std::string& password)
        : _Username(username)
        , _Password(password)
        , _IsLoginSuccess(fetch.Connect(_Username, _Password)) {}

    bool isLoginSuccess() const {
        return _IsLoginSuccess;
    }

private:
    std::string _Username;
    std::string _Password;
    bool _IsLoginSuccess;
    mutable Casablanca fetch;
};
