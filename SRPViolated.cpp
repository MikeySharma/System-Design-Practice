#include <iostream>
#include <vector>
using namespace std;

// SRP -> Single Responsibility Principle
class Product
{
private:
    string name;
    double price;

public:
    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }

    double getPrice()
    {
        return this->price;
    }

    string getName()
    {
        return this->name;
    }
};

class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *product)
    {
        products.push_back(product);
    }

    // 1. Calculate total price of products in the cart
    double calcTotalPrice()
    {
        double totalPrice = 0;
        for (Product *product : products)
        {
            totalPrice += product->getPrice();
        }
        return totalPrice;
    }

    // 2. Violating SRP: Generate invoice for the products in the cart
    void generateInvoice()
    {
        cout << "Shopping Cart Invoice:" << endl;
        for (Product *product : products)
        {
            cout << "Product: " << product->getName() << " - Price: " << product->getPrice() << endl;
        }

        cout << "Total Price: " << calcTotalPrice() << endl;
    }

    // 3. Violating SRP: save to DB
    void saveToDatabase()
    {
        cout << "Saving shopping cart to database..." << endl;
        // Simulate saving to database
        cout << "Shopping cart saved to database." << endl;
    }
};

int main()
{
    Product *laptop = new Product("Laptop", 100000);
    Product *phone = new Product("Phone", 50000);
    Product *headphones = new Product("Headphones", 10000);

    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(laptop);
    cart->addProduct(phone);
    cart->addProduct(headphones);

    cart->generateInvoice();
    cart->saveToDatabase();

    // clean up memory
    delete laptop;
    delete phone;
    delete headphones;
    delete cart;
}