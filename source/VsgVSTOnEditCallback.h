#ifndef __VsgVSTOnEditCallback_h__
#define __VsgVSTOnEditCallback_h__

#include "vsg/VsgOnEditCallback.h"

class VsgVSTOnEditCallback : public Vsg::VsgOnEditCallback {
public:
	VsgVSTOnEditCallback() : mCallback(NULL) {}
	void setCallback(Vsg::VsgOnEditCallback *callback) { mCallback = callback; }
	
	void beginEdit(long index) { mCallback->beginEdit(index); }
	void endEdit(long index) { mCallback->endEdit(index); }
private:
	VsgOnEditCallback *mCallback;
};

#endif

