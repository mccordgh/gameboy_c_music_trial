@REM kill open instance of BGB
taskkill /f /im bgb.exe

@REM start up bgb with latest compiled .gb
start /b C:\Users\mattm\Games\bgb\bgb.exe .\music.gb
