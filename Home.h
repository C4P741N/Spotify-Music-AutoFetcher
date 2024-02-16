#pragma once

#include "Casablanca.h"
#include "UserInfoManager.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

class Home
{
public:
    Home() {
        std::cout << "Setting things up...\n";

        std::cout << "Spotify username: ";
        std::string user_name;
        getline(std::cin, user_name);

        std::cout << "Spotify password: ";
        std::string user_password = getHiddenInput();

        UserInfoManager user(user_name, user_password);

        if (user.isLoginSuccess()) {
            std::cout << "Login is a success\n";
        }
        else {
            std::cout << "Login failed\n";
        }

        Casablanca fetch;
        fetch.Connect();
    }

private:
    std::string getHiddenInput() const {
        std::string input;
        char ch;

        std::cout << std::flush;

#ifdef _WIN32
        while ((ch = _getch()) != 13) { // 13 is the Enter key
#else
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        while ((ch = getchar()) != '\n') {
#endif
            input.push_back(ch);
        }

#ifndef _WIN32
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

        std::cout << std::endl;
        return input;
        }
    };
