.KEEP_STATE:
KNOWN_SYSTEM=no

## SPECIFY THE NAME OF THE FILE TO COMPILE
FILENAME=dummy
NAME=$(shell echo $(FILENAME) | cut -f1 -d '.')

## SPECIFY THE TYPE OF COMPILER: (g++)
SYSTEM=g++

## SPECIFY EDITOR
export EDITOR = code

## IF 'g++' COMPILER IS DETECTED, USE VARIABLES AND FLAGS. ALSO, UPDATE SYSTEM STATUS TO 'KNOWN'
## NOTE: g++ compiler (part of gcc 4.x.x)
ifeq ($(SYSTEM), g++)
   CXX=g++
   CXXFLAGS=-c   
   KNOWN_SYSTEM=yes
endif

%.o : %.cpp	
	@($(CXX) $(CXXFLAGS) $< -o $@)
	@echo $< "Compiled Successfully..."
	@echo "type 'make run' to execute the application"

default: checksystem checkname clean $(NAME).o 
	@($(CXX) $(NAME).o -o run)

run:
	@(./run.exe)

edit: checkname
ifneq ($(NAME), dummy)
	$(EDITOR) $(NAME).cpp &
	@echo
	@echo "FILE = '$(NAME).cpp' HAS OPENED SUCESSFULLY FOR EDITING"; echo;
endif

clean:
	-@(rm *.o 2>/dev/null; rm *.exe 2>/dev/null)
	@echo
	@echo "All the objects are cleared !!!";echo;

checksystem:
ifeq ($(KNOWN_SYSTEM), yes)
	@echo ""
	@echo "Compiling $(NAME) for $(SYSTEM) system..."	
else
	@echo ""
	@echo "make : ERROR: value of SYSTEM = $(SYSTEM) not recognised..."	
	@echo ""	
endif

checkname:
ifeq ($(NAME), dummy)
	@echo "Specify name of the source file to compile/edit."
	@echo "Eg: To compile: type 'make FILENAME=Prog_1' (or) 'make FILENAME=Prog_1.cpp' in command prompt"	
	@echo "Eg: To edit: type 'make edit FILENAME=Prog_1' (or) 'make edit FILENAME=Prog_1.cpp'  in command prompt"	
	@echo ""
else	
	@echo "$(NAME)"
endif