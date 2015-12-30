#ifndef DARKNESS_CONTEXT_H
#define DARKNESS_CONTEXT_H

#include <memory>

#include "Graphics.h"


class Context
{

protected:
    std::shared_ptr<Graphics> graphics;

public:
    virtual void render() = 0;
    virtual void update(float delta) = 0;

    void setGraphics(std::shared_ptr<Graphics> graphics);
};


#endif //DARKNESS_CONTEXT_H
