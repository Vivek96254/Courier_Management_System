//SEARCH MODULE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Courier {
   char name[50];
   char address[100];
   char phone[20];
   char email[50];
};

int main() {
   struct Courier courier;
   char search_name[50];
   FILE *fp;
   fp = fopen("courier_data.txt", "r");

   if(fp == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   printf("Enter name to search: ");
   fgets(search_name, 50, stdin);
   search_name[strcspn(search_name, "\n")] = '\0';

   printf("Courier data for '%s':\n", search_name);
   printf("--------------------------------------------------------------------\n");
   printf("Name\t\tAddress\t\tPhone\t\tEmail\n");
   printf("--------------------------------------------------------------------\n");

   int found = 0;

   while(fscanf(fp, "%s %s %s %s\n", courier.name, courier.address, courier.phone, courier.email) != EOF) {
      if(strcmp(courier.name, search_name) == 0) {
         printf("%-15s\t%-15s\t%-10s\t%s\n", courier.name, courier.address, courier.phone, courier.email);
         found = 1;
      }
   }

   if(!found) {
      printf("No data found for '%s'\n", search_name);
   }

   printf("--------------------------------------------------------------------\n");
   fclose(fp);
   return 0;
}

