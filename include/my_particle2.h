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
        Particle( vec2 );
        void update();
        void draw();
        vec2 mLoc;
        vec2 mVel;
        float mRadius;
    };
} // namespace myapp



#endif //FINAL_PROJECT_XZ90_MY_PARTICLE2_H

