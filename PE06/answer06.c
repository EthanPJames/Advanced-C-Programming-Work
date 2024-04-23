//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "answer06.h"
#include <limits.h>
//Start of the static of static functions
static int is_floor_length_valid(int length, FILE *fp)
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
    if (length != one)
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

static int are_coordinates_valid(int row, int column, FILE *fp) ////???? How do I know where the fiel index is?
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
    if(row != x)
    {
        return(0);
    }
    if(column != y)
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
//?????How do I do this check for this code?????????
///????What is actually contained in the input file??? IS it just the valid tiling solutions???
static int is_file_size_valid(FILE *fp)
{
    int count1 = 0;
    int count2 = 0;
    int c = fgetc(fp);
    int n; //Value of floor length
    fseek(fp, 0, SEEK_SET);
    fscanf(fp, "%d", &n);
    
   while((c != EOF)) ///IS there something wrong with this statement
   {
        if(c == '\n')
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
static int is_floor_content_valid(FILE *fp)
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
    if((count1) != (n+2))
    {
        return(0);
    }
   
   
    if((row != x) && (col != y))
    {
        
        return(0);
    }

    return(1);
   
    

    
    

}



//End of all the static fnction
//To use othe rfunctions call it static in front of the fucntion and then you can use it

//Allocating 2D arryay Function
char **allocate_2d_array(int n)
{
    
    char **array =  malloc(sizeof(*array) * (n)); //Array 0 - 7 ( base array) Arrar of arrays
    if(array == NULL)
    {
        free(array);
    }
    int i = 0;
    //int j = 0;
    //int x = 0;

    for(i = 0; i < n; i++)
    {
        array[i] = malloc(sizeof(*array[i]) * (n));  
        if(array[i] == NULL)
        {
            free(array[i]);
        }
        

    }
    
    
    
    
    /*for(j = 0; j < n; j++)
    {
        for(x = 0; x < n; x++)
        {
            array[j][x] = '0';
        }
         
    }*/
    
    return(array); 
}



//Freed 2D array Function
void free_2d_array(char **array, int n)
{
    int i = 0;
    

    for(i = 0; i < n; i++) 
    {
        free(array[i]);
    }
    

    free(array);
////???Did I free the array correctly
}



 


//Tiling solution function, similar to PE05
int determine_tiling_solution_category(char *filename, tiling_solution *ts)
{
    
    
    
    FILE *fp = fopen(filename, "r");
    int sub1 = is_floor_length_valid(ts->floor_length,fp);
    int sub2 = are_coordinates_valid(ts->row, ts->column, fp); //Check this function
    int sub3 = is_file_size_valid(fp);
    int sub4 = is_floor_content_valid(fp);
    
    
    

    //This should return error code "1"
    if(fp == NULL)
    {
        fclose(fp);
        return(INVALID_FILENAME);

    }
    //This should return error code "2"
    if(sub1 == 0)
    {
        fclose(fp);
        return(INVALID_FLOOR_LENGTH);
    }
    //This should return error code "3"
    if(sub2 == 0)
    {
        fclose(fp);
        return(INVALID_COORDINATES);
    }
    //THis hsould return error code"4"
    if(sub3 == 0)
    {
        fclose(fp);
        return(INVALID_FILE_SIZE);
    }
    //This hsould return error code "5"
   
    if((allocate_2d_array(ts->floor_length)) == NULL)
    {
        fclose(fp);
        return(INSUFFICIENT_MEMORY);
    }
    //This should return error code "6"
    //Writitng to two dimensional array
    int a = 0;
    int b = 0;
    fseek(fp, 7, SEEK_SET);
    for(a = 0; a < ts->floor_length; a++)
    {
        for(b = 0; b < ts->floor_length; b++)
        {
            ts->floor_content[a][b] = fgetc(fp);
        }
        fseek(fp, 1, SEEK_CUR);
    }
    //End of writing to two dimensional array
    //Position of file from with contnets of floor plan
    if(sub4 == 0)
    {
        fclose(fp);
        return(INVALID_FLOOR_CONTENT);
    }

    //Input tiling solution checker????Check for invalid floor content
    //Do i need a seek set to begin at the beginning or am I good??????????
    for(int row = 0; row < ts->floor_length; row++)
    {
        for(int col = 0; col < ts->floor_length; col++)
        {
            if(ts->floor_content[row][col] == '0')
            {
                if((row + 1) < ts->floor_length && (col - 1) >= 0) //ANywher + 1 should be less than fl and -1 should be greateer than or equal to 0
                {
                    if((ts->floor_content[row + 1][col] == '0') && (ts->floor_content[row + 1][col -1] == '0'))
                    {
                        ts->floor_content[row + 1][col] = 'a';
                        ts->floor_content[row + 1][col - 1] = 'a';
                        ts->floor_content[row][col] = 'a';

                    }
                    else
                    {
                        return(INVALID_FLOOR_CONTENT);
                    }
                }
                else
                {
                    return(INVALID_FLOOR_CONTENT);
                }
            }
            else if(ts->floor_content[row][col] == '1')
            {
                if((row + 1) < ts->floor_length && (col + 1) < ts->floor_length) //ANywher + 1 should be less than fl and -1 should be greateer than or equal to 0
                {
                    if((ts->floor_content[row + 1][col] == '1') && (ts->floor_content[row + 1][col +1] == '1'))
                    {
                        ts->floor_content[row + 1][col] = 'b';
                        ts->floor_content[row + 1][col + 1] = 'b';
                        ts->floor_content[row][col] = 'b';

                    }
                    else
                    {
                        return(INVALID_FLOOR_CONTENT);
                    }
                }
                else
                {
                    return(INVALID_FLOOR_CONTENT);
                }

            }
            else if(ts->floor_content[row][col] == '2')
            {
                if((row + 1) < ts->floor_length && (col + 1) < ts->floor_length) //ANywher + 1 should be less than fl and -1 should be greateer than or equal to 0
                {
                    if((ts->floor_content[row][col + 1] == '2') && (ts->floor_content[row + 1][col + 1] == '2'))
                    {
                        ts->floor_content[row][col + 1] = 'c';
                        ts->floor_content[row + 1][col + 1] = 'c';
                        ts->floor_content[row][col] = 'c';

                    }
                    else
                    {
                        return(INVALID_FLOOR_CONTENT);
                    }
                }
                else
                {
                    return(INVALID_FLOOR_CONTENT);
                }

            }
            else if(ts->floor_content[row][col] == '3')
            {
                if((row + 1) < ts->floor_length && (col + 1) < ts->floor_length) //ANywher + 1 should be less than fl and -1 should be greateer than or equal to 0
                {
                    if((ts->floor_content[row + 1][col] == '3') && (ts->floor_content[row][col +1] == '3'))
                    {
                        ts->floor_content[row + 1][col] = 'd';
                        ts->floor_content[row][col + 1] = 'd';
                        ts->floor_content[row][col] = 'd';

                    }
                    else
                    {
                        return(INVALID_FLOOR_CONTENT);
                    }
                }
                else
                {
                    return(INVALID_FLOOR_CONTENT);
                }

            }
            
        }
    }
    for(int row = 0; row < ts->floor_length; row++)
    {
        for(int col = 0; col < ts->floor_length; col++)
        {
            if(ts->floor_content[row][col] == 'a')
            {
                ts->floor_content[row][col] = '0';
            }
            if(ts->floor_content[row][col] == 'b')
            {
                ts->floor_content[row][col] = '1';
            }
            if(ts->floor_content[row][col] == 'c')
            {
                ts->floor_content[row][col] = '2';
            }
            if(ts->floor_content[row][col] == 'd')
            {
                ts->floor_content[row][col] = '3';
            }
        }
    }

   
    fclose(fp);
    return(VALID_SOLUTION);
    
}


//Saving tiling solution function
int save_tiling_solution(char *filename, tiling_solution *ts)
{
    FILE *out = fopen(filename, "w");
    fseek(out, 0, SEEK_SET);

    int d = 0;
    int j = 0;

    if (out == NULL)
    {
        fclose(out);
        return(0);
    }
    fprintf(out, "%d",ts->floor_length);
    fputc('\n', out);
    fprintf(out, "%d",ts->row);
    fputc(',', out);
    fprintf(out, "%d",ts->column);
    fputc('\n', out);
    
    while(d < (ts->floor_length))
    {
        for(j = 0; j < (ts->floor_length); j++)
        {
            fputc(ts->floor_content[d][j], out);
        }
        if(ts->floor_length - 1 > d)
        {
            fputc('\n', out);
        }
        d = d + 1;

    }

    
    return(1);

    

}