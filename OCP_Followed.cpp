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
    virtual void save(ShoppingCart *cart) = 0;
};

class SQLDBStorage : public DBStorage
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving products to SQL database..." << endl;
        for (Product *product : cart->getProducts())
        {
            cout << "Saving product: " << product->getName() << endl;
        }
        cout << "Products saved to SQL database." << endl;
    }
};

class MongoDBStorage : public DBStorage
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving products to MongoDB..." << endl;
        for (Product *product : cart->getProducts())
        {
            cout << "Saving product: " << product->getName() << endl;
        }
        cout << "Products saved to MongoDB." << endl;
    }
};

class FileStorage : public DBStorage
{
public:
    void save(ShoppingCart *cart) override
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

    cout << "----------------------------------" << endl;
    DBStorage *sqlStorage = new SQLDBStorage();
    sqlStorage->save(cart);

    cout << "----------------------------------" << endl;
    DBStorage *mongoStorage = new MongoDBStorage();
    mongoStorage->save(cart);

    cout << "----------------------------------" << endl;
    DBStorage *fileStorage = new FileStorage();
    fileStorage->save(cart);

    delete cart;
    delete sqlStorage;
    delete mongoStorage;
    delete fileStorage;
    return 0;
}