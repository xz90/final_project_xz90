//
// Created by Owenz on 4/19/2021.
//
#pragma warning( disable : 4819 4305)
#pragma once


#ifndef FINAL_PROJECT_XZ90_MY_PARTICLE_H
#define FINAL_PROJECT_XZ90_MY_PARTICLE_H
#include "cinder\gl\gl.h"
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "cinder/Perlin.h"
#include <vector>


using glm::vec2;

namespace myapp{
    class Particle {
    public:
        /**
         * Customized particle constructor without location and velocity values
         */
        Particle();

        /**
         * Default particle constructor
         * first vec2: location vector
         * second vec2: velocity vector
         */
        Particle( vec2 , vec2 );

        /**
         * pull the particle to center by changing its velocity
         */
        void pullToCenter();

        /**
         * pull the particle upwards by changing its velocity
         */
        void disappear();

        /**
         * add perlin noise for particles
         * @param perlin the original perlin class
         */
        void applyPerlin( const ci::Perlin &perlin );

        /**
         * update the situation of particles
         * @param channel pass the image to particles
         * @param mouseLoc the vector of mouse location
         */
        void update( const ci::Channel32f &channel, const vec2 &mouseLoc );

        /**
         * draw a single particle
         */
        void draw();

        vec2 mLoc;
        vec2 mVel;
        vec2 mAcc;

        // variables to change the size, mass and velocity of a particle
        float mDecay;
        float mRadius, mRadiusDest;
        float mScale;
        float mMass;

        // not in use so far
        int	mAge;
        int	mLifespan;
        bool mIsDead;

        bool shouldDisappear;
    };



} // namespace myapp



#endif //FINAL_PROJECT_XZ90_MY_PARTICLE_H




