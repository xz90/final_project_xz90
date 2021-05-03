//
// Created by Owenz on 4/19/2021.
//

#include "../include/my_controller.h"
#include "cinder/app/App.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"

using namespace ci;
using namespace myapp;
using std::list;

ParticleController::ParticleController()
{
}

void ParticleController::repulseParticles()
{
    for( list<Particle>::iterator p1 = mParticles.begin(); p1 != mParticles.end(); ++p1 ){

        list<Particle>::iterator p2 = p1;
        for( ++p2; p2 != mParticles.end(); ++p2 ) {
            vec2 dir = p1->mLoc - p2->mLoc;

            float thresh = ( p1->mRadius + p2->mRadius ) * 5.0f;
            if( dir.x > -thresh && dir.x < thresh && dir.y > -thresh && dir.y < thresh ){
//                float distSqrd = dir.lengthSquared() * dir.length();
                float distSqrd = (dir[0]*dir[0]+dir[1]*dir[1]) * dir.length();

                if( distSqrd > 0.0f ){
                    float F = 1.0f/distSqrd;
//                    dir.normalize();
                    dir[0]/=(dir[0]*dir[0]+dir[1]*dir[1]);
                    dir[1]/=(dir[0]*dir[0]+dir[1]*dir[1]);

                    // acceleration = force / mass
                    p1->mAcc += ( F * dir ) / p1->mMass;
                    p2->mAcc -= ( F * dir ) / p2->mMass;
                }
            }
        }
    }
}

void ParticleController::pullToCenter()
{
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
        p->pullToCenter();
    }
}

void ParticleController::disappear() {
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
        p->disappear();
//        p->mVel = vec2(10,-100);
//        p->mAcc = vec2(0,-100);
    }
}


void ParticleController::applyPerlin( const Perlin &perlin )
{
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
        p->applyPerlin( perlin );
    }
}

void ParticleController::update( const Channel32f &channel, const vec2 &mouseLoc )
{
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ){
        if( p->mIsDead ){
            p = mParticles.erase( p );
        } else {
            p->update( channel, mouseLoc );
            ++p;
        }
    }
}

void ParticleController::draw()
{
    for( list<Particle>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
        p->draw();
    }
}

void ParticleController::addParticles( int amt, const vec2 &mouseLoc, const vec2 &mouseVel )
{
    for( int i=0; i<amt; i++ )
    {
        vec2 loc = mouseLoc + Rand::randVec2() * Rand::randFloat( 5.0f );
        vec2 velOffset = Rand::randVec2() * Rand::randFloat( 1.0f, 3.0f );
        vec2 vel = mouseVel * 5.0f + velOffset;
        mParticles.push_back( Particle( loc, vel ) );
    }

    std::cout << mParticles.size() << std::endl;
}

void ParticleController::removeParticles( int amt )
{
    for( int i=0; i<amt; i++ )
    {
        mParticles.pop_back();
    }
}

void ParticleController::addDefaultParticles(int amt) {

    for( int y=0; y<960; y++ ){
        for( int x=0; x<1280; x++ ){
            addDefaultParticleHelper( x, y );
        }
    }

//    for( int i=0; i<amt; i++ )
//    {
//        vec2 mouseLoc = vec2(Rand::randFloat( 0.0f, 900.0f ),Rand::randFloat( 0.0f, 1100.0f ));
//        vec2 mouseVel = vec2(Rand::randFloat( -10.0f, 10.0f ),Rand::randFloat( -10.0f, 10.0f ));
//
//        vec2 loc = mouseLoc + Rand::randVec2() * Rand::randFloat( 5.0f );
//        vec2 velOffset = Rand::randVec2() * Rand::randFloat( 1.0f, 3.0f );
//        vec2 vel = mouseVel * 5.0f + velOffset;
//        mParticles.push_back( Particle( loc, vel ) );
//    }
//
//    std::cout << mParticles.size() << std::endl;


}

void ParticleController::addDefaultParticleHelper( int xi, int yi ) {
    float x = ( xi + 0.5f ) * 10.0f;
    float y = ( yi + 0.5f ) * 10.0f;
    mParticles.push_back( Particle( vec2( x, y ), vec2(0,0) ) );
}


