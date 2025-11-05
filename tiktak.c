#include<stdio.h>
  int a=0;
char k[9] = {'a','b','c','d','e','f','g','h','i'};
void check(int *m){
  int c[8][3]={{0,1,2},{0,3,6},{0,4,8},{0,4,7},{2,5,8},{2,4,6},{3,4,5},{6,7,8}};
  for(int i=0;i<8;i++){
   if((k[c[i][0]]==k[c[i][1]])&&(k[c[i][1]]==k[c[i][2]])){
    *m=0;
    if(a==0){
      printf("O won");
    }else{
      printf("X won");
    }
    break;   
   }
  }

}

void print(){
  int x=0;
  for(int i =1;i<6;i++){
    for(int j=1; j<12; j++){
      if(i%2!=0){
        if(j%4==0){
          printf("|");
        }
        else if((j+2)%4==0){
          printf("%c",k[x]);
          x++;
        }
        else{
          printf(" ");
        }
      }
      else{
        printf("-");
      }
    }
    printf("\n");
  }
}
void replace(char n){
  for(int i=0; i<10;i++){
    if(k[i]==n){
      if(a==0){
        k[i]='X';
      }
      else{
        k[i]='O';
      }
      a=!a;
    }
  }
}
void main(){
  int m=1;
   print();
  while(m){
    char c;
    printf("Enter position to play\nEnter q to exit\n");
    scanf("%c",&c);
    if(c=='q'){
      m=0;
    }
    else{
      replace(c);
      print();
      check(&m);
    }
    }
  }

