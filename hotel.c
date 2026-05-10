#include <stdio.h>
#include <stdlib.h>

typedef struct room
{
    float precio;
    int numero;
    int ocupada;
} Habitacion;

enum TipoHabitacion
{
    SENCILLA,
    DOBLE,
    SUITE
};

int main() {

    int option;
    Habitacion habitaciones[20];

    int habitacion_a_reservar;
    int tipo_habitacion_reserva;

    int habitacion_a_liberar;

    // Generando 20 habitaciones aleatorias, con distintos precios, ocupaciones, tipos, etc para llenar el arreglo
    for (int i = 0; i < 20; i++)
    {
        habitaciones[i].precio = 500.0 + ((float)rand() / RAND_MAX) * 2500.0f;
        habitaciones[i].numero = rand() % 3;
        habitaciones[i].ocupada = rand() % 2;
    }

    while(option!=5) {
        printf("\n===================================");
        printf("Menu\n");
        printf("  1. Show Unnocupied Rooms\n");
        printf("  2. Book Room\n");
        printf("  3. Free a Room\n");
        printf("  4. Show all Hotel Rooms\n");
        printf("  5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        printf("\n===================================");


        // Loop
        switch(option) {
            case 1:
            for (int i = 0; i < 20; i++)
            {
                if (habitaciones[i].ocupada == 0)
                {
                    switch (habitaciones[i].numero)
                    {
                        case SENCILLA:
                        printf("\nHabitacion %d Libre!. Tipo Sencilla. Precio: $%d", i, (int) habitaciones[i].precio);
                        break;
                        case DOBLE:
                        printf("\nHabitacion %d Libre!. Tipo Doble. Precio: $%d", i, (int) habitaciones[i].precio);
                        break;
                        case SUITE:
                        printf("\nHabitacion %d Libre!. Tipo Suite Precio: $%d", i, (int) habitaciones[i].precio);
                    }
                }
            }
                break;

            case 2:
            printf("\nElije una habitacion para reservar (0-19): ");
            scanf("%d", &habitacion_a_reservar);
            while (habitaciones[habitacion_a_reservar].ocupada != 0)
            {
                printf("\nEsta habitación ya está ocupada! Por favor selecciona otra: ");
                scanf("%d", &habitacion_a_reservar);
            }
            printf("Elije que tipo de habitación quieres (0,1,2): ");
            scanf("%d", &tipo_habitacion_reserva);
            habitaciones[habitacion_a_reservar].ocupada = 1;
            habitaciones[habitacion_a_reservar].numero = tipo_habitacion_reserva;
            switch (habitaciones[habitacion_a_reservar].numero)
            {
                case SENCILLA:
                printf("\nHabitación Reservada! Tipo Sencilla. Precio: $%d", (int) habitaciones[habitacion_a_reservar].precio);
                break;
                case DOBLE:
                printf("\nHabitación Reservada! Tipo Doble. Precio: $%d", (int) habitaciones[habitacion_a_reservar].precio);
                break;
                case SUITE:
                printf("\nHabitación Reservada! Tipo Suite. Precio: $%d", (int) habitaciones[habitacion_a_reservar].precio);
                break;
            }

                break;

            case 3:
            printf("\nElije una habitación para liberar (0-19): ");
            scanf("%d", &habitacion_a_liberar);
            while (habitaciones[habitacion_a_liberar].ocupada != 1)
            {
                printf("Esta habitación ya está libre! Por favor selecciona otra: ");
                scanf("%d", &habitacion_a_liberar);
            }
            habitaciones[habitacion_a_liberar].ocupada = 0;
            printf("\nLa habitación ha sido liberada!");
                break;

            case 4:
            for (int i = 0; i < 20; i++)
            {
                switch (habitaciones[i].numero)
                {
                    case SENCILLA:
                    printf("\nHabitacion %d. Tipo Sencilla. Precio: $%d, Ocupada: %d", i, (int) habitaciones[i].precio, habitaciones[i].ocupada);
                    break;
                    case DOBLE:
                    printf("\nHabitacion %d. Tipo Doble. Precio: $%d, Ocupada: %d", i, (int) habitaciones[i].precio, habitaciones[i].ocupada);
                    break;
                    case SUITE:
                    printf("\nHabitacion %d. Tipo Suite Precio: $%d, Ocupada: %d", i, (int) habitaciones[i].precio, habitaciones[i].ocupada);
                }
            }
                break;

            case 5:
                printf("\nExiting program...\n\n");
                break;

            default:
                printf("\nInvalid Option\n\n");
                break;
        }
    }

    return 0;
}