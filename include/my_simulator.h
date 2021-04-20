//
// Created by Owenz on 4/19/2021.
//
#pragma warning( disable : 4819 4244)
#pragma once


#ifndef FINAL_PROJECT_XZ90_MY_SIMULATOR_H
#define FINAL_PROJECT_XZ90_MY_SIMULATOR_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "my_controller.h"
#include "CinderOpenCV.h"

using namespace ci;
using namespace ci::app;


namespace myapp {

class MyApp : public ci::app::App{
public:
    MyApp();

    void draw() override;
    void update() override;
    void setup() override;

    /**
     * To take the input of keyboard and make some addition
     * in particles' position and velocity
     * @param event "wasd" for accelerates in four directions,
     * and "up down" arrows to speed up or slow down
     */
    void keyDown(cinder::app::KeyEvent event);

    const int kWindowSize = 2000;

    gl::Texture2dRef myImage;


    };

} // namespace myapp
#endif //FINAL_PROJECT_XZ90_MY_SIMULATOR_H
