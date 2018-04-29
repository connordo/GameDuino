#pragma once
#include "Entity.h"

class GameObject {
    public:
        virtual void tick() = 0;
        virtual void start() = 0;
};
