#include "material.hpp"
#include <GL/gl.h>
#include <cstring>

Material::Material(float mi, float density, float r, float g, float b) : mi(mi), density(density)

{

    color[0] = r;
    color[1] = g;
    color[2] = b;
}

float Material::getDensity()
{
    return this->density;
}

float Material::getMi()
{
    return this->mi;
}

void Material::apply()
{
    glColor3f(this->color[0], this->color[1], this->color[2]);
}
