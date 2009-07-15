#ifndef __VsgVSTIdler_h__
#define __VsgVSTIdler_h__

#import "vsg/VsgIdler.h"

class VsgVSTIdler : public VsgIdler {
public:
	VsgVSTIdler() : mIdler(NULL) {}
	
	void setIdler(VsgIdler *idler) { this->mIdler = idler; }
	
	void idle() { mIdler->idle(); }
	void masterIdle() { mIdler->masterIdle(); }
private:
	VsgIdler *mIdler;
};

#endif

