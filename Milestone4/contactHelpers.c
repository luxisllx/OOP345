/* -------------------------------
Name:     Luxi Liang
Student number: 165936188
Email:          lliang44@myseneca.ca
Section:        SJJ
Date:           August 2, 2019
----------------------------------
Assignment: 2
Milestone:  4
---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>
#include <ctype.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):

#define MAXCONTACTS 5

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')
        ;// empty execution code block on purpose
}

// pause function definition goes here:
void Pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
    int value=0;
    char NL = 'x';
    
    while ( NL != '\n')
    {
        scanf("%d%c", &value, &NL);  //Read and check if user input is an integer
        if (NL != '\n')
        {
            clearKeyboard(); //Empties buffer
            printf("*** INVALID INTEGER *** <Please enter an integer>: "); //Display invalid message if user does not input integer
        }
    }
    return value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
    int value = getInt();
    while (value > max || value < min) //If user input exceeds the max and min values then proceed to loop
    {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max); //Display error message if the value exceeds the loop
        value = getInt(); //Get new value
    }
    return value;
}

// yes function definition goes here:
int yes(void)
{
    char first, second; //Declare variables
    
    scanf("%c%c", &first, &second); //Read and check user's first and second character input
    while (second != '\n' ||( first != 'Y' && first != 'y' && first != 'N' && first != 'n')) //If user's first input is not the required character or second input is not a space, then proceed to loop
    {
        clearKeyboard(); //Empties buffer
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: "); //Display error message if second input is not a new line
        scanf("%c%c", &first, &second);
    }
    if (first == 'Y' || first == 'y')
        return 1;
    else
        return 0;
    
}

// menu function definition goes here:
int menu(void)
{
    int value;
    
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");
    
    value = getIntInRange(0, 6); //Request an integer between 0 and 6, inclusive
    return value;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void) {
    int value, redo = 0;
    struct Contact contact[MAXCONTACTS] =
    { {{ "Rick", {'\0'}, "Grimes" },
        { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
        { "4161112222", "4162223333", "4163334444" }},
        {
            { "Maggie", "R.", "Greene" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9051112222", "9052223333", "9053334444" }},
        {
            { "Morgan", "A.", "Jones" },
            { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
            { "7051112222", "7052223333", "7053334444" }},
        {
            { "Sasha", {'\0'}, "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555" }},
    };
    do {
        value = menu();
        if (value == 1)
        {
            printf("\n");
            displayContacts(contact, MAXCONTACTS);
            printf("\n");
            Pause();
            printf("\n");
        }
        else if (value == 2)
        {
            printf("\n");
            addContact(contact, MAXCONTACTS);
            printf("\n");
            Pause();
            printf("\n");
        }
        else if (value == 3)
        {
            printf("\n");
            updateContact(contact, MAXCONTACTS);
            printf("\n");
            Pause();
            printf("\n");
        }
        else if (value == 4)
        {
            printf("\n");
            deleteContact(contact, MAXCONTACTS);
            printf("\n");
            Pause();
            printf("\n");
        }
        else if (value == 5)
        {
            printf("\n");
            searchContacts(contact, MAXCONTACTS);
            printf("\n");
            Pause();
            printf("\n");
        }
        else if (value == 6)
        {
            printf("\n");
            sortContacts(contact, MAXCONTACTS);
            printf("\n");
            Pause();
            printf("\n");
        }
        else if (value == 0)
        {
            printf("\nExit the program? (Y)es/(N)o: ");
            redo = yes();
            printf("\n");
            if (redo == 1)
            {
                printf("Contact Management System: terminated\n");
            }
        }
    } while (!redo);
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;
    int i;
    int check = 1;
    
    while (needInput == 1) {
        
        check = 1;
        scanf("%10s", phoneNum);
        clearKeyboard();
        
        // (String Length Function: validate entry of 10 characters)
        for (i =0; i< strlen(phoneNum);i++) // validate if input is digits
		{
            if (phoneNum[i]<'0'||phoneNum[i]>'9'){
                check = 0;
                break;
            }
        }
        
        if (strlen(phoneNum) == 10 && check == 1) //if input fulfills loop condition, break out of loop
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");  // error message
        
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int index = -1;
    int i;
    for (i=0; i < size; i++)
    {
        if (strcmp(contacts[i].numbers.cell,cellNum)==0) // validate if user input matches phone number in system 
            index=i;
        
    }
    
    return index;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
    
}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n",count);
    
}
// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contact)
{
    printf(" %s", contact->name.firstName); 
    if(strlen(contact->name.middleInitial) != 0) // display user middle name input if needed
        printf(" %s", contact->name.middleInitial);
    printf(" %s",contact->name.lastName);
    printf("\n");
    
    
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
    if(contact->address.apartmentNumber > 0)
        printf("Apt# %d, ", contact->address.apartmentNumber);
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
    
}
// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
    int i, counter = 0;
    displayContactHeader();
    for(i=0; i<size; i++)
        if(strlen(contacts[i].numbers.cell) > 0) // search program if cell phone number exists 
        {
            displayContact(&contacts[i]);
            counter ++;
        }
    displayContactFooter(counter);
}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
    char phoneNum[11];
    int index;
    printf("Enter the cell number for the contact: "); 
    getTenDigitPhone(phoneNum);
    index = findContactIndex(contacts, size, phoneNum); // search program for matching input 
    
    if(index != -1)
    {
		printf("\n");
        displayContact(&contacts[index]);
        
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n"); 
    }
}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
    int index;
    index = findContactIndex(contacts, size, ""); // check to see if contact list exceeds capacity
    if (index == -1)
    {
        printf("*** ERROR: The contact list is full! ***\n");
    }
    else
    {
        getContact(&contacts[index]);
        printf("--- New contact added! ---\n");
    }
}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
    char phoneNum[11];
    int index;
    int update;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    index = findContactIndex(contacts, size, phoneNum); //search program for user input match
    
    if(index != -1) //if user input matches exisiting program information, then continue with update
    {
        printf("\n");
        printf("Contact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        
        printf("Do you want to update the name? (y or n): ");
        update = yes ();
        if (update == 1)
        {
            getName(&contacts[index].name);
        }
        printf("Do you want to update the address? (y or n): ");
        update = yes ();
        if (update == 1)
        {
            getAddress(&contacts[index].address);
        }
        printf("Do you want to update the numbers? (y or n): ");
        update = yes ();
        if (update == 1)
        {
            getNumbers(&contacts[index].numbers);
        }
        
        printf("--- Contact Updated! ---\n");
    }
    else
    {
        printf("*** Contact NOT FOUND ***\n");
    }
    
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
    char phoneNum[11];
    int index;
    int delete;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNum);
    index = findContactIndex(contacts, size, phoneNum);
    if (index != -1)
    {
        printf("\nContact found:\n"); //search program for information matching user input 
        displayContact(&contacts[index]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        delete = yes();
        if (delete)
        {

            contacts[index].numbers.cell[0] = '\0';
            
            
            printf("--- Contact deleted! ---\n");
        }
    }
    else
    {
        
        printf("*** Contact NOT FOUND ***\n");
    }
}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
    struct Contact temp;
    int i, j;
        
    for (i = 0; i < size - 1; i++) // compare phone numbers and sort according to smallest 
    {
        for (j = i + 1; j < size; j++)
        {
            if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[j].numbers.cell) != 0)
            {
                if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0)
                {
                    temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }
        printf("--- Contacts sorted! ---\n");
}

