#include "order.h"
#include <iostream>

Order::Order(int id) : id(id), total(0.0), status(OrderStatus::PAID) {}

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
    calculateTotal();
}

void Order::calculateTotal() {
    total = 0.0;
    for (const auto& item : items) {
        total += item.getPrice();
    }
}

void Order::setStatus(OrderStatus status) {
    this->status = status;
}

OrderStatus Order::getStatus() const {
    return status;
}

void Order::displayInfo() const {
    std::cout << "ID заказа: " << id << ", Статус: " << static_cast<int>(status) << ", ИТОГО: $" << total << std::endl;
    for (const auto& item : items) {
        item.displayInfo();
    }
}
