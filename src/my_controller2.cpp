//
// Created by Owenz on 5/3/2021.
//

#include "my_controller2.h"
#include "cinder/app/App.h"
#include "cinder/Rand.h"
#include "cinder/Vector.h"

using namespace ci;
using namespace myapp;
using std::list;

ParticleController2::ParticleController2()
{
    for( int y=0; y<96; y++ ){
        for( int x=0; x<128; x++ ){
            addParticle( x, y );
        }
    }
}

void ParticleController2::update(const ci::Channel32f &channel) {
    for( list<Particle2>::iterator p = mParticles2.begin(); p != mParticles2.end(); ++p ){
        p->update(channel);
    }
}

void ParticleController2::draw() {
    for( list<Particle2>::iterator p = mParticles2.begin(); p != mParticles2.end(); ++p ){
        p->draw();
    }
}

void ParticleController2::addParticles(int amt) {

}

void ParticleController2::addParticle( int xi, int yi ) {
    float x = ( xi + 0.5f ) * 10.0f;
    float y = ( yi + 0.5f ) * 10.0f;
    mParticles2.push_back( Particle2( vec2( x, y ) ) );
}

void ParticleController2::disappear() {
    for( list<Particle2>::iterator p = mParticles2.begin(); p != mParticles2.end(); ++p ){
        p->disappear();
    }
}