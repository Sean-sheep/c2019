#ifndef Const_H
#define Const_H

#define Height 17
#define _Length 17
#define Score 5
#define Pool 20
#define Deep 1

#define five 255
#define four 64
#define three 16
#define two 4
#define one 1

#define half_four 16
#define half_three 4
#define half_two 1

struct Location
{
     char Y;
     char X;
};

struct Vertex
{
     char Y;
     char X;
     int value;
};

struct Limit
{
     int maximum;
     int minimum;
};

#endif
