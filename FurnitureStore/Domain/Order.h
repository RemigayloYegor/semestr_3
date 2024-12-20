#pragma once
#include <string>
#include <chrono>
#include <memory>

namespace FurnitureStore
{
    /**
     * @brief Класс для хранения информации о заказе
     */
    class Order
    {
    private:
        // @param Имя клиента
        std::string customerName; 
        /**  
        // @param Название мебели
        */
        std::unique_ptr<std::string> furnitureName;   
        /** 
        // @param Итоговая цена
        */
        double totalPrice;   
        /**      
        // @param Дата заказа
        */
        std::chrono::system_clock::time_point orderDate;       

    public:
        /**
         * @brief Конструктор заказа
         * @param customerName Имя клиента
         * @param furnitureName Название мебели
         * @param totalPrice Итоговая цена
         */
        Order(const std::string& customerName, const std::string& furnitureName, double totalPrice);
        /**
        // @return Возвращает детали заказа в виде строки
        */
        std::string getOrderDetails() const;
    };
}