#include <stdio.h>
#include <stdint.h>

#define EACH_BUFFER_SIZE 1536
int main(int argc,const char **argv){
  FILE *fp;
  uint8_t filebuff[EACH_BUFFER_SIZE*2];
  uint8_t separated_audio[EACH_BUFFER_SIZE][2];
  
  if(argc != 2){
    fprintf(stderr,"usage: <program> <raw auido file>\n");
    return -1;
  }
  
  fp = fopen(argv[1],"r");
  while(fread(filebuff,2,EACH_BUFFER_SIZE,fp)){
    {
      int i;
      for(i=0;i<EACH_BUFFER_SIZE;i++){
	separated_audio[i][0] = filebuff[i*2];
	separated_audio[i][1] = filebuff[i*2+1];
      }
    }
    {
      int i;
      for(i=0;i<EACH_BUFFER_SIZE;i++){
	printf("%c",separated_audio[i][0]);
      }
    }
    {
      int i;
      for(i=0;i<EACH_BUFFER_SIZE;i++){
	printf("%c",separated_audio[i][1]);
      }
    }
  }
  return 0;
}
