/*
* Source.cpp
* Author: Marc Day
* Date: 4/14/2024
*/
#include "GroceryItem.h"


/*
* Prints the menu for display
*/
void PrintMenu() {

    cout << "1. Search for an item" << endl;
    cout << "2. Display all frequencies" << endl;
    cout << "3. Print Histogram" << endl;
    cout << "4. Exit" << endl << endl;
}
/*
* Checks Inventory.txt file and inserts int into a GroceryItem set items
* backs up data to a Frequency.dat file
* @return items -- Returns the set of items
*/
static auto readInventory() { 
    string itemName;
    int quantity{};
    set<GroceryItem> items;

    //Open file Inventory.txt
    ifstream inventory("Inventory.txt");
    if (!inventory.is_open()) {
        throw invalid_argument("Could not read Inventory.txt");
    }

    while (!inventory.eof()) {          // Loops until end of file
        inventory >> itemName;
        GroceryItem* item = new GroceryItem(itemName);      
        auto existingItem = items.find(*item);
        if (existingItem != items.end()) {
            existingItem->getName() = itemName;
            int quantity = existingItem->getQuantity(); 
            items.erase(existingItem);          // erases existing item pointer
            item = new GroceryItem(itemName, quantity);         
        }

        item->addItem();
        items.insert(*item);
    }
    //Close file Inventory.txt 
    inventory.close();

    //Open Frequency.dat
    ofstream Frequency("Frequency.dat");
    if (!Frequency.is_open()) {
        throw invalid_argument("Could not write to frequency.dat");
    }

    for (GroceryItem item : items) {
        Frequency << item.getName() << " " << item.getQuantity() << endl;
    }
    //Close file Frequency.dat
    Frequency.close();

    return items; 
}

/*
* Main program Function
* @return 0 - ends program when loop is exited.
*/
int main() {

    int const SELECT = 1;
    int const ITEMFREQUENCY = 2;
    int const HISTOGRAM = 3;
    int const EXIT = 4;
    int menuSelection{};

    string input; 
    string name{};
    int quantity{};
    set<GroceryItem> items;
    
  
    cin.exceptions(ios_base::failbit); 
     
    do {
        
        do {
            
            PrintMenu();
            try {
                
                cout << "Enter Menu Selection: " << endl;
                cin >> menuSelection;
                }
            catch (ios_base::failure) {
                cout << "Invalid Input, try again" << endl;          // Catches and displays an error if non-integer value 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }
        } while (menuSelection < 1 || menuSelection > 4);           // Input validation for menuSelection between for integers 1-4

            switch (menuSelection) {

            case SELECT:                    // Allows user to search for an item and displays item name and quantity
                readInventory();            // runs the readInventory method for every input, to refresh the data in the set, and the Frequency.dat file 
                cout << "Enter Item Name: " << endl;
                cin >> input;
               
                for (GroceryItem item : readInventory()) {

                    if (item.getName() == input) {
                        name = item.getName();
                        quantity = item.getQuantity();
                    }
                }
                if (input == name) {
                    cout << "Item Name: " << name << " Amount: " << quantity << endl;
                }
                else {
                    cout << "item not in inventory!" << endl;
                    continue;
                }
                
        
                    break;

            case ITEMFREQUENCY:             // Reads file and outputs frequency of all items
                readInventory();

                for (GroceryItem item : readInventory()) {
                    cout << "Item Name: " << item.getName() << " Amount: " << item.getQuantity() << endl;
                }
                break;

            case HISTOGRAM:             // Reads file and outputs histogram of all items
                readInventory();
                for (GroceryItem item : readInventory()) {
                    cout << "Item Name: " << item.getName() << "\t" << " Amount: ";
                    for (int i = 0; i < item.getQuantity(); i++)
                        cout << " *";
                    cout << endl;
                }
                break;

            case EXIT:
                cout << "Goodbye and Thanks for using the program!" << endl;
                break;
            }
        

        } while (menuSelection != 4);

    return 0;
} 