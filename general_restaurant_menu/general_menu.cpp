#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int choice, dishChoice, toppingChoice;
    bool decision;
    // Menus
    string italianDishes[] = {"Pasta", "Pizza", "Risotto"};
    string chineseDishes[] = {"Dumplings", "Sweet and Sour", "Kung Pao Chicken"};
    string mexicanDishes[] = {"Tacos", "Burritos", "Enchiladas"};
    string italianToppings[] = {"Tomato Sauce", "Mozzarella", "Basil"};
    string chineseToppings[] = {"Soy Sauce", "Ginger", "Garlic"};
    string mexicanToppings[] = {"Salsa", "Guacamole", "Sour Cream"};

    // Stores the Final order
    vector<string> orderedDishes;
    vector<vector<string>> dishToppings; // All Toppings for each dish
    // Using this to store the current toping for each cuisine
    vector<string> currentToppings;

    // From here the program is asking the user to select a cuisine, dish, and toppings
    cout << "Welcome to the General Restaurant Menu System!" << endl;
    bool orderMore = true;
    // cuisine retry loop
    while (orderMore)
    {
        // Resets for each dish
        currentToppings.clear();
        // Keep choosing cuisines and dishes
        do
        {
            cout << "Select one of the cuisines you would like to explore:" << endl;
            cout << "1. Italian" << endl;
            cout << "2. Chinese" << endl;
            cout << "3. Mexican" << endl;
            cout << "Enter your choice (1-3): ";
            cin >> choice;
            if (choice >= 1 && choice <= 3)
            {
                break;
            }
            else
            {
                // This will only run if the IF condition fails
                cout << "Invalid cuisine choice, please try again." << endl;
            }
        } while (true);

        switch (choice)
        {

        case 1:
        {

            // Lets the user select the cuisine and dish
            cout << "You have selected Italian cuisine." << endl;

            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << ". " << italianDishes[i] << endl;
            }
            // dish retry loop
            do
            {
                cout << "select your dish (1-3): ";
                cin >> dishChoice;
                if (dishChoice >= 1 && dishChoice <= 3)
                {
                    orderedDishes.push_back(italianDishes[dishChoice - 1]);
                    cout << "You have selected " << italianDishes[dishChoice - 1] << endl;
                    break;
                }
                else
                {
                    cout << "Invalid dish choice, please try again." << endl;
                }
            } while (true);
            // Asks the user if they want to add toppings
            cout << "Would you like to add toppings? (1 for Yes, 0 for No): ";
            cin >> decision;

            while (decision)
            {
                cout << "Here are the available toppings: " << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << i + 1 << ". " << italianToppings[i] << endl;
                }
                // Loop to retry toppings
                do
                {
                    cout << "Select your topping: ";
                    cin >> toppingChoice;
                    if (toppingChoice >= 1 && toppingChoice <= 3)
                    {
                        currentToppings.push_back(italianToppings[toppingChoice - 1]);
                        cout << "you have selected " << italianToppings[toppingChoice - 1] << endl;
                        break;
                    }
                    else
                    {
                        cout << "Invalid topping choice, please try again." << endl;
                    }

                } while (true);
                // Asks the user if they want to add another topping
                cout << "Would you like to add another topping? (1 for Yes, 0 for No): ";
                cin >> decision;
                // This will now show the topping summary
            }
        }
        case 2:
        {

            // Lets the user select the cuisine and dish
            cout << "You have selected Italian cuisine." << endl;

            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << ". " << chineseDishes[i] << endl;
            }
            // dish retry loop
            do
            {
                cout << "select your dish (1-3): ";
                cin >> dishChoice;
                if (dishChoice >= 1 && dishChoice <= 3)
                {
                    orderedDishes.push_back(chineseDishes[dishChoice - 1]);
                    cout << "You have selected " << chineseDishes[dishChoice - 1] << endl;
                    break;
                }
                else
                {
                    cout << "Invalid dish choice, please try again." << endl;
                }
            } while (true);
            // Asks the user if they want to add toppings
            cout << "Would you like to add toppings? (1 for Yes, 0 for No): ";
            cin >> decision;

            while (decision)
            {
                cout << "Here are the available toppings: " << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << i + 1 << ". " << chineseToppings[i] << endl;
                }
                // Loop to retry toppings
                do
                {
                    cout << "Select your topping: ";
                    cin >> toppingChoice;
                    if (toppingChoice >= 1 && toppingChoice <= 3)
                    {
                        currentToppings.push_back(chineseToppings[toppingChoice - 1]);
                        cout << "you have selected " << chineseDishes[toppingChoice - 1] << endl;
                        break;
                    }
                    else
                    {
                        cout << "Invalid topping choice, please try again." << endl;
                    }

                } while (true);
                // Asks the user if they want to add another topping
                cout << "Would you like to add another topping? (1 for Yes, 0 for No): ";
                cin >> decision;
                // This will now show the topping summary
            }
        }
        case 3:
        {

            // Lets the user select the cuisine and dish
            cout << "You have selected Italian cuisine." << endl;

            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << ". " << mexicanDishes[i] << endl;
            }
            // dish retry loop
            do
            {
                cout << "select your dish (1-3): ";
                cin >> dishChoice;
                if (dishChoice >= 1 && dishChoice <= 3)
                {
                    orderedDishes.push_back(mexicanDishes[dishChoice - 1]);
                    cout << "You have selected " << mexicanDishes[dishChoice - 1] << endl;
                    break;
                }
                else
                {
                    cout << "Invalid dish choice, please try again." << endl;
                }
            } while (true);
            // Asks the user if they want to add toppings
            cout << "Would you like to add toppings? (1 for Yes, 0 for No): ";
            cin >> decision;

            while (decision)
            {
                cout << "Here are the available toppings: " << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << i + 1 << ". " << mexicanToppings[i] << endl;
                }
                // Loop to retry toppings
                do
                {
                    cout << "Select your topping: ";
                    cin >> toppingChoice;
                    if (toppingChoice >= 1 && toppingChoice <= 3)
                    {
                        currentToppings.push_back(mexicanToppings[toppingChoice - 1]);
                        cout << "you have selected " << mexicanToppings[toppingChoice - 1] << endl;
                        break;
                    }
                    else
                    {
                        cout << "Invalid topping choice, please try again." << endl;
                    }

                } while (true);
                // Asks the user if they want to add another topping
                cout << "Would you like to add another topping? (1 for Yes, 0 for No): ";
                cin >> decision;
            }
        }
            dishToppings.push_back(currentToppings);

            if (currentToppings.empty())
            {
                cout << "No toppings were selected for this dish." << endl;
            }
            else
            {
                cout << "Toppings selected for this dish: ";
                for (size_t i = 0; i < currentToppings.size(); ++i)
                {
                    cout << currentToppings[i];
                    if (i + 1 < currentToppings.size())
                        cout << ", ";
                }
                cout << endl;
            }
            // Ask if they want to order another dish
            cout << "Would you like to order another dish? (1 for Yes, 0 for No): ";
            cin >> orderMore;
        }

        // Now i will show the final summary of the order
        cout << "Your final order summary:" << endl;
        if (orderedDishes.empty())
        {
            cout << "No dishes were ordered." << endl;
        }
        else
        {
            for (size_t i = 0; i < orderedDishes.size(); ++i)
            {
                cout << i + 1 << ". Dish: " << orderedDishes[i] << endl;
                if (i < dishToppings.size() && !dishToppings[i].empty())
                {
                    cout << "   Toppings: ";
                    for (size_t j = 0; j < dishToppings[i].size(); ++j)
                    {
                        cout << dishToppings[i][j];
                        if (j + 1 < dishToppings[i].size())
                            cout << ", ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "   No toppings selected." << endl;
                }
            }
        }
        cout << "Thank you for using the General Restaurant Menu System. Enjoy your meal!" << endl;
        return 0;
    }
}