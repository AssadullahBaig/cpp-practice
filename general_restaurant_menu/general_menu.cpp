#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int choice, dishChoice, toppingChoice;
    bool decision;

    string italianDishes[] = {"Pasta", "Pizza", "Risotto"};
    string chineseDishes[] = {"Dumplings", "Sweet and Sour", "Kung Pao Chicken"};
    string mexicanDishes[] = {"Tacos", "Burritos", "Enchiladas"};
    string italianToppings[] = {"Tomato Sauce", "Mozzarella", "Basil"};
    string chineseToppings[] = {"Soy Sauce", "Ginger", "Garlic"};
    string mexicanToppings[] = {"Salsa", "Guacamole", "Sour Cream"};
    vector<string> orderedDishes;
    vector<vector<string>> dishToppings;  //Toppings for each dish
    
// From here the program is asking the user to select a cuisine, dish, and toppings
    cout << "Welcome to the General Restaurant Menu System!" << endl;
    do{
        cout << "Select one of the cuisines you would like to explore:" << endl;
        cout << "1. Italian" << endl;
        cout << "2. Chinese" << endl;
        cout << "3. Mexican" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        if(choice >=1 && choice <=3){
            break;
        } else {
            cout << "Invalid cuisine choice, please try again." << endl;
    
        }   
    }while(true);

    switch(choice){
        case 1:
        // Lets the user select the cuisine and dish
            cout << "You have selected Italian cuisine." << endl;
            
            for (int i = 0; i < 3; i++){
                cout << i+1 << ". " << italianDishes[i] << endl;
            }
            // dish retry loop
            do{
            cout << "select your dish: " ;
            cin >> dishChoice;
            if(dishChoice >=1 && dishChoice <=3){
                orderedDishes.push_back(italianDishes[dishChoice - 1]);
                cout << "You have selected " << italianDishes[dishChoice - 1] << endl;
                break;
            } else {
                cout << "Invalid dish choice, please try again." << endl;
            }
            }while(true);
            // Asks the user if they want to add toppings
            cout << "Would you like to add toppings? (1 for Yes, 0 for No): ";
            cin >> decision;
            // #I will add a bool that checks if a topping was chosen, this starts with a false value( meaning no topping was chosen)
            bool toppingChosen = false;
            if(!decision){
                cout << "No toppings added." << endl;
                cout << "You have Bought " << italianDishes[dishChoice - 1] << endl;
                cout << "Enjoy your meal!" << endl;
                return 0;
            }
            while(decision){
                cout << "Here are the available toppings: " << endl;
                for(int i = 0; i < 3; i++){
                    cout << i+1 << ". " << italianToppings[i] << endl;
                }
                do{
                cout << "Select your topping: ";
                cin >> toppingChoice;
                if (toppingChoice >=1 && toppingChoice <=3)
                {
                    orderedToppings.push_back(italianToppings[toppingChoice - 1]);
                    cout << "you have selected " << italianToppings[toppingChoice - 1] << endl;
                    break;
                }
                else{
                    cout << "Invalid topping choice, please try again." << endl;
                }
                }while(true);
                cout << "Would you like to add another topping? (1 for Yes, 0 for No): ";
                cin >> decision;
                if(!toppingChosen){
                    cout << "No toppings were selected by you. Enjoy your meal!" << endl;
                }
                else{
                    cout << "You have selected the following toppings: ";
                    for(const auto& topping : orderedToppings){
                        cout << topping << ", ";
                    }
                    cout << endl;
                }
            
            
            
            cout <<"You have Bought " << italianDishes[dishChoice - 1] << " with " << italianToppings[toppingChoice - 1] << endl;
            cout << "Enjoy your meal!" << endl;

            
            break;
       
        default:
            cout << "Invalid cuisine choice." << endl;
            break;
    }
 
     return 0;
}