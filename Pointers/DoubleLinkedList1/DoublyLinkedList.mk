##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DoublyLinkedList
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/media/animesh/OS/From_Old_PC/Udemy/Advanced_C/Pointers
ProjectPath            :=/media/animesh/OS/From_Old_PC/Udemy/Advanced_C/Pointers/DoubleLinkedList1
IntermediateDirectory  :=../build-$(ConfigurationName)/DoubleLinkedList1
OutDir                 :=../build-$(ConfigurationName)/DoubleLinkedList1
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=animesh
Date                   :=21/09/19
CodeLitePath           :=/home/animesh/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/DoubleLinkedList1/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/DoubleLinkedList1/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/DoubleLinkedList1"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/DoubleLinkedList1"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/DoubleLinkedList1/.d:
	@mkdir -p "../build-$(ConfigurationName)/DoubleLinkedList1"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/DoubleLinkedList1/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/DoubleLinkedList1/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/animesh/OS/From_Old_PC/Udemy/Advanced_C/Pointers/DoubleLinkedList1/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/DoubleLinkedList1/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/DoubleLinkedList1/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/DoubleLinkedList1/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/DoubleLinkedList1/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/DoubleLinkedList1/main.c$(PreprocessSuffix) main.c


-include ../build-$(ConfigurationName)/DoubleLinkedList1//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


