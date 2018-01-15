#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=gcc
CXX=gcc
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin64-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/ServerProcess.o \
	${OBJECTDIR}/src/ServerProcessWorks.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../SocketLib/dist/Debug/Cygwin64-Windows -L../ServerLib/dist/Debug/Cygwin64-Windows -lsocketlib -lserverlib /cygdrive/D/naif/PCCYGWINgCC64bit/cspice/lib/cspice.a /cygdrive/D/naif/PCCYGWINgCC64bit/cspice/lib/csupport.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/servermain.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/servermain.exe: /cygdrive/D/naif/PCCYGWINgCC64bit/cspice/lib/cspice.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/servermain.exe: /cygdrive/D/naif/PCCYGWINgCC64bit/cspice/lib/csupport.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/servermain.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/servermain ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/ServerProcess.o: src/ServerProcess.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -I../SocketLib/headers -I../ServerLib/headers -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServerProcess.o src/ServerProcess.c

${OBJECTDIR}/src/ServerProcessWorks.o: src/ServerProcessWorks.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -I../SocketLib/headers -I../ServerLib/headers -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServerProcessWorks.o src/ServerProcessWorks.c

${OBJECTDIR}/src/main.o: src/main.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -I../SocketLib/headers -I../ServerLib/headers -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.c

# Subprojects
.build-subprojects:
	cd ../ServerLib && ${MAKE}  -f Makefile CONF=Debug
	cd ../SocketLib && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/servermain.exe

# Subprojects
.clean-subprojects:
	cd ../ServerLib && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../SocketLib && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
