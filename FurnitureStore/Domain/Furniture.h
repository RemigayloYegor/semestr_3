#pragma once
#include <string> 

namespace FurnitureStore
{
    /**
     * @brief Класс для представления предмета мебели
     */
    class Furniture
    {
    private:
        /**
        @param Название мебели
        */
        std::string name;
        /**
        @param Цена мебели
        */
        double price;        
    public:
        /**
         * @brief Конструктор мебели
         * @param name Название мебели
         * @param price Цена мебели
         */
        Furniture(const std::string& name, double price);

        /**
        @return Возвращает название мебели
        */
        const std::string& getName() const;
        
        /**
        @return Возвращает цену мебели
        */
        double getPrice() const;
    };
}
