//
// Created by Owenz on 5/3/2021.
//

#include "../include/my_particle2.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

using namespace ci;
using namespace myapp;

Particle2::Particle2()
{
}

Particle2::Particle2( vec2 loc)
{
    // variables for location, velocity and acceleration
    mLoc			= loc;
    mVel			= vec2(0,0);
    mRadius			= 4.0f;
}

void Particle2::update() {
    mLoc += mVel;
}

void Particle2::draw() {
    gl::drawSolidCircle( mLoc, mRadius );
}

