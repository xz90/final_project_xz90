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
    /**
     * particle2 class
     */
    class Particle2 {
    public:
        /**
         * Default constructor
         */
        Particle2();

        /**
         * vec2 represents its location
         */
        Particle2( vec2 );

        /**
         * update function to change the scene
         * @param channel the picture channel
         */
        void update(const ci::Channel32f &channel);

        void draw();

        vec2 mLoc;
        vec2 mVel;
        float mRadius;

        /**
         * disappear function
         */
        void disappear();

        bool shouldDisappear;
    };
} // namespace myapp



#endif //FINAL_PROJECT_XZ90_MY_PARTICLE2_H

