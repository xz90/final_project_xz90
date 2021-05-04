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
        /**
         * Default constructor
         */
        ParticleController2();

        /**
         * update function to update all particles
         * @param channel the channel class
         */
        void update(const ci::Channel32f &channel);
        void draw();

        /**
         * add certain amount of particles
         * @param amt the number of particles
         */
        void addParticles( int amt );

        /**
         * remove certain amount of particles
         * @param amt the number of particles
         */
        void removeParticles( int amt );

        std::list<Particle2> mParticles2;

        /**
         * add particle using the input location x and y
         * @param xi
         * @param yi
         */
        void addParticle(int xi, int yi);

        /**
         * disappear function
         */
        void disappear();
    };





}// namespace myapp


#endif //FINAL_PROJECT_XZ90_MY_CONTROLLER2_H
