//  case 2:
//             cout << "You have selected Chinese cuisine." << endl;
//             cout <<"Here are the available dishes: " << endl;
//             for(int i = 0; i < 3; i++){
//                 cout << i+1 << ". " << chineseDishes[i] << endl;
//             }
//             cout << "select your dish: " ;
//             cin >> dishChoice;
//             if(dishChoice >=1 && dishChoice <=3){
//                 cout << "You have selected " << chineseDishes[dishChoice - 1] << ". Enjoy your meal!" << endl;
//             } else {
//                 cout << "Invalid dish choice." << endl;
//             }
//              cout << "Would you like to add toppings? (1 for Yes, 0 for No): ";
//             cin >> decision;
//             if(!decision){
//                 cout << "No toppings added. Enjoy your meal!" << endl;
//                 break;
//             }
//             else{
//                 cout << "Here are the available toppings: " << endl;
//                 for(int i = 0; i < 3; i++){
//                     cout << i+1 << ". " << chineseToppings[i] << endl;
//                 }
//                 cout << "Select your topping: ";
//                 cin >> toppingChoice;
//                 if (toppingChoice >=1 && toppingChoice <=3)
//                 {
//                     cout << "you have selected " << chineseToppings[toppingChoice - 1] << endl;
//                 }
//                 else{
//                     cout << "Invalid topping choice." << endl;
//                 }
                
//             }
//             cout <<"You have Bought " << chineseDishes[dishChoice - 1] << " with " << chineseToppings[toppingChoice - 1] << endl;
//             cout << "Enjoy your meal!" << endl;
//             break;
//         case 3:
//             cout << "You have selected Mexican cuisine." << endl;
//             cout <<"Here are the available dishes: " << endl;
//             cout << "select your dish: ";
//             for(int i = 0; i < 3; i++){
//                 cout << i+1 << ". " << mexicanDishes[i] << endl;
//             }
//             cin >> dishChoice;
//             if(dishChoice >=1 && dishChoice <=3){
//                 cout << "You have selected " << mexicanDishes[dishChoice - 1] << ". Enjoy your meal!" << endl;
//             } else {
//                 cout << "Invalid dish choice." << endl;
//             }
//              cout << "Would you like to add toppings? (1 for Yes, 0 for No): ";
//             cin >> decision;
//             if(!decision){
//                 cout << "No toppings added. Enjoy your meal!" << endl;
//                 break;
//             }
//             else{
//                 cout << "Here are the available toppings: " << endl;
//                 for(int i = 0; i < 3; i++){
//                     cout << i+1 << ". " << mexicanToppings[i] << endl;
//                 }
//                 cout << "Select your topping: ";
//                 cin >> toppingChoice;
//                 if (toppingChoice >=1 && toppingChoice <=3)
//                 {
//                     cout << "you have selected " << mexicanToppings[toppingChoice - 1] << endl;
//                 }
//                 else{
//                     cout << "Invalid topping choice." << endl;
//                 }
                
//             }
//             cout <<"You have Bought " << mexicanDishes[dishChoice - 1] << " with " << mexicanToppings[toppingChoice - 1] << endl;
//             cout << "Enjoy your meal!" << endl;
//             break;