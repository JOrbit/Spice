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
	${OBJECTDIR}/_ext/858e0c8a/main.o \
	${OBJECTDIR}/_ext/858e0c8a/main_1.o \
	${OBJECTDIR}/_ext/858e0c8a/main_2.o \
	${OBJECTDIR}/_ext/858e0c8a/main_3.o \
	${OBJECTDIR}/_ext/858e0c8a/printEltsX.o \
	${OBJECTDIR}/_ext/858e0c8a/printEt.o \
	${OBJECTDIR}/_ext/858e0c8a/printState.o \
	${OBJECTDIR}/_ext/858e0c8a/printStateDiff.o \
	${OBJECTDIR}/_ext/858e0c8a/r2d.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/spiceorbitalelements.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/spiceorbitalelements.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/spiceorbitalelements ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/858e0c8a/main.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/main.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/858e0c8a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/858e0c8a/main.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/main.c

${OBJECTDIR}/_ext/858e0c8a/main_1.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/main_1.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/858e0c8a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/858e0c8a/main_1.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/main_1.c

${OBJECTDIR}/_ext/858e0c8a/main_2.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/main_2.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/858e0c8a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/858e0c8a/main_2.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/main_2.c

${OBJECTDIR}/_ext/858e0c8a/main_3.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/main_3.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/858e0c8a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/858e0c8a/main_3.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/main_3.c

${OBJECTDIR}/_ext/858e0c8a/printEltsX.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/printEltsX.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/858e0c8a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/858e0c8a/printEltsX.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/printEltsX.c

${OBJECTDIR}/_ext/858e0c8a/printEt.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/printEt.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/858e0c8a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/858e0c8a/printEt.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/printEt.c

${OBJECTDIR}/_ext/858e0c8a/printState.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/printState.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/858e0c8a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/858e0c8a/printState.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/printState.c

${OBJECTDIR}/_ext/858e0c8a/printStateDiff.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/printStateDiff.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/858e0c8a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/858e0c8a/printStateDiff.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/printStateDiff.c

${OBJECTDIR}/_ext/858e0c8a/r2d.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/r2d.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/858e0c8a
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/858e0c8a/r2d.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/src/r2d.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/spiceorbitalelements.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
