//
// Created by Owenz on 4/19/2021.
//
#pragma warning( disable : 4819 )
#include <catch2/catch.hpp>
#include "../include/my_particle.h"

using myapp::Particle;

TEST_CASE("Particle constructor") {
    SECTION("Default constructor") {
        Particle sample;
        SUCCEED();
    }
    SECTION("Customized constructor") {
        Particle sample1(vec2(1,2),vec2(2,2));
        REQUIRE(sample1.mVel == vec2(2,2));
        REQUIRE(sample1.mLoc == vec2(1,2));
    }
}