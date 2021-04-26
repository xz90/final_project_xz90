//
// Created by Owenz on 4/25/2021.
//
//#pragma comment (lib, "opencv_core248d.lib")
//#pragma comment (lib, "opencv_highgui248d.lib")
//#pragma comment (lib, "opencv_imgproc248d.lib")
//#pragma comment (lib, "opencv_video248d.lib")
//#pragma comment (lib, "opencv_features2d248d.lib")
#pragma warning( disable : 4819 4003)
#include "my_simulator.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Capture.h"

//#include "C:\Download\Cinder\blocks\Cinder-OpenCV3\include\CinderOpenCV.h"

using myapp::MyApp;
using namespace ci;
using namespace ci::app;

class ocvCaptureApp : public App {
public:
    void setup();
    void update();
    void draw();

    CaptureRef			mCapture;
    gl::TextureRef		mTexture;
};

void ocvCaptureApp::setup()
{
    try {
        mCapture = Capture::create( 640, 480 );
        mCapture->start();
    }
    catch( ... ) {
        console() << "Failed to initialize capture" << std::endl;
    }
}

void ocvCaptureApp::update()
{
    if( mCapture && mCapture->checkNewFrame() ) {
        cv::Mat input( toOcv( *mCapture->getSurface() ) ), output;

        cv::Sobel( input, output, CV_8U, 1, 0 );

//		cv::threshold( input, output, 128, 255, CV_8U );
//		cv::Laplacian( input, output, CV_8U );
//		cv::circle( output, toOcv( Vec2f(200, 200) ), 300, toOcv( Color( 0, 0.5f, 1 ) ), -1 );
//		cv::line( output, cv::Point( 1, 1 ), cv::Point( 30, 30 ), toOcv( Color( 1, 0.5f, 0 ) ) );

        mTexture = gl::Texture::create( fromOcv( output ), gl::Texture::Format().loadTopDown() );
    }
}

void ocvCaptureApp::draw()
{
    gl::clear();
    if( mTexture )
        gl::draw( mTexture );
}


CINDER_APP( ocvCaptureApp, RendererGl )