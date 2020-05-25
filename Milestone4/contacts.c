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
#include <string.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+
// getName:
void getName(struct Name* name) {
    int request;
    
    printf("Please enter the contact's first name: ");
    scanf(" %30[^\n]s", name->firstName); //Get user input for their first name
    clearKeyboard(); //Empties buffer
    
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    request = yes(); //call the function yes() from connected source file
    if (request)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %6[^\n]", name->middleInitial); //Get user input for their middle initial
        clearKeyboard(); //Empties buffer
    }
    else
    {
        strcpy(name->middleInitial, "");
    }
    printf("Please enter the contact's last name: ");
    scanf(" %35[^\n]", name->lastName); //Get user input for their last name
    clearKeyboard(); //Empties buffer
}


// getAddress:
void getAddress(struct Address* address)
{
    int request;
    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt(); //call the function getInt() in order to receive an integer
    
    while (address->streetNumber <= 0) //Integer provided for street number must be greater than zero
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: "); //Display message if user inputs integer less than zero
        address->streetNumber = getInt();
    }
    
    printf("Please enter the contact's street name: ");
    scanf(" %40[^\n]", address->street); //Get user input for their street name
    clearKeyboard(); // Empties buffer
    
    printf("Do you want to enter an apartment number? (y or n): ");
    request = yes(); //call the function yes()
    
    if (request) //Loop will only execute if user inputs 'y'
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt(); //Call the function getInt()
        
        while (address->apartmentNumber <= 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: "); //Display message if user inputs integer less than zero
            address->apartmentNumber = getInt();
        }
    
    }
    else
    {
        address->apartmentNumber = 0;
    }
    
    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]", address->postalCode); //Get user input for their postal code
    clearKeyboard(); //Empties buffer
    
    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]", address->city); //Get user input for their city
    clearKeyboard(); //Empties buffer
    
}


// getNumbers:
// HINT:  Update this function to use the new helper
//        function "getTenDigitPhone" where applicable


void getNumbers(struct Numbers* numbers)
{
    int request;
    
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell); //Get user input for their cell phone number
    
    
    printf("Do you want to enter a home phone number? (y or n): ");
    request = yes(); //Call the function yes()
    
    if (request) //Loop will only execute if user inputs 'y'
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
        
    }
    else
    {
        strcpy(numbers->home, "");
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    request = yes(); //Call the function yes()
    
    if (request) //Loop will only execute if user inputs 'y'
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
        
    }
    
    else
    {
        strcpy(numbers->business, "");
    }
}



// getContact

void getContact(struct Contact *contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
