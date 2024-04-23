#include "answer05.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include <limits.h>
#include <errno.h>








int is_floor_length_valid(FILE *fp)
{
    int one; //First value scan in
    char two; //Second value or essentially should be the new line character?????
    char white; //Scan in new line
    int multiplier = 1; //Start at one
    

    fscanf(fp, "%d", &one);
    fscanf(fp, "%c", &two); //????IS this the new line character????
    fseek(fp, 0, SEEK_SET);
    fscanf(fp,"%c", &white);

    if(isspace(white))
    {
        return(0);
    }
    if(white == '0') 
    {
        return(0);
    }
    if(two == '\n')
    {
        while (one > multiplier)
        {
            multiplier = multiplier * 2;
            if(one == multiplier)
            {
                return(1);
            }
            
        }
        return(0);
    }
    else
    {
        return(0);
    }
   
        
}

//Start of if coordinates are valid function

int are_coordinates_valid(FILE *fp) ////???? How do I know where the fiel index is?
{
    
     int one; //First value scan in
     int x; //x coordinate
     int y; //y coordinate
     char comma; //Comma value
     char w1; //White space checker before x
     char w2; //Whit space checker before ','
     char new; //New line

     
     fseek(fp, 0, SEEK_SET);
     fscanf(fp, "%d", &one); //Getting floor length
     
     fseek(fp, 1, SEEK_CUR); //Beginning of coordinates 
     fscanf(fp, "%c", &w1);
     if(isspace(w1) != 0)
    {
        
        return(0);
    }
    if(w1 == '0') 
    {
        return(0);
    }

     fseek(fp, -1, SEEK_CUR);
     fscanf(fp, "%d", &x);

     fscanf(fp, "%c", &comma);
     if (comma != ',')
     {
        return(0);
     }
     fscanf(fp, "%c", &w2);
     if(isspace(w2) != 0)
    {
        return(0);
    }
    if(w2 == '0') 
    {
        return(0);
    }

    fseek(fp, -1, SEEK_CUR);
    fscanf(fp, "%d", &y);
    
    fscanf(fp, "%c", &new);
    if ( x > one)
    {
        
        return(0);
    }
    if (y > one)
    {
        
        return(0);
    }
     if (new == '\n')
    {
        return(1);
    }
    else
    {
        return(0);
    }
    
    


   

} 



    



//START OF file size function
int is_file_size_valid(FILE *fp)
{
    int count1 = 0;
    int count2 = 0;
    int c;
    int n; //Value of floor length
    fseek(fp, 0, SEEK_SET);
    fscanf(fp, "%d", &n);
    
    

    
   while ((c = fgetc(fp)) != EOF) 
   {
  
    if (c == '\n') 
    {
         count1 = count1 + 1;
    }
    
      if (count1 >= 2)
    {
        count2 = (count2 + 1);
    }
   
   }
    count2 = count2 - 1; //Accounts for the extra new line symbol in count
    int math1 = n * (n + 1); //Number of characters
    int math2 = n + 2; //Number of new lines

    if((count2 = math1) && (count1 = math2))
    {
        return(1);
    }
    else
    {
        return(0);
    }

}


//Check for repeating 4's
int is_floor_content_valid(FILE *fp)
{
    int n;
    int x;
    int y;
    int count1 = 1;
    int count2 = 0;
    char c; 
    int row = 0;
    int col = 0;
    fseek(fp, 0, SEEK_SET);
    fscanf(fp, "%d", &n); //Getting floor length
    fseek(fp, +1, SEEK_CUR); //Beginning of coordinates 
    fscanf(fp, "%d", &x); //Scanning in f coordinate
    fseek(fp, +1, SEEK_CUR ); //Change to seek cur
    fscanf(fp, "%d", &y); //Getting y value
    int four_count = 0;

     while ((c = fgetc(fp)) != EOF)
     {
        col = col + 1;
       
    
        if (count1 >= 2)
        {
            
            count2 = (count2 + 1);
            if((c != '0') && (c != '1') && (c != '2') && (c != '3') && (c != '4') && (c != '\n'))
            {
                
                return(0);
            }
    
        }

        if (c == '\n') 
        {
            col = 0;
            count1 = count1 + 1;
            
         
        }
        if (c == '4')
        {
            row = count1 - 2;
            col = col - 1;
            four_count = four_count + 1;
        }
    
    }
       
    if (four_count > 1)
    {
        return(0);
    }
   if((count1) != (n + 2) ) //Any issues here???????????????????????
   {
    
    return(0);
   }
   
    if((row != x) && (col != y))
    {
        
        return(0);
    }

    return(1);
   
    

    
    

}



//START OF TILING SOLUTION CATGORY FUNCTION
int determine_tiling_solution_category(char *filename)
{
    FILE *fp = fopen(filename, "r");
    int sub1 = is_floor_length_valid(fp);
    int sub2 = are_coordinates_valid(fp);
    int sub3 = is_file_size_valid(fp);
    int sub4 = is_floor_content_valid(fp);

   
    if(fp == NULL)
    {
        fclose(fp);
        return(INVALID_FILENAME);
    }
    if(sub1 == 0)
    {
        fclose(fp);
        return(INVALID_FLOOR_LENGTH);
    }
    if(sub2 == 0)
    {
        fclose(fp);
        return(INVALID_COORDINATES);
    }
    if(sub3 == 0)
    {
        fclose(fp);
        return(INVALID_FILE_SIZE);
    }
    if(sub4 == 0)
    {
        fclose(fp);
        return(INVALID_FLOOR_CONTENT);
    }

    fclose(fp);
    return(VALID_SOLUTION);
    
}


