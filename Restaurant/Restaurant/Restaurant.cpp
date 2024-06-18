#include <iostream>
#include <fstream>
#include <vector>
#include "menu.h"
#include "product.h"
#include "user.h"
#include "order.h"
#include "utils.h"
#include "authentication.h"

void adminMenu(Menu& menu);
void guestMenu(Menu& menu, Guest& guest);

int main() {
    setlocale(LC_ALL, "Russian");

    Menu menu;
    Authentication auth;

    Product tomato(1, "Томат", 0.5);
    Product cheese(2, "Сыр", 1.0);
    Product dough(3, "Тесто", 1.5);

    menu.addItem("Пицца", { tomato, cheese, dough }, "Вкусная сырная пицца", 20, 8.99);
    menu.addItem("Салат", { tomato, cheese }, "Свежий томатный и сырный салат", 10, 4.99);

    std::cout << "Добро пожаловать в буфет МПТ" << std::endl;

    while (true) {
        std::cout << "\n1. Администратор\n2. Гость\n3. Сотрудник\n4. Выход" << std::endl;
        int choice = Utils::getIntInput("Введите ваш выбор: ");

        switch (choice) {
        case 1: {
            std::cout << "Вход для администратора" << std::endl;
            std::string login = Utils::getStringInput("Логин: ");
            std::string password = Utils::getStringInput("Пароль: ");

            if (auth.login(login, password)) {
                adminMenu(menu);
            }
            else {
                std::cout << "Неверный логин или пароль" << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "Меню для гостя" << std::endl;
            Guest guest(1, "Гость");
            guestMenu(menu, guest);
            break;
        }
        case 3: {
            std::cout << "Меню для сотрудника" << std::endl;
            std::string login = Utils::getStringInput("Логин: ");
            std::string password = Utils::getStringInput("Пароль: ");

            if (auth.login(login, password)) {
                employeeMenu(menu);
            }
            else {
                std::cout << "Неверный логин или пароль" << std::endl;
            }
            break;
        }
        case 4:
            std::cout << "Выход..." << std::endl;
            return 0;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    }
}

void adminMenu(Menu& menu) {
    while (true) {
        std::cout << "\n1. Добавить пункт меню\n2. Редактировать пункт меню\n3. Удалить пункт меню\n4. Отобразить меню\n5. Вернуться в главное меню" << std::endl;
        int choice = Utils::getIntInput("Введите ваш выбор: ");

        switch (choice) {
        case 1: {
            std::string name = Utils::getStringInput("Введите название товара: ");
            std::string description = Utils::getStringInput("Введите описание товара: ");
            double preparationTime = Utils::getIntInput("Введите время приготовления (в минутах): ");
            double price = Utils::getIntInput("Введите цену: ");

            std::vector<Product> ingredients;
            ingredients.push_back(Product(1, "Томат", 0.5));
            ingredients.push_back(Product(2, "Сыр", 1.0));

            menu.addItem(name, ingredients, description, preparationTime, price);
            break;
        }
        case 2: {
            int id = Utils::getIntInput("Введите ID товара для редактирования: ");
            std::string name = Utils::getStringInput("Введите новое название товара: ");
            std::string description = Utils::getStringInput("Введите новое описание товара: ");
            double preparationTime = Utils::getIntInput("Введите новое время приготовления (в минутах): ");
            double price = Utils::getIntInput("Введите новую цену: ");

            std::vector<Product> ingredients;
            ingredients.push_back(Product(1, "Томат", 0.5)); 

            menu.editItem(id, name, ingredients, description, preparationTime, price);
            break;
        }
        case 3: {
            int id = Utils::getIntInput("Введите ID товара для удаления: ");
            menu.removeItem(id);
            break;
        }
        case 4:
            menu.displayMenu();
            break;
        case 5:
            return;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    }
}

void guestMenu(Menu& menu, Guest& guest) {
    while (true) {
        std::cout << "\n1. Сделать заказ\n2. Просмотр заказов\n3. Вернуться в главное меню" << std::endl;
        int choice = Utils::getIntInput("Введите ваш выбор: ");

        switch (choice) {
        case 1: {
            Order order(1);
            while (true) {
                menu.displayMenu();
                int itemId = Utils::getIntInput("Введите ID товара для добавления в заказ (0 для завершения): ");
                if (itemId == 0) break;

                MenuItem* item = menu.getItem(itemId);
                if (item) {
                    order.addItem(*item);
                }
            }
            guest.addOrder(order);
            break;
        }
        case 2:
            guest.displayOrders();
            break;
        case 3:
            return;
        default:
            std::cout << "Неверный выбор" << std::endl;
        }
    }
}
