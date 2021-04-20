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

namespace myapp {

    using cinder::app::KeyEvent;

    MyApp::MyApp() { }

    void MyApp::setup() {
//        auto img = loadImage( loadAsset( "image.jpg" ) );
        auto img = loadImage("C:\\Download\\Cinder\\my-projects\\final-project-xz90\\src\\image.jpg" );
        myImage = gl::Texture2d::create( img );

    }


    void MyApp::update() { }

    void MyApp::draw() {
        cinder::gl::clear();
//        cinder::gl::clear( cinder::Color( 1, 0, 0 ), true );
//        float gray = float(sin( getElapsedSeconds() )) * 0.5f + 0.5f;
//        cinder::gl::clear( cinder::Color( double(gray),double(gray),double(gray) ), true );
        gl::draw( myImage );

    }

    void MyApp::keyDown(KeyEvent event) { }

}