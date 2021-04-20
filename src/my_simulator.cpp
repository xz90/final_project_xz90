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
//
//    using cinder::app::KeyEvent;
//
////    MyApp::MyApp() { }
//
//    void MyApp::setup() {
////        auto img = loadImage( loadAsset( "image.jpg" ) );
//        auto img = loadImage("C:\\Download\\Cinder\\my-projects\\final-project-xz90\\src\\image.jpg" );
//        myImage = gl::Texture2d::create( img );
//
//    }
//
//
//    void MyApp::update() { }
//
//    void MyApp::draw() {
//        cinder::gl::clear();
////        // red background
////        cinder::gl::clear( cinder::Color( 1, 0, 0 ), true );
//
////        // black white changing background
////        float gray = float(sin( getElapsedSeconds() )) * 0.5f + 0.5f;
////        cinder::gl::clear( cinder::Color( double(gray),double(gray),double(gray) ), true );
//
//        gl::draw( myImage );
//        gl::drawSolidCircle( vec2( 800, 600 ), 50.0 );
//        double x = cos( getElapsedSeconds() )*50 + double(getWindowWidth())/2;
//        double y = sin( getElapsedSeconds() )*50 + double(getWindowHeight())/2;
//        gl::drawSolidCircle( vec2( x, y ), 50.0 );
//
//
//    }
//
//    void MyApp::keyDown(KeyEvent event) { }



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
        }
    }


    void MyApp::update()
    {
//        if( ! mChannel ) return;

        if( mIsPressed )
            mParticleController.addParticles( NUM_PARTICLES_TO_SPAWN, mMouseLoc, mMouseVel );

        mParticleController.repulseParticles();

        if( mCentralGravity )
            mParticleController.pullToCenter();

        if( mAllowPerlin )
            mParticleController.applyPerlin( mPerlin );

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













