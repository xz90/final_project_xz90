//
// Created by Owenz on 5/3/2021.
//
#pragma warning( disable : 4819 4305)
#pragma once
#ifndef FINAL_PROJECT_XZ90_MY_PARTICLE2_H
#define FINAL_PROJECT_XZ90_MY_PARTICLE2_H


class my_particle2 {

};


#endif //FINAL_PROJECT_XZ90_MY_PARTICLE2_H


#pragma once
#include "Particle.h"
#include <list>
class ParticleController {
public:
    ParticleController();
    void update();
    void draw();
    void addParticles( int amt );
    void removeParticles( int amt );
    std::list<Particle> mParticles;
};