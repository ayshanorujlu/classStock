#include <iostream>
using namespace std;

//Task	1

class Product
{
private:
	int id;
	char* name;
	char* description;
	int price;
	int discount;
public:
	Product() {
		id = 0;
		SetName(nullptr);
		SetDescription(nullptr);
		price = 0;
		discount = 0;
	};
	Product(const int& id1, const int& price, const int& disc) {
		SetId(id1);
		SetName(nullptr);
		SetDescription(nullptr);
		SetPrice(price);
		SetDiscount(disc);
	};
	Product(const char* name) {
		SetName(name);
		SetId(0);
		SetDescription(nullptr);
		SetPrice(0);
		SetDiscount(0);
	}
	Product(const int& id1, const int& price, const int& disc, const char* name, const char* description) {
		SetId(id1);
		SetPrice(price);
		SetDiscount(disc);
		SetName(name);
		SetDescription(description);
	};
#pragma region Set
	void SetId(int id1) {
		if (id1 > 0) {
			this->id = id1;
		}
		else {
			cout << "Can not be\n";
		}
	}
	void SetPrice(int price) {
		if (price > 0) {
			this->price = price;
		}
		else {
			cout << "Can not be\n" << endl;
		}
	}
	void SetDiscount(int discount) {
		if (discount > 0) {
			this->discount = discount;
		}
		else {
			cout << "Can not be" << endl;
		}
	}
	void SetDescription(const char* d) {
		if (d != nullptr) {
			int l = strlen(d);
			description = new char[l + 1] {};
			strcpy_s(description, l + 1, d);
		}

	}
	void SetName(const char* n) {
		if (n != nullptr) {
			int l = strlen(n);
			name = new char[l + 1] {};
			strcpy_s(name, l + 1, n);
		}
	}
#pragma endregion Set
	void Show() {
		cout << " Product information:\n\n";
		cout << "ID : " << GetId() << endl;
		if (GetName() != nullptr) {
			cout << "Name : " << GetName() << endl;
		}
		if (GetDescription() != nullptr) {
			cout << "Description : " << GetDescription() << endl;
		}
		cout << "Price : " << GetPrice() << endl;
		cout << "Discount : " << GetDiscount() << endl << endl;
	}
#pragma region Get
	int GetId() {
		return id;
	}

	char* GetName() {
		return name;
	}

	char* GetDescription() {
		return description;
	}

	int GetPrice() {
		return price;
	}

	int GetDiscount() {
		return discount;
	}
#pragma endregion Get
	~Product() {
		delete[]name;
		delete[]description;
	}
};
class Stock
{
private:
	char* adress;
	Product* products;
	int product_count;
	void SetCount(int count) {
		if (count > 0) {
			this->product_count = count;
		}
	}
public:
	Stock(const char* adress, Product* products, int product_count) {
		SetAdress(adress);
		SetCount(product_count);
		SetProducts(products);
	}
	Product* GetProducts() {
		return products;
	}
	char* GetAdress() {
		return adress;
	}
	int GetCount() {
		return product_count;
	}
	void SetAdress(const char* adress) {
		if (adress != nullptr) {
			int l = strlen(adress);
			this->adress = new char[l + 1] {};
			strcpy_s(this->adress, l + 1, adress);
		}
	}
	void SetProducts(Product* newproducts) {
		this->products = new Product[product_count]{};
		for (size_t i = 0; i < product_count; i++)
		{
			products[i].SetId(newproducts[i].GetId());
			products[i].SetName(newproducts[i].GetName());
			products[i].SetDescription(newproducts[i].GetDescription());
			products[i].SetPrice(newproducts[i].GetPrice());
			products[i].SetDiscount(newproducts[i].GetDiscount());
		}
	}
	void Show() {
		for (size_t i = 0; i < product_count; i++)
		{
			products[i].Show();
		}
	}
	~Stock() {
		delete[]adress;
		delete[]products;
	}
};

void main() {
	Product products[3]
	{
		Product(1567, 3600, 20, "MacBook Pro", "13 inch"),
		Product(4578, 3200, 10, "ASUS TUF", "15'6 inch"),
		Product(2873, 2300, 40, "HP Pavilion", "16 inch")
	};
	Stock s("Inshaatchilar", products, 3);
	s.Show();
}





