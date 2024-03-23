#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un cliente
typedef struct {
    int numeroCuenta;
    int tipoCuenta; // 1 para preferencial, 2 para tradicional
} Cliente;

// Estructura para representar un nodo de la fila
typedef struct Nodo {
    Cliente cliente;
    struct Nodo* siguiente;
} Nodo;

// Estructura para representar una fila de clientes
typedef struct {
    Nodo* frente;
    Nodo* final;
} Cola;

// Inicializar una fila vacía
void inicializarCola(Cola* cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

// Verificar si la fila está vacía
int colaVacia(Cola* cola) {
    return (cola->frente == NULL);
}

// Añadir un cliente a la fila
void encolar(Cola* cola, Cliente cliente) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error de asignacion de memoria\n");
        exit(1);
    }
    nuevoNodo->cliente = cliente;
    nuevoNodo->siguiente = NULL;

    if (colaVacia(cola)) {
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
}

// Remover y obtener el primer cliente de la fila
Cliente desencolar(Cola* cola) {
    if (colaVacia(cola)) {
        printf("Cola vacia\n");
        exit(1);
    }

    Nodo* temp = cola->frente;
    Cliente cliente = temp->cliente;

    cola->frente = temp->siguiente;
    free(temp);

    if (cola->frente == NULL) {
        cola->final = NULL; // La fila está vacía
    }

    return cliente;
}

// Visualizar los clientes presentes en la fila
void mostrarCola(Cola* cola) {
    if (colaVacia(cola)) {
        printf("La cola esta vacia\n");
        return;
    }

    printf("Clientes en la cola:\n");
    
    Nodo* actual = cola->frente;
    
    while (actual != NULL) {
        printf("Numero de Cuenta: %d, Tipo de Cuenta: %s\n", actual->cliente.numeroCuenta, 
               (actual->cliente.tipoCuenta == 1) ? "Preferencial" : "Tradicional");
        actual = actual->siguiente;
    }
}

int main() {
    Cola colaPreferencial, colaTradicional;
    Cliente cliente1, cliente2;

    inicializarCola(&colaPreferencial);
    inicializarCola(&colaTradicional);

    int eleccion;
    do {
        printf("\nSistema de Gestion de Colas Bancarias\n");
        printf("1. Agregar cliente preferencial\n");
        printf("2. Agregar cliente tradicional\n");
        printf("3. Mostrar cola preferencial\n");
        printf("4. Mostrar cola tradicional\n");
        printf("5. Salir\n");
        printf("Ingrese su eleccion: ");
        scanf("%d", &eleccion);

        switch (eleccion) {
            case 1:
                printf("Ingrese el numero de cuenta del cliente preferencial: ");
                scanf("%d", &cliente1.numeroCuenta);
                cliente1.tipoCuenta = 1;
                encolar(&colaPreferencial, cliente1);
                printf("Cliente preferencial agregado a la cola\n");
                break;
            case 2:
                printf("Ingrese el numero de cuenta del cliente tradicional: ");
                scanf("%d", &cliente2.numeroCuenta);
                cliente2.tipoCuenta = 2;
                encolar(&colaTradicional, cliente2);
                printf("Cliente tradicional agregado a la cola\n");
                break;
            case 3:
                printf("Cola Preferencial:\n");
                mostrarCola(&colaPreferencial);
                break;
            case 4:
                printf("Cola Tradicional:\n");
                mostrarCola(&colaTradicional);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while (eleccion != 5);

    return 0;
}


