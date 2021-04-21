//
// Created by Owenz on 4/19/2021.
//

#include "../include/my_particle.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"

using namespace ci;
using namespace myapp;

Particle::Particle()
{
}

Particle::Particle( vec2 loc, vec2 vel )
{
    // variables for location, velocity and acceleration
    mLoc			= loc;
    mVel			= vel;
    mAcc			= vec2(0,0);

    // Decay value,radius, mass, scale
    mDecay			= Rand::randFloat( 0.95f, 0.951f );
    mRadius			= 5.0f + Rand::randFloat( 0.2f );
    mRadiusDest		= 5.0f;
    mMass			= mRadius * mRadius * 0.0001f + 0.01f;

    // value for changing its radius
    mScale			= 7.0f;

    // not in use so far
    mAge			= 0;
    mLifespan		= Rand::randInt( 50, 250 );
    mIsDead			= false;
}

void Particle::pullToCenter()
{
    // decrease the velocity as it approaches to the center
    vec2 dirToCenter = mLoc - app::getWindowCenter();
    mVel -= dirToCenter * mMass * 0.025f;
}

void Particle::applyPerlin( const Perlin &perlin )
{
    // from Cinder Tutorial: Chapter4
    // add perlin noise for particles
    float nX = mLoc.x * 0.005f;
    float nY = mLoc.y * 0.005f;
    float nZ = app::getElapsedFrames() * 0.0025f;
    float noise = perlin.fBm( nX, nY, nZ );
    float angle = noise * 15.0f;
    vec2 noiseVector( cos( angle ), sin( angle ) );
    mVel += noiseVector * mMass * 1.0f;
}

void Particle::update( const Channel32f &channel, const vec2 &mouseLoc )
{
    // add velocity
    mVel += mAcc;

    // to guarantee the max velocity
    float maxVel = mRadius + 0.025f;

    float velLength = mVel[0]*mVel[0]+mVel[1]*mVel[1] + 0.1f;
    if( velLength > maxVel*maxVel ){
        mVel[0]/=velLength;
        mVel[1]/=velLength;
        mVel *= maxVel;
    }

    // change the location of certain particle
    mLoc += mVel;
    mVel *= mDecay;
    mAcc = vec2( 0, 0 );

    // decrease the size of the particle
    if( mLoc.x >= 0.0f && mLoc.x <= (float)app::getWindowWidth() - 1 &&
        mLoc.y >= 0.0f && mLoc.y <= (float)app::getWindowHeight() - 1 ) {
        mRadiusDest	= channel.getValue( mLoc ) * mScale + 0.5f;
    } else {
        mRadiusDest = 0.1f;
    }

    // decrease the mass
    mRadius -= ( mRadius - mRadiusDest ) * 0.1f;
    mMass		= mRadius * mRadius * 0.0001f + 0.01f;

    //Uncomment these lines to enable particles to die over time
    //mAge++;
    //if( mAge > mLifespan ) mIsDead = true;
}

void Particle::draw()
{
    // draw particles depending on the location and radius
    gl::drawSolidCircle( mLoc, mRadius );
}


