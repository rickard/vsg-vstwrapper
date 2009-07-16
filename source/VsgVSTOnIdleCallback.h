#ifndef __VsgVSTIdler_h__
#define __VsgVSTIdler_h__

#import "vsg/VsgOnIdleCallback.h"

class VsgVSTOnIdleCallback : public Vsg::VsgOnIdleCallback {
public:
	VsgVSTOnIdleCallback() : mIdler(NULL) {}
	
	void setCallback(Vsg::VsgOnIdleCallback *idler) { this->mIdler = idler; }
	
	void idleCallback() { mIdler->idleCallback(); }
	void masterIdleCallback() { mIdler->masterIdleCallback(); }
private:
	Vsg::VsgOnIdleCallback *mIdler;
};

#endif

