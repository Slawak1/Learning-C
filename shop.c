#include <stdio.h>
#include <string.h>
#include <stdlib.h>




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
    int index;

};

struct Customer
{
    char* name;
    double budget;
    struct ProductStock shoppingList[10];
    int index;
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

    for (int i =0; i<c.index; i++ )
    {
        printProduct(c.shoppingList[i].product);
        printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shoppingList[i].quantity);

        double cost = c.shoppingList[i].quantity * c.shoppingList[i].product.price;
        printf("The cost to %s will be %.2f\n", c.name, cost);
    }
}

struct Shop createAndStockShop()
{
    struct Shop shop = {200};
    
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    size_t read;

    fp = fopen("stock.csv","r");
    if(fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line,&len,fp))!= -1)
    {
       // printf("%s IS A LINE", line);
       char* n = strtok(line, ",");
       char* p = strtok(NULL, ",");
       char* q = strtok(NULL, ",");

        // convert to Interger

        int quantity = atoi(q);
        double price = atof(p);
        char *name = malloc(sizeof(char) * 50);
        strcpy(name,n);
        struct Product product = {name, price};
        struct ProductStock stockItem = {product, quantity};

        shop.stock[shop.index++] = stockItem;

       // printf("NAME OF PRODUCT: %s, PRICE: %.2f, QUANTITY: %d\n", name,price,quantity);
    }
    return shop;
}

void printShop(struct Shop s)
{
    printf("SHOP HAS %.2f IN CASH\n",s.cash);
    for (int i = 0; i<s.index; i++)
    {
        printProduct(s.stock[i].product);
        printf("THE SHOP HAS %d OF THE ABOVE\n", s.stock[i].quantity);
    }
}

int main(void)
{
    struct Shop shop = createAndStockShop();
    printShop(shop);

    return 0;
}