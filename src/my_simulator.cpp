//
// Created by Owenz on 4/19/2021.
//

#include "../include/my_simulator.h"
#include "my_simulator.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"


#include <cinder/app/App.h>

using namespace ci;
using namespace ci::app;
using glm::vec2;

namespace myapp {

    void MyApp::setup()
    {
        mPerlin = Perlin();

        mChannel = Channel32f ( loadImage("C:\\Download\\Cinder\\my-projects\\final-project-xz90\\src\\image1.jpg") );
//        mTexture = mChannel;
        auto img = loadImage("C:\\Download\\Cinder\\my-projects\\final-project-xz90\\src\\image1.jpg" );
        mTexture = gl::Texture2d::create( img );
//        mTexture = loadImage("C:\\Download\\Cinder\\my-projects\\final-project-xz90\\src\\image.jpg");

        mMouseLoc = vec2( 0, 0 );
        mMouseVel = vec2( 0, 0 );

        mDrawParticles	= true;
        mDrawImage		= false;
        mIsPressed		= false;
        mCentralGravity = false;
        mAllowPerlin	= false;
        mSaveFrames		= false;
        mDisappear      = false;
        mSaveFrameCount = 0;
    }


    void MyApp::mouseDown( MouseEvent event )
    {
        mIsPressed = true;
    }

    void MyApp::mouseUp( MouseEvent event )
    {
        mIsPressed = false;
    }

    void MyApp::mouseMove( MouseEvent event )
    {
        mMouseVel = ( vec2(event.getPos()) - mMouseLoc );
        mMouseLoc = event.getPos();
    }

    void MyApp::mouseDrag( MouseEvent event )
    {
        mouseMove( event );
    }

    void MyApp::keyDown( KeyEvent event )
    {
        if( event.getChar() == '1' ){
            mDrawImage = ! mDrawImage;
        } else if( event.getChar() == '2' ){
            mDrawParticles = ! mDrawParticles;
        }

        if( event.getChar() == 's' ){
            mSaveFrames = ! mSaveFrames;
        } else if( event.getChar() == 'g' ){
            mCentralGravity = ! mCentralGravity;
        } else if( event.getChar() == 'p' ){
            mAllowPerlin = ! mAllowPerlin;
        }else if( event.getChar() == '3'){
            writeImage( getHomeDirectory().string() + "Desktop/renders/images/image_" + toString( getElapsedFrames() ) + ".png",copyWindowSurface());
        }else if( event.getChar() == 'd' ){
            mDisappear = ! mDisappear;
        }
    }


    void MyApp::update()
    {
//        if( ! mChannel ) return;

        if( mIsPressed )
            mParticleController.addParticles( NUM_PARTICLES_TO_SPAWN, mMouseLoc, mMouseVel );

        if (getElapsedSeconds() < 10) {
            mParticleController.addDefaultParticles(30);
        }
        mParticleController.repulseParticles();

        if( mCentralGravity )
            mParticleController.pullToCenter();

        if( mAllowPerlin )
            mParticleController.applyPerlin( mPerlin );

        if( mDisappear )
            mParticleController.disappear();

        mParticleController.update( mChannel, mMouseLoc );
    }

    void MyApp::draw()
    {
        gl::clear( Color( 0, 0, 0 ), true );

        if( mDrawImage ){
//            mTexture.enableAndBind();
            mTexture->bind();
            gl::draw( mTexture, getWindowBounds() );
        }

        if( mDrawParticles ){
            glDisable( GL_TEXTURE_2D );
            mParticleController.draw();
        }

        if( mSaveFrames ){
            writeImage( getHomeDirectory().string() + "Desktop/renders/image_" + toString( getElapsedFrames() ) + ".png",copyWindowSurface());

        }
    }
}













