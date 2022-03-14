#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
  int matrix[10][10];                                             
  int i,j,koor_x,koor_y, lower, upper,x,y;                                                                                                                                    
  for(i=0;i<10;i++)                                                           
  {                                                                             
    for(j=0;j<10;j++)                                                      
    {                                                                           
      matrix[i][j]=0;             /* Membuat matriks 10x10 ( yang beroperasi hanya 8x8 ) karena dikurangi oleh tembok */                                                    
    }                                                                           
  }   
  for(i=0;i<10;i++)                                                           
  {                                                                             
    for(j=0;j<10;j++)                                                      
    {                                                                           
      matrix[i][9]=2;
      matrix[9][j]=2;
      matrix[0][j]=2;             /* Membuat matrix tembok dengan kode 2 pada peta */
      matrix[j][0]=2;                                                                 
    }                                                                           
  }                                                                          
  printf("\nMatrix : \n"); 

  matrix[1][8]=1;                 /* Meletakan posisi robot awal (0,0) */
  
  for(i=9;i>-1;i=i-1)                                                           
  {                                                                             
    for(j=9;j>-1;j=j-1)                                                      
    {                                                                           
      if (matrix[i][j]==1)        /* Program pembaca koordinat robot  */
      {
        koor_x=9-j-1 ;
        koor_y=i-1;             /* Melakukan transformasi agar ke titik cartesius  */
      }                                        
    }                                                                                                                                          
  }       
  printf("koordinat-x: %d\n", koor_x);
  printf("koordinat-y: %d\n", koor_y);                    


  srand(time(0));    
  lower = 0;
  upper = 7;
  x = (rand() % (upper - lower + 1)) + lower;       /* Menginisiasikan bunshin mecha kurama */
  y = (rand() % (upper - lower + 1)) + lower;                       
  printf("koordinat x mecha :%d\n", x);
  printf("koordinat y mecha :%d\n", y);
  if (x==0)
  {
    if (y==0)
    {
      y = (rand() % (upper - lower + 1)) + lower;
      printf("koordinat x mecha :%d ", x);
      printf("koordinat y mecha %d\n", y);
    } 
  }
  
  matrix[y+1][8-x]=3;
  
  for(i=9;i>-1;i=i-1)                                                           
  {                                                                             
    for(j=9;j>-1;j=j-1)                                                      
    {                                                                           
      printf("%d\t", matrix[i][j]);                                    
    }                                                                           
    printf("\n");                                   /* Membuat peta */                            
  } 
  
  int inputUser, check;
  printf("Type 0 for attack or 1 to move: ");
  scanf("%d", &inputUser);
  if(inputUser == 0)
  {
    printf("Making desicion to attack"); 
  }
  else if (inputUser ==1)
  {
    printf("Making desicion to move");
  }
  else{
    check = 0;
    while (check == 0)
    {
      printf("Wrong input please try again");
      printf("Type 0 for attack or 1 to move: ");
      scanf("%d", &inputUser);
      if (inputUser == 0 )
      {
        check = 1;
        printf("Making desicion to attack"); 
      }
      else if (inputUser == 1)
      {
        check = 1;
        printf("Making desicion to move");
      }
      else
      {
        check = 0;
      }     
    }
  }
  return 0;
}