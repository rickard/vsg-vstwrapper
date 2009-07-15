#include "VsgVSTEditor.h"
#include "VsgVSTKey.h"
#include "VsgVSTBounds.h"
#include <vsg/VsgEditor.h>

VsgVSTEditor :: VsgVSTEditor(VsgEditor& vsgEditor, void *effect) : mEditor(vsgEditor), mAudioEffect((AudioEffect *) effect) {
	mAudioEffect->setEditor(this);
	mIsIdle = false;
	VsgWindowBounds windowSize = mEditor.getWindowSize();
	mRect.top = windowSize.getTop();
	mRect.bottom = windowSize.getBottom();
	mRect.left = windowSize.getLeft();
	mRect.right = windowSize.getRight();
}

bool VsgVSTEditor :: getRect(ERect** rect) {
	*rect = &mRect;
	return true;
}

bool VsgVSTEditor :: open(void *ptr) {
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

/*	if (frame)
	{
		CRect r;
		if (ppErect)
			r (ppErect->left, ppErect->top, ppErect->right, ppErect->bottom);
		else
			r = frame->getViewSize ();
		CDrawContext* context = frame->createDrawContext();
		frame->drawRect (context, r);
		context->forget();
	}
*/
}

void VsgVSTEditor :: idle() {
	if (mIsIdle)
		return;
	
	AEffEditor::idle ();
	mEditor.idle();
}

void VsgVSTEditor :: masterIdle() {
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

