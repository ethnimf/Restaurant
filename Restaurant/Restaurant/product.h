#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product();
    Product(int id, const std::string& name, double cost);

    int getId() const;
    std::string getName() const;
    void setName(const std::string& name);
    double getCost() const;
    void setCost(double cost);
    void displayInfo() const;

private:
    int id;
    std::string name;
    double cost;
};

#endif 
