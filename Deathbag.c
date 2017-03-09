#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>




int main(int argc, char* argv[])
{
  
    
    if( (argc != 2 && argc != 3)  )
    {
        puts("usage: ./deathbag        *number of deaths*           *optional number of people dead* \n ");
        return 1;
    }
     srand(time(NULL)); 
   
    
    int deaths = atoi(argv[1]);
   
    
    deaths += 9;
    
    if (deaths > 30)
    {
        puts("i'm just gonna pull 30 stones");
        deaths = 30;
        sleep(2);
    }
    
    int people = 0;
    int pd = 0;
    int level = 0;
    int forgot = 0;
    int devine = 0;
    
    if (argc == 3)
    {
    people = atoi(argv[2]);
    
    }
    else
    people++;
    
 
    
 for (int q = 0; q < people; q++)   
 {
    int black_stones = 3;
    int red_stones = 10;
    int white_stones = 20;


    for (int i = 0; i < deaths; i++)
    {
        
        int stones = (black_stones + red_stones + white_stones );
        
        int j = rand() %stones;
        if(stones == j){
        printf("yes");
        }

        
        if (j <  white_stones)
        {
            white_stones--;
        }
        else if(j < (white_stones + red_stones))
        {
            red_stones--;
        }
        else if(j< white_stones + red_stones + black_stones)
        {
            black_stones--;
        }
        else {
            return 2;
        }
    }
    
    if (((black_stones + red_stones + white_stones) == 24))
    {
        
         puts("usage: ./deathbag        *number of deaths(integer)*         *optional: number of people(integer)* \n ");
        return 3;
    }
  
   
        
    if (people == 1)
    printf("blackstones: %i \nredstones: %i \nwhitestones: %i \n", 3 - black_stones, 10 - red_stones, 20 - white_stones);
    
    else
    {
        if (black_stones == 0)
        {
            pd++;
            
            if (red_stones < 10)
            devine++;
        }
        
        else if (black_stones == 1)
        level++;
        
        else if(black_stones ==2)
        forgot++;
    
        
    }
     
  
}

if (people > 1)
{
    printf("%i forgot how they died\n%i lost a level\n%i PD'd\n%i got devine intervention\n%i PD'd for real\n", forgot, level, pd, devine, pd - devine);
}

return 0;
}
