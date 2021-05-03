//
// Created by Owenz on 5/3/2021.
//
#pragma warning( disable : 4819 4305)
#pragma once

#ifndef FINAL_PROJECT_XZ90_MY_PARTICLE2_H
#define FINAL_PROJECT_XZ90_MY_PARTICLE2_H
#include "cinder\gl\gl.h"
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/Perlin.h"
#include <vector>

using glm::vec2;
namespace myapp{
    class Particle2 {
    public:
        Particle2();
        Particle2( vec2 );
        void update(const ci::Channel32f &channel);
        void draw();
        vec2 mLoc;
        vec2 mVel;
        float mRadius;
    };
} // namespace myapp



#endif //FINAL_PROJECT_XZ90_MY_PARTICLE2_H

