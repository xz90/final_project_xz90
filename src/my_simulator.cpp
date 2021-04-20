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
//        // red background
//        cinder::gl::clear( cinder::Color( 1, 0, 0 ), true );

//        // black white changing background
//        float gray = float(sin( getElapsedSeconds() )) * 0.5f + 0.5f;
//        cinder::gl::clear( cinder::Color( double(gray),double(gray),double(gray) ), true );

        gl::draw( myImage );
        gl::drawSolidCircle( vec2( 800, 600 ), 50.0 );
        double x = cos( getElapsedSeconds() )*50 + double(getWindowWidth())/2;
        double y = sin( getElapsedSeconds() )*50 + double(getWindowHeight())/2;
        gl::drawSolidCircle( vec2( x, y ), 50.0 );


    }

    void MyApp::keyDown(KeyEvent event) { }

}