#include <stdio.h>

int main() {

    
    int   ids[6]    = {1, 2, 3, 4, 5, 6};
    char* nombres[6]= {"Hamburguesa", "Pizza", "Perro Caliente",
                       "Pollo Broaster", "Wrap Vegetal", "Combo Familiar"};
    float precios[6]= {18500, 24900, 10000, 22000, 14500, 38000};

    /* --- Carrito --- */
    int carrito_id[20];
    int carrito_cant[20];
    int total_items = 0;

    int opcion, id, cant, i, idx;
    float subtotal, total;

    do {
        
        
        printf("1. Ver productos\n");
        printf("2. Agregar al carrito\n");
        printf("3. Ver carrito\n");
        printf("4. Confirmar pedido\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
          
            printf("\n--- Productos ---\n");
            for (i = 0; i < 6; i++) {
                printf("[%d] %s - $%.0f\n", ids[i], nombres[i], precios[i]);
            }

        } else if (opcion == 2) {
            
            printf("\nID del producto: ");
            scanf("%d", &id);

            
            idx = -1;
            for (i = 0; i < 6; i++) {
                if (ids[i] == id) {
                    idx = i;
                }
            }

            if (idx == -1) {
                printf("Producto no existe.\n");
            } else {
                printf("Cantidad: ");
                scanf("%d", &cant);

                if (cant <= 0) {
                    printf("Cantidad invalida.\n");
                } else {
                    carrito_id[total_items]   = id;
                    carrito_cant[total_items] = cant;
                    total_items++;
                    printf("Agregado: %s x%d\n", nombres[idx], cant);
                }
            }

        } else if (opcion == 3) {
            
            if (total_items == 0) {
                printf("\nCarrito vacio.\n");
            } else {
                subtotal = 0;
                printf("\n--- Carrito ---\n");
                for (i = 0; i < total_items; i++) {
                    idx = carrito_id[i] - 1;
                    printf("%s x%d = $%.0f\n",
                        nombres[idx],
                        carrito_cant[i],
                        precios[idx] * carrito_cant[i]);
                    subtotal += precios[idx] * carrito_cant[i];
                }
                total = subtotal + (subtotal * 0.19) + 5000;
                printf("Subtotal : $%.0f\n", subtotal);
                printf("IVA 19%%  : $%.0f\n", subtotal * 0.19);
                printf("Domicilio: $5000\n");
                printf("TOTAL    : $%.0f\n", total);
            }

        } else if (opcion == 4) {
            
            if (total_items == 0) {
                printf("\nCarrito vacio.\n");
            } else {
                subtotal = 0;
                for (i = 0; i < total_items; i++) {
                    idx = carrito_id[i] - 1;
                    subtotal += precios[idx] * carrito_cant[i];
                }
                total = subtotal + (subtotal * 0.19) + 5000;
                printf("\nPedido confirmado!\n");
                printf("Total a pagar: $%.0f\n", total);
                printf("Tiempo: 30-45 minutos\n");
                total_items = 0;
            }

        } else if (opcion != 5) {
            printf("Opcion invalida.\n");
        }

    } while (opcion != 5);

    printf("\nHasta luego!\n");
    return 0;
}