//
// Created by Owenz on 5/3/2021.
//
#pragma once
#include ".h"
#include <list>
#ifndef FINAL_PROJECT_XZ90_MY_CONTROLLER2_H
#define FINAL_PROJECT_XZ90_MY_CONTROLLER2_H


class my_controller2 {

};



class ParticleController {
public:
    ParticleController();
    void update();
    void draw();
    void addParticles( int amt );
    void removeParticles( int amt );
    std::list<Particle> mParticles;
};

#endif //FINAL_PROJECT_XZ90_MY_CONTROLLER2_H
