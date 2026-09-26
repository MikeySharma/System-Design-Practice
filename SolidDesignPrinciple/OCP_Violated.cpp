#include <iostream>
#include <vector>

using namespace std;

// OCP -> Open Closed Principle
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
        this->products.push_back(product);
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

    // Get the list of products in the cart
    vector<Product *> &getProducts()
    {
        return this->products;
    }
};

class DBStorage
{
private:
    ShoppingCart *cart;

public:
    DBStorage(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    // Violating OCP: Save products to the SQL database
    void saveToSQLDB()
    {
        cout << "Saving products to SQL database..." << endl;
        for (Product *product : cart->getProducts())
        {
            cout << "Saving product: " << product->getName() << endl;
        }
        cout << "Products saved to SQL database." << endl;
    }

    // Violating OCP: Save products to the MongoDB database
    void saveToMongoDB()
    {
        cout << "Saving products to MongoDB database..." << endl;
        for (Product *product : cart->getProducts())
        {
            cout << "Saving product: " << product->getName() << endl;
        }
        cout << "Products saved to MongoDB database." << endl;
    }

    // Violating OCP: Save products to the Firebase database
    void saveToFile()
    {
        cout << "Saving products to file..." << endl;
        for (Product *product : cart->getProducts())
        {
            cout << "Saving product: " << product->getName() << endl;
        }
        cout << "Products saved to file." << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1000));
    cart->addProduct(new Product("Phone", 500));

    DBStorage *dbStorage = new DBStorage(cart);

    cout << "----------------------------------" << endl;
    dbStorage->saveToSQLDB();

    cout << "----------------------------------" << endl;
    dbStorage->saveToMongoDB();

    cout << "----------------------------------" << endl;
    dbStorage->saveToFile();

    delete cart;
    delete dbStorage;

    return 0;
}