#include<stdio.h>
#include<string.h>
void main()
{
    char fn[50], pat[50], temp[200];
    FILE *fp;
    
    printf("Enter file name\n");
    scanf("%s", fn);
    printf("Enter pattern to be searched\n");
    scanf("%s", pat);
    
    fp = fopen(fn, "r");
    
    if (fp == NULL){
        printf("Error: Could not open file '%s'\n", fn);
        return;
    }
    
    while(fgets(temp, 100, fp)!= NULL){
        if(strstr(temp, pat))
            printf("%s", temp);
    }
    fclose(fp);
}

