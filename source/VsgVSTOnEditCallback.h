#ifndef __VsgVSTOnEditCallback_h__
#define __VsgVSTOnEditCallback_h__

class VsgVSTOnEditCallback : public VsgOnEditCallback {
public:
	VsgVSTOnEditCallback() : mCallback(NULL) {}
	void setCallback(VsgOnEditCallback *callback) { mCallback = callback; }
	
	void beginEdit(long index) { mCallback->beginEdit(index); }
	void endEdit(long index) { mCallback->endEdit(index); }
private:
	VsgOnEditCallback *mCallback;
};

#endif

