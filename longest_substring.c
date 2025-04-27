
#include <stdio.h>
#include<string.h>
void sort(char* a,int z);
void long_subs(char* a,char* b,int z);
int main()
{
    char a[20];
    char b[20];
    printf("enter your string\n");
    gets(a);
    sort(a,strlen(a)); //sorts the dtring to pass to next function
    long_subs(a,b,strlen(a)); //returns the longest non recurring string
    printf("sorted string: %s\n", a);
    printf("longest non-recurring string: %s", b);
}
void sort(char* a,int z){
    for(int i=0;i<z-1;i++){
        for(int j=0;j<z-1-i;j++){
            if(a[j]>a[j+1]){
                char p = a[j+1];
                a[j+1] =a[j];
                a[j]=p;
            }
        }
    }
}
void long_subs(char* a,char* b,int z){
    b[0]=a[0];
    int j=0;
    for(int i =1; i<z+1;i++){
        if(a[i]!=b[j]){
            b[++j]=a[i];
        }
    }
}