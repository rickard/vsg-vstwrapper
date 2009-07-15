#ifndef __VsgVSTTypes_h__
#define __VsgVSTTypes_h__

class Bounds {
public:
	Bounds(short top, short left, short bottom, short right) : rect.top(top), rect.left(left), rect.bottom(bottom), rect.right(right) {}
private:
	ERect rect;
	
};

#endif

