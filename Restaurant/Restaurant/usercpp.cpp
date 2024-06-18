#include "user.h"
#include <iostream>

User::User() : id(0), role(Role::GUEST), login(""), password("") {}

User::User(int id, std::string name, Role role, std::string login, std::string password)
    : id(id), name(name), role(role), login(login), password(password) {}

int User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

Role User::getRole() const {
    return role;
}

std::string User::getLogin() const {
    return login;
}

std::string User::getPassword() const {
    return password;
}

void User::displayInfo() const {
    std::cout << "ID: " << id << ", Имя: " << name << ", Роль: " << static_cast<int>(role) << std::endl;
}

Guest::Guest(int id, std::string name) : User(id, name, Role::GUEST, "", "") {}

void Guest::addOrder(const Order& order) {
    orders.push_back(order);
}

void Guest::displayOrders() const {
    for (const auto& order : orders) {
        order.displayInfo();
    }
}


Admin::Admin(int id, std::string name, std::string login, std::string password)
    : User(id, name, Role::ADMIN, login, password) {}


Employee::Employee(int id, std::string name, std::string login, std::string password)
    : User(id, name, Role::EMPLOYEE, login, password) {}
