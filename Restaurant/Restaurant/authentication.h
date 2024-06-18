#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include <unordered_map>

class Authentication {
public:
    Authentication();
    bool login(const std::string& username, const std::string& password);

private:
    std::unordered_map<std::string, std::string> users;
};

#endif 
