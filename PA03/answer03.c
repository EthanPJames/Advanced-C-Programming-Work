//Macros
#include "answer03.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

/*static int is_floor_length_valid(int, FILE *)
                __attribute__((nonnull (1)));

static int are_coordinates_valid(int, int, FILE *)
                __attribute__((nonnull (1)));

static int is_file_size_valid(FILE *fp)
                __attribute__((nonnull (1)));

static int is_floor_content_valid(FILE *fp)
                __attribute__((nonnull (1)));
static void array_fill(int, tiling_solution *);*/

//Input static functionshere below
//STATIC FUNCTION
//STATIC FUNCTION
//STATIC FUNCTION
//STATIC FUNCTION
//STATIC FUNCTION
//STATIC FUNCTION
//STATIC FUNCTION
//STATIC FUNCTION


static int is_floor_length_valid(int length, FILE *fp)
{
    int one; //First value scan in
    char two; //Second value or essentially should be the new line character?????
    char white; //Scan in new line
    int multiplier = 1; //Start at one
    
    fseek(fp, 0l, SEEK_SET);
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
        //printf("enter while loop \n");
        if(c == '\n')
        {
            //printf("if C is a end of line \n\n");
            count1 = count1 + 1;
        }
        if (count1 >= 2)
        {
            //printf("Number of rows for the coordinates\n\n");
            count2 = (count2 + 1);
        }
        c = fgetc(fp);
   }
   
    count2 = count2 - 1; //Accounts for the extra new line symbol in count
    int math1 = n * (n + 1); //Number of characters
    int math2 = n + 2; //Number of new lines

    


    if((count2 == math1) && (count1 == math2))
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
    fscanf(fp, "%d", &x); //Scanning in x coordinate
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
            col = col - 1; //???Why do i move column move 
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








char **allocate_2d_array(int n)
{
    char **array =  malloc(sizeof(*array) * (n)); //Array 0 - 7 ( base array) Arrar of arrays
    if(array == NULL)
    {
        return(NULL);
    }
    int i = 0;

    for(i = 0; i < n; i++)
    {
        array[i] = malloc(sizeof(*array[i]) * (n));  
        if(array[i] == NULL)
        {
            free_2d_array(array, i-1); //Checl with KOH?????????????????
            return(NULL);
        }
        

    }

    return(array); 
    

}

void free_2d_array(char **array, int n)
{
    int i = 0;
    for(i = 0; i < n; i++) 
    {
        free(array[i]);
    }
    free(array);

}

int determine_tiling_solution_category(char *filename, tiling_solution *ts)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
    {
        
        return(INVALID_FILENAME);

    }
    
    int sub1 = is_floor_length_valid(ts->floor_length,fp);
    //printf("FLOOR LENGTH VALID\n");
    int sub2 = are_coordinates_valid(ts->row, ts->column, fp); //Check this function
    //printf("Coordinates Valid\n");
    int sub3 = is_file_size_valid(fp);
    //printf("File size valid \n");
    int sub4 = is_floor_content_valid(fp);
    //printf("Floor_content valid \n");
    
    
    

    //This should return error code "1"
    
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
   
    if((ts->floor_content) == NULL)
    {
        fclose(fp);
        return(INSUFFICIENT_MEMORY);
    }
    //This should return error code "6"
    //Writitng to two dimensional array
    int a = 0;
    int b = 0;
    fseek(fp, 7, SEEK_SET);
    //Why is this being allocated here???????????????????
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
                        fclose(fp);
                        return(INVALID_FLOOR_CONTENT);
                    }
                }
                else
                {   //Possible free
                    fclose(fp);
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
                        fclose(fp);
                        return(INVALID_FLOOR_CONTENT);
                    }
                }
                else
                {
                    fclose(fp);
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
                        fclose(fp);
                        return(INVALID_FLOOR_CONTENT);
                    }
                }
                else
                {
                    fclose(fp);
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
                        fclose(fp);
                        return(INVALID_FLOOR_CONTENT);
                    }
                }
                else
                {
                    fclose(fp);
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
        fputc('\n', out); //Adds the new line character one line after
        d = d + 1;

    }
    fclose(out);
    return(1);

}


static void fill(int length, int row, int column, char **floor_content , int or, int oc)
{
    if(length == 2)
    {
        
        if((row == or) && (column == oc + 1))
        {
            floor_content[or][oc] = '1';
            floor_content[or+1][oc] = '1';
            floor_content[or+1][oc+1] = '1';
        }
        if((row == or) && (column == oc))
        {
            floor_content[or][oc+1] = '0';
            floor_content[or+1][oc+1] = '0';
            floor_content[or+1][oc] = '0';
        }
        if((row == or + 1) && (column == oc))
        {
            floor_content[or][oc] = '2';
            floor_content[or][oc+1] = '2';
            floor_content[or+1][oc+1] = '2';
        }
        if((row == or + 1) && (column == oc + 1))
        {
            //printf("\n\nENTER FOURTH QUADRANT\n\n");
            
            floor_content[or][oc] = '3';
            floor_content[or][oc+1] = '3';
            floor_content[or+1][oc] = '3';
        }
        //printf("Or : %d\n", or);
        //printf("Oc : %d\n", oc);

        return;
    }
    char fill_tile; //Tiling solution place
    int length_update = length / 2;

    //quadrant 2
    if((row < length_update + or) && (column < length_update + oc))
    {
        fill_tile = '0';
        fill(length_update, or + length_update - 1,  oc + length_update, floor_content, or, length_update + oc); //Should these two last parameters be 0,0
        fill(length_update, row , column, floor_content, or , oc );
        fill(length_update, or + length_update, oc+ length_update - 1, floor_content, or + length_update, oc);
        fill(length_update, or + length_update, oc + length_update, floor_content, or + length_update, oc + length_update);


    }
    //quadrant 1
    if((row < length_update + or) && (column >= length_update + oc))
    {
        fill_tile = '1';
        fill(length_update, row,  column, floor_content, or, oc + length_update); //Should these two last parameters be 0,0
        fill(length_update, or + length_update - 1 , oc + length_update - 1, floor_content, or , oc );
        fill(length_update, or + length_update, oc+ length_update - 1, floor_content, or + length_update, oc);
        fill(length_update, or + length_update, oc + length_update, floor_content, or + length_update, oc + length_update);
    }
    //quadrant 3
    if((row >= length_update + or) && (column < length_update + oc))
    {
        fill_tile = '2';
        fill(length_update, or + length_update - 1,  oc + length_update, floor_content, or, length_update + oc);
        fill(length_update, or + length_update - 1 , oc + length_update - 1, floor_content, or , oc );
        fill(length_update, row, column, floor_content, or + length_update, oc);
        fill(length_update, or + length_update, oc + length_update, floor_content, or + length_update, oc + length_update);
        

    }
    //quadrant 4
    if((row >= length_update + or) && (column >= length_update + oc))
    {
        fill_tile = '3';
        fill(length_update, or + length_update - 1,  oc + length_update, floor_content, or, length_update + oc);
        fill(length_update, or + length_update - 1 , oc + length_update - 1, floor_content, or , oc );
        fill(length_update, or + length_update, oc+ length_update - 1, floor_content, or + length_update, oc);
        fill(length_update, row, column, floor_content, or + length_update, oc + length_update);
      

    }
    if(fill_tile == '1')
    {
        floor_content[or + length_update - 1][oc + length_update-1] = '1';
        floor_content[or + length_update][oc + length_update-1] = '1';
        floor_content[or + length_update][oc + length_update] = '1';
    }
    if(fill_tile == '2')
    {
        floor_content[or + length_update -1][oc + length_update - 1] = '2';
        floor_content[or + length_update -1][oc + length_update] = '2';
        floor_content[or + length_update][oc + length_update] = '2';
        
    }
    if(fill_tile == '3')
    {
        floor_content[or + length_update -1][oc + length_update - 1] = '3';
        floor_content[or + length_update][oc + length_update -1] = '3';
        floor_content[or + length_update -1][oc + length_update] = '3';

    }
    if(fill_tile == '0')
    {
        floor_content[or + length_update -1][oc + length_update] = '0';
        floor_content[or + length_update][oc + length_update - 1] = '0';
        floor_content[or + length_update][oc + length_update] = '0';

    }



        

    

}

void generate_tiling_solution(tiling_solution *ts)
{
    

    
    if(ts->floor_length == 1)
    {
        ts->floor_content[ts->row][ts->column] = '4';
        return;

    }
    
    //Place 4 tile
    ts->floor_content[ts->row][ts->column] = '4';

    int length = ts->floor_length;
    int row = ts->row;
    int column = ts->column;

    fill(length, row, column, ts->floor_content, 0, 0 );
    
   
   
    
    
    
}










    
    


   





    






