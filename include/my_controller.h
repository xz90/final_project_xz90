//
// Created by Owenz on 4/19/2021.
//
#pragma warning( disable : 4819 )
#pragma once

#ifndef FINAL_PROJECT_XZ90_MY_CONTROLLER_H
#define FINAL_PROJECT_XZ90_MY_CONTROLLER_H

#include "cinder\gl\gl.h"
#include "cinder/Channel.h"
#include "../include/my_particle.h"
#include "cinder/Perlin.h"
#include <list>

namespace myapp{
    class ParticleController {
    public:
        ParticleController();
        void repulseParticles();
        void pullToCenter();
        void applyPerlin( const ci::Perlin &perlin );
        void update( const ci::Channel32f &channel, const vec2 &mouseLoc );
        void draw();
        void addParticles( int amt, const vec2 &mouseLoc, const vec2 &mouseVel );
        void addDefaultParticles( int amt );
        void removeParticles( int amt );

        std::list<Particle>	mParticles;

        void disappear();
    };




} // namespace myapp


#endif //FINAL_PROJECT_XZ90_MY_CONTROLLER_H
