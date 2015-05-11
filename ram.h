/** @file ram_utils.h 
* 	\brief Defines portable functions for estimating RAM resources and copying data from flash to RAM. Written by Jerrold Luck, Queensland University of Technology
*
*	File:	ram.h
*	Author: Jerrold Luck, Queensland University of Technology.
*	Date:	10 May 2015.
*
*	Helpful RAM utility functions.
*/

#ifndef RAM_UTILS_H_
#define RAM_UTILS_H_

#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#ifndef RAM_GUARD 
	#define RAM_GUARD 100 /**< The minimum amount of space between the stack and heap that is acceptable. */
#endif

/**
 * Estimates how much RAM will be left if you allocate an object of size len
 * 
 * @param len Object length to test for remaining RAM
 * @return Returns the amount of RAM remaining for object of length len
 */
int estimate_alloc(int len);

/**
 * Estimates the amount of free ram in both stack and heap 
 * 
 * @return Returns an estimate of the amount of free RAM in both the heap and stack
 */
int estimate_ram();

/**
 * Loads bitmap from flash into RAM 
 * 
 * @param len Size of the PROGMEM bitmap
 * @param source Pointer to the PROGMEM bitmap
 * @return Returns a pointer to the stored bitmap in RAM (unsigned char*)
 */
unsigned char* load_rom_bitmap(const unsigned char* source, int len);

/**
 * Loads string from flash into RAM 
 * 
 * @param source Pointer to the PROGMEM string
 * @return Returns a pointer to the stored bitmap in RAM (unsigned char*)
 */
unsigned char* load_rom_string(const unsigned char* source);

#endif /* RAM_H_ */
