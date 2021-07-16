'
set speech = Wscript.CreateObject("SAPI.spVoice") 
Set speech.Voice = speech.GetVoices.Item(1)
speech.speak"are friends" 