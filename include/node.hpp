#pragma once
#include "type.h"
#include <cstdint>

class Node 
{    
public:
    Node(){}

    Transform transform;
    Node *parent = nullptr;
    uint16_t id;
    
    virtual void Render() {};
    virtual ~Node() {}
};

