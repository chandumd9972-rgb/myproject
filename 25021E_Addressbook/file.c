/* 
     Name : Chandu M D
     Date : 10 oct 2025
     Description : Addressbook project
                 * Here save the name,mobile number,email to file
		 * also loadcontacts from .csv file 

 */

#include <stdio.h>
#include "file.h"

void saveContactsToFile(struct AddressBook *addressBook)
{
	FILE* fp = fopen("addressbook.csv","w");
	if(fp == NULL)
	{
		printf("File not found.");
	}
	fprintf(fp,"#%d\n",addressBook->contactCount);
	for(int i = 0; i < addressBook->contactCount; i++)
	{
		fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	}

	fclose(fp);
  
}

void loadContactsFromFile(struct AddressBook *addressBook) 
{
	FILE* fp = fopen("addressbook.csv","r");
	fscanf(fp,"#%d",&addressBook->contactCount);
	int i = 0;
	while(fgetc(fp) != EOF)
	{
		fscanf(fp,"%[^,],%[^,],%[^\n]",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
		i++;
	}
	fclose(fp);
}
