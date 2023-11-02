//INSERT MODULE

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
   fp = fopen("courier_data.txt", "a");

   if(fp == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   printf("Enter Name:");
//   fgets(courier.name, 50, stdin);
    fscanf(stdin, "%49[^\n]%*c", courier.name);
   printf("Enter address: ");
//   fgets(courier.address, 100, stdin);
   fscanf(stdin, "%99[^\n]%*c", courier.address);
   printf("Enter phone: ");
//   fgets(courier.phone, 20, stdin);
   fscanf(stdin, "%19[^\n]%*c", courier.phone);
   printf("Enter email: ");
//   fgets(courier.email, 50, stdin);
   fscanf(stdin, "%49[^\n]%*c", courier.email);
   

   fprintf(fp, "\n%s %s %s %s\n", courier.name, courier.address, courier.phone, courier.email);
   printf("Courier data inserted successfully.\n");
   fclose(fp);
   return 0;
}
