#include "Store.h"
#include <iostream>

int main()
{
    
    FurnitureStore::Store store;
    store.addFurniture("Стул", 50.0);
    store.addFurniture("Стол", 150.0);
    store.addFurniture("Диван", 300.0);

    std::cout << "=== Инвентарь ===\n";
    store.displayInventory();

    std::cout << "\n=== Продажа мебели ===\n";
    store.sellFurniture("Клиент1", "Стул");
    store.sellFurniture("Клиент1", "Диван");

    std::cout << "\n=== Статистика продаж ===\n";
    store.displaySales();

    std::cout << "\n=== Создание заказов ===\n";
    store.createOrder("Алиса", "Стол", 20.0);
    store.createOrder("Борис", "Стул", 15.0);

    std::cout << "\n=== Список заказов ===\n";
    store.displayOrders();

    return 0;
}
