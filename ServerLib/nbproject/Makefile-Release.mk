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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/7d3a4fb8/LoadSpiceData.o \
	${OBJECTDIR}/ListenFd.o \
	${OBJECTDIR}/ServerProcess.o \
	${OBJECTDIR}/SocketFd.o \
	${OBJECTDIR}/src/RecvFd.o \
	${OBJECTDIR}/src/handlers/GetEt.o \
	${OBJECTDIR}/src/handlers/GetGm.o


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

${OBJECTDIR}/_ext/7d3a4fb8/LoadSpiceData.o: /cygdrive/D/JOrbit/Spice/ServerLib/src/handlers/LoadSpiceData.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/7d3a4fb8
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/7d3a4fb8/LoadSpiceData.o /cygdrive/D/JOrbit/Spice/ServerLib/src/handlers/LoadSpiceData.c

${OBJECTDIR}/ListenFd.o: ListenFd.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListenFd.o ListenFd.c

${OBJECTDIR}/ServerProcess.o: ServerProcess.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ServerProcess.o ServerProcess.c

${OBJECTDIR}/SocketFd.o: SocketFd.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SocketFd.o SocketFd.c

${OBJECTDIR}/src/RecvFd.o: src/RecvFd.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/RecvFd.o src/RecvFd.c

${OBJECTDIR}/src/handlers/GetEt.o: src/handlers/GetEt.c 
	${MKDIR} -p ${OBJECTDIR}/src/handlers
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/handlers/GetEt.o src/handlers/GetEt.c

${OBJECTDIR}/src/handlers/GetGm.o: src/handlers/GetGm.c 
	${MKDIR} -p ${OBJECTDIR}/src/handlers
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/handlers/GetGm.o src/handlers/GetGm.c

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
