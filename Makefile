main.o:main.cpp menu.h addrecord.h checkbudget.h editrecord.h setbudget.h signin.h viewrecord.h report.h
	g++ -c main.cpp

menu.o:menu.cpp menu.h
	g++ -c menu.cpp

addrecord.o:addrecord.cpp addrecord.h menu.h
	g++ -c addrecord.cpp

checkbudget.o:checkbudget.cpp checkbudget.h menu.h
	g++ -c checkbudget.cpp

editrecord.o:editrecord.cpp editrecord.h menu.h
	g++ -c editrecord.cpp

setbudget.o:setbudget.cpp setbudget.h menu.h
	g++ -c setbudget.cpp

signin.o:signin.cpp signin.h
	g++ -c signin.cpp

viewrecord.o:viewrecord.cpp viewrecord.h menu.h
	g++ -c viewrecord.cpp

report.o:report.cpp report.h menu.h
	g++ -c report.cpp

main:main.o menu.o addrecord.o checkbudget.o editrecord.o setbudget.o signin.o viewrecord.o report.o
	g++ main.o menu.o addrecord.o checkbudget.o editrecord.o setbudget.o signin.o viewrecord.o report.o -o main
