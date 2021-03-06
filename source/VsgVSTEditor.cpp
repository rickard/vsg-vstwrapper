#include "VsgVSTEditor.h"
#include "VsgVSTKey.h"
#include "VsgVSTBounds.h"
#include <vsg/VsgEditor.h>

using Vsg::VsgEditor;
using Vsg::VsgWindowBounds;
using Vsg::VsgRedrawAllBounds;

VsgVSTEditor :: VsgVSTEditor(VsgEditor& vsgEditor, void *effect) : mEditor(vsgEditor), mAudioEffect((AudioEffect *) effect) {
	mAudioEffect->setEditor(this);
	mRect.top = 0;
	mRect.bottom = 300;
	mRect.left = 0;
	mRect.right = 300;
	mIsIdle = false;
}

bool VsgVSTEditor :: getRect(ERect** rect) {
	*rect = &mRect;
	return true;
}

bool VsgVSTEditor :: open(void *ptr) {
	mEditor.open(ptr);
	return AEffEditor::open(ptr);
}

#if VST_2_1_EXTENSIONS
bool VsgVSTEditor :: onKeyDown(VstKeyCode& keyCode)
{
	VsgVSTKey key(keyCode);
	return mEditor.onKeyDown(key);
	
//	return frame ? frame->onKeyDown (keyCode) > 0 : false;
}

//-----------------------------------------------------------------------------
bool VsgVSTEditor :: onKeyUp(VstKeyCode& keyCode)
{
	VsgVSTKey key(keyCode);
	return mEditor.onKeyUp(key);
//	return frame ? frame->onKeyUp (keyCode) > 0 : false;
}
#endif

void VsgVSTEditor :: draw (ERect* pRect) {
	if (pRect == NULL) {
		VsgRedrawAllBounds noBounds;
		mEditor.draw(noBounds);
	} else {
		VsgVSTBounds bounds(pRect->top, pRect->left, pRect->bottom, pRect->right);
		mEditor.draw(bounds);
	}
}

void VsgVSTEditor :: idleCallback() {
	if (mIsIdle)
		return;
	
	AEffEditor::idle ();
	mEditor.idle();
}

void VsgVSTEditor :: masterIdleCallback() {
	mIsIdle = true;
	if (effect)
		effect->masterIdle ();
	
	mIsIdle = false;
}	

#if VST_2_1_EXTENSIONS
void VsgVSTEditor :: beginEdit (long index) { 
	((AudioEffectX*) mAudioEffect)->beginEdit (index); 
}

void VsgVSTEditor :: endEdit (long index) { 
	((AudioEffectX*) mAudioEffect)->endEdit (index); 
}
#endif	

