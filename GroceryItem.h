/*
* GroceryItem.h
* Author: Marc Day
* Date: 4/14/2024
*/
#pragma once

#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <iomanip>
using namespace std;


class GroceryItem
{
public:
	GroceryItem(std::string& name);
	GroceryItem(std::string& name, int quantity);

	std::string getName() const;
	int getQuantity() const;

	void addItem();
	void removeItem();

	bool operator<(const GroceryItem& other) const;

private:
	string name;
	int quantity;
};