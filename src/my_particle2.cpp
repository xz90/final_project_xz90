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
    shouldDisappear = false;
}


void Particle2::update( const Channel32f &channel ) {
    float gray = channel.getValue( mLoc );
    mRadius = channel.getValue( mLoc ) * 7.0f;

    if (shouldDisappear) {
        vec2 dirToCenter = mLoc - vec2(640,0);
        vec2 mAcc = vec2(Rand::randFloat( -10.0f, 10.0f ),Rand::randFloat( -500.0f, 0.0f )/dirToCenter[1]);
        mVel += mAcc;
        mLoc += mVel;
        return;
    }
}

void Particle2::draw() {
    gl::drawSolidCircle( mLoc, mRadius );
}
void Particle2::disappear() {
    shouldDisappear = true;
}

