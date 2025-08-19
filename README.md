# Blood-Bank-Management-System-in-C# Blood Bank Management System in C

## Overview
The **Blood Bank Management System** is a console-based C program designed to manage blood inventory efficiently. It allows users to add, delete, search, display, and update blood groups, as well as create customized blood group packages.

This project is ideal for learning basic file-less C programming, working with structures, arrays, and menu-driven programs.

---

## Features

1. **Add Blood Group**
   - Add a new blood type with its quantity.
   - Checks if the blood bank is full (max 10 blood groups).

2. **Delete Blood Group**
   - Delete an existing blood group from the inventory.
   - Shifts remaining blood groups to maintain array order.

3. **Search Blood Group**
   - Search for a blood group by type.
   - Displays the quantity if found.

4. **Display Blood Groups**
   - Lists all available blood groups and their quantities.

5. **Update Blood Quantity**
   - Update the quantity of an existing blood group.

6. **Create Blood Group Package**
   - Create a package consisting of multiple blood groups.
   - Deducts the quantity from the main inventory if available.
   - Notifies if requested quantity exceeds available stock.

7. **Exit**
   - Exit the program safely.

---

## Program Structure

- `struct BloodGroup`
  - Stores information about each blood group (`type` and `quantity`).
- `bloodGroups[10]`
  - Array to store up to 10 blood group records.
- `count`
  - Tracks the number of blood groups in the inventory.
- Functions:
  - `addBloodGroup()`
  - `deleteBloodGroup()`
  - `searchBloodGroup()`
  - `displayBloodGroups()`
  - `updateBloodQuantity()`
  - `createBloodGroupPackage()`
- `main()`
  - Menu-driven interface allowing users to perform different operations.

---

## How to Run

1. Make sure you have a C compiler installed (e.g., GCC).
2. Clone or download the project files.
3. Compile the program:

```bash
gcc blood_bank.c -o blood_bank
