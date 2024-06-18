#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "product.h"

class MenuItem {
public:
    MenuItem();
    MenuItem(int id, const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price);

    int getId() const;
    std::string getName() const;
    std::vector<Product> getIngredients() const;
    std::string getDescription() const;
    double getPreparationTime() const;
    double getPrice() const;
    void displayInfo() const;

private:
    int id;
    std::string name;
    std::vector<Product> ingredients;
    std::string description;
    double preparationTime;
    double price;
};

class Menu {
public:
    void addItem(const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price);
    void editItem(int id, const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price);
    void removeItem(int id);
    void displayMenu() const;
    MenuItem* getItem(int id);

private:
    std::vector<MenuItem> items;
    int nextId = 1;
};

void employeeMenu(Menu& menu);

#endif 
