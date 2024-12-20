#include "Furniture.h"
#include <string>

namespace FurnitureStore
{
    Furniture::Furniture(const std::string& name, double price)
        : name{name}, price{price} {}

    const std::string& Furniture::getName() const { return name; }
    double Furniture::getPrice() const { return price; }
}