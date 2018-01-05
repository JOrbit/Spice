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
	${OBJECTDIR}/_ext/d4ee5d15/ListenFd.o \
	${OBJECTDIR}/_ext/d4ee5d15/ServerProcess.o \
	${OBJECTDIR}/_ext/d4ee5d15/SocketFd.o \
	${OBJECTDIR}/src/RecvFd.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverclientlib.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverclientlib.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverclientlib.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverclientlib.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverclientlib.a

${OBJECTDIR}/_ext/d4ee5d15/ListenFd.o: /cygdrive/D/JOrbit/Spice/ServerClientLib/src/ListenFd.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/d4ee5d15
	${RM} "$@.d"
	$(COMPILE.c) -g -Iheaders -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d4ee5d15/ListenFd.o /cygdrive/D/JOrbit/Spice/ServerClientLib/src/ListenFd.c

${OBJECTDIR}/_ext/d4ee5d15/ServerProcess.o: /cygdrive/D/JOrbit/Spice/ServerClientLib/src/ServerProcess.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/d4ee5d15
	${RM} "$@.d"
	$(COMPILE.c) -g -Iheaders -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d4ee5d15/ServerProcess.o /cygdrive/D/JOrbit/Spice/ServerClientLib/src/ServerProcess.c

${OBJECTDIR}/_ext/d4ee5d15/SocketFd.o: /cygdrive/D/JOrbit/Spice/ServerClientLib/src/SocketFd.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/d4ee5d15
	${RM} "$@.d"
	$(COMPILE.c) -g -Iheaders -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/d4ee5d15/SocketFd.o /cygdrive/D/JOrbit/Spice/ServerClientLib/src/SocketFd.c

${OBJECTDIR}/src/RecvFd.o: src/RecvFd.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Iheaders -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/RecvFd.o src/RecvFd.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libserverclientlib.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
