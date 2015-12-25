/* <Alizain Charania>

This program finds George (possibly incognito) in a crowd. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int               CrowdInts[1024];
    int               NumInts, Location=0;
    int               Load_Mem(char *, int *);

    if (argc != 2) {
        printf("usage: ./P1-1 valuefile\n");
        exit(1);
    }
    NumInts = Load_Mem(argv[1], CrowdInts);
    if (NumInts != 1024) {
        printf("valuefiles must contain 1024 entries\n");
        exit(1);
    }
    int crowd[4096];
    int realNum;
    int i = 0;
    int k = 0;
    int j;
    int num;
    for (i = 0; i < 4096; i++) {
        num = CrowdInts[k];
        for (j = 0; j < 3; j++) {
            realNum = num & 0xFF;
            crowd[i] = realNum;
            num << 8;
        }
    }
    //printf("%d", crowd[4095]);
    i = 0;
    while(i < 4096 && Location == 0) {
        if (crowd[i] == 8 || crowd[i] == 3) {
            if (crowd[i] == 8) {
                j = i + 65;
                if (crowd[j] == 1) {
                    j += 128;
                    if (crowd[j] == 1) {
                        j += 128;
                        if (crowd[j] == 3) {
                            j += 128;
                            if (crowd[j] == 5) {
                                j += 64;
                                if (crowd[j] == 8) {
                                    j += 192;
                                    if (crowd[j] == 8) {
                                        Location = i + 3;
                                    } else {
                                        i += 11;
                                    }
                                } else {
                                    i += 11;
                                }
                            } else {
                                i += 11;
                            }
                        } else {
                            i += 11;
                        }
                    } else {
                        i += 11;
                    }
                } else {
                    i += 11;
                }
            } else if (crowd[i] == 3) {
              j = i + 65;
                if (crowd[j] == 1) {
                    j += 128;
                    if (crowd[j] == 1) {
                        j += 127;
                        if (crowd[j] == 7) {
                            j += 128;
                            if (crowd[j] == 2) {
                                j += 64;
                                if (crowd[j] == 5) {
                                    j += 192;
                                    if (crowd[j] == 3) {
                                        Location = i + 3;
                                    } else {
                                        i += 11;
                                    }
                                } else {
                                    i += 11;
                                }
                            } else {
                                i += 11;
                            }
                        } else {
                            i += 11;
                        }
                    } else {
                        i += 11;
                    }
                } else {
                    i += 11;
                }  
            }
        }
        else {
          i++;
        }
    }











    /* your code goes here. */

    printf("The rightmost pixel at the top of George's hat is located at: %4d.\n", Location);
    exit(0);
}

/* This routine loads in up to 1024 newline delimited integers from
a named file in the local directory. The values are placed in the
passed integer array. The number of input integers is returned. */

int Load_Mem(char *InputFileName, int IntArray[])
{
    int  N, Addr, Value, NumVals;
    FILE *FP;

    FP = fopen(InputFileName, "r");
    if (FP == NULL) {
        printf("%s could not be opened; check the filename\n", InputFileName);
        return 0;
    } else {
        for (N=0; N < 1024; N++) {
            NumVals = fscanf(FP, "%d: %d", &Addr, &Value);
            if (NumVals == 2)
                IntArray[N] = Value;
            else
                break;
        }
        fclose(FP);
        return N;
    }
}

