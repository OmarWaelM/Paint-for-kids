#include "ToggleAudioAction.h"

void ToggleAudioAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	// changes audio mode of UI
	if (UI.audio == AUDIO_ON)
	{
		UI.audio = AUDIO_OFF;
		pOut->PrintMessage("Audio Muted");
	}
	else
	{
		UI.audio = AUDIO_ON;
		pOut->PrintMessage("Audio On");
	}
}