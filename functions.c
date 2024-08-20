#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

// Global variables
Patient patients[MAX_PATIENTS]; // Array to store patient records
int patientCount = 0; // Counter for the number of patients
Slot slots[MAX_SLOTS] = {{false, -1}, {false, -1}, {false, -1}, {false, -1}, {false, -1}}; // Array to store slot reservations
const char* slotTimes[MAX_SLOTS] = {"2pm to 2:30pm", "2:30pm to 3pm", "3pm to 3:30pm", "4pm to 4:30pm", "4:30pm to 5pm"}; // Array to store slot times

// Function to authenticate admin
bool authenticateAdmin() {
    char password[20]; // Buffer to store the entered password
    int attempts = 3; // Number of attempts allowed

    while (attempts > 0) {
        // Prompt for password
        printf("Enter password: ");
        scanf("%s", password);

        // Check password
        if (strcmp(password, DEFAULT_PASSWORD) == 0) {
            return true; // Authentication successful
        } else {
            printf("Incorrect password. Try again.\n");
            attempts--; // Decrement the number of attempts
        }
    }
    return false; // Authentication failed
}

// Function to handle admin mode
void adminMode() {
    int choice;

    while (1) { // Infinite loop for admin mode menu
        // Display admin menu
        printf("Admin Mode:\n1. Add New Patient\n2. Edit Patient\n3. Reserve Slot\n4. Cancel Reservation\n5. Logout\n");
        scanf("%d", &choice);

        // Handle admin menu selection
        switch (choice) {
            case 1:
                addPatient(); // Call function to add a new patient
                break;
            case 2:
                editPatient(); // Call function to edit patient details
                break;
            case 3:
                reserveSlot(); // Call function to reserve a slot
                break;
            case 4:
                cancelReservation(); // Call function to cancel a reservation
                break;
            case 5:
                return; // Logout from admin mode
            default:
                printf("Invalid selection. Try again.\n"); // Handle invalid selection
                break;
        }
    }
}

// Function to handle user mode
void userMode() {
    int choice;

    while (1) { // Infinite loop for user mode menu
        // Display user menu
        printf("User Mode:\n1. View Patient\n2. View Reservations\n3. Logout\n");
        scanf("%d", &choice);

        // Handle user menu selection
        switch (choice) {
            case 1:
                viewPatient(); // Call function to view patient details
                break;
            case 2:
                viewReservations(); // Call function to view reservations
                break;
            case 3:
                return; // Logout from user mode
            default:
                printf("Invalid selection. Try again.\n"); // Handle invalid selection
                break;
        }
    }
}

// Function to add a new patient
void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient limit reached. Cannot add more patients.\n");
        return;
    }

    Patient newPatient;
    // Prompt for patient details
    printf("Enter patient ID: ");
    scanf("%d", &newPatient.id);

    // Check for unique ID
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == newPatient.id) {
            printf("ID already exists.\n");
            return;
        }
    }

    printf("Enter name: ");
    scanf("%s", newPatient.name);
    printf("Enter age: ");
    scanf("%d", &newPatient.age);

    int gender;
    printf("Enter gender (0 for Male, 1 for Female): ");
    scanf("%d", &gender);
    newPatient.gender = (Gender)gender;

    // Add new patient to the array
    patients[patientCount++] = newPatient;
    printf("Patient added successfully.\n");
}

// Function to edit patient details
void editPatient() {
    int id;
    printf("Enter patient ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            // Prompt for new details
            printf("Enter new name: ");
            scanf("%s", patients[i].name);
            printf("Enter new age: ");
            scanf("%d", &patients[i].age);

            int gender;
            printf("Enter new gender (0 for Male, 1 for Female): ");
            scanf("%d", &gender);
            patients[i].gender = (Gender)gender;

            printf("Patient record updated successfully.\n");
            return;
        }
    }
    printf("Invalid patient ID.\n");
}

// Function to reserve a slot
void reserveSlot() {
    int id, slotChoice;
    printf("Available slots:\n");

    // Display available slots
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (!slots[i].reserved) {
            printf("%d. %s\n", i + 1, slotTimes[i]);
        }
    }

    // Get patient ID
    printf("Enter patient ID: ");
    scanf("%d", &id);

    // Check if patient ID exists
    bool patientExists = false;
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            patientExists = true;
            break;
        }
    }

    if (!patientExists) {
        printf("Invalid patient ID. Cannot reserve slot.\n");
        return;
    }

    // Get slot choice
    printf("Enter slot number to reserve: ");
    scanf("%d", &slotChoice);

    // Validate slot choice
    if (slotChoice < 1 || slotChoice > MAX_SLOTS || slots[slotChoice - 1].reserved) {
        printf("Invalid slot selection.\n");
        return;
    }

    // Reserve slot
    slots[slotChoice - 1].reserved = true;
    slots[slotChoice - 1].patientID = id;
    printf("Slot reserved successfully.\n");
}

// Function to cancel a reservation
void cancelReservation() {
    int id, slotChoice;

    // Get patient ID
    printf("Enter patient ID to cancel reservation: ");
    scanf("%d", &id);

    // Check if patient has any reservations
    bool reservationFound = false;
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (slots[i].reserved && slots[i].patientID == id) {
            reservationFound = true;
            break;
        }
    }

    if (!reservationFound) {
        printf("No reservation found for the given patient ID.\n");
        return;
    }

    // Get slot choice
    printf("Enter slot number to cancel: ");
    scanf("%d", &slotChoice);

    // Validate slot choice
    if (slotChoice < 1 || slotChoice > MAX_SLOTS || !slots[slotChoice - 1].reserved || slots[slotChoice - 1].patientID != id) {
        printf("Invalid slot selection or no reservation found for the given slot and patient ID.\n");
        return;
    }

    // Cancel reservation
    slots[slotChoice - 1].reserved = false;
    slots[slotChoice - 1].patientID = -1;
    printf("Reservation canceled successfully.\n");
}

// Function to view patient details
void viewPatient() {
    int id;
    printf("Enter patient ID to view: ");
    scanf("%d", &id);

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            printf("Patient ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            // Check gender and print accordingly
            if (patients[i].gender == MALE) {
                printf("Gender: Male\n");
            } else {
                printf("Gender: Female\n");
            }
            return;
        }
    }
    printf("Invalid patient ID.\n");
}

// Function to view today's reservations
void viewReservations() {
    printf("Today's Reservations:\n");

    for (int i = 0; i < MAX_SLOTS; i++) {
        if (slots[i].reserved) {
            printf("Slot %s - Patient ID: %d\n", slotTimes[i], slots[i].patientID);
        } else {
            printf("Slot %s - Available\n", slotTimes[i]);
        }
    }
}
