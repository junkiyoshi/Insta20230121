#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(270);
	ofRotateZ(-15);

	auto radius = 300;


	for (auto deg = 0; deg < 360 * 10; deg += 10) {

		auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), ofMap(deg, 0, 360 * 10, -900, 900));

		ofPushMatrix();
		ofTranslate(location);
		ofRotateZ(deg);

		auto noise_value = ofNoise(deg * 0.0005 + ofGetFrameNum() * 0.0025);

		if (noise_value > 0.4 && noise_value < 0.5) {

			auto rotate_y = ofMap(noise_value, 0.4, 0.5, -180, 180);
			ofRotateY(rotate_y);
		}

		ofFill();
		ofSetColor(0);
		ofDrawBox(45);

		ofNoFill();
		ofSetColor(255);
		ofDrawBox(45);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}