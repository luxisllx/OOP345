// Name: Luxi Liang
// Seneca Student ID: 165936188
// Seneca email: lliang44@myseneca.ca
// Date of completion: 03-25-2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		//cout << desc.size();
		//cout << price.size();

		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				//cout << "i="<<i << desc[i].code << "j=" <<j<< price[j].code << endl;
				if (desc[i].code == price[j].code) {
					Product* tmp = new Product(desc[i].desc, price[j].price);
					tmp->validate();
					priceList += tmp;
					delete tmp;
				}
			}
		}



		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				//cout << "i="<<i << desc[i].code << "j=" <<j<< price[j].code << endl;
				if (desc[i].code == price[j].code) {
					std::shared_ptr<Product> tmp(new Product(desc[i].desc, price[j].price));
					tmp->validate();
					priceList += tmp;
				}
			}
		}

		return priceList;
	}
}