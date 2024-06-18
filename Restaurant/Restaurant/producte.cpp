#include "product.h"
#include <iostream>


Product::Product() : id(0), cost(0.0) {}

Product::Product(int id, const std::string& name, double cost)
    : id(id), name(name), cost(cost) {}

int Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

void Product::setName(const std::string& name) {
    this->name = name;
}

double Product::getCost() const {
    return cost;
}

void Product::setCost(double cost) {
    this->cost = cost;
}

void Product::displayInfo() const {
    std::cout << "ID: " << id << ", Название: " << name << ", Стоимость: $" << cost << std::endl;
}
