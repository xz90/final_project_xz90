//
// Created by Owenz on 4/19/2021.
//
#pragma warning( disable : 4819 )
#include <catch2/catch.hpp>
#include "../include/my_controller.h"

using myapp::Particle;
using namespace ci;
using namespace myapp;
using std::list;

TEST_CASE("Controller constructor") {
    SECTION("Default controller constructor") {
        ParticleController controller;
        SUCCEED();
    }
    SECTION("Add particles") {
        ParticleController controller;
        controller.addDefaultParticles(1);
    }
}
