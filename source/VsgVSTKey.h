#ifndef __VsgVSTKey_h__
#define __VsgVSTKey_h__

#include <vsg/VsgKey.h>
#include "vstkeycode.h"

class VstKeyCode;

class VsgVSTKey : public Vsg::VsgKey {
public:
	VsgVSTKey(VstKeyCode& keycode);
	
	long getCharacter() const;
	char getModifier() const;
	char getVirtual() const;	
private:
	VstKeyCode mKey;
};

#endif

