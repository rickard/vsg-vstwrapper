#include "VsgVSTKey.h"

VsgVSTKey :: VsgVSTKey(VstKeyCode& keycode) : mKey(keycode) {
}

long VsgVSTKey :: getCharacter() const {
	return mKey.character;
}

char VsgVSTKey :: getModifier() const {
	return mKey.modifier;
}

char VsgVSTKey :: getVirtual() const {
	return mKey.virt;
}


