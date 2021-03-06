#ifndef CROW_1_8K_H_
#define CROW_1_8K_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define CROW_1_8K_NUM_CELLS 5227
#define CROW_1_8K_SAMPLERATE 8000
 
const int8_t __attribute__((section(".progmem.data"))) CROW_1_8K_DATA [] = {0,
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 1, 1, 2, 1, 2, 3, 3, 1, 2, 3, 2, 2, 0, 2, 2, 2,
2, 0, 2, 0, 0, 0, 3, 0, 3, -2, 3, 0, 0, 0, 3, 3, 0, 0, 0, 0, 4, 4, 0, -3, -3, 0,
0, 0, -3, -3, -3, -4, -4, -4, -18, -4, 20, -4, -4, 5, 0, 0, 5, 0, -5, -5, 0, 0,
-16, 0, 12, -11, -5, 6, 0, 0, -12, 0, 13, -6, -6, 7, -6, -6, -13, -13, 7, -6,
-14, 0, -6, -7, 0, -7, 0, -7, 0, 0, -23, 0, 0, -24, -7, -16, -8, 0, -8, -8, 0,
-17, -8, 9, -8, 0, -8, 0, 0, -18, 9, 9, -8, 0, -8, -27, -27, 19, 28, -8, 0, 0,
-8, -8, 0, -37, 19, 28, -27, 0, 9, -8, 9, 0, 19, 28, -18, 28, 19, -8, 19, -18,
-46, 47, 28, -8, 19, 19, 9, 19, -8, -27, 38, 19, -18, 19, 9, -8, -8, 0, 57, -8,
-18, 28, -18, 9, -27, -27, 57, 0, -18, 38, -8, 0, 0, -46, 47, 38, -46, 19, 28,
9, 28, -18, 9, 47, -27, 0, 19, -8, -18, -18, 47, 19, -46, 9, 9, -8, 9, -8, 19,
28, -37, 19, 19, -27, 0, 9, 9, 0, -27, 9, 28, -27, 0, 0, -46, 9, 28, -27, 0, 9,
0, -8, -37, 0, 57, -8, -46, 19, 0, 0, -8, 0, 19, -8, -18, 0, -27, -8, -46, 0,
57, -46, -18, 28, -18, 19, -46, -27, 95, -27, -56, 57, -8, -18, 9, 9, -18, 0,
28, -37, -75, 19, 57, -46, 9, 66, -37, -27, -37, -8, 104, -56, -75, 76, 9, -27,
19, -18, -8, 19, 9, -46, -46, 66, 28, -56, 28, 9, -18, 0, -37, 66, 28, -103, 28,
47, -18, 19, 9, -8, 0, 9, -18, -46, 28, 57, -37, 9, 28, -84, -27, 57, 38, 28,
-56, -46, 76, 0, -27, 47, 0, -27, 38, -18, -37, 57, 28, -8, 19, 0, -37, -8, 57,
28, -8, -8, -27, 19, 57, 19, 0, -8, 0, 28, 0, -8, 0, 19, 9, -8, 9, -8, 9, -27,
-18, 76, 19, -84, 0, 66, 38, -18, 0, 28, -18, 9, 28, -56, -56, 47, 47, 9, -18,
-8, 19, -56, 9, 114, -56, -103, 66, 85, 0, -8, -8, -8, 19, 19, -94, -46, 95, 9,
-27, 38, -37, -46, -18, 47, 95, -37, -113, 38, 57, 19, -8, -56, 9, 47, -103,
-94, 127, 28, -94, 47, 38, -65, -94, 9, 114, 19, -56, -8, -18, 38, 47, -18, -37,
-18, -84, -18, 114, -27, -37, 57, -18, -56, -37, 19, 57, -27, -18, 76, -27, -84,
9, 66, 38, -65, -128, 95, 95, -113, 47, 66, -103, -94, 28, 104, -18, -94, 28,
66, -27, -18, -27, -18, 95, -37, -128, 95, 28, -56, 57, 9, -75, -8, 38, 38, 19,
-46, -18, 57, -8, -18, 28, 28, 0, -46, -56, 66, 47, -65, 47, 66, -65, -94, 9,
127, 57, -128, -27, 85, 9, -65, 9, 76, 9, -27, -37, -46, 57, 57, -37, 19, 19,
-27, -56, 9, 104, 28, -94, 19, 47, -56, 9, 114, -8, -65, 19, -8, -75, 47, 76,
-37, -8, 19, -37, -37, 19, 95, 38, -84, -46, 38, 19, 38, 28, 0, 9, -18, -128,
38, 127, -65, -75, 47, 9, -56, -46, 66, 104, -46, -75, 0, 0, 38, 28, -8, 9, -27,
-103, 47, 85, -27, 0, -8, -27, -8, -37, 66, 47, -94, -8, 57, -27, -27, -8, 28,
19, -94, -75, 114, 9, -75, 57, 9, -84, -75, 47, 127, -18, -113, 28, 66, 0, -27,
-37, 9, 57, -94, -84, 127, 19, -103, 66, 9, -94, -37, 47, 85, 0, -103, 19, 57,
-46, 0, 57, -8, 0, -84, -37, 127, 0, -65, 57, -8, -65, 0, 76, 76, -37, -56, 47,
38, -56, -37, 66, 66, -27, -56, 19, -18, -37, 85, 57, -27, -56, -27, 28, 19, 47,
19, -27, 9, -46, -56, 76, 47, -18, -18, 47, -8, -94, -37, 104, 76, -65, -46, 28,
19, -18, -8, 76, 0, -128, -37, 123, 19, -56, 38, 57, -8, -37, -84, -37, 76, 19,
-56, 38, 9, -75, 19, 28, -18, 9, -75, -8, 76, -46, 0, 57, -18, -18, 0, -65, -84,
76, 66, -18, 38, -8, -37, -27, -8, 85, -8, -94, 38, 28, -18, 57, 9, -27, 19, 28,
-128, -27, 127, -18, -8, 57, -27, -56, -46, 66, 76, -94, -56, 66, 28, 9, 19,
-18, 0, 19, -122, 9, 127, -56, -37, 95, 9, -94, -84, 95, 114, -103, -84, 95, -8,
-56, 28, 28, 19, -37, -128, 76, 104, -128, 19, 123, -65, -84, 28, 95, 57, -75,
-65, 66, 28, -65, 19, 66, 19, -18, -103, 0, 104, -18, -18, 38, -8, -56, -27, 76,
95, -56, -84, 28, 9, -37, 19, 57, 9, -27, -8, -8, -75, 19, 127, -27, -103, 19,
76, -27, -56, 57, 28, -84, -56, 19, 47, 0, 0, 9, -27, 19, -27, -75, -8, 66, 28,
-65, 0, 95, 19, -65, -46, 95, 0, -128, 38, 127, -18, -56, 19, 57, -8, -27, -8,
-46, -18, 66, 0, 9, 57, -37, -37, -27, -37, 95, -27, -75, 104, 28, -56, 38, 19,
-46, 28, 66, -103, -46, 104, -8, 9, 38, -27, -8, -113, -18, 127, -37, -84, 38,
-8, 57, 38, -103, -8, 95, -56, -128, 95, 95, -84, 0, 66, -18, -65, -113, 85,
127, -128, -84, 76, 57, 0, -27, 9, 0, -27, -103, 47, 104, -94, 19, 104, -56,
-84, -65, 57, 104, -94, -8, 57, -37, -8, 38, 28, -8, -46, -94, 57, 85, -65, 47,
38, -18, -18, -103, 28, 95, -65, 0, 76, -8, -56, -18, 57, 57, -46, -84, 66, -8,
-56, 95, 0, -65, 9, -8, 9, 9, -46, 38, 38, -27, 9, 9, -18, 9, 57, 9, -84, -84,
104, 104, -84, -27, 57, 0, -46, 0, 57, -27, -27, 38, 9, 38, -8, -8, 66, 19, 19,
-65, -46, 76, 57, -18, -56, 19, 47, -8, -27, -18, 57, -46, -103, 127, 85, -128,
-46, 95, 47, -75, -8, 76, -18, -128, -8, 127, -18, -65, 19, 38, 9, -128, -46,
127, 0, -46, -8, 0, 19, -37, -46, 104, 85, -128, -128, 123, 127, -103, -37, 57,
-18, -46, -113, 57, 127, -113, -37, 76, -18, -8, -37, 19, 104, -27, -128, -84,
127, 95, -84, 28, 28, -84, -46, -56, 104, 85, -128, 28, 38, -56, 28, 0, -18, 9,
28, -94, -94, 127, 57, -75, 28, -18, -37, -56, -37, 127, 19, -128, 38, 19, -18,
9, 38, 19, -18, -94, -103, 127, 127, -128, 0, 95, -37, -103, -65, 127, 95, -128,
19, 28, 0, 47, -18, 9, 76, -8, -128, 19, 127, -8, -84, 19, 66, -56, -122, 114,
127, -128, -37, 66, -46, -18, 57, 66, -18, -27, 38, -8, -75, 47, 76, -46, -37,
19, 9, -37, -27, 95, -8, -75, 9, 0, 38, 28, -37, 28, -8, -27, 19, 47, -8, -103,
47, 47, -46, 57, 9, -27, -37, -37, 66, -27, -18, 57, 0, -8, -37, 57, 19, -56,
66, -18, -65, -46, 38, 57, -84, 28, 85, -56, -94, -56, 127, 66, -128, 57, 76,
-46, -27, 28, 66, -27, -46, 0, 9, -27, 19, 47, -37, 28, -37, -56, 38, -18, 76,
19, -122, 76, 28, -37, 57, 19, -84, -8, 104, -18, -94, 38, 57, -27, -56, -46,
85, 85, -128, -27, 127, -65, -75, 57, 76, 0, -84, -27, 85, 66, -65, -75, 0, 66,
-27, -94, 47, 85, 28, -103, -84, 127, -18, -103, 66, 28, 19, -65, -46, 104, 95,
-103, -128, 127, 127, -128, -56, 127, 28, -94, -128, 123, 127, -128, -65, 104,
95, -56, -113, 85, 95, 0, -128, -37, 127, -27, -128, 85, 76, -27, -122, -8, 127,
-27, -94, -18, 28, 66, -65, -8, 66, 47, -56, -128, 127, 127, -122, -65, 85, 57,
-103, -75, 127, 76, -122, -27, 76, 57, -94, -37, 127, 28, -84, -27, 47, 19, -8,
0, -18, 19, 19, -8, -8, -8, 0, 9, -27, 38, 38, -75, -8, 66, 66, -75, -84, 114,
76, -94, -128, 66, 127, -56, -84, 28, 57, -37, -113, 66, 123, -113, -37, 38, 38,
38, -75, 0, 76, 38, -103, -46, 85, -37, 19, 9, -37, 47, -27, -37, 28, 0, 19,
-27, -27, 104, 19, -75, -18, 123, -8, -84, 57, 19, 0, -103, 19, 66, -65, 28, 28,
9, -46, -122, 123, 76, -128, 28, 66, 0, -65, 19, 28, -8, 9, -27, -75, -8, 95,
-46, -37, 85, 0, -65, -65, 38, 127, -122, -56, 127, 0, -56, 0, 76, 0, -18, -18,
-84, -8, 123, -46, -75, 104, 19, -46, -56, -27, 127, -37, -113, 66, 85, 47, -75,
-37, 95, 66, -75, -122, 104, 104, -113, -37, 114, 0, -75, -37, 76, 104, -128,
-27, 127, 9, -56, 47, 66, -65, -8, 0, -56, 66, 9, -37, 85, 0, -75, -8, -37, 123,
19, -128, 28, 76, 28, -84, 0, 76, 0, 0, -113, -37, 104, -37, -46, 76, 0, -65,
-56, 47, 76, -65, -56, 47, 38, -27, -37, 57, 38, -8, 28, -46, -8, -18, -56, 95,
0, -56, 57, -8, 28, -56, -75, 127, 9, -94, -8, 57, 28, -56, 38, 66, -46, -8, 0,
9, -27, -75, 104, 57, -103, 28, 66, -46, -46, -8, 57, 28, -56, 47, 28, -37, -46,
28, 114, -37, -65, -46, 57, 85, -128, -8, 114, 28, -37, -103, 57, 66, -122, 28,
123, -37, -56, -46, 57, 66, -27, -94, 9, 95, -65, -56, -46, 76, 38, -94, 38, 9,
-56, 66, -8, 0, 28, -56, 57, -18, -18, 57, 38, -65, -27, 76, -37, -37, -56, 85,
66, -56, -18, -46, 47, 95, -122, 19, 85, -46, 19, -27, 19, 47, 57, -56, -65, 66,
0, -46, -27, 76, 66, -27, -27, 9, 38, 9, -75, 76, 9, -37, 57, -56, 9, 76, 0,
-27, -8, 0, 0, -65, 38, 95, -56, -27, 57, 76, -27, -128, 76, 127, -84, -94, 9,
127, 9, -122, 47, 47, -37, -128, 0, 123, 0, -75, 9, 57, -8, -56, -37, 85, 9,
-84, 57, 19, -18, 9, 66, -46, -46, 38, -103, 38, 76, -84, 66, 28, -65, 19, -46,
57, 85, -113, -27, 19, 57, -65, -56, 127, -18, -122, -46, 28, 38, -37, -37, 28,
47, -56, -56, 38, -8, 19, 9, -103, 28, 76, -8, -65, -8, 104, -8, -94, -8, 47,
57, -103, -65, 127, -8, -84, 57, 38, -18, -27, -56, 47, 66, -37, 19, 28, -8, 0,
19, 28, -18, -18, -8, 47, 38, -128, 19, 123, -27, -75, 9, 66, -8, -56, 0, 76,
-18, 0, 19, -8, 0, 9, 47, -94, 47, 85, -18, 0, -103, 57, 47, -84, 19, 57, 19,
-27, -103, 57, 104, -65, 0, 19, 19, 0, -27, -8, 47, 57, -75, -37, -46, 38, 19,
-37, 57, 28, -8, -46, -94, 85, 95, -94, 38, 28, -27, -18, 38, -8, -18, 66, -37,
-18, -56, 28, 85, -8, 9, -8, -8, 9, -65, 19, 85, -8, 38, -46, -27, 76, 9, -75,
19, 47, -18, -84, -37, 104, 19, -46, 19, -27, -27, -46, 0, 127, -103, -75, 104,
57, -27, -94, 9, 95, 9, -113, -75, 104, 85, -84, 9, 38, -18, 28, -113, -27, 127,
-27, -37, 0, 38, 95, -65, -46, 57, 28, -75, -65, 114, 9, -27, 66, -18, -18, -18,
-75, 28, 47, -8, 19, -65, 28, 38, 9, -37, -56, 76, 19, -84, -84, 104, 104, -94,
-56, 38, 57, -37, -113, 85, 85, -84, -8, 47, -8, -27, 38, 0, -37, 19, 47, -8,
-37, -56, 38, 104, -94, -65, 19, 66, 66, -65, -75, 57, 95, -37, -37, 9, 47, -37,
-8, 85, 28, -65, -65, 123, 57, -128, 28, 127, -46, -56, 28, 19, 9, -75, 28, 123,
-65, -56, 28, 19, -27, 19, 28, -27, 95, -27, -65, 38, -75, 76, 19, -37, 28, -46,
85, 28, -113, 38, 76, -18, -18, -8, 19, -37, 66, 47, 0, -56, -8, 85, -94, -18,
38, 19, 104, -37, -103, 19, 19, 66, -8, -103, 66, -8, -56, -18, 95, -8, -65, 85,
-37, -113, -56, 114, 85, -94, -27, 19, -8, -27, -65, 66, 38, -103, 47, 9, -65,
9, 66, -8, -46, -27, -8, -27, -8, 38, -18, 28, 47, -94, 19, 0, -27, 95, -103, 9,
85, -27, -8, -8, 38, 0, -37, -18, -46, 47, 38, -37, 38, 9, -27, 66, -94, -56,
127, 9, -37, -27, 19, 104, -27, -65, 38, 57, -46, -113, 76, 85, -65, 38, 66, -8,
-46, -27, 95, 9, -84, 57, 66, 28, -56, -27, 104, -8, 0, 19, -18, 28, -37, 28,
28, -46, 85, 9, -65, 28, 0, 9, 0, -27, 114, 19, -94, 0, 57, 28, -37, -8, 66, -8,
9, 28, -113, 0, 123, -75, -94, 66, 76, -18, -65, -8, 95, 0, -103, 38, -8, -37,
57, 19, -56, 0, 114, -37, -84, -37, -46, 47, -8, -37, 9, 19, 9, -8, -18, -37, 0,
-18, 19, 9, -56, -27, 104, 19, -113, 85, -37, -94, 0, -65, 66, -37, -27, 104,
-37, -18, -8, -65, 47, 38, -75, 19, 38, 9, 0, 28, -8, -27, 19, -37, 19, -37, 0,
47, -27, 57, 28, -56, 19, 9, -46, 38, -8, -8, 76, 9, -18, 28, 19, -37, 28, -46,
28, 19, -84, 47, 19, 19, 19, -46, 9, 38, -75, 19, 38, 0, 47, -46, 28, 66, 0,
-27, -18, 57, 19, -103, -8, 95, 9, 28, 0, -37, 0, 57, -46, 19, 9, 9, 66, -27,
-27, 85, 66, -65, -46, 9, -8, -18, 38, -18, -8, 85, 19, -94, 0, 19, 0, 38, -56,
19, 66, 9, 28, -8, -8, 66, -27, -75, 19, 9, 47, -27, -56, 95, 57, -75, -8, 19,
-18, 0, -27, 19, 38, -18, -8, 19, 28, -37, -56, 38, 38, -37, -46, -56, -27, 66,
28, -27, -65, 9, 76, -27, -113, -27, 127, 28, -128, -27, 47, 19, -37, 0, 47, -8,
-46, -18, 0, 38, -27, -56, 38, 9, -46, -8, 9, 38, 76, -103, -84, 114, -8, -65,
0, 28, 57, 19, -46, -56, 66, 38, -27, 28, -113, 0, 104, -65, -37, -27, 76, 66,
-8, -65, -65, 76, 47, -37, -37, -8, 76, 0, -94, 28, 76, -27, -27, 0, -56, 38, 0,
-46, 66, 19, -37, 28, 19, -18, 9, 9, 19, 19, -65, 0, 85, -27, -27, 47, 66, 28,
-113, -84, 127, 28, -122, 28, 76, 76, -8, -56, 19, 66, 0, -37, 28, 19, -37, 28,
47, -27, 19, 28, 9, -56, -37, 57, -27, 28, 28, 9, 19, 19, -27, -27, 66, -8, 0,
0, -18, 9, 19, 0, 19, -8, -18, -18, -46, 38, 0, -37, 38, 9, -8, 0, -84, 0, 127,
-75, -128, 85, 47, -8, -27, -37, 95, 85, -103, -84, 19, 95, -18, -84, 38, 66,
-27, -8, 19, -18, 9, 19, -8, -37, -18, 57, 19, -46, -18, 0, 38, 38, -8, -56,
-103, 9, 76, -46, -84, 38, 127, -37, -103, 0, 19, 47, -46, -37, 38, -27, -27, 0,
47, -8, -27, 38, -27, -37, 28, -65, -37, 66, 0, -27, 47, 28, -75, 0, 9, -18, 0,
-37, 47, 19, -37, 9, 9, 9, -27, 9, 19, -27, -8, -75, 66, 76, -75, -8, 19, 85,
-37, -18, 28, -37, 38, 19, 19, 28, -75, 9, 104, -46, -56, 85, 28, -27, -37, -56,
95, 19, -18, 57, -18, 0, 9, 19, -46, 28, 95, -37, -27, -46, 0, 104, 9, -65, 38,
47, -37, -37, -37, 9, 114, -27, -46, 19, 19, 0, 28, 19, -46, 38, -8, -18, 28,
-46, -8, 123, 19, -128, 0, 85, 47, 0, -128, 19, 127, -56, -84, -46, 104, 95,
-65, -75, -37, 66, 57, -56, -65, 19, 76, 47, -94, -94, 104, 114, -56, -94, -65,
76, 66, -65, -65, 0, 123, 19, -75, -65, 9, 95, -37, -84, 9, 28, 57, 0, -94, -18,
95, 0, -113, -46, -8, 104, -8, -113, 38, 66, 19, -56, -37, 0, 9, 38, -46, -27,
19, -18, -8, 19, 9, -75, 9, 47, -46, 0, -37, -18, 76, -27, -46, 0, 9, -8, -18,
19, -56, 28, 38, -56, -18, -27, 28, 47, -18, -46, -27, 47, 19, 0, -37, -27, 28,
9, -27, -37, -8, 85, 66, -56, -27, 9, 19, 19, -18, 9, -8, 9, 28, -27, 9, 9, 57,
28, -65, 9, 19, -27, -46, 38, 38, -18, 19, 47, 28, -27, -8, 0, -27, -8, 19, 28,
-8, -18, 38, 38, -37, -8, 19, 38, -8, -56, 19, 76, -27, -94, 28, 95, -37, -65,
-8, 66, 19, -65, -8, 57, 19, -46, 9, 19, -27, 47, 0, -37, -8, 19, 38, 0, 9, -18,
28, -8, -27, 28, -37, -27, 28, 28, 19, -46, -8, 66, 0, -18, -37, 28, 66, -75,
-56, 66, 38, -18, -56, -8, 28, 38, 0, -65, -8, 38, 66, -8, -75, -8, 28, 28, -8,
-84, -18, 38, 76, 0, -65, 0, 28, 9, 19, -8, -18, 9, 9, -46, -8, 57, 0, -37, -27,
19, 38, -18, -37, -18, 47, -8, -56, 9, 38, -8, -18, -18, -8, -8, 0, -18, -18,
-37, 9, 28, -18, 9, -18, -8, 9, -27, -56, -18, 0, 19, 19, -18, -46, 9, 19, -27,
0, -27, 9, 9, -37, 0, 0, 47, 19, -46, -18, 28, 47, -8, -46, 28, 47, -8, 0, 0, 9,
47, -18, -37, 57, 28, -37, -8, 57, 57, -27, 0, 28, 28, 9, -37, 9, 57, -18, -8,
-8, 28, 47, -37, -37, 47, 47, 9, -65, -8, 76, -8, -18, -8, 9, 38, 19, -18, -27,
9, 0, 9, 9, -46, -8, 66, 9, -27, -8, 28, 19, -37, -37, 28, 38, -8, -8, 19, 28,
0, -18, -8, -8, 0, 9, 0, -46, 0, 76, 0, -37, -8, 9, 19, -27, -18, 9, -46, -18,
38, 0, -46, 0, 47, 9, -56, -65, 9, 38, -8, -46, -8, 38, 19, -27, -46, -8, 28, 0,
0, -56, -56, 57, 38, -37, -46, 9, 66, -18, -65, -18, 38, 9, -56, -8, 38, 0, -27,
9, 0, 0, 0, -18, 9, 19, 9, -18, -27, 28, 19, -27, 19, 28, 19, -27, -46, 38, 57,
-27, -46, 47, 66, -8, -46, -27, 38, 38, -18, -27, 0, 9, 0, 19, 38, 0, 19, -8,
-8, 0, -37, 28, 57, -18, -18, 0, 38, 28, -18, -27, 19, 47, 0, -46, -27, 47, 66,
-18, -37, 28, 19, -8, 0, 28, -8, -18, 38, 19, -37, 0, 57, 9, -27, 0, 19, 0, 0,
-8, 9, 28, 19, -18, -8, -8, 0, 28, -8, -37, 0, -8, 9, 38, -27, -46, 0, 38, 0,
-46, -8, 28, -8, -75, -18, 57, -8, -37, 0, 9, 9, -27, -27, 9, 28, -46, -75, 9,
47, 9, -46, -8, 38, 0, -27, -46, 9, 19, 0, -8, -37, 0, 38, 9, 9, 0, 0, -8, -8,
19, 0, -8, 19, 28, -8, -27, 28, 28, 0, -18, -27, 28, 0, -8, 28, 0, -8, -46, 19,
57, -27, -37, 9, 38, 9, -56, -37, 47, 28, -37, 9, 9, -8, -8, -8, -27, -27, 28,
57, 0, -75, -8, 57, -8, -46, 0, 9, 9, -8, -27, 0, 9, 9, 9, -8, -18, 19, 0, -37,
0, 57, 0, -46, 0, 47, 9, -37, -8, 28, 19, 0, -18, -8, 47, 28, -37, -27, 28, 47,
-18, -46, 28, 47, 28, -18, -37, 19, 47, 0, -46, 0, 47, 19, -37, -46, 19, 47, 9,
-18, -18, 0, 0, 9, 9, -18, 9, 9, -18, -8, -8, 9, 9, 19, -8, 0, -8, -8, 28, 0,
-27, -18, 19, 28, -27, -27, 57, 28, -27, -27, -8, 38, 9, -18, 19, -8, 0, 0, -18,
9, 19, -18, -8, 0, -8, 9, 0, 0, 28, -18, -46, -8, 28, 0, -8, 9, 28, 19, -37,
-27, 9, 19, 19, 19, -18, -37, 19, 28, -8, -8, 0, 0, 19, 0, -8, 19, 19, 0, -27,
0, 9, -8, 0, 19, 0, 0, -8, 9, 0, -18, 19, 19, -27, -18, 9, 19, 9, 0, 9, 9, 0,
-18, -18, 9, 19, 0, -18, 0, 38, -8, -37, 0, 19, 28, -18, -27, 0, 47, 0, -37, -8,
0, -8, 9, -8, 0, 9, -18, 0, 9, -8, 9, 9, 0, 0, 9, -27, 0, 57, 0, -8, 9, 19, -18,
-46, 9, 47, 19, -46, -8, 38, 9, -8, -8, 9, 28, -8, -37, 0, 19, -8, 0, 0, -8, -8,
9, 9, -18, -8, 19, 19, -18, -27, 28, 19, -18, 0, 9, 0, -8, -27, 28, 19, -8, -8,
-8, 9, -18, -27, 28, 19, 9, -8, -8, 9, 0, -18, 0, 19, 9, -18, -18, 28, 9, -18,
0, 0, 28, 0, -37, -27, 9, 28, 0, -37, 0, 38, 0, -75, -27, 38, 38, 9, -37, 9, 28,
-27, -37, 19, 28, -8, -27, -8, 9, -8, -18, 9, 19, -8, -37, 9, 19, -37, -8, 28,
19, 9, -27, 9, 28, -8, -37, -18, 19, 9, 0, 9, -8, 0, 9, 0, 28, 9, -18, 0, 0, -8,
0, 28, 9, 0, 9, 9, 9, -27, -8, 57, 28, -46, -18, 19, 28, -8, -8, 19, 28, -8,
-56, 9, 47, 9, -18, -8, 28, 28, -27, -46, 9, 19, 19, -8, -37, 9, 28, -8, 19, 9,
-8, -8, 19, 19, -8, -27, 19, 38, -18, -37, 9, 47, 0, -18, -8, 19, 28, 0, -18,
19, 19, 0, -8, -27, 0, 57, 0, -37, 0, 19, 19, 0, -37, 0, 38, 0, -18, -8, 0, 0,
0, -18, -37, 19, 9, -37, -27, 19, 9, -18, -27, 0, 19, 9, -18, -27, 9, 0, 0, -8,
-8, 28, 19, -27, -46, 0, 28, -8, -27, 19, 28, 9, -27, -8, 28, 9, -27, -8, 19, 9,
-8, -18, 9, 38, -8, -8, -8, -8, 28, 0, -18, 0, 19, 28, 0, -8, -8, 9, 9, -8, 0,
0, 9, 28, 0, -18, 0, 19, 9, 0, 19, 0, -8, -8, 9, 28, 0, -18, 9, 9, 9, 0, -18,
19, 38, -8, -18, -18, 19, 28, -18, -8, 38, -8, -27, 19, 0, 9, 9, -8, 0, 0, 0, 0,
9, 9, -18, -8, 19, -27, -8, 28, 0, -18, 0, 9, 19, -8, -27, 19, 47, -27, -37, 0,
47, 9, -46, -18, 28, 38, -18, -65, -27, 47, 28, -56, -18, 28, 9, -27, -37, 0,
28, 9, -27, -18, 19, 19, 0, -18, 0, 9, 0, 0, -8, -8, 9, 19, 9, -18, -8, 9, 0, 0,
-8, 0, 9, -8, 9, 19, -8, 0, 19, -8, -27, 0, 38, -18, -37, 28, 28, 9, -18, -8,
19, 19, -18, -18, 0, 0, 19, 0, -37, 9, 47, 0, -18, 0, -8, -8, 9, 0, 9, -8, 0,
28, 9, 0, 9, -8, 9, 19, -18, -18, 19, 28, 0, -18, 19, 19, -8, -27, 0, 28, -8,
-18, 0, 9, 9, 19, 0, -8, -8, 9, -8, 0, -8, -8, 19, 9, 0, -18, 9, 19, -8, -27,
-27, 19, 9, 0, 0, -8, -8, 0, 19, 19, -27, -27, 19, 9, -18, -18, 9, 19, -18, -27,
-8, 9, 0, -18, 0, -8, 0, 9, -18, -8, 19, 0, 9, 0, -18, 9, 0, 0, -18, -18, 19, 9,
-18, -8, 28, 9, -18, 0, -8, 19, 0, 0, 9, 9, -8, 0, 9, 0, -8, 9, -8, -8, 0, 0,
-8, -8, 9, 19, 9, 9, -37, -8, 19, 9, 0, -18, 9, 0, 0, 0, -8, -18, 19, 9, -8, -8,
9, 28, 9, -18, 0, 28, 9, 0, 0, 9, 9, 0, -8, -8, 28, 19, -8, -8, 0, 9, 19, 9, 9,
0, 9, 0, -8, 0, 0, 19, 0, 9, 9, -18, -18, 9, 19, 0, -18, -8, 19, 19, -8, -27,
19, 28, -27, -27, -8, 19, 28, -27, -37, -8, 38, 0, -37, -18, 9, 0, -8, -18, 0,
28, -8, -27, 19, 0, -8, 19, 0, 0, 0, -8, 0, 0, -8, -8, 0, 28, 0, -27, 0, 9, 9,
-18, -18, 9, 19, -8, -18, 0, 19, 9, -18, -8, 9, 19, 0, -37, -8, 0, 19, 9, -18,
-8, 9, 9, 9, -18, 0, 19, 9, 0, -8, 9, 9, 9, 0, -18, 0, 19, 19, 0, -8, 9, 9, 0,
0, 0, -8, 0, 19, 9, 0, 0, 9, 0, 9, 9, 0, -8, 9, 19, 9, -8, -8, 9, 19, 19, -8,
-18, 9, 0, -8, -8, 0, 9, 9, 0, 0, -18, -8, 19, 38, -8, -18, -8, -8, 0, 0, -18,
0, 9, 9, 9, -27, -18, 9, -8, -8, 0, -18, 0, 19, 0, -37, 0, 28, 0, -37, -27, 9,
19, -8, -27, 19, 19, 19, -18, -27, -8, 19, 19, 0, -18, 9, 9, 0, 0, -18, 0, 9, 0,
0, 0, 0, 9, 19, 0, -18, -18, 9, 28, -18, -18, 9, 19, 0, -18, -8, 19, 9, -8, -8,
-18, 0, 19, 19, -8, -37, 9, 9, 0, -8, 9, 9, -8, -8, 0, 9, 9, 9, 0, -18, -8, -8,
19, 19, 0, 9, 19, 9, -18, -8, 19, 28, 9, -8, -18, 0, 19, 0, -8, 9, 0, -18, -8,
19, 19, -8, -8, 0, 0, -18, 9, 9, -8, -8, 9, 19, -8, -27, 9, 28, 0, -27, -18, 0,
19, 0, -18, 0, 28, 9, -37, -27, 19, 19, 0, -18, 0, 9, 9, -8, -8, -8, 9, 9, -18,
-18, 9, 19, -8, -18, 0, 9, 0, -27, -18, 28, 19, -18, -18, 0, 9, -18, -8, 0, 0,
0, 0, -8, 0, 19, 0, -8, 0, 0, 0, 9, 9, -18, -18, 19, 9, 0, -8, -8, -8, -8, -8,
-8, 0, 19, 0, -8, -8, 0, 9, 0, -8, 0, 9, -8, -8, 19, 0, -18, -8, 19, 9, 0, -8,
9, 19, 0, -8, 9, 9, 0, 9, 0, 0, 9, 9, 9, 9, 0, 0, 0, -8, 9, 0, 9, 19, 9, 9, 0,
0, 0, 9, 0, 0, 19, -8, -8, 9, -8, 0, 9, 19, 9, -8, -8, -8, 0, 0, -18, 9, 9, -18,
0, 9, 9, 9, -8, -8, 19, 9, -8, 0, 0, 0, 0, -8, -8, 0, 28, -8, -27, -8, -8, 0, 9,
0, -8, -18, 0, 9, -8, -8, 0, 28, 0, -18, -8, 9, 9, 0, 0, 0, -8, 0, 0, 0, 0, 9,
9, -8, -18, 0, 0, 0, 0, -8, 0, 19, 0, -18, 0, 9, 0, -18, 0, 9, 0, 0, 0, 19, 9,
-8, 0, 9, 0, -8, 0, 0, 0, 9, 0, -8, 0, 0, 0, 0, 0, 9, 9, 0, 0, -8, -8, 9, 19, 9,
-18, 0, 9, 9, -18, -18, 19, 19, 0, -8, -18, 9, 9, -8, 0, 0, 0, 9, 0, -8, -8, 9,
19, -8, -18, -18, 19, 9, -8, -8, 0, 9, 9, -8, -27, 0, 19, 0, 9, -8, -18, 0, 9,
-8, 0, 9, 0, -8, 0, 9, 9, -8, -18, 0, 19, 0, 0, 19, 9, -18, 0, 9, 0, -8, 19, 19,
-8, -18, 9, 28, 0, 0, 9, 19, -8, -27, -8, 28, 9, -8, -8, 9, 9, 9, -8, -8, 28, 9,
0, -8, 9, 9, 0, 9, 9, 0, 0, 9, 9, -8, 0, -8, -8, 0, 0, -8, 0, 19, 0, -18, -18,
9, 9, 0, -8, -8, 9, 9, 0, -8, -8, 9, 9, -18, -8, 0, 0, 0, -8, 0, -8, -18, -8, 0,
-18, -18, 0, 0, -18, -18, 0, 9, -8, -18, -18, -8, 0, 0, -27, -18, 9, 19, -8,
-18, -8, 0, 9, 9, -8, 0, 9, 9, -8, -8, 9, 19, 9, -8, -18, 19, 9, 9, 0, -8, 19,
9, -27, -8, 19, 28, 0, -18, 0, 19, 0, -8, 0, 0, 0, 9, 0, -8, 9, 28, 9, -18, -8,
0, 28, -8, -18, 9, 9, 0, -8, 9, 19, 19, 0, 9, 9, 0, 0, 19, 9, 9, 0, 0, 19, 19,
0, 0, 9, 9, 0, 0, 9, 19, 0, -8, 0, 9, 0, 0, 0, 9, 0, 9, 9, 0, 0, 9, 9, 0, 0, 19,
19, -8, 0, 19, 0, 0, 9, 0, -8, -8, 0, 28, 0, -37, 0, 9, 0, -8, -27, 9, 9, -27,
-27, -8, 19, 9, -18, -8, 28, 19, -27, -18, 28, 19, -27, -27, 9, 19, -8, -27, 9,
28, 0, -8, -8, 19, 19, 0, -8, 0, 9, 9, 0, -18, 0, 19, 0, 0, 0, 0, 9, 9, -8, -18,
0, 9, 19, -8, -18, 0, 9, 0, -8, -8, 9, 9, -8, -18, -8, 19, 9, -8, -8, 0, 9, -8,
0, -8, 0, 0, -8, 0, 0, -8, -18, 0, 9, -17, -17, -8, 9, 0, -17, -8, 9, 0, -8,
-17, 0, 18, 0, -8, -17, 9, 18, 0, -8, 0, 9, 0, 9, -8, -8, 9, 9, 0, 0, 0, 8, 8,
8, 8, 0, 0, 8, -7, 0, 16, 16, 0, -7, 0, 8, 8, 0, 8, 8, 0, 0, 8, 8, 16, 8, 0, 16,
0, -7, 15, 23, 8, -7, 8, 0, 8, -7, 0, 15, 7, 0, -6, 15, 22, 0, -6, 7, 0, -6, -6,
7, 14, 0, 0, -6, 0, 0, -13, 0, 7, 0, 0, -6, -6, 7, 7, -6, -6, 0, 7, 0, -12, -6,
0, -6, -6, -6, -5, -5, 6, -12, -12, 0, 0, 0, 6, -5, -18, 0, -5, -5, 0, -11, -5,
0, 0, -5, -17, 0, 12, 6, -5, -11, 6, 12, 0, -5, -5, 6, 0, -5, -5, -5, 0, 6, 0,
-5, 0, 0, -4, -10, 0, 0, -4, -4, 0, 0, -4, 5, -4, -4, -4, -4, -4, -4, 0, 10, 0,
-4, -4, -4, -4, 5, 0, 0, 0, 0, 5, 0, 0, 0, 5, 5, 0, 0, 5, 5, 0, -3, 4, 9, 4, -3,
-3, 4, 9, 0, 4, 0, 4, 8, 4, -3, 0, 12, 8, -3, 4, 8, 8, 4, 0, 4, 4, 4, 0, 4, 0,
0, 7, 0, 0, 0, 4, 4, -3, -2, 0, 3, 0, 0, -2, -2, 3, 3, -2, -5, 3, 3, 0, -2, 0,
0, 0, 0, 0, 0, 0, 0, 0, -2, -2, -2, 0, 3, -2, -4, 3, 3, 0, -7, 0, 3, -2, -7, -4,
2, 2, -4, -4, 0, 2, 0, -4, 0, 2, -1, -3, 0, -1, -1, 0, 2, 2, -1, -1, 0, 0, -3,
-5, -1, 2, 0, -3, -1, 2, 2, -2, -2, 0, 2, 0, -4, -1, 2, 0, -2, 0, 3, 1, -2, 0,
3, 1, -2, 0, 1, 1, 0, 0, 1, 2, 1, 0, 0, 2, 1, 0, 0, 2, 1, 0, 0, 1, 2, 1, 0, 0,
1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
 
 #endif /* CROW_1_8K_H_ */
