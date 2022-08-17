#include "Graphics/Graphics.h"

class Ray
{
    public:
        Ray() : tMax(Infinity), time(0.f) {}
        Ray(const glm::vec3 &o, const glm::vec3 &d, float tMax = Infinity, float time = 0.f) 
        : o(o), d(d), tMax(tMax), time(time)  {}
        glm::vec3 operator()(float t) const {return o + d * t; }
        bool HasNaNs() const { return glm::any(glm::isnan(o)) || glm::any(glm::isnan(d)) || std::isnan(tMax);}
        

    private:
        glm::vec3 d;
        glm::vec3 o;
        mutable glm::float32 tMax;
        float time;

};