#pragma once
#include "macros.h"
#include "Image.h"


class Background: public Image
{
public:
    /* Constructor / Distructor */
    Background( const Type_t objectTex );
    virtual ~Background() = default;
};