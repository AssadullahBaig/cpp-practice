
//   Restaurant Menu System with Pricing

//   This program allows customers to:
//   - Select from 3 cuisines (Italian, Chinese, Mexican)
//   - Choose dishes with prices
//   - Add optional toppings with prices
//   - View running order total
//   - Get final receipt with tax calculation

//   I have organized the code into modular functions for easy maintenance and expansion.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For fixed and setprecision (price formatting)
using namespace std;

// ============================================================================
// DATA STRUCTURES
// ============================================================================

// Structure to hold dish information (name and price)
struct Dish
{
    string name;  // Dish name (e.g., "Pizza")
    double price; // Dish price in dollars (e.g., 15.99)
};

// Structure to hold topping information (name and price)
struct Topping
{
    string name;  // Topping name (e.g., "Mozzarella")
    double price; // Topping price in dollars (e.g., 2.00)
};

// Structure to hold a complete order item (dish + selected toppings)
struct OrderItem
{
    string dishName;              // Name of the ordered dish
    double dishPrice;             // Price of the dish
    vector<string> toppingNames;  // List of selected topping names
    vector<double> toppingPrices; // List of selected topping prices
};

// ============================================================================
// MENU DATA - All available dishes and toppings with prices
// ============================================================================

// Italian cuisine menu
Dish italianDishes[] = {
    {"Pasta", 12.99},
    {"Pizza", 15.99},
    {"Risotto", 14.99}};

// Chinese cuisine menu
Dish chineseDishes[] = {
    {"Dumplings", 10.99},
    {"Sweet and Sour", 13.99},
    {"Kung Pao Chicken", 14.99}};

// Mexican cuisine menu
Dish mexicanDishes[] = {
    {"Tacos", 11.99},
    {"Burritos", 13.99},
    {"Enchiladas", 12.99}};

// Italian toppings menu
Topping italianToppings[] = {
    {"Tomato Sauce", 1.50},
    {"Mozzarella", 2.00},
    {"Basil", 0.75}};

// Chinese toppings menu
Topping chineseToppings[] = {
    {"Soy Sauce", 0.50},
    {"Ginger", 1.00},
    {"Garlic", 0.75}};

// Mexican toppings menu
Topping mexicanToppings[] = {
    {"Salsa", 1.00},
    {"Guacamole", 2.50},
    {"Sour Cream", 1.25}};

// ============================================================================
// GLOBAL VARIABLES
// ============================================================================

// Vector to store all order items (each item = dish + toppings)
vector<OrderItem> order;

// ============================================================================
// FUNCTION DECLARATIONS
// ============================================================================

// Display functions
void displayWelcome();                              // Shows welcome message
void displayDishes(Dish dishes[], int size);        // Shows available dishes with prices
void displayToppings(Topping toppings[], int size); // Shows available toppings with prices
void displayCurrentOrder();                         // Shows current order with running total
void displayFinalSummary();                         // Shows final receipt with tax

// Input/Selection functions
int selectCuisine();                                      // Handles cuisine selection (returns 1-3)
int selectDish(Dish dishes[], int size);                  // Handles dish selection (returns 1-3)
bool getYesNoInput(const string &prompt);                 // Reusable yes/no input validation
vector<int> selectToppings(Topping toppings[], int size); // Handles multiple topping selections

// Order management functions
void addToOrder(int cuisineChoice, int dishChoice, vector<int> selectedToppings); // Adds item to order
double calculateTotal();                                                          // Calculates and returns total price

// ============================================================================
// MAIN FUNCTION - Program entry point and main flow control
// ============================================================================

int main()
{
    // Display welcome message
    displayWelcome();

    // Variable to control the ordering loop
    bool orderMore = true;

    // Main ordering loop - continues until customer is done ordering
    while (orderMore)
    {
        // STEP 1: Select cuisine (Italian, Chinese, or Mexican)
        int cuisineChoice = selectCuisine();

        // STEP 2: Select dish based on chosen cuisine
        int dishChoice = -1;
        Dish *dishes = nullptr; // Pointer to the appropriate dish array
        int dishCount = 3;      // All cuisines have 3 dishes

        // Set the dishes pointer to the correct cuisine's menu
        switch (cuisineChoice)
        {
        case 1:
            dishes = italianDishes;
            break;
        case 2:
            dishes = chineseDishes;
            break;
        case 3:
            dishes = mexicanDishes;
            break;
        }

        // Let user select their dish
        dishChoice = selectDish(dishes, dishCount);

        // STEP 3: Select toppings (optional)
        vector<int> selectedToppings; // Will store indices of selected toppings

        // Ask if they want toppings
        bool wantToppings = getYesNoInput("Would you like to add toppings?");

        if (wantToppings)
        {
            // Set pointer to the correct toppings array based on cuisine
            Topping *toppings = nullptr;
            switch (cuisineChoice)
            {
            case 1:
                toppings = italianToppings;
                break;
            case 2:
                toppings = chineseToppings;
                break;
            case 3:
                toppings = mexicanToppings;
                break;
            }

            // Let user select multiple toppings
            selectedToppings = selectToppings(toppings, 3);
        }

        // STEP 4: Add the complete item (dish + toppings) to the order
        addToOrder(cuisineChoice, dishChoice, selectedToppings);

        // STEP 5: Display the current order so far
        displayCurrentOrder();

        // STEP 6: Ask if they want to order another dish
        orderMore = getYesNoInput("Would you like to order another dish?");
    }

    // After ordering is complete, display the final receipt
    displayFinalSummary();

    return 0;
}

// ============================================================================
// FUNCTION IMPLEMENTATIONS
// ============================================================================

//   displayWelcome()
//   Purpose: Shows a formatted welcome message when the program starts

void displayWelcome()
{
    cout << "========================================" << endl;
    cout << "  Welcome to the Restaurant Menu System!" << endl;
    cout << "========================================" << endl;
    cout << endl;
}

//  selectCuisine()
//  Purpose: Handles cuisine selection with input validation
//  Returns: Integer (1=Italian, 2=Chinese, 3=Mexican)

int selectCuisine()
{
    int choice;

    // Loop until user enters a valid choice (1-3)
    do
    {
        // Display cuisine options
        cout << "\nSelect one of the cuisines you would like to explore:" << endl;
        cout << "1. Italian Cuisine" << endl;
        cout << "2. Chinese Cuisine" << endl;
        cout << "3. Mexican Cuisine" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        // Check if choice is valid
        if (choice >= 1 && choice <= 3)
        {
            // Array for easy cuisine name lookup (index 0 is empty, 1-3 are cuisine names)
            string cuisineName[] = {"", "Italian", "Chinese", "Mexican"};
            cout << "\nYou have selected " << cuisineName[choice] << " cuisine." << endl;
            return choice;
        }
        else
        {
            // Invalid input - show error and loop again
            cout << "Invalid cuisine choice, please try again." << endl;
        }
    } while (true);
}

//   selectDish()
//   Purpose: Displays dishes and handles dish selection with validation
//   Parameters:
//     - dishes[]: Array of Dish structures for the selected cuisine
//     - size: Number of dishes in the array
//   Returns: Integer representing selected dish (1-size)

int selectDish(Dish dishes[], int size)
{
    // First, display all available dishes
    displayDishes(dishes, size);

    int dishChoice;

    // Loop until user enters a valid dish number
    do
    {
        cout << "Select your dish (1-" << size << "): ";
        cin >> dishChoice;

        // Check if choice is within valid range
        if (dishChoice >= 1 && dishChoice <= size)
        {
            // Show confirmation with dish name and price
            // Note: dishChoice-1 because array is 0-indexed but menu shows 1-indexed
            cout << "You have selected " << dishes[dishChoice - 1].name
                 << " ($" << fixed << setprecision(2) << dishes[dishChoice - 1].price << ")" << endl;
            return dishChoice;
        }
        else
        {
            // Invalid input - show error and loop again
            cout << "Invalid dish choice, please try again." << endl;
        }
    } while (true);
}

//  displayDishes()
//  Purpose: Shows all available dishes with their prices
//  Parameters:
//    - dishes[]: Array of Dish structures to display
//    - size: Number of dishes in the array

void displayDishes(Dish dishes[], int size)
{
    cout << "\nAvailable Dishes:" << endl;

    // Loop through all dishes and display them
    for (int i = 0; i < size; i++)
    {
        // Display: number. name - $price
        // fixed and setprecision(2) ensure price shows exactly 2 decimal places
        cout << i + 1 << ". " << dishes[i].name
             << " - $" << fixed << setprecision(2) << dishes[i].price << endl;
    }
}

//  displayToppings()
//  Purpose: Shows all available toppings with their prices
//  Parameters:
//    - toppings[]: Array of Topping structures to display
//    - size: Number of toppings in the array

void displayToppings(Topping toppings[], int size)
{
    cout << "\nAvailable Toppings:" << endl;

    // Loop through all toppings and display them
    for (int i = 0; i < size; i++)
    {
        // Display: number. name - $price
        cout << i + 1 << ". " << toppings[i].name
             << " - $" << fixed << setprecision(2) << toppings[i].price << endl;
    }
}

//  getYesNoInput()
//  Purpose: Reusable function to get and validate yes/no input from user
//  Parameters:
//    - prompt: The question to ask the user
//  Returns: true if user enters 1 (yes), false if user enters 0 (no)

bool getYesNoInput(const string &prompt)
{
    int decision;

    // Loop until user enters valid input (0 or 1)
    do
    {
        cout << prompt << " (1 for Yes, 0 for No): ";
        cin >> decision;

        // Check if input is valid
        if (decision == 0 || decision == 1)
        {
            // Return true if 1, false if 0
            return decision == 1;
        }
        else
        {
            // Invalid input - show error and loop again
            cout << "Invalid choice! Please enter 1 for Yes or 0 for No." << endl;
        }
    } while (true);
}

//  selectToppings()
//  Purpose: Allows user to select multiple toppings one at a time
//  Parameters:
//    - toppings[]: Array of available Topping structures
//    - size: Number of toppings available
//  Returns: Vector of integers containing the indices of selected toppings

vector<int> selectToppings(Topping toppings[], int size)
{
    vector<int> selectedToppings; // Will store the choices (1-3)
    bool addMore = true;          // Controls the topping selection loop

    // Loop to add multiple toppings
    while (addMore)
    {
        // Show available toppings each time
        displayToppings(toppings, size);

        int toppingChoice;

        // Get valid topping selection
        do
        {
            cout << "Select your topping (1-" << size << "): ";
            cin >> toppingChoice;

            // Check if choice is valid
            if (toppingChoice >= 1 && toppingChoice <= size)
            {
                // Add the choice to our selected toppings list
                selectedToppings.push_back(toppingChoice);

                // Show confirmation with topping name and price
                cout << "You have selected " << toppings[toppingChoice - 1].name
                     << " ($" << fixed << setprecision(2) << toppings[toppingChoice - 1].price << ")" << endl;
                break;
            }
            else
            {
                // Invalid input - show error and loop again
                cout << "Invalid topping choice! Please enter a number between 1-" << size << "." << endl;
            }
        } while (true);

        // Ask if they want to add another topping
        addMore = getYesNoInput("\nWould you like to add another topping?");
    }

    // Return the vector of selected topping indices
    return selectedToppings;
}

//  addToOrder()
//  Purpose: Creates an OrderItem and adds it to the global order vector
//  Parameters:
//    - cuisineChoice: Which cuisine was selected (1-3)
//    - dishChoice: Which dish was selected (1-3)
//    - selectedToppings: Vector of topping indices that were selected

void addToOrder(int cuisineChoice, int dishChoice, vector<int> selectedToppings)
{
    OrderItem item; // Create a new order item

    // Pointers to hold the correct menu arrays
    Dish *dishes = nullptr;
    Topping *toppings = nullptr;

    // Set pointers based on which cuisine was selected
    switch (cuisineChoice)
    {
    case 1: // Italian
        dishes = italianDishes;
        toppings = italianToppings;
        break;
    case 2: // Chinese
        dishes = chineseDishes;
        toppings = chineseToppings;
        break;
    case 3: // Mexican
        dishes = mexicanDishes;
        toppings = mexicanToppings;
        break;
    }

    // Store dish information in the order item
    // (dishChoice-1 because array is 0-indexed but user sees 1-indexed)
    item.dishName = dishes[dishChoice - 1].name;
    item.dishPrice = dishes[dishChoice - 1].price;

    // Add each selected topping's information to the order item
    for (int toppingIndex : selectedToppings)
    {
        // Store topping name and price
        // (toppingIndex-1 for same reason as above)
        item.toppingNames.push_back(toppings[toppingIndex - 1].name);
        item.toppingPrices.push_back(toppings[toppingIndex - 1].price);
    }

    // Add the complete item to the global order vector
    order.push_back(item);

    // Show confirmation message
    cout << "\n✓ Item added to your order!" << endl;
}

//  displayCurrentOrder()
//  Purpose: Shows all items currently in the order with prices and running subtotal

void displayCurrentOrder()
{
    cout << "\n--- Current Order ---" << endl;

    // Check if order is empty
    if (order.empty())
    {
        cout << "No items in order yet." << endl;
        return;
    }

    double subtotal = 0.0; // Running total of all items

    // Loop through each item in the order
    for (size_t i = 0; i < order.size(); i++)
    {
        // Start with the base dish price
        double itemTotal = order[i].dishPrice;

        // Display the dish name and price
        cout << i + 1 << ". " << order[i].dishName
             << " - $" << fixed << setprecision(2) << order[i].dishPrice << endl;

        // If this item has toppings, display them
        if (!order[i].toppingNames.empty())
        {
            cout << "   Toppings:" << endl;

            // Loop through each topping for this item
            for (size_t j = 0; j < order[i].toppingNames.size(); j++)
            {
                // Display topping name and price
                cout << "     + " << order[i].toppingNames[j]
                     << " - $" << fixed << setprecision(2) << order[i].toppingPrices[j] << endl;

                // Add topping price to this item's total
                itemTotal += order[i].toppingPrices[j];
            }
        }

        // Show the total for this specific item (dish + all toppings)
        cout << "   Item Total: $" << fixed << setprecision(2) << itemTotal << endl;

        // Add this item's total to the order subtotal
        subtotal += itemTotal;
    }

    // Display the current subtotal for all items
    cout << "\nCurrent Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
    cout << "---------------------" << endl;
}

//  displayFinalSummary()
//  Purpose: Shows the complete final receipt with all items, subtotal, tax, and total

void displayFinalSummary()
{
    cout << "\n========================================" << endl;
    cout << "      YOUR FINAL ORDER SUMMARY" << endl;
    cout << "========================================" << endl;

    // Check if any items were ordered
    if (order.empty())
    {
        cout << "No dishes were ordered." << endl;
        cout << "========================================" << endl;
        return;
    }

    double grandTotal = 0.0; // Total of all items before tax

    // Loop through each item and display detailed breakdown
    for (size_t i = 0; i < order.size(); i++)
    {
        // Start with base dish price
        double itemTotal = order[i].dishPrice;

        // Display item number and dish name
        cout << "\n"
             << i + 1 << ". " << order[i].dishName << endl;
        cout << "   Base Price: $" << fixed << setprecision(2) << order[i].dishPrice << endl;

        // Display toppings if any
        if (!order[i].toppingNames.empty())
        {
            cout << "   Toppings:" << endl;

            // Loop through each topping
            for (size_t j = 0; j < order[i].toppingNames.size(); j++)
            {
                // Display topping with (+$price) format
                cout << "     + " << order[i].toppingNames[j]
                     << " (+$" << fixed << setprecision(2) << order[i].toppingPrices[j] << ")" << endl;

                // Add topping price to item total
                itemTotal += order[i].toppingPrices[j];
            }
        }
        else
        {
            // No toppings were selected for this item
            cout << "   No toppings selected." << endl;
        }

        // Show total for this item
        cout << "   Item Total: $" << fixed << setprecision(2) << itemTotal << endl;

        // Add to grand total
        grandTotal += itemTotal;
    }

    // Calculate tax (8% of subtotal)
    double tax = grandTotal * 0.08;

    // Calculate final total (subtotal + tax)
    double finalTotal = grandTotal + tax;

    // Display financial summary
    cout << "\n========================================" << endl;
    cout << "Subtotal:        $" << fixed << setprecision(2) << grandTotal << endl;
    cout << "Tax (8%):        $" << fixed << setprecision(2) << tax << endl;
    cout << "----------------------------------------" << endl;
    cout << "TOTAL:           $" << fixed << setprecision(2) << finalTotal << endl;
    cout << "========================================" << endl;

    // Thank you message
    cout << "\nThank you for dining with us!" << endl;
    cout << "Enjoy your meal! " << endl;
}

//  calculateTotal()
//  Purpose: Calculates and returns the total price of all items in the order
//  Returns: Double representing the total price (before tax)
//  Note: This function is defined but not currently used. It's here for
//        future functionality like applying discounts or showing running totals.

double calculateTotal()
{
    double total = 0.0;

    // Loop through each order item
    for (const auto &item : order)
    {
        // Add dish price
        total += item.dishPrice;

        // Add all topping prices for this item
        for (double toppingPrice : item.toppingPrices)
        {
            total += toppingPrice;
        }
    }

    return total;
}