/*-----------------------------------------------------------------------------
*				HTBLA-Leonding / Class: <your class name here>
*-----------------------------------------------------------------------------
* Exercise Number: #exercise_number#
* File:			counter.h
* Author(s):	<your name here>
* Due Date:		#due#
*-----------------------------------------------------------------------------
* Description:
* A counter to count up and count down.
*-----------------------------------------------------------------------------
*/
#ifndef ___COUNTER_H
#define ___COUNTER_H

#define COUNTER_COUNT 8
enum Directions {UP, DOWN, UNDEFINED};
typedef struct CounterImplementation* Counter;

void init();
Counter new_counter(enum Directions d);
enum Directions get_direction(Counter c);
void set_direction(Counter c,enum Directions d);
int get_increment_value(Counter c);
void set_increment_value(Counter c,int increment_value);
int get_value(Counter c);
void increment(Counter c);
bool set_value(Counter c, int value);

#endif
