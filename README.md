# Clinic Management System

This project is a Clinic Management System developed in C during my training at ITI Embedded Systems. It provides two modes of operation: Admin Mode and User Mode, offering various functionalities to manage patient records and doctor appointment reservations.

## Features

### Admin Mode
- **Password Protection**: The system requires a password for access. The default password is `1234`, and the system allows a maximum of 3 attempts before locking.
- **Add New Patient Record**: The system allows the admin to add a new patient by providing basic information such as name, age, gender, and a unique ID. If the ID already exists, the system will reject the entry.
- **Edit Patient Record**: Admins can update patient details by entering the patient’s ID. The system verifies the existence of the ID before allowing any edits.
- **Reserve a Slot with the Doctor**: The system offers five available time slots for appointments. Admins can reserve a slot for a patient by entering their ID. Reserved slots will no longer appear as available.
- **Cancel Reservation**: Admins can cancel a patient's reservation, which makes the time slot available again.

### User Mode
- **View Patient Record**: Users can view a patient's basic information by entering the patient’s ID.
- **View Today's Reservations**: Users can view all the reservations made for the current day, along with the corresponding patient IDs.

## Project Structure

- **Admin Mode Functions**: These functions handle tasks such as adding, editing, and managing patient records and appointments.
- **User Mode Functions**: These functions allow users to view patient records and today's reservations.

## How to Run

1. Clone this repository to your local machine.
2. Compile the C code using your preferred C compiler.
3. Run the executable and follow the prompts to navigate between Admin Mode and User Mode.

## Acknowledgments

This project was created during my training at ITI Embedded Systems. Special thanks to:
- [Mahmoud Niazy](https://www.linkedin.com/in/mahmoud-niazy-670582228)
- [Ahmed Saber Elmoharkawy](https://www.linkedin.com/in/ahmed-saber-elmoharkawy-395a60167)

for their guidance and support in completing this project.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
