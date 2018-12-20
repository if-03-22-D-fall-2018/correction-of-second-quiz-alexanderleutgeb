/*-----------------------------------------------------------------------------
*				HTBLA-Leonding / Class: <your class name here>
*-----------------------------------------------------------------------------
* Exercise Number: #exercise_number#
* File:			counter.cpp
* Author(s):	<your name here>
* Due Date:		#due#
*-----------------------------------------------------------------------------
* Description:
* A counter to count up and count down.
*-----------------------------------------------------------------------------
*/
#include "counter.h"
#include <stdio.h>
#include <stdbool.h>

struct CounterImplementation{
  enum Directions direction;
  int value;
  int increment_value;
  bool isUsed;
};

struct CounterImplementation POS_PRPR_01={UNDEFINED,0, 0, false};
struct CounterImplementation POS_PRPR_02={UNDEFINED,0, 0, false};
struct CounterImplementation POS_PRPR_03={UNDEFINED,0, 0, false};
struct CounterImplementation POS_PRPR_04={UNDEFINED,0, 0, false};
struct CounterImplementation POS_PRPR_05={UNDEFINED,0, 0, false};
struct CounterImplementation POS_PRPR_06={UNDEFINED,0, 0, false};
struct CounterImplementation POS_PRPR_07={UNDEFINED,0, 0, false};
struct CounterImplementation POS_PRPR_08={UNDEFINED,0, 0, false};

static Counter counters_so_far[COUNTER_COUNT] = {&POS_PRPR_01,&POS_PRPR_02,&POS_PRPR_03,&POS_PRPR_04,&POS_PRPR_05,&POS_PRPR_06,&POS_PRPR_07,&POS_PRPR_08};
void init(){

  for (int i = 0; i < COUNTER_COUNT; i++) {
    counters_so_far[i]->direction = UNDEFINED;
    counters_so_far[i]->value = 0;
    counters_so_far[i]->increment_value = 1;
    counters_so_far[i]->isUsed = false;
  }
}
Counter new_counter(enum Directions d){
  for (int i = 0; i < COUNTER_COUNT; i++)
  {
    if (!counters_so_far[i]->isUsed)
    {
      counters_so_far[i]->isUsed=true;
      counters_so_far[i]->direction=d;
      return counters_so_far[i];
    }
  }
  return 0;
}
enum Directions get_direction(Counter c){
  return c->direction;
}
void set_direction(Counter c,enum Directions d){
  c->direction = d;
}
int get_increment_value(Counter c){
  return c->increment_value;
}
void set_increment_value(Counter c,int increment_value){
  if(0<=increment_value){
     c->increment_value=increment_value;
  }
}
int get_value(Counter c){
  return c->value;
}
void increment(Counter c){
  if (c->direction==UP)
    {
      c->value+=c->increment_value;
    }
    else if (c->direction==DOWN)
    {
      c->value-=c->increment_value;
    }
}
bool set_value(Counter c, int value){
  if (c->direction==DOWN)
  {
    c->value=value;
      return true;
  }
  return false;

}
