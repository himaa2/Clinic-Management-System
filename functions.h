#ifndef FUNCTIONS_H // Header guard to prevent multiple inclusions of this file
#define FUNCTIONS_H

#include <stdbool.h> // Include for boolean type

// Define maximum number of patients and slots
#define MAX_PATIENTS 7 // Maximum number of patients allowed
#define MAX_SLOTS 5    // Maximum number of slots available

// Define default password
#define DEFAULT_PASSWORD "1234" // Default password for admin authentication

// Enum for gender
typedef enum {
    MALE,    // Male gender
    FEMALE   // Female gender
} Gender;

// Struct for Patient
typedef struct {
    int id;                 // Unique identifier for the patient
    char name[50];          // Name of the patient (up to 49 characters + null terminator)
    int age;                // Age of the patient
    Gender gender;          // Gender of the patient (MALE or FEMALE)
} Patient;

// Struct for Slot
typedef struct {
    bool reserved;          // Flag indicating if the slot is reserved (true) or available (false)
    int patientID;          // ID of the patient who reserved the slot, or -1 if not reserved
} Slot;

// Function prototypes
// Function to authenticate the admin user
bool authenticateAdmin();

// Function to handle admin mode operations
void adminMode();

// Function to handle user mode operations
void userMode();

// Function to add a new patient to the system
void addPatient();

// Function to edit details of an existing patient
void editPatient();

// Function to reserve a slot for a patient
void reserveSlot();

// Function to cancel an existing reservation
void cancelReservation();

// Function to view details of a specific patient
void viewPatient();

// Function to view all reservations for the day
void viewReservations();

#endif // FUNCTIONS_H
