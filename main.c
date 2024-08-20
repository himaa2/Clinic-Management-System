#include <stdio.h>
#include "functions.h"

// Entry point of the program
int main() {
    int mode;  // Variable to store user's mode selection

    while (1) {  // Infinite loop to keep the program running until the user chooses to exit
        // Display mode selection menu
        printf("Select Mode:\n1. Admin Mode\n2. User Mode\n3. Exit\n");
        scanf("%d", &mode);  // Read the user's selection

        // Handle mode selection
        switch (mode) {
            case 1:
                // If Admin Mode is selected
                if (authenticateAdmin()) {  // Authenticate the admin
                    adminMode();  // Enter Admin Mode if authentication is successful
                } else {
                    // If authentication fails, display a message
                    printf("You are not the admin, go out!!\n");
                }
                break;
            case 2:
                // If User Mode is selected
                userMode();  // Enter User Mode
                break;
            case 3:
                // If Exit is selected
                printf("WELCOME ANY TIME HOPE YOU GET BETTER (*_*)\n");
                return 0;  // Exit the program
            default:
                // If an invalid selection is made
                printf("Invalid selection. Try again.\n");
                break;
        }
    }

    return 0;  // This line is not actually reachable, but is good practice to include
}
