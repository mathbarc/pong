#ifndef MATERIAL_HPP
#define MATERIAL_HPP
#include <initializer_list>

class Material
{
    public:
        Material(float mi, float density, float r, float g, float b);

        float getMi();
        float getDensity();

        void apply();


    private:
        float mi;
        float color[3];
        float density;
};

static const Material ice(0.05, 1, 0.7, 0.7, 1.);
static const Material wood(0.1, 1.5, 0.5, 0.5, 0.);
static const Material pool(0.2, 1.2, 0., 0.5, 0.);
static const Material metal(0.075, 2, 0.2, 0.2, 0.2);

#endif
