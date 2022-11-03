#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  float x;
  float y;
} point;

void point_debug(point *A)
{
  printf("(%f ; %f)\n", A->x, A->y);
}

point point_create(float x, float y)
{
  point p;

  p.x = x;
  p.y = y;
  return (p);
}

point *point_create_dyn(float x, float y)
{
  point *p;

  p = malloc(sizeof(point));
  p->x = x;
  p->y = y;
  return (p);
}

void f(point *p)
{
  p->x += 3.6;
}

int main(int argc, char **argv)
{
  point p;

  p = point_create(12.0, -3.0);
  point_debug(&p);
  f(&p);
  point_debug(&p);
  return (0);
}