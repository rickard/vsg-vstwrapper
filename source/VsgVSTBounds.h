#ifndef __VsgVSTBounds_h__
#define __VsgVSTBounds_h__

#include <vsg/VsgBounds.h>

class VsgVSTBounds : public VsgBounds {
public:
	VsgVSTBounds(short top, short left, short bottom, short right) : mTop(top), mLeft(left), mBottom(bottom), mRight(right) {}
	
	bool redrawAll() const { return false; }
	
	short getTop() const { return mTop; }
	short getLeft() const { return mLeft; }
	short getBottom() const { return mBottom; }
	short getRight() const { return mRight; }
private:
	short mTop;
	short mLeft;
	short mBottom;
	short mRight;
};

#endif