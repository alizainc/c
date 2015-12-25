/*    When Harry Met Sally

This program finds the earliest year in which Harry and Sally live in the same
city.

09/04/2015	               Alizain Charania  */

#include <stdio.h>
#include <stdlib.h>

/* City IDs used in timelines. */
enum Cities{ London, Boston, Paris, Atlanta, Miami, 
             Tokyo, Metz, Seoul, Toronto, Austin };

int main(int argc, char *argv[]) {
   int	HarryTimeline[10];
   int	SallyTimeline[10];
   int	NumNums, Year=0;
   int  Load_Mem(char *, int *, int *);

   if (argc != 2) {
     printf("usage: ./HW2-1 valuefile\n");
     exit(1);
   }
   NumNums = Load_Mem(argv[1], HarryTimeline, SallyTimeline);
   if (NumNums != 20) {
     printf("valuefiles must contain 20 entries\n");
     exit(1);
   }

   /* Your program goes here */
   int begin, HarryFirst, SallyFirst;
   HarryFirst = HarryTimeline[0];
   SallyFirst = SallyTimeline[0];
   if (HarryFirst < SallyFirst) {
      begin = HarryFirst;
   }
   else {
      begin = SallyFirst;
   }
   int end = 2015;
   int i = 0;
   int j = 0;
   int hCity = -2;
   int sCity = -1;
   while (begin <= end && Year ==0) {
      if (begin == HarryTimeline[i]) {
         int ind1 = i+1;
         hCity = HarryTimeline[ind1];
         i = i+2;
      }
      if (begin == SallyTimeline[j]) {
         int ind2 = j+1;
         sCity = SallyTimeline[ind2];
         j = j+2;
      }
      if (hCity == sCity) {
         Year = begin;
      }
      begin++;
   }

   printf("Earliest year in which both lived in the same city: %d\n", Year);
   exit(0);
}

/* This routine loads in up to 20 newline delimited integers from
a named file in the local directory. The values are placed in the
passed integer array. The number of input integers is returned. */

int Load_Mem(char *InputFileName, int IntArray1[], int IntArray2[]) {
   int	N, Addr, Value, NumVals;
   FILE	*FP;

   FP = fopen(InputFileName, "r");
   if (FP == NULL) {
     printf("%s could not be opened; check the filename\n", InputFileName);
     return 0;
   } else {
     for (N=0; N < 20; N++) {
       NumVals = fscanf(FP, "%d: %d", &Addr, &Value);
       if (NumVals == 2)
	 if (N < 10)
	   IntArray1[N] = Value;
	 else
	   IntArray2[N-10] = Value;
       else
	 break;
     }
     fclose(FP);
     return N;
   }
}
