//DELETE/UPDATE MODULE

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
   char search_name[50], new_name[50], new_address[100], new_phone[20], new_email[50];
   FILE *fp, *temp_fp;
   fp = fopen("courier_data.txt", "r");
   temp_fp = fopen("temp_courier_data.txt", "w");

   if(fp == NULL || temp_fp == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   int option, found = 0;

   printf("Enter option:\n1 - Delete data\n2 - Update data\nOption: ");
   scanf("%d", &option);

   if(option == 1) {
      printf("Enter name to delete: ");
      scanf("%s", search_name);

      while(fscanf(fp, "%s %s %s %s\n", courier.name, courier.address, courier.phone, courier.email) != EOF) {
         if(strcmp(courier.name, search_name) != 0) {
            fprintf(temp_fp, "%s %s %s %s\n", courier.name, courier.address, courier.phone, courier.email);
         } else {
            found = 1;
         }
      }

      if(!found) {
         printf("No data found for '%s'\n", search_name);
      } else {
         printf("Data deleted successfully for '%s'\n", search_name);
      }

   } else if(option == 2) {
      printf("Enter name to update: ");
      scanf("%s", search_name);

      while(fscanf(fp, "%s %s %s %s\n", courier.name, courier.address, courier.phone, courier.email) != EOF) {
         if(strcmp(courier.name, search_name) != 0) {
            fprintf(temp_fp, "%s %s %s %s\n", courier.name, courier.address, courier.phone, courier.email);
         } else {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", new_name);
            printf("Enter new address: ");
            scanf(" %[^\n]", new_address);
            printf("Enter new phone number: ");
            scanf("%s", new_phone);
            printf("Enter new email address: ");
            scanf("%s", new_email);

            fprintf(temp_fp, "%s %s %s %s\n", new_name, new_address, new_phone, new_email);
            printf("Data updated successfully for '%s'\n", search_name);
         }
      }

      if(!found) {
         printf("No data found for '%s'\n", search_name);
      }

   } else {
      printf("Invalid option\n");
      exit(1);
   }

   fclose(fp);
   fclose(temp_fp);
   remove("courier_data.txt");
   rename("temp_courier_data.txt", "courier_data.txt");
   return 0;
}
