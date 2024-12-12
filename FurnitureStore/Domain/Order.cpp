#include "Order.h"
#include <iomanip>
#include <sstream>

namespace FurnitureStore
{
    Order::Order(const std::string& customerName, const std::string& furnitureName, double totalPrice)
        : customerName{customerName}, furnitureName{furnitureName}, totalPrice{totalPrice}
    {
        orderDate = std::time(nullptr);
    }

    std::string Order::getOrderDetails() const
    {
        char dateBuffer[100];
        #ifdef _MSC_VER 
            std::tm localTime;
            localtime_s(&localTime, &orderDate);
            std::strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d %H:%M:%S", &localTime);
        #else 
            std::strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d %H:%M:%S", std::localtime(&orderDate));
        #endif

        std::ostringstream oss;
        oss << "Клиент: " << customerName
            << ", Мебель: " << furnitureName
            << ", Итоговая цена: " << std::fixed << std::setprecision(2) << totalPrice
            << ", Дата: " << dateBuffer;

        return oss.str();
    }

}