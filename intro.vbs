Dim Ravi

set speech = Wscript.CreateObject("SAPI.spVoice") 
Set speech.Voice = speech.GetVoices.Item(1)
Speech.Rate = 0.8
speech.speak"Welcome to Social Network Project ............. Team Members : Aman ............. Parish .............  Nikhil .............  Nayyvedtheia"