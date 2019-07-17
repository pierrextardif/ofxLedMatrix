#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(100);
	ofSetLogLevel(OF_LOG_ERROR);	
	ofSetVerticalSync(true);
	backGroundColor = ofColor::fuchsia;


	#ifdef COMPUTERWORK
		
		f.allocate(WIDTH, HEIGHT, GL_RGBA);
		cam.setDistance(400);
	
	#else
	
		ledMatrix.setup(WIDTH, HEIGHT);
		cam.setDistance(40);
	
	#endif

	acceleration = ofVec3f(1.0, 1.0, 1.0);

	#ifdef COMPUTERWORK
		amountPoints = 500;
	#else
		amountPoints = 40;
	#endif
	increments = initPolyline(WIDTH, HEIGHT, &points);

	poly.setMode(OF_PRIMITIVE_LINES);


}

//--------------------------------------------------------------
void ofApp::update(){

	#ifndef COMPUTERWORK
		acceleration = {	float(ledMatrix.xx) / 32000,
							float(ledMatrix.yy) / 32000,
							float(ledMatrix.zz) / 32000 };
		// cout << "acceleration = " << ofToString(acceleration) << endl;
	#endif


	points = updatePolyline(points);

	float thresholdVbo = 10;
	#ifdef COMPUTERWORK
		thresholdVbo = 25 + 25 * sin( ofNoise(ofGetElapsedTimef() * 2) );
	#endif

	updateVbo(points, &poly,thresholdVbo);
	
	#ifdef COMPUTERWORK
		f.begin();
	#else
		ledMatrix.begin();
	#endif

		cam.begin();
		ofEnableDepthTest();

	#ifndef COMPUTERWORK
		ofRotateXRad(acceleration.x * M_PI);
		ofRotateYRad(acceleration.y * M_PI);
		ofRotateZRad(acceleration.z * M_PI);
	#endif

		ofClear(0,0);
		ofBackground(ofColor::black);

		ofPushMatrix();
		ofSetColor(255, 0,0, 255);
		// float radiusSize = 0.4;
		float radiusSize = 2;
		for(int i=0;i<points.size();i++){
			ofDrawCircle({points[i].x, points[i].y, points[i].z}, radiusSize);
		}

		ofSetColor(255, 255);
		poly.draw();

		ofPopMatrix();
		ofDisableDepthTest();
		cam.end();
	
	#ifdef COMPUTERWORK
			f.end();
		#else
			ledMatrix.end();
			ledMatrix.updateMatrixLED();
	#endif

}

//--------------------------------------------------------------
void ofApp::draw(){

	#ifdef COMPUTERWORK
		
		f.draw(0,0);

	#endif

}

vector < ofVec3f> ofApp::initPolyline(int _width, int _height, vector < ofVec3f >* pol){

	for( int i=0;i< amountPoints;i++){
		ofVec3f point = {ofRandom(_width) - _width / 2, ofRandom(_height) - _height / 2, 0};
		// ofColor tempCol = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 210);
		(pol->push_back(point));
		//pol->addIndex(indexVertex);
		//pol->addColor(tempCol);

	}

	return incrementsInit(amountPoints);
}

vector < ofVec3f > ofApp::incrementsInit(int amountPoints){
	vector < ofVec3f > increments;

	float speed = 0.4;
	for (int i = 0; i < amountPoints; ++i)
	{
		increments.push_back({	ofRandom(speed) * pow(-1, i+1),
								ofRandom(speed),
								ofRandom(speed) * pow(-1, i+2) });
	}

	return increments;
}

vector < ofVec3f > ofApp::updatePolyline(vector < ofVec3f > pol){
	for(int i=0;i<pol.size();i++){
		ofVec3f temp = pol[i];

		temp.x += increments[i].x * acceleration.x;
		temp.y += increments[i].y * acceleration.y;
		temp.z += increments[i].z * acceleration.z;
		
		if( (temp.x > WIDTH / 2) || (temp.x < - WIDTH / 2) )increments[i].x = -increments[i].x;
		if( (temp.y > HEIGHT / 2 ) || (temp.y < - HEIGHT / 2) )increments[i].y = -increments[i].y;
		if( (temp.x > WIDTH / 2) || (temp.z < -WIDTH / 2) )increments[i].z = -increments[i].z;

		pol[i] = temp;
	}
	return pol;
}


void ofApp::updateVbo(vector < ofVec3f > points, ofVboMesh* poly, float distThreshold){
	poly->clear();

	for(int i = 0; i < points.size();i++){
		for( int j=0;j<points.size();j++){
			float dist = sqrt( 	pow(points[i].x - points[j].x, 2) + 
								pow(points[i].y - points[j].y, 2) +
								pow(points[i].z - points[j].z, 2) );
			if(dist < distThreshold){
				poly->addVertex(points[i]);
				poly->addVertex(points[j]);
			}
		}
	}
}