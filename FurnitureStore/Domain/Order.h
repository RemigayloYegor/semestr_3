#pragma once
#include <string>
#include <ctime>

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
        std::string furnitureName;   
        /** 
        // @param Итоговая цена
        */
        double totalPrice;   
        /**      
        // @param Дата заказа
        */
        std::time_t orderDate;       

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