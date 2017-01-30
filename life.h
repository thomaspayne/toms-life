#pragma once
#include "defs.h"

#include <stdlib.h>

typedef struct {
  uint8 width, height;
  uint8** data;
  uint8** back;
}life;

life* life_create(uint8 width, uint8 height);
void life_destroy(life* l);
void life_step(life* l);

