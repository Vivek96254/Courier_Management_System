//DISPLAY MODULE

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
   FILE *fp;
   fp = fopen("courier_data.txt", "r");

   if(fp == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   printf("Courier data:\n");
   printf("--------------------------------------------------------------------\n");
   printf("Name\t\tAddress\t\tPhone\t\tEmail\n");
   printf("--------------------------------------------------------------------\n");

   while(fscanf(fp, "%s %s %s %s\n", courier.name, courier.address, courier.phone, courier.email) != EOF) {
      printf("%-15s\t%-15s\t%-10s\t%s\n", courier.name, courier.address, courier.phone, courier.email);
   }

   printf("--------------------------------------------------------------------\n");
   fclose(fp);
   return 0;
}

