#ifndef __VsgVSTEditor_h__
#define __VsgVSTEditor_h__	

#include "public.sdk/source/vst2.x/aeffeditor.h"
#include <vsg/VsgIdler.h>
#include <vsg/VsgOnEditCallback.h>

class VsgEditor;
class EERect;

class VsgVSTEditor : AEffEditor, VsgIdler, VsgOnEditCallback {
public:
	VsgVSTEditor(VsgEditor& vsgEditor, void *effect);
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
	void idle();
	void masterIdle();
	
private:
	ERect mRect;
	VsgEditor& mEditor;
	AudioEffect *mAudioEffect;
	bool mIsIdle;
};

#endif

