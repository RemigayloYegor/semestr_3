#include "Store.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>

namespace FurnitureStore
{
    // Реализация метода getDetails для SaleRecord
    std::string Store::SaleRecord::getDetails() const
    {
        auto time = std::chrono::system_clock::to_time_t(saleDate);
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time));

        std::ostringstream oss;
        oss << "Клиент: " << customerName
            << ", Мебель: " << furnitureName
            << ", Дата продажи: " << buffer;

        return oss.str();
    }

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

    void Store::sellFurniture(const std::string& customerName, const std::string& furnitureName)
    {
        auto it = std::find_if(inventory.begin(), inventory.end(),
            [&furnitureName](const auto& item) { return item->getName() == furnitureName; });

        if (it != inventory.end())
        {
            auto now = std::chrono::system_clock::now();
            saleRecords.emplace_back(customerName, furnitureName, now);
            sales[furnitureName]++;
            inventory.erase(it);
            std::cout << furnitureName << " продано клиенту " << customerName << "!\n";
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
        inventory.erase(it);
        std::cout << "Заказ создан для " << customerName << " с ценой " << finalPrice << "\n";
    }

    void Store::displayOrders() const
    {
        std::cout << "Список заказов:\n";
        for (const auto& order : orders)
        {
            std::cout << order->getOrderDetails() << "\n";
        }
    }

    void Store::displaySaleRecords() const
    {
        std::cout << "Записи о продажах:\n";
        for (const auto& record : saleRecords)
        {
            std::cout << record.getDetails() << "\n";
        }
    }
}
