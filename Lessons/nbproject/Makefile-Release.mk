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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/api_examples/orbital.o \
	${OBJECTDIR}/src/binary_pck/binary_pck.o \
	${OBJECTDIR}/src/event_finding/event_finding.o \
	${OBJECTDIR}/src/insitu_sensing/convrt.o \
	${OBJECTDIR}/src/insitu_sensing/getsta.o \
	${OBJECTDIR}/src/insitu_sensing/sclket.o \
	${OBJECTDIR}/src/insitu_sensing/scvel.o \
	${OBJECTDIR}/src/insitu_sensing/soldir.o \
	${OBJECTDIR}/src/insitu_sensing/sscpnt.o \
	${OBJECTDIR}/src/lessons.o \
	${OBJECTDIR}/src/other_stuff/aderr.o \
	${OBJECTDIR}/src/other_stuff/coord.o \
	${OBJECTDIR}/src/other_stuff/errsyst.o \
	${OBJECTDIR}/src/other_stuff/kervar.o \
	${OBJECTDIR}/src/other_stuff/kpool.o \
	${OBJECTDIR}/src/other_stuff/sccalc.o \
	${OBJECTDIR}/src/other_stuff/tkvstr.o \
	${OBJECTDIR}/src/other_stuff/win.o \
	${OBJECTDIR}/src/other_stuff/xtix.o \
	${OBJECTDIR}/src/start_programming/star_programing.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lessons.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lessons.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lessons ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/src/api_examples/orbital.o: src/api_examples/orbital.c 
	${MKDIR} -p ${OBJECTDIR}/src/api_examples
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/api_examples/orbital.o src/api_examples/orbital.c

${OBJECTDIR}/src/binary_pck/binary_pck.o: src/binary_pck/binary_pck.c 
	${MKDIR} -p ${OBJECTDIR}/src/binary_pck
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/binary_pck/binary_pck.o src/binary_pck/binary_pck.c

${OBJECTDIR}/src/event_finding/event_finding.o: src/event_finding/event_finding.c 
	${MKDIR} -p ${OBJECTDIR}/src/event_finding
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/event_finding/event_finding.o src/event_finding/event_finding.c

${OBJECTDIR}/src/insitu_sensing/convrt.o: src/insitu_sensing/convrt.c 
	${MKDIR} -p ${OBJECTDIR}/src/insitu_sensing
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/insitu_sensing/convrt.o src/insitu_sensing/convrt.c

${OBJECTDIR}/src/insitu_sensing/getsta.o: src/insitu_sensing/getsta.c 
	${MKDIR} -p ${OBJECTDIR}/src/insitu_sensing
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/insitu_sensing/getsta.o src/insitu_sensing/getsta.c

${OBJECTDIR}/src/insitu_sensing/sclket.o: src/insitu_sensing/sclket.c 
	${MKDIR} -p ${OBJECTDIR}/src/insitu_sensing
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/insitu_sensing/sclket.o src/insitu_sensing/sclket.c

${OBJECTDIR}/src/insitu_sensing/scvel.o: src/insitu_sensing/scvel.c 
	${MKDIR} -p ${OBJECTDIR}/src/insitu_sensing
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/insitu_sensing/scvel.o src/insitu_sensing/scvel.c

${OBJECTDIR}/src/insitu_sensing/soldir.o: src/insitu_sensing/soldir.c 
	${MKDIR} -p ${OBJECTDIR}/src/insitu_sensing
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/insitu_sensing/soldir.o src/insitu_sensing/soldir.c

${OBJECTDIR}/src/insitu_sensing/sscpnt.o: src/insitu_sensing/sscpnt.c 
	${MKDIR} -p ${OBJECTDIR}/src/insitu_sensing
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/insitu_sensing/sscpnt.o src/insitu_sensing/sscpnt.c

${OBJECTDIR}/src/lessons.o: src/lessons.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/lessons.o src/lessons.c

${OBJECTDIR}/src/other_stuff/aderr.o: src/other_stuff/aderr.c 
	${MKDIR} -p ${OBJECTDIR}/src/other_stuff
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/other_stuff/aderr.o src/other_stuff/aderr.c

${OBJECTDIR}/src/other_stuff/coord.o: src/other_stuff/coord.c 
	${MKDIR} -p ${OBJECTDIR}/src/other_stuff
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/other_stuff/coord.o src/other_stuff/coord.c

${OBJECTDIR}/src/other_stuff/errsyst.o: src/other_stuff/errsyst.c 
	${MKDIR} -p ${OBJECTDIR}/src/other_stuff
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/other_stuff/errsyst.o src/other_stuff/errsyst.c

${OBJECTDIR}/src/other_stuff/kervar.o: src/other_stuff/kervar.c 
	${MKDIR} -p ${OBJECTDIR}/src/other_stuff
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/other_stuff/kervar.o src/other_stuff/kervar.c

${OBJECTDIR}/src/other_stuff/kpool.o: src/other_stuff/kpool.c 
	${MKDIR} -p ${OBJECTDIR}/src/other_stuff
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/other_stuff/kpool.o src/other_stuff/kpool.c

${OBJECTDIR}/src/other_stuff/sccalc.o: src/other_stuff/sccalc.c 
	${MKDIR} -p ${OBJECTDIR}/src/other_stuff
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/other_stuff/sccalc.o src/other_stuff/sccalc.c

${OBJECTDIR}/src/other_stuff/tkvstr.o: src/other_stuff/tkvstr.c 
	${MKDIR} -p ${OBJECTDIR}/src/other_stuff
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/other_stuff/tkvstr.o src/other_stuff/tkvstr.c

${OBJECTDIR}/src/other_stuff/win.o: src/other_stuff/win.c 
	${MKDIR} -p ${OBJECTDIR}/src/other_stuff
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/other_stuff/win.o src/other_stuff/win.c

${OBJECTDIR}/src/other_stuff/xtix.o: src/other_stuff/xtix.c 
	${MKDIR} -p ${OBJECTDIR}/src/other_stuff
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/other_stuff/xtix.o src/other_stuff/xtix.c

${OBJECTDIR}/src/start_programming/star_programing.o: src/start_programming/star_programing.c 
	${MKDIR} -p ${OBJECTDIR}/src/start_programming
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/start_programming/star_programing.o src/start_programming/star_programing.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lessons.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
