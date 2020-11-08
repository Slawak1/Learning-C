#include <stdio.h>
#include <string.h>




struct Product
{
    char* name;
    double price;
};

struct ProductStock
{
    struct Product product;
    int quantity;
};

struct Shop {
    double cash;
    struct ProductStock stock[20];

};

struct Customer
{
    char* name;
    double budget;
    struct ProductStock shoppingList[10];
};

void printProduct(struct Product p)
{
    printf("----------------\n");
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
}

void printCustomer(struct Customer c)
{
    printf("----------------\n");
    printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget);
}

int main(void)
{
    struct Customer slawek = {"Slaw",100};
    
    printCustomer(slawek);

    struct Product coke = {"Can Coke",1.10};
    printProduct(coke);
    

    struct ProductStock cokeStock = {coke, 20};
    printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name);



    return 0;
}