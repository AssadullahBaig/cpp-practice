#include <iostream>
#include "restraunt_mech.cpp"
using namespace std;


int main() {
    Menu menu;

    menu.addItem({"Margherita Pizza", "Mains", 8.50, "Classic tomato, mozzarella, basil"});
    menu.addItem({"Cheeseburger", "Mains", 9.99, "Beef patty, cheddar, pickles"});
    menu.addItem({"Caesar Salad", "Starters", 5.75, "Romaine, croutons, parmesan"});
    menu.addItem({"Fries", "Sides", 2.99, "Crispy golden fries"});
    menu.addItem({"Brownie", "Desserts", 3.50, "Chocolate fudge brownie"});
    menu.addItem({"Cola", "Drinks", 1.99, "Chilled can"});

    cout << fixed << setprecision(2);
    menu.printAll();

    menu.updatePrice("Fries", 3.25);
    menu.updateDescription("Fries", "Crispy golden fries with sea salt");
    menu.recategorize("Caesar Salad", "Mains");

    cout << "\nAfter updates:\n";
    menu.printAll();

    vector<LineItem> order = {
        {"Margherita Pizza", 2},
        {"Fries", 1},
        {"Cola", 3},
        {"Unknown Dish", 1}
    };

    auto bill = computeBill(menu, order, 0.13, 0.05);
    printBill(order, menu, bill);

    if (auto item = menu.find("Brownie")) {
        cout << "Found dessert: ";
        Menu::printItem(*item);
    }

    return 0;
}
