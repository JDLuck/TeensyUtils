/*
 *	File:	ram.c
 *	Author: Jerrold Luck, Queensland University of Technology.
 *	Date:	10 May 2015.
 *
 *	Helpful RAM utility functions.
 */

#include "ram.h"

int estimate_alloc(int len){
	extern int __heap_start, *__brkval; 
	int v; 
	return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval) - len;
} 

int estimate_ram(void){
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

unsigned char* load_rom_bitmap(const unsigned char* source, int len){

	/* allocate memory */
	unsigned char* heap_alloc = (unsigned char*)malloc(len);
	
	/* check we have heap space allocated */
	if(heap_alloc == NULL)
		return NULL;

	/* copy bytes over */
	for(int i=0;i<len;i++)
		heap_alloc[i] = pgm_read_byte(&(source[i]));
		
	/* return pointer to ram object*/
	return heap_alloc;
}

unsigned char* load_rom_string(const unsigned char* source){
	
	/* quick & dirty strlen */
	int len = 1;
	const unsigned char* temp = source;
	while( pgm_read_byte(&(*(temp++))) != '\0')
		len++;
	
	/* allocate memory */
	unsigned char* heap_alloc = (unsigned char*)malloc(len);
	
	/* check we have heap space allocated */
	if(heap_alloc == NULL)
		return NULL;

	/* copy bytes over */
	for(int i=0;i<len;i++)
		heap_alloc[i] = pgm_read_byte(&((source[i])));
		
	/* return pointer to ram object */
	return heap_alloc;
}