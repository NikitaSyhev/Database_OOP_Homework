
#include <iostream>
#include "Database.h"
#include <vector>
#include<unordered_map>



int main() {
	setlocale(LC_ALL, "Russian");

	Database<std::string> d1;


	d1.addData("Vova");
	d1.addData("Petr");
	d1.addData("Ignat");
	d1.addData("Marya");
	d1.addData("John");

	d1.deleteData(5);
	d1.modifyData(4, "Barak");
	d1.showData();

	d1.searchData(3);
	
	std::cout << "Most Searched Key is " <<d1.mostSearchedKey() << std::endl;


	return 0;
}