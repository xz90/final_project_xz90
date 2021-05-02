//
// Created by Owenz on 4/19/2021.
//

#include "../include/my_simulator2.h"
#include "my_simulator.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"


#include <cinder/app/App.h>

using namespace ci;
using namespace ci::app;
using glm::vec2;

namespace myapp {

    void MyApp2::setup()
    {
//        try{
//            mCamera = Capture::create( 640, 480 );
//            mCamera->start();
//        } catch( ... ) {
//            console() << "Could not initialize the capture" << endl;
//        }




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


    void MyApp2::mouseDown( MouseEvent event )
    {
        mIsPressed = true;
    }

    void MyApp2::mouseUp( MouseEvent event )
    {
        mIsPressed = false;
    }

    void MyApp2::mouseMove( MouseEvent event )
    {
        mMouseVel = ( vec2(event.getPos()) - mMouseLoc );
        mMouseLoc = event.getPos();
    }

    void MyApp2::mouseDrag( MouseEvent event )
    {
        mouseMove( event );
    }

    void MyApp2::keyDown( KeyEvent event )
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


    void MyApp2::update()
    {
//        if( mCamera ){
//            if( mCamera->checkNewFrame() ){
//                auto img = *mCamera->getSurface();
//                mChannel = Channel32f ( img );
//                mTexture = gl::Texture::create(img, gl::Texture::Format().loadTopDown());
//
//            }
//        }

//        if( ! mChannel ) return;

        if( mIsPressed )
            mParticleController.addParticles( NUM_PARTICLES_TO_SPAWN, mMouseLoc, mMouseVel );

//        if (getElapsedSeconds() < 10) {
//            mParticleController.addDefaultParticles(30);
//        }
        mParticleController.repulseParticles();

        if( mCentralGravity )
            mParticleController.pullToCenter();

        if( mAllowPerlin )
            mParticleController.applyPerlin( mPerlin );

        if( mDisappear )
            mParticleController.disappear();

        mParticleController.update( mChannel, mMouseLoc );
    }

    void MyApp2::draw()
    {
//        gl::clear( Color( 0, 0, 0 ) );
//        if( mTexture ){
//            gl::draw( mTexture, getWindowBounds() );
//        }




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













