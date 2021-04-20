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
        Particle();
        Particle( vec2 , vec2 );
        void pullToCenter();
        void applyPerlin( const ci::Perlin &perlin );
        void update( const ci::Channel32f &channel, const vec2 &mouseLoc );
        void draw();

        vec2 mLoc;
        vec2 mVel;
        vec2 mAcc;

        float		mDecay;
        float		mRadius, mRadiusDest;
        float		mScale;

        float		mMass;

        int			mAge;
        int			mLifespan;
        bool		mIsDead;
    };



} // namespace myapp



#endif //FINAL_PROJECT_XZ90_MY_PARTICLE_H




