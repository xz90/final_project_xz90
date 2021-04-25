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
#include "C:\Download\Cinder\blocks\Cinder-OpenCV3\include\CinderOpenCV.h"
#include "cinder/app/App.h"
#include "cinder/ImageIO.h"
#include "cinder/gl/Texture.h"
#include "cinder/Perlin.h"
#include "cinder/Channel.h"
#include "cinder/Vector.h"
#include "cinder/Utilities.h"
#include "../include/my_controller.h"
#include <sstream>
#define RESOLUTION 10
#define NUM_PARTICLES_TO_SPAWN 15


using namespace ci;
using namespace ci::app;
using std::stringstream;

namespace myapp {

class MyApp : public ci::app::App{
public:
//    MyApp();


    void draw() override;
    void update() override;
    void setup() override;


    void keyDown(KeyEvent event);
    void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );




    Perlin mPerlin;

    Channel32f mChannel;
    gl::Texture2dRef mTexture;

    vec2 mMouseLoc;
    vec2 mMouseVel;
    bool mIsPressed;

    ParticleController mParticleController;

    bool mDrawParticles;
    bool mDrawImage;
    bool mSaveFrames;
    bool mCentralGravity;
    bool mAllowPerlin;
    bool mDisappear;

    int mSaveFrameCount;
    };

} // namespace myapp
#endif //FINAL_PROJECT_XZ90_MY_SIMULATOR_H
