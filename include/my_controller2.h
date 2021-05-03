//
// Created by Owenz on 5/3/2021.
//
#pragma warning( disable : 4819 )
#pragma once

#ifndef FINAL_PROJECT_XZ90_MY_CONTROLLER2_H
#define FINAL_PROJECT_XZ90_MY_CONTROLLER2_H

#include "cinder\gl\gl.h"
#include "cinder/Channel.h"
#include "../include/my_particle2.h"
#include "cinder/Perlin.h"
#include <list>



namespace myapp {
    class ParticleController2 {
    public:
        ParticleController2();
        void update(const ci::Channel32f &channel);
        void draw();
        void addParticles( int amt );
        void removeParticles( int amt );
        std::list<Particle2> mParticles2;

        void addParticle(int xi, int yi);
    };





}// namespace myapp


#endif //FINAL_PROJECT_XZ90_MY_CONTROLLER2_H
