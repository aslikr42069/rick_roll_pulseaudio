#include <pulse/simple.h>
#include <pulse/error.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h> 

#define BUFFER_SIZE 44100 /* Size of the array for the provided audio spec for half a second of audio*/
#define TAU (2 * M_PI) /* An important note is that because each sample represents half a second of audio
                          we will need to do something along the lines of sinf((TAU * FREQUENCY * i) / 88200)
                          where i is the loop index*/

int playFrequency(pa_simple * s, pa_sample_spec *ss, int * error, float frequency){
 float buffer[BUFFER_SIZE];
 for(uint32_t i = 0; i < BUFFER_SIZE; i += 1.0){
  buffer[i] = sinf((TAU * frequency * (float)i) / 88200);
 }
 
  if(pa_simple_write(s, buffer, pa_bytes_per_second(ss)/2, error) < 0){
  printf("pa_simple_write() failed: %s\n", pa_strerror(*error));
  return -1;
 }
 return 0;
}

int playFiveFrequencies(pa_simple * s, pa_sample_spec *ss, int * error, float f1, float f2, float f3, float f4, float f5){
 float buffer[BUFFER_SIZE];
 float buffer1[BUFFER_SIZE];
 float buffer2[BUFFER_SIZE];
 float buffer3[BUFFER_SIZE];
 float buffer4[BUFFER_SIZE];
 float buffer5[BUFFER_SIZE];

 for(uint32_t i = 0; i < BUFFER_SIZE; i += 1.0){
  buffer1[i] = sinf((TAU * f1 * (float)i) / 88200);
 }
 
 for(uint32_t i = 0; i < BUFFER_SIZE; i += 1.0){
  buffer2[i] = sinf((TAU * f2 * (float)i) / 88200);
 }
  
 for(uint32_t i = 0; i < BUFFER_SIZE; i += 1.0){
  buffer3[i] = sinf((TAU * f3 * (float)i) / 88200);
 }

 for(uint32_t i = 0; i < BUFFER_SIZE; i += 1.0){
  buffer4[i] = sinf((TAU * f4 * (float)i) / 88200);
 }
  
 for(uint32_t i = 0; i < BUFFER_SIZE; i += 1.0){
  buffer5[i] = sinf((TAU * f5 * (float)i) / 88200);
 }

 for(uint32_t i = 0; i < BUFFER_SIZE; i += 1){
  buffer[i] = (buffer1[i] + buffer2[i] + buffer3[i] + buffer4[i] + buffer5[i]) / 5.0;
 }
 
  if(pa_simple_write(s, buffer, pa_bytes_per_second(ss)/2, error) < 0){
  printf("pa_simple_write() failed: %s\n", pa_strerror(*error));
  return -1;
 }
 return 0;
}


int main(){
 /* The format for sound samples */
 pa_sample_spec ss = {
  .format   = PA_SAMPLE_FLOAT32LE,
  .rate     = 44100,
  .channels = 2
 };
 
 pa_simple *s = NULL;
 int error;
 if(!(s = pa_simple_new(NULL, "Rick Roll", PA_STREAM_PLAYBACK, NULL, "You're getting Rick Rolled lol", &ss, NULL, NULL, &error))){
  printf("pa_simple_new() failed: %s\n", pa_strerror(error)); // If there is any error in starting the audio stream, it will be detected here
  return -1;
 }

 if(playFrequency(s, &ss, &error, 261.626) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 293.66) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 349.23) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 293.66) < 0){
  return -1;
 }

 if(playFiveFrequencies(s, &ss, &error, 293.66, 349.23, 440.0, 61.74, 123.47) < 0){
  return -1;
 }

 if(playFrequency(s, &ss, &error, 0) < 0){
  return -1;
 }

 if(playFiveFrequencies(s, &ss, &error, 293.66, 349.23, 440.0, 61.74, 123.47) < 0){
  return -1;
 }

 if(playFiveFrequencies(s, &ss, &error, 293.66, 349.23, 440.0, 61.74, 123.47) < 0){
  return -1;
 }

 if(playFiveFrequencies(s, &ss, &error, 261.63, 329.63, 392.0, 65.41, 130.81) < 0){
  return -1;
 }

 if(playFiveFrequencies(s, &ss, &error, 261.63, 329.63, 392.0, 65.41, 130.81) < 0){
  return -1;
 }

 if(playFrequency(s, &ss, &error, 261.626) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 293.66) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 349.23) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 293.66) < 0){
  return -1;
 }
 if(playFiveFrequencies(s, &ss, &error, 261.63, 329.63, 392.0, 65.41, 130.81) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 0.0) < 0){
  return -1;
 }
 if(playFiveFrequencies(s, &ss, &error, 261.63, 329.63, 392.0, 65.41, 130.81) < 0){
  return -1;
 }
 if(playFiveFrequencies(s, &ss, &error, 261.63, 329.63, 392.0, 65.41, 130.81) < 0){
  return -1;
 }
 if(playFiveFrequencies(s, &ss, &error, 220.00, 293.66, 349.23, 73.42, 146.83) < 0){
  return -1;
 }
 if(playFiveFrequencies(s, &ss, &error, 220.00, 293.66, 349.23, 73.42, 146.83) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 329.63) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 293.66) < 0){
  return -1;
 }

 if(playFrequency(s, &ss, &error, 261.626) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 293.66) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 349.23) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 293.66) < 0){
  return -1;
 }
 if(playFiveFrequencies(s, &ss, &error, 245.94, 293.66, 329.63, 49.00, 98.00) < 0){
  return -1;
 }
 if(playFrequency(s, &ss, &error, 392.00) < 0){
  return -1;
 }
 if(playFiveFrequencies(s, &ss, &error, 261.63, 329.63, 65.41, 130.81, 00.00) < 0){
  return -1;
 }






 if(pa_simple_drain(s, &error) < 0){
  printf("pa_simple_drain failed: %s\n", pa_strerror(error));
  return -1;
 }
 pa_simple_free(s);
}
