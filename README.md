# Blood-Bank-Management-System-in-C
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
//Add Blood Group
void addBloodGroup()
{
printf("\nEnter Blood Type: ");
scanf("%s", bloodType);
printf("Enter Quantity: ");
scanf("%d", &quantity);
if(count < 10)
{
strcpy(bloodGroups[count].type, bloodType);
bloodGroups[count].quantity = quantity;
count++;
printf("\nBlood group added successfully!\n");
}
else
printf("\nBlood bank is full. Cannot add more blood groups.\n");
}
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
strcpy(bloodGroups[j].type, bloodGroups[j+1].type);
bloodGroups[j].quantity = bloodGroups[j+1].quantity;
}
count--;
printf("\nBlood group %s deleted successfully!\n", bloodType);
return;
}
}
printf("\nBlood group not found.\n");
}
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
// Display Blood Groups
void displayBloodGroups()
{
printf("Blood Groups:\n");
for (int i = 0; i < count; i++)
{
printf("\t %s: %d\n", bloodGroups[i].type, bloodGroups[i].quantity);
}
}
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
// Create Blood group Package
void createBloodGroupPackage() {
int packageCount;
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
if(strcmp(bloodGroups[j].type, bloodType) == 0) {
if(bloodGroups[j].quantity >= quantity) {
strcpy(package[i].type, bloodType);
package[i].quantity = quantity;
bloodGroups[j].quantity -= quantity;
found = 1;
break;
} else {
printf("\nNot enough quantity of %s available. Available: %d\n", bloodType,
bloodGroups[j].quantity);
i--;
found = 1;
break;
}
}
}
if(!found) {
printf("\nBlood type %s not found in the blood bank.\n", bloodType);
i--;
}
}
printf("\nBlood Group Package Created:\n");
for(int i = 0; i < packageCount; i++) {
printf("\t%s: %d\n", package[i].type, package[i].quantity);
}
}
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
addBloodGroup();
break;
case 2:
deleteBloodGroup();
break;
case 3:
searchBloodGroup();
break;
case 4:
displayBloodGroups();
break;
case 5:
updateBloodQuantity();
break;
case 6:
createBloodGroupPackage();
break;
case 7:
exit(0);
default:
printf("Invalid choice!\n");
}
}
return 0;
}
