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

    vector<Product *> getProducts()
    {
        return this->products;
    }

    // Calculate total price of products in the cart
    double calcTotalPrice()
    {
        double total = 0;
        for (Product *product : products)
        {
            total += product->getPrice();
        }

        return total;
    }
};

class PrintInvoice
{
private:
    ShoppingCart *cart;

public:
    PrintInvoice(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void printInvoice()
    {

        cout << "Printing Invoice: " << endl;
        for (Product *product : cart->getProducts())
        {
            cout << product->getName() << " : NPR " << product->getPrice() << endl;
        }
        cout << "Total Price: NPR " << cart->calcTotalPrice() << endl;
    }
};

class ShoppingCartStorage
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartStorage(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    void SaveToDB()
    {
        cout << "Saving products from cart to DB." << endl;
        for (Product *product : cart->getProducts())
        {
            cout << "Saving product : " << product->getName() << endl;
        }

        cout << "Saved products from cart to DB." << endl;
    }
};

int main()
{
    Product *laptop = new Product("Laptop", 100000);
    Product *phone = new Product("Phone", 50000);
    Product *headphone = new Product("Headphone", 10000);

    // Add products to cart
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(laptop);
    cart->addProduct(phone);
    cart->addProduct(headphone);

    // Print Invoice
    PrintInvoice *invoice = new PrintInvoice(cart);
    invoice->printInvoice();

    cout << "-----------------------------------------" << endl;

    // Save to DB
    ShoppingCartStorage *storage = new ShoppingCartStorage(cart);
    storage->SaveToDB();

    // cleanup
    delete laptop;
    delete headphone;
    delete phone;
    delete cart;
    delete invoice;
    delete storage;

    return 0;
}