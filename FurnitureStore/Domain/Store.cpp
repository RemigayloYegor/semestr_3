#include "Store.h"
#include <iostream>
#include <algorithm>

namespace FurnitureStore
{
    void Store::addFurniture(const std::string& name, double price)
    {
        inventory.push_back(std::make_unique<Furniture>(name, price));
    }

    void Store::displayInventory() const
    {
        std::cout << "Доступная мебель:\n";
        for (const auto& item : inventory)
        {
            std::cout << "Название: " << item->getName() << ", Цена: " << item->getPrice() << "\n";
        }
    }

    void Store::sellFurniture(const std::string& name)
    {
        auto it = std::find_if(inventory.begin(), inventory.end(),
            [&name](const auto& item) { return item->getName() == name; });

        if (it != inventory.end())
        {
            sales[name]++;
            inventory.erase(it); // Удаляем только один предмет.
            std::cout << name << " продано!\n";
        }
        else
        {
            std::cout << "Мебель не найдена!\n";
        }
    }

    void Store::displaySales() const
    {
        std::cout << "Данные о продажах:\n";
        for (const auto& sale : sales)
        {
            std::cout << "Название: " << sale.first << ", Количество продаж: " << sale.second << "\n";
        }
    }

void Store::createOrder(const std::string& customerName, const std::string& furnitureName, double customSurcharge)
{
    if (customSurcharge < 0)
    {
        std::cout << "Некорректная наценка!\n";
        return;
    }

    auto it = std::find_if(inventory.begin(), inventory.end(),
        [&furnitureName](const auto& item) { return item->getName() == furnitureName; });

    if (it == inventory.end())
    {
        std::cout << "Мебель не найдена для заказа!\n";
        return;
    }

    double basePrice = (*it)->getPrice();
    double finalPrice = basePrice + (basePrice * customSurcharge / 100);

    orders.push_back(std::make_unique<Order>(customerName, furnitureName, finalPrice));
    inventory.erase(it); // Удаляем товар из инвентаря.
    std::cout << "Заказ создан для " << customerName << " с ценой " << finalPrice << "\n";
}


    void Store::displayOrders() const
    {
        std::cout << "Orders:\n";
        for (const auto& order : orders)
        {
            std::cout << order->getOrderDetails() << "\n";
        }
    }
}
