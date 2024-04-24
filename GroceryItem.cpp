/*
* GroceryItem.cpp
* Author: Marc Day
* Date: 4/14/2024
*/

#include "GroceryItem.h" 
/*
* GroceryItem class constructor with quantity set to 0
* @param string& name -- uses the name private member variable memory address
*/
GroceryItem::GroceryItem(std::string& name) {
	this->name = name;
	this->quantity = 0; 
}
/*
* GroceryItem class constructor
* @param string& name -- uses the name private member variable memory address
* @param int quantity -- uses the quantity member value
*/
GroceryItem::GroceryItem(std::string& name, int quantity) {
	this->name = name;
	this->quantity = quantity;
}
/*
GroceryItem getName function to get the name of the items
@return name - gets the name private member variable 
*/
std::string GroceryItem::getName() const {
	return name;
}
/*
GroceryItem getQuantity function to get the quantity of the number of items
@return quantity - gets the quantity private member variable
*/
int GroceryItem::getQuantity() const {
	return quantity;
}
/*
* Grocery addItem function to add 1 item when called
*/
void GroceryItem::addItem() {
	quantity++;
}
/*
* Grocery removeItem function to subtract 1 item when called
*/
void GroceryItem::removeItem() {
	quantity--;
}
/*
* Overloaded < operator
* @param const GroceryItem& other -- gets the memory address of the other item
* @return name.compare(other.getName()) < 0 -- comparing name with other objects with eachother
*/
bool GroceryItem::operator<(const GroceryItem& other) const {
	return name.compare(other.getName()) < 0; 
}