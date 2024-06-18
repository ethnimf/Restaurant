#include "authentication.h"

Authentication::Authentication() {
    users["admin"] = "admin123";       
    users["employee"] = "employee123"; 
}

bool Authentication::login(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;
    }
    return false;
}
