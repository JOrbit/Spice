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
	${OBJECTDIR}/src/GetEt.o \
	${OBJECTDIR}/src/GetGm.o \
	${OBJECTDIR}/src/LoadSpiceData.o \
	${OBJECTDIR}/src/ProcessSpiceCommand.o \
	${OBJECTDIR}/src/ProcessSpiceCommands.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverlib.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverlib.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverlib.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverlib.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverlib.a

${OBJECTDIR}/src/GetEt.o: src/GetEt.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Iheaders -I../../../naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GetEt.o src/GetEt.c

${OBJECTDIR}/src/GetGm.o: src/GetGm.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Iheaders -I../../../naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GetGm.o src/GetGm.c

${OBJECTDIR}/src/LoadSpiceData.o: src/LoadSpiceData.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Iheaders -I../../../naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LoadSpiceData.o src/LoadSpiceData.c

${OBJECTDIR}/src/ProcessSpiceCommand.o: src/ProcessSpiceCommand.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Iheaders -I../../../naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ProcessSpiceCommand.o src/ProcessSpiceCommand.c

${OBJECTDIR}/src/ProcessSpiceCommands.o: src/ProcessSpiceCommands.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Iheaders -I../../../naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ProcessSpiceCommands.o src/ProcessSpiceCommands.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverlib.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
