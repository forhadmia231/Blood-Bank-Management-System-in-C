////////////////////////////////////////////////Blood Bank Management System in C

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct BloodGroup
{
char type[10];
int quantity;
};

struct BloodGroup bloodGroups[10];
int count = 0;
int choice;
char bloodType[10];
int quantity;

/*-	struct BloodGroup: A structure to store information about a blood group.
-	bloodGroups[10]: An array to hold up to 10 blood group records.
-	count: Tracks the number of blood groups currently stored.
-	choice, bloodType, quantity: Temporary variables used for user input and operations.

*/
// Add Blood Group

void addBloodGroup()
{
printf("\nEnter Blood Type: ");
scanf("%s", bloodType);
printf("Enter Quantity: ");
scanf("%d", &quantity);

if(count < 10)
{
strcpy(bloodGroups[count].type, bloodType); 
bloodGroups[count].quantity = quantity; count++;
printf("\nBlood group added successfully!\n");
}
else
printf("\nBlood bank is full. Cannot add more blood groups.\n");
}
/* 
Prompt for Number of Blood Groups: The function first asks the user how many blood groups they want to add.
Loop for Each Blood Group: A loop runs for the number of blood groups specified. For each iteration, the function:
●	Prompts the user to enter the blood type and quantity.
●	Checks if the blood type already exists in the inventory.
●	If it exists, the quantity is updated.
●	If it does not exist, a new entry is created, provided there is space in the inventory.

Add or Update Blood Group: The function either updates the quantity of an existing blood group or adds a new blood group if there is space.
*/
//Delete Blood Group

void deleteBloodGroup()
{
printf("Enter blood type to delete: ");
scanf("%s", bloodType);

for(int i=0; i<count; i++)
{
if(strcmp(bloodGroups[i].type, bloodType) == 0)
{
for(int j=i; j<count-1; j++)
{
strcpy(bloodGroups[j].type, bloodGroups[j+1].type); bloodGroups[j].quantity = bloodGroups[j+1].quantity;
}
count--;
printf("\nBlood group %s deleted successfully!\n", bloodType);
return;
}
}
printf("\nBlood group not found.\n");
}

/*Prompt for Blood Type to Delete: The function asks the user to enter the blood type they wish to delete.
Search for the Blood Type: The function iterates through the bloodGroups array to find the specified blood type.
Delete the Blood Group: If the blood type is found, the function shifts all subsequent elements in the array one position to the left to fill the gap left by the deleted blood group. The count of blood groups is then decremented.
Handle Blood Group Not Found: If the specified blood type is not found, the function notifies the user that the blood group was not found.
 */
//Search BloodGroup

void searchBloodGroup()
{
printf("Enter blood type to search: ");
scanf("%s", bloodType);
for(int i=0; i<count; i++)
{
if(strcmp(bloodGroups[i].type, bloodType) == 0)
{
printf("\nBlood group %s found. Quantity: %d\n", bloodType, bloodGroups[i].quantity);
return;
}
}
printf("\nBlood group not found.\n");
}
/*Prompt for Blood Type to Search: The function asks the user to enter the blood type they wish to search for.
Search for the Blood Type: The function iterates through the bloodGroups array to find the specified blood type.
Display Result: If the blood type is found, the function displays the blood type and its quantity. If the blood type is not found, the function notifies the user that the blood group was not found.


*/
// Display Blood Groups

void displayBloodGroups()
{
printf("Blood Groups:\n");
for (int i = 0; i < count; i++)
{
printf("\t %s: %d\n", bloodGroups[i].type, bloodGroups[i].quantity);
}
}
/*-	Display Header: The function starts by printing a header to indicate that the list of blood groups will follow.
-	Iterate Through Blood Groups: The function iterates through the bloodGroups
array, printing each blood group's type and quantity.*/
 
//UpdateBloodQuantity

void updateBloodQuantity()
{
printf("Enter blood type to update: ");
scanf("%s", bloodType);
printf("Enter new quantity: "); 
scanf("%d", &quantity);

for(int i=0; i<count; i++)
{
if(strcmp(bloodGroups[i].type, bloodType) == 0)
{
bloodGroups[i].quantity = quantity;
printf("\nBlood group %s quantity updated successfully!\n", bloodType);
return;
}
}
printf("\nBlood group not found.\n");
}

/*Prompt for Package Information: The function prompts the user to enter the blood type and quantity they want to add to the package.
Search and Update Package: It searches for the specified blood type in the existing package. If found, it updates the quantity by adding the new quantity to the existing one. Handle Not Found: If the specified blood type is not found in the package, it prints an appropriate message.

// Create Blood group Package*/


void createBloodGroupPackage() { int packageCount;
printf("Enter the number of blood groups to include in the package: ");
scanf("%d", &packageCount);

struct BloodGroup package[packageCount];
for(int i = 0; i < packageCount; i++) {
printf("\nEnter Blood Type for package item %d: ", i + 1);
scanf("%s", bloodType);
printf("Enter Quantity for package item %d: ", i + 1);
scanf("%d", &quantity);

int found = 0;
for(int j = 0; j < count; j++) {
 
if(strcmp(bloodGroups[j].type, bloodType) == 0) { if(bloodGroups[j].quantity >= quantity) {
strcpy(package[i].type, bloodType); package[i].quantity = quantity; bloodGroups[j].quantity -= quantity; found = 1;
break;
} else {
printf("\nNot enough quantity of %s available. Available: %d\n", bloodType, bloodGroups[j].quantity);
i--;
found = 1; break;
}
}
}
if(!found) {
printf("\nBlood type %s not found in the blood bank.\n", bloodType);
i--;
}
}

printf("\nBlood Group Package Created:\n"); for(int i = 0; i < packageCount; i++) {
printf("\t%s: %d\n", package[i].type, package[i].quantity);
}
}

//Prompt for Number of Blood Groups: The function first asks the user how many blood groups they want to include in the package.
//Array for Package: An array package of struct BloodGroup is created to store the blood types and quantities for the package.
//Loop for Each Blood Group: A loop runs for the number of blood groups specified. For each iteration, the function:
//●	Prompts the user to enter the blood type and quantity.
//●	Checks if the specified blood type exists in the inventory.
//●	Checks if the specified quantity is available.
//●	If available, the blood group is added to the package and the quantity is deducted from the inventory.
//●	If the quantity is not sufficient or the blood type is not found, the user is notified, and the iteration is retried.
//Display the Package: After collecting all the required blood groups, the function displays the final package.
 
// Main function
int main()
{
while(1)
{
printf("\nBlood Management System\n"); 
printf("1. Add Blood Group\n");
printf("2. Delete Blood Group\n"); 
printf("3. Search Blood Group\n"); 
printf("4. Display Blood Groups\n");
printf("5. Update Blood Quantity\n");
printf("6. Create Blood Group Package\n"); 
printf("7. Exit\n");
printf("Enter your choice: "); 
scanf("%d", &choice);

switch (choice)
{
case 1:
addBloodGroup(); break;
case 2:
deleteBloodGroup(); break;
case 3:
searchBloodGroup(); break;
case 4:
displayBloodGroups(); break;
case 5:
updateBloodQuantity(); break;
case 6:
createBloodGroupPackage(); break;
case 7:
exit(0); default:
printf("Invalid choice!\n");
}
}



return 0;
 
}

/*Infinite Loop: The main function runs an infinite loop using while(1) to continuously present a menu to the user until the user chooses to exit.
Display Menu: Inside the loop, a menu with options is displayed to the user. The user is prompted to enter a choice corresponding to one of the menu options.
Handle User Choice: The user's choice is read using scanf, and a switch statement is used to handle the different cases based on the user's input. Each case calls a different function to perform the desired operation.
Exit Option: If the user chooses the exit option (7), the program terminates by calling
exit(0).
Invalid Choice: If the user enters an invalid choice, a message is displayed to inform the user of the invalid input.*/
