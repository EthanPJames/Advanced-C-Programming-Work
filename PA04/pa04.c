#include <stdlib.h>
#include <stdio.h>
#include "answer04.h"

int main(int argc, char **argv)
{
  BMP_image *image_data; //variables for BMP iamge structure
  
  if(argc != 3)
  {
    return(EXIT_FAILURE);
  }

  image_data = read_BMP_image(argv[1]);
  if (image_data == NULL)
  {
    return(EXIT_FAILURE);
  }

  BMP_image *new_image; //???? DO i need to malloc this if I do it this way?????????

  if(image_data->header.bits == 24)
  {
    new_image = convert_24_to_16_BMP_image_with_dithering(image_data);
    
  }
  else
  {
    new_image = convert_16_to_24_BMP_image(image_data);
  }
  
  if(new_image == NULL)
  {
    //Would i need to free this still
    free_BMP_image(new_image); //Freeing new image
    free_BMP_image(image_data); //Freeing the old image
    return(EXIT_FAILURE);
  }

  int write_success = write_BMP_image(argv[2], new_image);
  if(write_success != 1)
  {
    ////???Would I free these two here
    free_BMP_image(image_data); //Freeing the old image
    free_BMP_image(new_image); //Freeing the new image
    return(EXIT_FAILURE);
  }
  
  free_BMP_image(image_data); //Freeing the old image
  free_BMP_image(new_image); //Freeing the new image

  return(EXIT_SUCCESS); 
}