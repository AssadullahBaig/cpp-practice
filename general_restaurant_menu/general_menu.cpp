#include <iostream>
using namespace std;

int main() {
    int choice, dishChoice, toppingChoice;
    bool decision;

    string italianDishes[] = {"Pasta", "Pizza", "Risotto"};
    string chineseDishes[] = {"Dumplings", "Sweet and Sour Pork", "Kung Pao Chicken"};
    string mexicanDishes[] = {"Tacos", "Burritos", "Enchiladas"};
    string italianToppings[] = {"Tomato Sauce", "Mozzarella", "Basil"};
    string chineseToppings[] = {"Soy Sauce", "Ginger", "Garlic"};
    string mexicanToppings[] = {"Salsa", "Guacamole", "Sour Cream"};

    cout << "Welcome to the General Restaurant Menu System!" << endl;
    cout << "Select one of the cuisines you would like to explore:" << endl;
    cout << "1. Italian" << endl;
    cout << "2. Chinese" << endl;
    cout << "3. Mexican" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    switch(choice){
        case 1:
            cout << "You have selected Italian cuisine." << endl;
            
            for (int i = 0; i < 3; i++){
                cout << i+1 << ". " << italianDishes[i] << endl;
            }
            cout << "select your dish: " ;
            cin >> dishChoice;
            if(dishChoice >=1 && dishChoice <=3){
                cout << "You have selected " << italianDishes[dishChoice - 1] << endl;
            } else {
                cout << "Invalid dish choice." << endl;
            }
            cout << "Would you like to add toppings? (1 for Yes, 0 for No): ";
            cin >> decision;
            if(!decision){
                cout << "No toppings added. Enjoy your meal!" << endl;
                break;
            }
            else{
                cout << "Here are the available toppings: " << endl;
                for(int i = 0; i < 3; i++){
                    cout << i+1 << ". " << italianToppings[i] << endl;
                }
                cout << "Select your topping: ";
                cin >> toppingChoice;
                if (toppingChoice >=1 && toppingChoice <=3)
                {
                    cout << "you have selected " << italianToppings[toppingChoice - 1] << endl;
                }
                else{
                    cout << "Invalid topping choice." << endl;
                }
                
            }
            cout <<"You have Bought " << italianDishes[dishChoice - 1] << " with " << italianToppings[toppingChoice - 1] << endl;
            cout << "Enjoy your meal!" << endl;

            
            break;
        case 2:
            cout << "You have selected Chinese cuisine." << endl;
            cout <<"Here are the available dishes: " << endl;
            for(int i = 0; i < 3; i++){
                cout << i+1 << ". " << chineseDishes[i] << endl;
            }
            cout << "select your dish: " ;
            cin >> dishChoice;
            if(dishChoice >=1 && dishChoice <=3){
                cout << "You have selected " << chineseDishes[dishChoice - 1] << ". Enjoy your meal!" << endl;
            } else {
                cout << "Invalid dish choice." << endl;
            }
            break;
        case 3:
            cout << "You have selected Mexican cuisine." << endl;
            cout <<"Here are the available dishes: " << endl;
            cout << "select your dish: ";
            for(int i = 0; i < 3; i++){
                cout << i+1 << ". " << mexicanDishes[i] << endl;
            }
            cin >> dishChoice;
            if(dishChoice >=1 && dishChoice <=3){
                cout << "You have selected " << mexicanDishes[dishChoice - 1] << ". Enjoy your meal!" << endl;
            } else {
                cout << "Invalid dish choice." << endl;
            }
            break;
        default:
            cout << "Invalid cuisine choice." << endl;
            break;
    }
    return 0;
}