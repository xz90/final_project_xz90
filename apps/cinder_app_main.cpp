//
// Created by Owenz on 4/19/2021.
//
#pragma warning( disable : 4819 )
#include "my_simulator.h"

using myapp::MyApp;

void prepareSettings(MyApp::Settings* settings) {
//    settings->setResizable(false);
    settings->setWindowSize( 900, 1100 );
    settings->setFrameRate( 30.0f );
}


// This line is a macro that expands into an "int main()" function.
CINDER_APP(MyApp, ci::app::RendererGl, prepareSettings);