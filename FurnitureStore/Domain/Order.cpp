#include "Order.h"
#include <iomanip>
#include <sstream>

namespace FurnitureStore
{
    Order::Order(const std::string& customerName, const std::string& furnitureName, double totalPrice)
        : customerName{customerName}, furnitureName{std::make_unique<std::string>(furnitureName)}, totalPrice{totalPrice}
    {
        orderDate = std::chrono::system_clock::now();
    }

    std::string Order::getOrderDetails() const
    {
        auto time = std::chrono::system_clock::to_time_t(orderDate);
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time));

        std::ostringstream oss;
        oss << "Клиент: " << customerName
            << ", Мебель: " << *furnitureName
            << ", Итоговая цена: " << std::fixed << std::setprecision(2) << totalPrice
            << ", Дата: " << buffer;

        return oss.str();
    }
}