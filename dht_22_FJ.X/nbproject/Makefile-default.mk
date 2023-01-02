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
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/dht_22_FJ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/dht_22_FJ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=src/config/global_definitions.c src/config/pll.c src/dht/dht.c src/oled/OLED.c src/oled/i2c_routines.c src/timer/timer.c src/timer/timerstart.c src/uart/uart.c src/uart/uart_dsPIC.c src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/config/global_definitions.o ${OBJECTDIR}/src/config/pll.o ${OBJECTDIR}/src/dht/dht.o ${OBJECTDIR}/src/oled/OLED.o ${OBJECTDIR}/src/oled/i2c_routines.o ${OBJECTDIR}/src/timer/timer.o ${OBJECTDIR}/src/timer/timerstart.o ${OBJECTDIR}/src/uart/uart.o ${OBJECTDIR}/src/uart/uart_dsPIC.o ${OBJECTDIR}/src/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/config/global_definitions.o.d ${OBJECTDIR}/src/config/pll.o.d ${OBJECTDIR}/src/dht/dht.o.d ${OBJECTDIR}/src/oled/OLED.o.d ${OBJECTDIR}/src/oled/i2c_routines.o.d ${OBJECTDIR}/src/timer/timer.o.d ${OBJECTDIR}/src/timer/timerstart.o.d ${OBJECTDIR}/src/uart/uart.o.d ${OBJECTDIR}/src/uart/uart_dsPIC.o.d ${OBJECTDIR}/src/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/config/global_definitions.o ${OBJECTDIR}/src/config/pll.o ${OBJECTDIR}/src/dht/dht.o ${OBJECTDIR}/src/oled/OLED.o ${OBJECTDIR}/src/oled/i2c_routines.o ${OBJECTDIR}/src/timer/timer.o ${OBJECTDIR}/src/timer/timerstart.o ${OBJECTDIR}/src/uart/uart.o ${OBJECTDIR}/src/uart/uart_dsPIC.o ${OBJECTDIR}/src/main.o

# Source Files
SOURCEFILES=src/config/global_definitions.c src/config/pll.c src/dht/dht.c src/oled/OLED.c src/oled/i2c_routines.c src/timer/timer.c src/timer/timerstart.c src/uart/uart.c src/uart/uart_dsPIC.c src/main.c



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

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/dht_22_FJ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33FJ128GP802
MP_LINKER_FILE_OPTION=,--script=p33FJ128GP802.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/config/global_definitions.o: src/config/global_definitions.c  .generated_files/flags/default/e643786b4e6e025638f0c9a373f7da7cb0edddcd .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o.d 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/global_definitions.c  -o ${OBJECTDIR}/src/config/global_definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/global_definitions.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/pll.o: src/config/pll.c  .generated_files/flags/default/4bd5e6b467d495b3eb6a8a80d2987f653e88e0f7 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/pll.o.d 
	@${RM} ${OBJECTDIR}/src/config/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/pll.c  -o ${OBJECTDIR}/src/config/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/pll.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/dht/dht.o: src/dht/dht.c  .generated_files/flags/default/df52e73ed7defc0373e1602e1b1ae88a887887be .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/dht" 
	@${RM} ${OBJECTDIR}/src/dht/dht.o.d 
	@${RM} ${OBJECTDIR}/src/dht/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/dht/dht.c  -o ${OBJECTDIR}/src/dht/dht.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/dht/dht.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/OLED.o: src/oled/OLED.c  .generated_files/flags/default/fb1c357b63eb34ccdd97ad5a6a485c12f72e2686 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o.d 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/OLED.c  -o ${OBJECTDIR}/src/oled/OLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/OLED.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/i2c_routines.o: src/oled/i2c_routines.c  .generated_files/flags/default/4df9c4f97f5b758b53b3a8a0ee22090d9e02897f .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o.d 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/i2c_routines.c  -o ${OBJECTDIR}/src/oled/i2c_routines.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/i2c_routines.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timer.o: src/timer/timer.c  .generated_files/flags/default/4acfc96442c347a2746a0a4d8e68445618c092ba .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timer.c  -o ${OBJECTDIR}/src/timer/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timerstart.o: src/timer/timerstart.c  .generated_files/flags/default/26743339f78aea963bff974937540c8e9366ba59 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timerstart.c  -o ${OBJECTDIR}/src/timer/timerstart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timerstart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart.o: src/uart/uart.c  .generated_files/flags/default/3a038de5e90e3be5f539b11dffee24c7ca82391c .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart.c  -o ${OBJECTDIR}/src/uart/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart_dsPIC.o: src/uart/uart_dsPIC.c  .generated_files/flags/default/710c9b6600b92d351a999a2b34ba8c97b01554d5 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart_dsPIC.c  -o ${OBJECTDIR}/src/uart/uart_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_dsPIC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/cadd2e53a9a62041dfbac6eb99e8217be5335d8 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/config/global_definitions.o: src/config/global_definitions.c  .generated_files/flags/default/d79178f3a5b67e618cb58fbd551fd5fbf3ae8aa7 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o.d 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/global_definitions.c  -o ${OBJECTDIR}/src/config/global_definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/global_definitions.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/pll.o: src/config/pll.c  .generated_files/flags/default/fb7068d38e38c26ae596097da710b570103f5295 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/pll.o.d 
	@${RM} ${OBJECTDIR}/src/config/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/pll.c  -o ${OBJECTDIR}/src/config/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/pll.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/dht/dht.o: src/dht/dht.c  .generated_files/flags/default/f3ac82cafa2c8236cf01a326b3cdf5640283449f .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/dht" 
	@${RM} ${OBJECTDIR}/src/dht/dht.o.d 
	@${RM} ${OBJECTDIR}/src/dht/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/dht/dht.c  -o ${OBJECTDIR}/src/dht/dht.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/dht/dht.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/OLED.o: src/oled/OLED.c  .generated_files/flags/default/e52102983055fea93941f136d6cbc4f186a74931 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o.d 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/OLED.c  -o ${OBJECTDIR}/src/oled/OLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/OLED.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/i2c_routines.o: src/oled/i2c_routines.c  .generated_files/flags/default/4a77584d7925de4b98c56d100906b03371fd3374 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o.d 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/i2c_routines.c  -o ${OBJECTDIR}/src/oled/i2c_routines.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/i2c_routines.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timer.o: src/timer/timer.c  .generated_files/flags/default/f3e35a4e080cda00a3aea6e081d16f590d3f52d .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timer.c  -o ${OBJECTDIR}/src/timer/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timerstart.o: src/timer/timerstart.c  .generated_files/flags/default/e62ea0414d90eb986f656be9c9e023e80fdd5b23 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timerstart.c  -o ${OBJECTDIR}/src/timer/timerstart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timerstart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart.o: src/uart/uart.c  .generated_files/flags/default/b6c5b5df5a73f1293a576ef4ba9d4be7f36ca196 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart.c  -o ${OBJECTDIR}/src/uart/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart_dsPIC.o: src/uart/uart_dsPIC.c  .generated_files/flags/default/eced963132478c6ff78dc5ee782318829a89fb60 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart_dsPIC.c  -o ${OBJECTDIR}/src/uart/uart_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_dsPIC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/1e3be5990ca05398561140e308ac53df9fad0db0 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${DISTDIR}/dht_22_FJ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/dht_22_FJ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD4=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/dht_22_FJ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/dht_22_FJ.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/dht_22_FJ.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
