//
// Created by Owenz on 4/19/2021.
//
#pragma warning( disable : 4819 )
#include "my_simulator2.h"

using myapp::MyApp2;

void prepareSettings(MyApp2::Settings* settings) {
//    settings->setResizable(false);
    settings->setWindowSize( 900, 1100 );
    settings->setFrameRate( 30.0f );
}


// This line is a macro that expands into an "int main()" function.
CINDER_APP(MyApp2, ci::app::RendererGl, prepareSettings);