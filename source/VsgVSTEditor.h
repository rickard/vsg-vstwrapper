#ifndef __VsgVSTEditor_h__
#define __VsgVSTEditor_h__	

#include "public.sdk/source/vst2.x/aeffeditor.h"
#include <vsg/VsgOnIdleCallback.h>
#include <vsg/VsgOnEditCallback.h>
#include <vsg/VsgEditor.h>

class EERect;

class VsgVSTEditor : public AEffEditor, public Vsg::VsgOnIdleCallback, public Vsg::VsgOnEditCallback {
public:
	VsgVSTEditor(Vsg::VsgEditor& vsgEditor, void *effect);
	bool getRect(ERect** rect);
	bool open(void *ptr);
	
#if VST_2_1_EXTENSIONS
	bool onKeyDown(VstKeyCode& keyCode);
	bool onKeyUp(VstKeyCode& keyCode);
#endif
	
#if VST_2_1_EXTENSIONS
	void beginEdit (long index);
	void endEdit (long index);
#endif	
	
	void draw(ERect* pRect);
	void idleCallback();
	void masterIdleCallback();
	
private:
	ERect mRect;
	Vsg::VsgEditor& mEditor;
	AudioEffect *mAudioEffect;
	bool mIsIdle;
};

#endif

