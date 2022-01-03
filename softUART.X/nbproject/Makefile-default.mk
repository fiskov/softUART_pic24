#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/softUART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/softUART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/app/cmd.c ../src/app/init.c ../src/drv/softUART.c ../src/lib/crc.c ../src/lib/textfunctions.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/659850791/cmd.o ${OBJECTDIR}/_ext/659850791/init.o ${OBJECTDIR}/_ext/659853742/softUART.o ${OBJECTDIR}/_ext/659861131/crc.o ${OBJECTDIR}/_ext/659861131/textfunctions.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/659850791/cmd.o.d ${OBJECTDIR}/_ext/659850791/init.o.d ${OBJECTDIR}/_ext/659853742/softUART.o.d ${OBJECTDIR}/_ext/659861131/crc.o.d ${OBJECTDIR}/_ext/659861131/textfunctions.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/659850791/cmd.o ${OBJECTDIR}/_ext/659850791/init.o ${OBJECTDIR}/_ext/659853742/softUART.o ${OBJECTDIR}/_ext/659861131/crc.o ${OBJECTDIR}/_ext/659861131/textfunctions.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/app/cmd.c ../src/app/init.c ../src/drv/softUART.c ../src/lib/crc.c ../src/lib/textfunctions.c ../src/main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

# The following macros may be used in the pre and post step lines
_/_=\\
ShExtension=.bat
Device=PIC24F16KA102
ProjectDir="C:\Work\Proton\Projects\sorfUART\softUART.X"
ProjectName=softUART
ConfName=default
ImagePath="dist\default\${IMAGE_TYPE}\softUART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="dist\default\${IMAGE_TYPE}"
ImageName="softUART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/softUART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [COPY  ${ImageDir}\${ProjectName}.X.production.cof ..\proteus\out.cof]"
	@COPY  ${ImageDir}\${ProjectName}.X.production.cof ..\proteus\out.cof
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=24F16KA102
MP_LINKER_FILE_OPTION=,--script=p24F16KA102.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/659850791/cmd.o: ../src/app/cmd.c  .generated_files/flags/default/fb4c421f9c18c42e589bbbe939565996ce2a0cc3 .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659850791" 
	@${RM} ${OBJECTDIR}/_ext/659850791/cmd.o.d 
	@${RM} ${OBJECTDIR}/_ext/659850791/cmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/app/cmd.c  -o ${OBJECTDIR}/_ext/659850791/cmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659850791/cmd.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/659850791/init.o: ../src/app/init.c  .generated_files/flags/default/3404252782237163eed00511ee9f8f3fd5b38691 .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659850791" 
	@${RM} ${OBJECTDIR}/_ext/659850791/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/659850791/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/app/init.c  -o ${OBJECTDIR}/_ext/659850791/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659850791/init.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/659853742/softUART.o: ../src/drv/softUART.c  .generated_files/flags/default/d12a409b87efa4173c2e46843c1723aee5e09bcb .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659853742" 
	@${RM} ${OBJECTDIR}/_ext/659853742/softUART.o.d 
	@${RM} ${OBJECTDIR}/_ext/659853742/softUART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/drv/softUART.c  -o ${OBJECTDIR}/_ext/659853742/softUART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659853742/softUART.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/659861131/crc.o: ../src/lib/crc.c  .generated_files/flags/default/f23f1c7a63300aafcc19fcb7828daefd1e5ba4f .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659861131" 
	@${RM} ${OBJECTDIR}/_ext/659861131/crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/659861131/crc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/lib/crc.c  -o ${OBJECTDIR}/_ext/659861131/crc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659861131/crc.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/659861131/textfunctions.o: ../src/lib/textfunctions.c  .generated_files/flags/default/49ea33416666a3d2d92efa5f6f24b08b01c93c94 .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659861131" 
	@${RM} ${OBJECTDIR}/_ext/659861131/textfunctions.o.d 
	@${RM} ${OBJECTDIR}/_ext/659861131/textfunctions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/lib/textfunctions.c  -o ${OBJECTDIR}/_ext/659861131/textfunctions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659861131/textfunctions.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/a6ecef60c6fdc6255350cb17e5c88c748f6d5f3c .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG     -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/659850791/cmd.o: ../src/app/cmd.c  .generated_files/flags/default/6f821ecf57caca0908d2038c89fb377acd6a5943 .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659850791" 
	@${RM} ${OBJECTDIR}/_ext/659850791/cmd.o.d 
	@${RM} ${OBJECTDIR}/_ext/659850791/cmd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/app/cmd.c  -o ${OBJECTDIR}/_ext/659850791/cmd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659850791/cmd.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/659850791/init.o: ../src/app/init.c  .generated_files/flags/default/8ee6c4ac1afd61b31317529cfdcac7d3bb5f4461 .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659850791" 
	@${RM} ${OBJECTDIR}/_ext/659850791/init.o.d 
	@${RM} ${OBJECTDIR}/_ext/659850791/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/app/init.c  -o ${OBJECTDIR}/_ext/659850791/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659850791/init.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/659853742/softUART.o: ../src/drv/softUART.c  .generated_files/flags/default/3b9616bdcde4b17a41866ae9c725f7262281f40d .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659853742" 
	@${RM} ${OBJECTDIR}/_ext/659853742/softUART.o.d 
	@${RM} ${OBJECTDIR}/_ext/659853742/softUART.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/drv/softUART.c  -o ${OBJECTDIR}/_ext/659853742/softUART.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659853742/softUART.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/659861131/crc.o: ../src/lib/crc.c  .generated_files/flags/default/cc71e99b997655412e6817817ffbffa7bbccb49d .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659861131" 
	@${RM} ${OBJECTDIR}/_ext/659861131/crc.o.d 
	@${RM} ${OBJECTDIR}/_ext/659861131/crc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/lib/crc.c  -o ${OBJECTDIR}/_ext/659861131/crc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659861131/crc.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/659861131/textfunctions.o: ../src/lib/textfunctions.c  .generated_files/flags/default/6d47d111651eb40d9d0a4f62b0f105ee5f29208c .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/659861131" 
	@${RM} ${OBJECTDIR}/_ext/659861131/textfunctions.o.d 
	@${RM} ${OBJECTDIR}/_ext/659861131/textfunctions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/lib/textfunctions.c  -o ${OBJECTDIR}/_ext/659861131/textfunctions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/659861131/textfunctions.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/ae44e1a6579eb4f6dfd41e494652a214cab7369d .generated_files/flags/default/ea2a7066b12fd53932fd9a63046cd42f96dd5fb4
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -msmall-data -O1 -I"../src/config" -I"../src/lib" -I"../src/drv" -I"../src/app" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/softUART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/softUART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/softUART.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/softUART.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=coff -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/softUART.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=coff   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
