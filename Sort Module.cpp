//SORT MODULE

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
   struct Courier courier[100];
   int i = 0, j, n;
   FILE *fp;
   fp = fopen("courier_data.txt", "r");

   if(fp == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   while(fscanf(fp, "%s %s %s %s\n", courier[i].name, courier[i].address, courier[i].phone, courier[i].email) != EOF) {
      i++;
   }

   n = i;

   for(i = 0; i < n; i++) {
      for(j = i+1; j < n; j++) {
         if(strcmp(courier[i].name, courier[j].name) > 0) {
            struct Courier temp = courier[i];
            courier[i] = courier[j];
            courier[j] = temp;
         }
      }
   }

   fclose(fp);

   fp = fopen("courier_data.txt", "w");

   for(i = 0; i < n; i++) {
      fprintf(fp, "%s %s %s %s\n", courier[i].name, courier[i].address, courier[i].phone, courier[i].email);
   }

   fclose(fp);

   printf("Data sorted successfully\n");
   return 0;
}

