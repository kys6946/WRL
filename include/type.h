#pragma once

struct Position
{
    float x;
    float y;
};


struct Scale
{
    float x;
    float y;
};


struct Transform
{
    struct Position position;
    struct Scale scale;
    
};
