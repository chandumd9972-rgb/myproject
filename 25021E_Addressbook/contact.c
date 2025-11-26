/* 
   Name : Chandu M D
   Date : 10 oct 2025 
   Description : Addressbook project 
   		* in this project we have to store the person name,mobile number,and email.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(struct AddressBook *addressBook) 
{
    /* Define the logic for print the contacts */
	//printing the contacts by using the for loop.
	
	printf("------------ contact information ------------------\n");
	for(int i=0;i<addressBook->contactCount;i++)
	{
		printf(".......................................................\n");

		
		printf("sl.no : %d\nName : %s\nMobile number : %s\nG-mail : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);


		printf(".......................................................\n");
	}

}

void initialize(struct AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);

    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(struct AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(struct AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    	addressBook->contactCount;

	char arr[20];
	printf("Enter the name :");
	getchar();
	scanf("%[^\n]",arr);
	
	char mobile[20];
	int i=1;
	while(i)
	{
	printf("Enter the mobile number : ");
	scanf("%s",mobile);
	if(validation_mobile(addressBook,mobile))
	{
		break;
	}
	else
	{
		printf("Invalid mobile number.\n");
		i=1;
	}
	}
	char mail[20];
	while(i)
	{
	printf("Enter the e-mail id : ");
	getchar();
	scanf("%[^\n]",mail);
	if(validation_email(addressBook,mail))
	{
		break;
	}
	else
	{
		printf("Invalid e_mail id.\n");
		i=1;
	}
	}
	//The strcpy() function in C is a standard library function used to copy the contents of one string (the source) to another string

	strcpy(addressBook->contacts[addressBook->contactCount].name, arr);
	strcpy(addressBook->contacts[addressBook->contactCount].phone, mobile);
	strcpy(addressBook->contacts[addressBook->contactCount].email, mail);
    	(addressBook->contactCount)++;
}
void searchContact(struct AddressBook *addressBook) 
{
    /* Define the logic for search */
	printf("Search by :\n");
	printf("1.Name\n2.Mobile\n3.email\n");
	int opt;
	scanf("%d",&opt);
	int c = addressBook->contactCount;
switch(opt)
{
	case 1:
		//search by name
		{	
		char a[20];
		printf("Enter the name : ");
		getchar();
		scanf("%[^\n]",a);
		int flag=0;
		for(int i=0;i<c;i++)
		{
		//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file
		if(strcmp(a,addressBook->contacts[i].name) == 0)
				{
		printf("......................................................................\n");

					printf("Name : %s\nMobile No : %s\nEmail : %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					
					flag = 1;
					
		printf(".......................................................................\n");
				}
		
		}
				if(flag==0)
				{
					printf("name not found.\n");
				}
				break;
		}

		
	case 2:
		//search by mobile number
		{
		char m[20];
		int flag = 0;
		printf("Enter the mobile number : ");
		getchar();
		scanf("%[^\n]",m);
		for(int i=0;i<c;i++)
		{
		//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file
			if(strcmp(m,addressBook->contacts[i].phone)==0)
			{	
			printf("...............................................................................\n");
			
			printf("Name : %s\nMobile No : %s\nEmail : %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					
			printf("...............................................................................\n");

					flag = 1;
					break;
			}
		}
		if(flag==0)
		{							
			printf("Mobile number not found.\n");
		}
		break;
		}
			
	case 3:
		//search by email
		{
		char g[20];
		int flag = 0;
		printf("Enter the email : ");
		getchar();
		scanf("%[^\n]",g);
		for(int i=0;i<c;i++)
		{
		//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file
			if(strcmp(g,addressBook->contacts[i].email)==0)
			{
			printf("..........................................................................\n");

				printf("Name : %s\nMobile No : %s\nEmail : %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
					
			printf(".........................................................................\n");

					flag = 1;
					break;
			}
		}
		if(flag==0)
		{
			printf("email not found.\n");			

		}
		break;
		}
	
}
}

void editContact(struct AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
	char phone[20];
	int choice;
	int c = addressBook->contactCount;
	int res;
	do
	{
		getchar();
		printf("1.search by name\n2.search by mobile number\n3.search by email\n4.Exit\n");
		printf("Enter your choice : \n");
		scanf("%d",&choice);
		printf(".........................................................................\n");
		switch(choice)
		{
			case 1://edit the name
				{
					char name[50];
					int count = 0;
					int arr[100];
					getchar();
					printf("Enter the name to search : ");
					scanf("%[^\n]",name);
					for(int i=0;i<c;i++)
					{
					//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file	
						if(strcmp(name,addressBook->contacts[i].name)==0)
						{
							printf("..........................................................\n");

							printf("sl no : %d\nName : %s\nMobile No : %s\nEmail : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
						
							printf("..........................................................\n");
							arr[count] = i;
							count++;
						}
					}
					if(count > 1)
					{
						int n;
						printf("Enter the serial number(sl no) to edit the contact : ");
						scanf("%d",&n);
						res = n-1;
					}
					if(count==1)
					{
						res=arr[0]; 
					}
					if(count == 0)
					{
						printf("contact not found.\n");
					}
					contact_edit(addressBook,res);
					break;
				}
			case 2 : //edit the mobile number
				{
					char b[20];
					int count = 0;
					int brr[100];
					printf("Enter the mobile number : ");
					getchar();
					scanf("%[^\n]",b);
					for(int i=0;i<c;i++)
					{
					//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file
						if(strcmp(b,addressBook->contacts[i].phone)==0)
						{
							printf(".........................................................\n");

							printf("sl no : %d\nName : %s\nMobile No : %s\nEmail : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
							
							printf("..........................................................\n");
							brr[count] = i;
							count++;
							break;
						}
					}
					if(count == 1)
					{
						res = brr[0];
					}
					else
					{
						printf("Contact not found.");
					}
					contact_edit(addressBook,res);
					break;

				}
			case 3:          //edit the email

				{
					char e[20];
					int count = 0;
					int crr[100];
					printf("Enter the Email id : ");
					getchar();
					scanf("%[^\n]",e);
					for(int i=0;i<c;i++)
					{
					//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file	
						if(strcmp(e,addressBook->contacts[i].email)==0)
						{
							printf(".........................................................\n");

							printf("sl no : %d\nName : %s\nMobile No : %s\nEmail : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
							
							printf("..........................................................\n");
							crr[count] = i;
							count++;
							break;
						}
					}
					if(count == 1)
					{
						res = crr[0];
					}
					else
					{
						printf("Email not found.");
					}
					contact_edit(addressBook,res);
					break;

				}

		}
	}while(choice != 4);
	

}

void deleteContact(struct AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
	char p[20];
	int op;
	int c = addressBook->contactCount;
	int res;
	do
	{
		getchar();
		printf("1.search by name\n2.search by mobile number\n3.search by email\n4.Exit\n");
		printf("Enter your choice : \n");
		scanf("%d",&op);
		printf(".........................................\n");
		switch(op)
		{
			case 1:
				//deleting contact using name
				{
				char n[50];
				int count=0;
				int arr[100];
				getchar();
				printf("Enter the name to search : ");
				scanf("%[^\n]",n);
				for(int i=0;i<c;i++)
				{
				//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file	
					if(strcmp(n,addressBook->contacts[i].name)==0)
					{
					
						printf(".................................................\n");

						printf("sl no : %d\nName : %s\nMobile No : %s\nEmail : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
						printf("...................................................\n");
						arr[count] = i;
						count++;
					}
				}
				if(count > 1)
				{
					int n;
					printf("Enter a serial number(sl no) to delete contact : ");
					scanf("%d",&n);
					res = n-1;
					for(int i=res;i<c;i++)
					{
					//The strcpy() function in C is a standard library function used to copy the contents of one string (the source) to another string
					strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
					strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
					strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
					}
					(addressBook->contactCount)--;
					printf("Contact deleted successfully.\n");
					printf("....................................\n");
				}
				if(count==1)
				{
					res = arr[0];
					for(int i=res;i<c;i++)
					{
					//The strcpy() function in C is a standard library function used to copy the contents of one string (the source) to another string

					strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
					strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
					strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
					}
					(addressBook->contactCount)--;
					printf("Contact deleted successfully.\n");
					printf("..................................\n");
				}
				if(count==0)
				{
					printf("contact not found.\n");
					printf("...................................\n");
				}
				break;
				}
			case 2:
				//deleting contact using mobile number
				{
				char p[20];
				int count=0;
				int prr[100];
				getchar();
				printf("Enter the mobile number to search : ");
				scanf("%[^\n]",p);
				for(int i=0;i<c;i++)
				{
				//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file
					if(strcmp(p,addressBook->contacts[i].phone)==0)
					{
					
						printf(".......................................................\n");

						printf("sl no : %d\nName : %s\nMobile No : %s\nEmail : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
						printf("........................................................\n");
						prr[count] = i;
						count++;
					}
				}
				if(count==1)
				{
					res = prr[0];
					for(int i=res;i<c;i++)
					{
					//The strcpy() function in C is a standard library function used to copy the contents of one string (the source) to another string
					strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
					strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
					strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
					}
					(addressBook->contactCount)--;
					printf("Contact deleted successfully.\n");
					printf("....................................\n");
				}
				if(count==0)
				{
					printf("contact not found.\n");
					printf(".....................................\n");
				}
				break;
				}
			case 3:
				//deleting contact using email
				{
				char e[20];
				int count=0;
				int err[100];
				getchar();
				printf("Enter the E-mail id to search : ");
				scanf("%[^\n]",e);
				for(int i=0;i<c;i++)
				{
				//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file
					if(strcmp(e,addressBook->contacts[i].email)==0)
					{
					
						printf(".......................................................\n");

						printf("sl no : %d\nName : %s\nMobile No : %s\nEmail : %s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
						printf("........................................................\n");
						err[count] = i;
						count++;
					}
				}
				if(count==1)
				{
					res = err[0];
					for(int i=res;i<c;i++)
					{
					//The strcpy() function in C is a standard library function used to copy the contents of one string (the source) to another string
					strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
					strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
					strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
					}
					(addressBook->contactCount)--;
					printf("Contact deleted successfully.\n");
					printf(".....................................\n");
				}
				if(count==0)
				{
					printf("contact not found.\n");
					printf(".....................................\n");
				}
				break;
				}
		}
	}while(op!=4);
}
//validation mobile number

int validation_mobile(struct AddressBook *addressBook, char* mobile)
{
	int c = addressBook->contactCount;
	int l = strlen(mobile);
//The strlen() function in C is a standard library function used to determine the length of a null-terminated string.
	{
	if(l != 10)
	{
		return 0;
	}
	for(int i=0;i<l;i++)
	{
		if(!(mobile[i] >= '0' && mobile[i] <= '9'))
		{
			return 0;
		}

	}
	for(int i=0;i<c;i++)
	{
		//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file
		int ret = strcmp(mobile,addressBook->contacts[i].phone);
		if(ret==0)
		{
			return ret;
		}
	}
	return 1;
	}
}


//gmail validation
int validation_email(struct AddressBook *addressBook, char* mail)
{
//The strlen() function in C is a standard library function used to determine the length of a null-terminated string.
	int l = strlen(mail);
	int c = addressBook->contactCount;
	for(int i=0;i<l;i++)
	{
	if(mail[i]>='A' && mail[i]<='Z')
	{
		return 0;
	}	
	if(mail[i] == '@')
	{
		if(!(mail[i-1] >= 'a' && mail[i-1] <= 'z' && mail[i+1] >= 'a' && mail[i+1] <= 'z'))
		{
			return 0;
		}
	}
	}
	if(!(mail[l-1]=='m' && mail[l-2]=='o' && mail[l-3]=='c' && mail[l-4]=='.'))
	{
		return 0;
	}
	for(int i=0;i<c;i++)
	{
//The strcmp() function in C is a standard library function used to compare two strings lexicographically. It is declared in the <string.h> header file
		int ret = strcmp(mail,addressBook->contacts[i].email);
		if(ret==0)
		{
			return ret;
		}
	}
}
// contact edit
void contact_edit(struct AddressBook *addressBook,int res)
{
	int m;
	do
	{
	printf("1.Name\n2.Mobile number\n3.Email\n4.Exit\n");
	printf("Enter your choice.\n");
	scanf("%d",&m);
	switch(m)
	{
		case 1: //edit the name
			{
				getchar();
				printf("Enter the new name : \n");
				scanf("%[^\n]",addressBook->contacts[res].name);
				printf("Name has updated successfully.\n");
				printf("...........................................\n");
				break;
			}
		case 2: //edit the mobile number
			{
				getchar();
				char mobile[20];
				printf("Enter the new mobile number : \n");
				scanf("%[^\n]",mobile);
				int mat = validation_mobile(addressBook,mobile);
				if(mat)
				{
					strcpy(addressBook->contacts[res].phone,mobile);
					printf("Phone number has updated successfully.\n");
					printf("...........................................\n");
					break;
				}
				else
				{
					printf("Phone number is not valid.\n");
					break;
				}
				break;
			}
		case 3:     //edit the gamil

			{
				getchar();
				char mail[20];
				printf("Enter the new Email id : \n");
				scanf("%[^\n]",mail);
				int t = validation_email(addressBook,mail);
				if(t)
				{
					//The strcpy() function in C is a standard library function used to copy the contents of one string (the source) to another string
					strcpy(addressBook->contacts[res].email,mail);
					printf("Email id updated successfully.\n");
					printf("...........................................\n");
					break;
				}
				else
				{
					printf("Email id is not valid.\n");
					break;
				}
				break;
			}
	}

	}while(m!=4);

}

