#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 1000
#define MAX_EMPLOYEES 100
#define MAX_PRODUCTS 1000

typedef struct {
    int id;
    char name[100];
} Client;

typedef struct {
    int id;
    char name[100];
} Employee;

typedef struct {
    int id;
    char name[100];
    float price;
} Product;

int read_clients(Client *clients) {
    FILE *fp;
    int count = 0;

    fp = fopen("clientes.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo clientes.txt\n");
        return 0;
    }

    while (fscanf(fp, "%d %[^\n]s", &clients[count].id, clients[count].name) != EOF) {
        count++;
    }

    fclose(fp);
    return count;
}

int read_employees(Employee *employees) {
    FILE *fp;
    int count = 0;

    fp = fopen("funcionarios.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo funcionarios.txt\n");
        return 0;
    }

    while (fscanf(fp, "%d %[^\n]s", &employees[count].id, employees[count].name) != EOF) {
        count++;
    }

    fclose(fp);
    return count;
}

int read_products(Product *products) {
    FILE *fp;
    int count = 0;

    fp = fopen("produtos.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo produtos.txt\n");
        return 0;
    }

    while (fscanf(fp, "%d %[^\n]s %f", &products[count].id, products[count].name, &products[count].price) != EOF) {
        count++;
    }

    fclose(fp);
    return count;
}


//ver se funciona
int main() {
    Client clients[MAX_CLIENTS];
    Employee employees[MAX_EMPLOYEES];
    Product products[MAX_PRODUCTS];
    int num_clients, num_employees, num_products;

    num_clients = read_clients(clients);
    num_employees = read_employees(employees);
    num_products = read_products(products);

    printf("Foram lidos %d clientes:\n", num_clients);
    for (int i = 0; i < num_clients; i++) {
        printf("%d - %s\n", clients[i].id, clients[i].name);
    }

    printf("\nForam lidos %d funcionarios:\n", num_employees);
    for (int i = 0; i < num_employees; i++) {
        printf("%d - %s\n", employees[i].id, employees[i].name);
    }

    printf("\nForam lidos %d produtos:\n", num_products);
    for (int i = 0; i < num_products; i++) {
        printf("%d - %s - %.2f\n", products[i].id, products[i].name, products[i].price);
    }

    return 0;
}
