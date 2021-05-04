//
// Created by Owenz on 4/19/2021.
//

#include "../include/my_simulator2.h"
//#include "my_simulator.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"


#include <cinder/app/App.h>

using namespace ci;
using namespace ci::app;
using glm::vec2;

namespace myapp {

    void MyApp2::setup()
    {
        try{
            mCamera = Capture::create( 1280, 960 );
            mCamera->start();
        } catch( ... ) {
            console() << "Could not initialize the capture" << endl;
        }

        ParticleController m;

        mPerlin = Perlin();

        mChannel = Channel32f ( loadImage("C:\\Download\\Cinder\\my-projects\\final-project-xz90\\src\\baymax.jpg") );
        auto img = loadImage("C:\\Download\\Cinder\\my-projects\\final-project-xz90\\src\\baymax.jpg" );
        mTexture = gl::Texture2d::create( img );


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

    void MyApp2::keyDown( KeyEvent event )
    {
        if( event.getChar() == '1' ){
            mDrawImage = ! mDrawImage;
        }

        if( event.getChar() == 's' ){
            mSaveFrames = ! mSaveFrames;
        } else if( event.getChar() == 'd' ){
            mDisappear = ! mDisappear;
        }
    }


    void MyApp2::update()
    {
        if( mCamera ){
            if( mCamera->checkNewFrame() ){
                auto img = *mCamera->getSurface();
                mChannel = Channel32f ( img );
                mTexture = gl::Texture::create(img, gl::Texture::Format().loadTopDown());

            }
        }

        if( mDisappear )
            mParticleController.disappear();

        mParticleController.update( mChannel );
    }

    void MyApp2::draw()
    {
        gl::clear( Color( 0, 0, 0 ), true );
        mParticleController.draw();

        if( mDrawImage ){
//            mTexture.enableAndBind();
            mTexture->bind();
            gl::draw( mTexture, getWindowBounds() );
        }

        if( mSaveFrames ){
            writeImage( getHomeDirectory().string() + "Desktop/renders/image_" + toString( getElapsedFrames() ) + ".png",copyWindowSurface());
        }
    }

}













