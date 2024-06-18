#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "order.h"

enum class Role {
    GUEST,
    ADMIN,
    EMPLOYEE
};

class User {
public:
    User();
    User(int id, std::string name, Role role, std::string login, std::string password);

    int getId() const;
    std::string getName() const;
    Role getRole() const;
    std::string getLogin() const;
    std::string getPassword() const;
    void displayInfo() const;

private:
    int id;
    std::string name;
    Role role;
    std::string login;
    std::string password;
};

class Guest : public User {
public:
    Guest(int id, std::string name);
    void addOrder(const Order& order);
    void displayOrders() const;

private:
    std::vector<Order> orders;
};

class Admin : public User {
public:
    Admin(int id, std::string name, std::string login, std::string password);
};

class Employee : public User {
public:
    Employee(int id, std::string name, std::string login, std::string password);
};

#endif 
