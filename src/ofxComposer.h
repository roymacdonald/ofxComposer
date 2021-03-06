//
//  ofxComposer.h
//  GPUBurner
//
//  Created by Patricio Gonzalez Vivo on 3/9/12.
//  Copyright (c) 2012 http://www.PatricioGonzalezVivo.com All rights reserved.
//

#define USE_OFXGLEDITOR

#ifndef OFXCOMPOSER
#define OFXCOMPOSER

#include "ofMain.h"
#include "ofxPatch.h"

#ifdef USE_OFXGLEDITOR
#include "ofxGLEditor.h"
#endif

class ofxComposer {
public:
    ofxComposer();
    
    void    load(string _fileConfig = "default");
    bool    addPatch(string _filePath, ofPoint _position);
    
    ofxPatch* operator[](int _nID){ if ( (_nID != -1) && (patches[_nID] != NULL) ) return patches[_nID]; };
    
    void    update();
    void    draw();
    
private:
    // Events
    void    _mouseMoved(ofMouseEventArgs &e);
    void    _keyPressed(ofKeyEventArgs &e);
	void    _mousePressed(ofMouseEventArgs &e);
	void    _mouseReleased(ofMouseEventArgs &e);
	void    _windowResized(ofResizeEventArgs &e);
    
    void    closePatch( int &_nID );
    void    activePatch( int _nID );
    bool    connect( int _fromID, int _toID, int _nTexture );

#ifdef USE_OFXGLEDITOR
	ofxGLEditor editor;
#endif
    ofFbo       fbo;
    
    map<int,ofxPatch*>  patches;
    
    string  configFile;
    
    int     selectedDot;
    int     selectedID;
    
    bool    bGLEditor;
};


#endif
