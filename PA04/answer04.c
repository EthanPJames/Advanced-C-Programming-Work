#include <stdlib.h>
#include <stdio.h>
#include "answer04.h"

//Macros
#define BMP_TYPE 0x4d42
#define BMP_HEADER_SIZE 54
#define DIB_HEADER_SIZE 40

//Read image function
BMP_image *read_BMP_image(char *filename)
{
  FILE *open = fopen(filename, "r"); // Is this the right data type???????????????
  if(open == NULL)
  {
    return(NULL);
    
  }
  BMP_image *my_image = malloc(sizeof(*my_image)); //?? Did I malloc this correctly? mall 
  
  if(my_image == NULL)
  {
    
    fclose(open);
    return(NULL);
  }
  //Is followng fread correct ???????????????????????????????????????? check sizeof
  fseek(open, 0l, SEEK_SET);
  if(fread(&(my_image->header), sizeof(my_image->header), 1 , open) != 1) //???? IS the one correct, Is this format correct???
  {
   
    fclose(open);
    free(my_image);
    return(NULL);
  }
   int valid_header = is_BMP_header_valid(&my_image->header, open); //???What do i put as parameters
  if(valid_header == 0)
  {
    
    fclose(open);
    free(my_image); 
    return(NULL);
    
  }
  fseek(open, 54l, SEEK_SET);
  my_image->data = calloc(my_image->header.imagesize, sizeof(*(my_image->data))); //Allocate space for image data???????????????????????
  if(my_image->data == NULL)
  {
    
    fclose(open);
    free(my_image);
    return(NULL);
  }
  //Is the following correct???????????????????????????????
  if(fread((my_image->data), sizeof(*(my_image->data)), my_image->header.imagesize, open) != my_image->header.imagesize)
  {
    
    fclose(open);
    free(my_image);
    free(my_image->data); 
    return(NULL);
    
  }
  //Sub function below called to check for valid header
 
  ///Would i free anything here????
  fclose(open); 
  return(my_image);


} 

//Is file header valid
int is_BMP_header_valid(BMP_header* header, FILE *fptr) {
  // Make sure this is a BMP file
  if (header->type != BMP_TYPE) {
     return 0;
  }
  // skip the two unused reserved fields
  

  // check the offset from beginning of file to image data
  // essentially the size of the BMP header
  // BMP_HEADER_SIZE for this exercise/assignment
  if (header->offset != BMP_HEADER_SIZE) {
     return 0;
  }
      
  // check the DIB header size == DIB_HEADER_SIZE
  // For this exercise/assignment
  if (header->DIB_header_size != DIB_HEADER_SIZE) {
     return 0;
  }

  // Make sure there is only one image plane
  if (header->planes != 1) {
    return 0;
  }
  // Make sure there is no compression
  if (header->compression != 0) {
    return 0;
  }

  // skip the test for xresolution, yresolution

  // ncolours and importantcolours should be 0
  if (header->ncolours != 0) {
    return 0;
  }
  if (header->importantcolours != 0) {
    return 0;
  }
  
  // Make sure we are getting 24 bits per pixel
  // or 16 bits per pixel
  if (header->bits != 24 && header->bits != 16) {
    return 0;
  }

  // fill in code to check for file size, image size
  // based on bits, width, and height
  //What I have added(Ethan James)
  
  
  
  int byte_total;
  
  if(header->bits == 24)
  {
    
    int math_24bit1 = ((header->width * 3 * 8) + 31); //First part of eqution
    int math_24bit2 = ((math_24bit1 / 32) * 4);//Second part of equation 
    byte_total = math_24bit2 * header->height; //Total amountof bytes
    if(header->imagesize != byte_total)
    {
      return(0);
    }
  }
 
  
  if(header->bits == 16)
  {
   
    int math_16bit1 = ((header->width * 2 * 8) + 31); //First part of equation
    int math_16bit2 = ((math_16bit1 / 32) * 4); //Second part of equation
    byte_total = math_16bit2 * header->height; //Total amount of bytes
    if(header->imagesize != byte_total)
    {
      
      return(0);
    }
  }
  //Check file size
  fseek(fptr, 0l, SEEK_END); //Make sure file is at the end
  //Would this check filesize????????
  if(ftell(fptr) != header->size)
  {
    
    return(0);
  }
  
  return 1;
}


//Write image
int write_BMP_image(char *filename, BMP_image *image)
{
  FILE *open = fopen(filename, "w"); //Open the output file to write to
  if (open == NULL)
  {
    
    return(0);
  }
  
  //Check this fwrite, what is the parameters for the fwrite here
  fseek(open, 0l, SEEK_SET);
  if(fwrite(&(image->header), sizeof(image->header), 1 , open) != 1)
  {
    
    fclose(open);
    return(0);
  }
  if(fwrite(image->data, sizeof(*(image->data)) , image->header.imagesize, open) != image->header.imagesize) //??What goes in this fwrite statement???????????????????????????????????????????
  {
    
    fclose(open);
    return(0);

  }
  fclose(open);
  return(1);
}

//Free image function
void free_BMP_image(BMP_image *image)
{
  free(image->data);
  free(image);
}

//Convert 24 to 16
BMP_image *convert_24_to_16_BMP_image(BMP_image *image)
{
  
    BMP_image *new =  malloc(sizeof(*image));
    if(new == NULL)
    {
      
      return(NULL);
    }
    
    
    
    new->header = image->header; ////Set the old struct equal to the new struct
    
    new->header.bits = 16; //Number of bits changes
    int padding = 0;
    int pad_math = 0;
    pad_math = (image->header.width * 2) % 4; //Calculates amount of padding Should be times 2 TA CODE
    
    new->header.imagesize = ((2 * new->header.width) + pad_math) * new->header.height; 
  
    
    new->header.size = new->header.imagesize + sizeof(new->header);
    
    new->data = calloc((new->header.imagesize), sizeof(*(new->data)));
    
    
    if(new == NULL)
    {
        
      return(NULL);
    }

    padding = padding + ((image->header.width * 2) % 4);
    
   

    int byte0 = 0; //red
    int byte1 = 0; // green
    int byte2 = 0; // blue
   
    int control = 0;
    int control2 = 0;
    int bytes_row = image->header.imagesize / image->header.height;
    int br = new->header.imagesize / new->header.height;
    for(int i = 0; i < image->header.height; i++)
    {
      for(int j = 0; j < image->header.width; j++)
      {
        control = (i * bytes_row) + (j *3);
        control2 = (i * br) + (j * 2);
        byte0 = image->data[control] >> 3;
        byte1 = image->data[control + 1] >> 3;
        byte2 = image->data[control + 2] >> 3;
        int combination = (byte1 << 5) | (byte2 << 10) | (byte0);
        
        
        new->data[control2] = (unsigned char) combination;
        control2++;
        new->data[control2] = (unsigned char) (combination >> 8);
        
       

       
        
       

         
        
      
        
      }
    }
    
 
    
  return(new);
}

BMP_image *convert_16_to_24_BMP_image(BMP_image *image)
{
    BMP_image *new =  malloc(sizeof(*image));
    if(new == NULL)
    {
        return(NULL);
    }
    //Reading in padding check
    int storepad_old = ((image->header.width * image->header.height) % 2 ) * 2; //???Possible error
    int storepad_new = ((image->header.width * image->header.height) % 4 ); 
    
    

    new->header = image->header; ////Set the old struct equal to the new struct
    new->header.imagesize = (1.5 * image->header.imagesize) + (storepad_new * new->header.height);
    new->header.size = new->header.imagesize + 54; //Just for the file size
    new->header.bits = 24;

    new->data = calloc((new->header.imagesize), sizeof(*(new->data)));
    if(new == NULL)
    {
       
      
        return(NULL);
    }
    
    
    //Loop variables
    int control = 0; //While loop control
    int control2 = 0; //Control for alocating new array
    int red = 0; //red start value
    int blue = 0; //Blue start value
    int green = 0; //Green start value
    int byte0; //First byte size conversion
    int byte1; //Second byte size conversions
    int combo; //Concateneater byte 0 and byte 1
    int pixel = 0;

   
    while(control < image->header.imagesize)
    {
        

        if(pixel == image->header.width)
        {
          pixel = 0;
          control = control + storepad_old;
          control2 = control2 + storepad_new;
        }

        

        byte0 = image->data[control+1];
        byte1 = image->data[control];
        byte0 = byte0 << 8; //Shift byte 0 over 8

        combo = byte0 | byte1; //Basically adds them together, concatenates them

        red = combo >> 10; //shift red over 10
        red = red * 255/31;
        blue = (combo & 31);
        blue = blue * 255/31;
        green = (combo >> 5) & (31);
        green = green * 255/31;

        new->data[control2] = blue;
        control2 = control2 + 1;
        new ->data[control2] = green;
        control2 = control2 + 1;
        new->data[control2] = red;
        control2 = control2 + 1;

        control = control + 2;
        pixel = pixel + 1;
    }


  return(new);

}

BMP_image *convert_24_to_16_BMP_image_with_dithering(BMP_image *image)
{
  return(NULL);
  
  
}