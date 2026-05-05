# include <stdio.h>

int main() {

    int option;

    while(option!=5) {
        printf("===================================\n");
        printf("Menu\n");
        printf("  1. Show Unnocupied Rooms\n");
        printf("  2. Book Room\n");
        printf("  3. Free a Room\n");
        printf("  4. Show all Hotel Rooms\n");
        printf("  5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        printf("===================================\n"); 
        
        
        // Loop
        switch(option) {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
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