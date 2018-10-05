@if (@X == @Y) @then
@echo off
rem This is a hybrid bat + jscript script. Bat section is inside js comment.
cscript //nologo //E:jscript "%~f0" %*
exit /b
@end //============ End of bat section, jscript section below ==============

WScript.Echo(WScript.Arguments.Item(0))
