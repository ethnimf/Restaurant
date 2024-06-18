#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "menu.h"

enum class OrderStatus {
    PAID,
    PREPARING,
    READY_FOR_PICKUP,
    COMPLETED
};

class Order {
public:
    Order(int id);

    void addItem(const MenuItem& item);
    void calculateTotal();
    void setStatus(OrderStatus status);
    OrderStatus getStatus() const;
    void displayInfo() const;

private:
    int id;
    std::vector<MenuItem> items;
    double total;
    OrderStatus status;
};

#endif 
