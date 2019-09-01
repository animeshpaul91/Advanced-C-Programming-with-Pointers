##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FromBook
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/media/animesh/OS/From_Old_PC/Udemy/Advanced_C/Pointers
ProjectPath            :=/media/animesh/OS/From_Old_PC/Udemy/Advanced_C/Pointers/FromBook
IntermediateDirectory  :=../build-$(ConfigurationName)/FromBook
OutDir                 :=../build-$(ConfigurationName)/FromBook
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=animesh
Date                   :=31/08/19
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
Objects0=../build-$(ConfigurationName)/FromBook/main.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/FromBook/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/FromBook"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/FromBook"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/FromBook/.d:
	@mkdir -p "../build-$(ConfigurationName)/FromBook"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/FromBook/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/FromBook/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/media/animesh/OS/From_Old_PC/Udemy/Advanced_C/Pointers/FromBook/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/FromBook/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/FromBook/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/FromBook/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/FromBook/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/FromBook/main.c$(PreprocessSuffix) main.c


-include ../build-$(ConfigurationName)/FromBook//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


