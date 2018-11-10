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
	${OBJECTDIR}/_ext/16a1d3b5/printEltsX.o \
	${OBJECTDIR}/_ext/16a1d3b5/printEt.o \
	${OBJECTDIR}/_ext/16a1d3b5/printState.o \
	${OBJECTDIR}/_ext/16a1d3b5/printStateDiff.o \
	${OBJECTDIR}/_ext/16a1d3b5/r2d.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/main_1.o


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
LDLIBSOPTIONS=/cygdrive/D/naif/PCCYGWINgCC64bit/cspice/lib/cspice.a /cygdrive/D/naif/PCCYGWINgCC64bit/cspice/lib/csupport.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/spiceorbitalelements.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/spiceorbitalelements.exe: /cygdrive/D/naif/PCCYGWINgCC64bit/cspice/lib/cspice.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/spiceorbitalelements.exe: /cygdrive/D/naif/PCCYGWINgCC64bit/cspice/lib/csupport.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/spiceorbitalelements.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/spiceorbitalelements ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/16a1d3b5/printEltsX.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/printEltsX.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/16a1d3b5
	${RM} "$@.d"
	$(COMPILE.c) -g -I/cygdrive/D/naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/16a1d3b5/printEltsX.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/printEltsX.c

${OBJECTDIR}/_ext/16a1d3b5/printEt.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/printEt.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/16a1d3b5
	${RM} "$@.d"
	$(COMPILE.c) -g -I/cygdrive/D/naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/16a1d3b5/printEt.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/printEt.c

${OBJECTDIR}/_ext/16a1d3b5/printState.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/printState.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/16a1d3b5
	${RM} "$@.d"
	$(COMPILE.c) -g -I/cygdrive/D/naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/16a1d3b5/printState.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/printState.c

${OBJECTDIR}/_ext/16a1d3b5/printStateDiff.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/printStateDiff.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/16a1d3b5
	${RM} "$@.d"
	$(COMPILE.c) -g -I/cygdrive/D/naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/16a1d3b5/printStateDiff.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/printStateDiff.c

${OBJECTDIR}/_ext/16a1d3b5/r2d.o: /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/r2d.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/16a1d3b5
	${RM} "$@.d"
	$(COMPILE.c) -g -I/cygdrive/D/naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/16a1d3b5/r2d.o /cygdrive/D/JOrbit/Spice/SpiceOrbitalElements/r2d.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I/cygdrive/D/naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/main_1.o: main_1.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -I/cygdrive/D/naif/PCCYGWINgCC64bit/cspice/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_1.o main_1.c

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
