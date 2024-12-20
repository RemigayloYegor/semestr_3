#pragma once
#include "Furniture.h"
#include "Order.h"
#include <vector>
#include <unordered_map>
#include <memory>

namespace FurnitureStore
{
    /**
     * @brief Класс магазина мебели
     * 
     * Управляет инвентарем, заказами и продажами мебельного магазина
     */
    class Store
    {
    private:
        /**
        // @param Список доступной мебели
        */
        std::vector<std::unique_ptr<Furniture>> inventory;
        /**
        // @param Список заказов
        */
        std::vector<std::unique_ptr<Order>> orders;
        /**
        // @param Статистика продаж
        */
        std::unordered_map<std::string, int> sales;
        /**
        // @param Записи о продажах
        */
        struct SaleRecord
        {
            std::string customerName;
            std::string furnitureName;
            std::chrono::system_clock::time_point saleDate;

            SaleRecord(const std::string& customer, const std::string& furniture, std::chrono::system_clock::time_point date)
                : customerName{customer}, furnitureName{furniture}, saleDate{date} {}

            std::string getDetails() const;
        };
        std::vector<SaleRecord> saleRecords;
    public:
        /**
         * @brief Добавляет новый предмет мебели в инвентарь
         * @param name Название мебели
         * @param price Цена мебели
         */
        void addFurniture(const std::string& name, double price);
        
        /**
         * @brief Отображает текущий инвентарь магазина
         */
        void displayInventory() const;
        
        /**
         * @brief Продает предмет мебели
         * @param customerName Имя клиента
         * @param furnitureName Название мебели для продажи
         */
        void sellFurniture(const std::string& customerName, const std::string& furnitureName);
        
        /**
         * @brief Отображает статистику продаж
         */
        void displaySales() const;
        
        /**
         * @brief Создает новый заказ
         * @param customerName Имя клиента
         * @param furnitureName Название мебели
         * @param customSurcharge Наценка в процентах
         */
        void createOrder(const std::string& customerName, const std::string& furnitureName, double customSurcharge);
        
        /**
         * @brief Отображает все заказы
         */
        void displayOrders() const;

        /**
         * @brief Отображает все записи о продажах
         */
        void displaySaleRecords() const;
    };
}