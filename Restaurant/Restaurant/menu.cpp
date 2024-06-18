#include "menu.h"
#include <iostream>

MenuItem::MenuItem()
    : id(0), preparationTime(0.0), price(0.0) {}

MenuItem::MenuItem(int id, const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price)
    : id(id), name(name), ingredients(ingredients), description(description), preparationTime(preparationTime), price(price) {}

int MenuItem::getId() const {
    return id;
}

std::string MenuItem::getName() const {
    return name;
}

std::vector<Product> MenuItem::getIngredients() const {
    return ingredients;
}

std::string MenuItem::getDescription() const {
    return description;
}

double MenuItem::getPreparationTime() const {
    return preparationTime;
}

double MenuItem::getPrice() const {
    return price;
}

void MenuItem::displayInfo() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Описание: " << description << std::endl;
    std::cout << "Время пригтовления: " << preparationTime << " мин" << std::endl;
    std::cout << "Цена: $" << price << std::endl;
    std::cout << "Ингридиенты: ";
    for (const auto& ingredient : ingredients) {
        std::cout << ingredient.getName() << " ";
    }
    std::cout << std::endl;
}

void Menu::addItem(const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price) {
    MenuItem newItem(nextId++, name, ingredients, description, preparationTime, price);
    items.push_back(newItem);
}

void Menu::editItem(int id, const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price) {
    for (auto& item : items) {
        if (item.getId() == id) {
            item = MenuItem(id, name, ingredients, description, preparationTime, price);
            return;
        }
    }
    std::cerr << "ID " << id << " не найден." << std::endl;
}

void Menu::removeItem(int id) {
    auto it = std::remove_if(items.begin(), items.end(), [id](const MenuItem& item) {
        return item.getId() == id;
        });
    if (it != items.end()) {
        items.erase(it, items.end());
    }
    else {
        std::cerr << "ID " << id << " не найден." << std::endl;
    }
}

void Menu::displayMenu() const {
    for (const auto& item : items) {
        item.displayInfo();
        std::cout << "---------------------------" << std::endl;
    }
}

MenuItem* Menu::getItem(int id) {
    for (auto& item : items) {
        if (item.getId() == id) {
            return &item;
        }
    }
    return nullptr;
}

void employeeMenu(Menu& menu) {
    int choice;
    do {
        std::cout << "1. Добавить пункт меню\n";
        std::cout << "2. Редактировать пункт меню\n";
        std::cout << "3. Удалить пункт меню\n";
        std::cout << "4. Показать меню\n";
        std::cout << "5. Выход\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        std::string name, description;
        std::vector<Product> ingredients;
        double preparationTime, price;
        int id;

        switch (choice) {
        case 1:
            std::cout << "Введите название: ";
            std::cin >> name;
            std::cout << "Введите описание: ";
            std::cin >> description;
            std::cout << "Введите время приготовления: ";
            std::cin >> preparationTime;
            std::cout << "Введите цену: ";
            std::cin >> price;
            menu.addItem(name, ingredients, description, preparationTime, price);
            break;
        case 2:
            std::cout << "Введите ID пункта для редактирования: ";
            std::cin >> id;
            std::cout << "Введите новое название: ";
            std::cin >> name;
            std::cout << "Введите новое описание: ";
            std::cin >> description;
            std::cout << "Введите новое время приготовления: ";
            std::cin >> preparationTime;
            std::cout << "Введите новую цену: ";
            std::cin >> price;
            menu.editItem(id, name, ingredients, description, preparationTime, price);
            break;
        case 3:
            std::cout << "Введите ID пункта для удаления: ";
            std::cin >> id;
            menu.removeItem(id);
            break;
        case 4:
            menu.displayMenu();
            break;
        case 5:
            std::cout << "Выход из меню сотрудника." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 5);
}
