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

// Llena el arreglo con 20 habitaciones de datos aleatorios
void inicializarHabitaciones(Habitacion habitaciones[])
{
    for (int i = 0; i < 20; i++)
    {
        habitaciones[i].precio  = 500.0 + ((float)rand() / RAND_MAX) * 2500.0f;
        habitaciones[i].numero  = rand() % 3;
        habitaciones[i].ocupada = rand() % 2;
    }
}

// Muestra solo las habitaciones que no están ocupadas
void mostrarHabitacionesLibres(Habitacion habitaciones[])
{
    for (int i = 0; i < 20; i++)
    {
        if (habitaciones[i].ocupada == 0)
        {
            switch (habitaciones[i].numero)
            {
                case SENCILLA:
                    printf("\nHabitacion %d Libre!. Tipo Sencilla. Precio: $%d", i, (int)habitaciones[i].precio);
                    break;
                case DOBLE:
                    printf("\nHabitacion %d Libre!. Tipo Doble. Precio: $%d", i, (int)habitaciones[i].precio);
                    break;
                case SUITE:
                    printf("\nHabitacion %d Libre!. Tipo Suite. Precio: $%d", i, (int)habitaciones[i].precio);
                    break;
            }
        }
    }
}

// Pide al usuario una habitación libre y la marca como ocupada
void reservarHabitacion(Habitacion habitaciones[])
{
    int habitacion_a_reservar;
    int tipo_habitacion_reserva;

    printf("\nElije una habitacion para reservar (0-19): ");
    scanf("%d", &habitacion_a_reservar);

    // Repite hasta que el usuario elija una habitación desocupada
    while (habitaciones[habitacion_a_reservar].ocupada != 0)
    {
        printf("\nEsta habitacion ya esta ocupada! Por favor selecciona otra: ");
        scanf("%d", &habitacion_a_reservar);
    }

    printf("Elije que tipo de habitacion quieres (0=Sencilla, 1=Doble, 2=Suite): ");
    scanf("%d", &tipo_habitacion_reserva);

    habitaciones[habitacion_a_reservar].ocupada = 1;
    habitaciones[habitacion_a_reservar].numero  = tipo_habitacion_reserva;

    switch (habitaciones[habitacion_a_reservar].numero)
    {
        case SENCILLA:
            printf("\nHabitacion Reservada! Tipo Sencilla. Precio: $%d", (int)habitaciones[habitacion_a_reservar].precio);
            break;
        case DOBLE:
            printf("\nHabitacion Reservada! Tipo Doble. Precio: $%d", (int)habitaciones[habitacion_a_reservar].precio);
            break;
        case SUITE:
            printf("\nHabitacion Reservada! Tipo Suite. Precio: $%d", (int)habitaciones[habitacion_a_reservar].precio);
            break;
    }
}

// Pide al usuario una habitación ocupada y la marca como libre
void liberarHabitacion(Habitacion habitaciones[])
{
    int habitacion_a_liberar;

    printf("\nElije una habitacion para liberar (0-19): ");
    scanf("%d", &habitacion_a_liberar);

    // Repite hasta que el usuario elija una habitación que sí esté ocupada
    while (habitaciones[habitacion_a_liberar].ocupada != 1)
    {
        printf("Esta habitacion ya esta libre! Por favor selecciona otra: ");
        scanf("%d", &habitacion_a_liberar);
    }

    habitaciones[habitacion_a_liberar].ocupada = 0;
    printf("\nLa habitacion ha sido liberada!");
}

// Muestra todas las habitaciones con su tipo, precio y estado
void mostrarTodasHabitaciones(Habitacion habitaciones[])
{
    for (int i = 0; i < 20; i++)
    {
        switch (habitaciones[i].numero)
        {
            case SENCILLA:
                printf("\nHabitacion %d. Tipo Sencilla. Precio: $%d, Ocupada: %d", i, (int)habitaciones[i].precio, habitaciones[i].ocupada);
                break;
            case DOBLE:
                printf("\nHabitacion %d. Tipo Doble. Precio: $%d, Ocupada: %d", i, (int)habitaciones[i].precio, habitaciones[i].ocupada);
                break;
            case SUITE:
                printf("\nHabitacion %d. Tipo Suite. Precio: $%d, Ocupada: %d", i, (int)habitaciones[i].precio, habitaciones[i].ocupada);
                break;
        }
    }
}

void limpiarPantalla(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
}

int main()
{
    int option = 0;
    Habitacion habitaciones[20];

    inicializarHabitaciones(habitaciones);

    while (option != 5)
    {
        printf("\n===================================\n");
        printf("Menu\n");
        printf("  1. Show Unnocupied Rooms\n");
        printf("  2. Book Room\n");
        printf("  3. Free a Room\n");
        printf("  4. Show all Hotel Rooms\n");
        printf("  5. Exit\n");
        printf("  6. Clean Screen\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        printf("\n===================================\n");

        switch (option)
        {
            case 1: mostrarHabitacionesLibres(habitaciones);
                break;
            case 2: reservarHabitacion(habitaciones);
                break;
            case 3: liberarHabitacion(habitaciones);
                break;
            case 4: mostrarTodasHabitaciones(habitaciones);
                break;
            case 5: printf("\nExiting program...\n\n");
                break;
            case 6: limpiarPantalla();
                break;
            default: printf("\nInvalid Option\n\n");
                break;
        }
    }

    return 0;
}
