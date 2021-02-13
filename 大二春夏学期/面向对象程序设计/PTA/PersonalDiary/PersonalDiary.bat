@echo off
:BEGIN
	set/p p1=Input your command: 
	if %p1%==pdadd goto ADD
	if %p1%==pdshow goto SHOW
	if %p1%==pdlist goto LIST
	if %p1%==pdremove goto REMOVE

:EXIT
	pause
	exit

:ADD
	set/p p2=Input your date: 
	.\add.exe %p2%
	goto EXIT

:SHOW
	set/p p2=Input your date: 
	.\show.exe %p2%
	goto EXIT

:LIST
	set/p flag=List all?(1 means yes and others means no)
	if %flag%==1 goto LISTALL
	set/p p2=Begin date: 
	set/p p3=End date: 
	.\list.exe %p2% %p3%
	goto EXIT
	
:LISTALL
	.\list.exe
	goto EXIT

:REMOVE
	set/p p2=Input your date: 
	.\remove.exe %p2%
	goto EXIT
