	echo off
	rem 'goto' cause %1 unavailable in 'call'
	goto :GET_PARENT_DIR
:BAT_CODE
	
	goto :END



:GET_PARENT_DIR
  echo %1
	if [%1]==[] (
		set parentDir=%~dp0
	) else (
		set parentDir=%1\
	)
	rem echo Parent directory is: %parentDir%
	goto :BAT_CODE

:END
  pause