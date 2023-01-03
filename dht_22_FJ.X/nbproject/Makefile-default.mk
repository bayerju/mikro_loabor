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
SOURCEFILES_QUOTED_IF_SPACED=src/config/global_definitions.c src/config/pll.c src/dht/dht.c src/oled/OLED.c src/oled/i2c_routines.c src/timer/timer.c src/timer/timerstart.c src/uart/uart.c src/uart/uart_dsPIC.c src/main.c src/ampel/ampel.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/config/global_definitions.o ${OBJECTDIR}/src/config/pll.o ${OBJECTDIR}/src/dht/dht.o ${OBJECTDIR}/src/oled/OLED.o ${OBJECTDIR}/src/oled/i2c_routines.o ${OBJECTDIR}/src/timer/timer.o ${OBJECTDIR}/src/timer/timerstart.o ${OBJECTDIR}/src/uart/uart.o ${OBJECTDIR}/src/uart/uart_dsPIC.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/ampel/ampel.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/config/global_definitions.o.d ${OBJECTDIR}/src/config/pll.o.d ${OBJECTDIR}/src/dht/dht.o.d ${OBJECTDIR}/src/oled/OLED.o.d ${OBJECTDIR}/src/oled/i2c_routines.o.d ${OBJECTDIR}/src/timer/timer.o.d ${OBJECTDIR}/src/timer/timerstart.o.d ${OBJECTDIR}/src/uart/uart.o.d ${OBJECTDIR}/src/uart/uart_dsPIC.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/ampel/ampel.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/config/global_definitions.o ${OBJECTDIR}/src/config/pll.o ${OBJECTDIR}/src/dht/dht.o ${OBJECTDIR}/src/oled/OLED.o ${OBJECTDIR}/src/oled/i2c_routines.o ${OBJECTDIR}/src/timer/timer.o ${OBJECTDIR}/src/timer/timerstart.o ${OBJECTDIR}/src/uart/uart.o ${OBJECTDIR}/src/uart/uart_dsPIC.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/ampel/ampel.o

# Source Files
SOURCEFILES=src/config/global_definitions.c src/config/pll.c src/dht/dht.c src/oled/OLED.c src/oled/i2c_routines.c src/timer/timer.c src/timer/timerstart.c src/uart/uart.c src/uart/uart_dsPIC.c src/main.c src/ampel/ampel.c



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
${OBJECTDIR}/src/config/global_definitions.o: src/config/global_definitions.c  .generated_files/flags/default/77e7536ba9de67ee9b353ae2e13eacb8fe4197e9 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o.d 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/global_definitions.c  -o ${OBJECTDIR}/src/config/global_definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/global_definitions.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/pll.o: src/config/pll.c  .generated_files/flags/default/91f9aefcbd3815db13e7663893ca87fe1a195e2e .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/pll.o.d 
	@${RM} ${OBJECTDIR}/src/config/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/pll.c  -o ${OBJECTDIR}/src/config/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/pll.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/dht/dht.o: src/dht/dht.c  .generated_files/flags/default/ac305230ecacbcb7ebeebc6cc76dece73ee3e920 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/dht" 
	@${RM} ${OBJECTDIR}/src/dht/dht.o.d 
	@${RM} ${OBJECTDIR}/src/dht/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/dht/dht.c  -o ${OBJECTDIR}/src/dht/dht.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/dht/dht.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/OLED.o: src/oled/OLED.c  .generated_files/flags/default/fdecd63c975d33f9d4a612e9de922c0f09928722 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o.d 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/OLED.c  -o ${OBJECTDIR}/src/oled/OLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/OLED.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/i2c_routines.o: src/oled/i2c_routines.c  .generated_files/flags/default/d0197bf87518ccf86e2d80c832cdd7c35b27085 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o.d 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/i2c_routines.c  -o ${OBJECTDIR}/src/oled/i2c_routines.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/i2c_routines.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timer.o: src/timer/timer.c  .generated_files/flags/default/8febe08efdba925d9bc89fda5511daf46ae8fead .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timer.c  -o ${OBJECTDIR}/src/timer/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timerstart.o: src/timer/timerstart.c  .generated_files/flags/default/a4c3307c5a08d250dccd7765320b86e4f962b9c4 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timerstart.c  -o ${OBJECTDIR}/src/timer/timerstart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timerstart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart.o: src/uart/uart.c  .generated_files/flags/default/acac886dad6f0de80cbf30fb6a6eb23bfc87a9c7 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart.c  -o ${OBJECTDIR}/src/uart/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart_dsPIC.o: src/uart/uart_dsPIC.c  .generated_files/flags/default/827c6034037c63554164b3a9bf0f11c1f116d05d .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart_dsPIC.c  -o ${OBJECTDIR}/src/uart/uart_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_dsPIC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/116f9dae241dddc965ad299a6455b80756567c1 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/ampel/ampel.o: src/ampel/ampel.c  .generated_files/flags/default/bdc621115a767bc9303c8fd6c341005a916597c1 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/ampel" 
	@${RM} ${OBJECTDIR}/src/ampel/ampel.o.d 
	@${RM} ${OBJECTDIR}/src/ampel/ampel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/ampel/ampel.c  -o ${OBJECTDIR}/src/ampel/ampel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/ampel/ampel.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/config/global_definitions.o: src/config/global_definitions.c  .generated_files/flags/default/a96981224e9bc09f74a5de0d8c9dab73985ade9a .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o.d 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/global_definitions.c  -o ${OBJECTDIR}/src/config/global_definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/global_definitions.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/pll.o: src/config/pll.c  .generated_files/flags/default/6f3e4a1e9efabcfbd40624a8aafe30d0bf7b1844 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/pll.o.d 
	@${RM} ${OBJECTDIR}/src/config/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/pll.c  -o ${OBJECTDIR}/src/config/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/pll.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/dht/dht.o: src/dht/dht.c  .generated_files/flags/default/78b8fd43adefdbde826c90848b7b6d03ca73bcb .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/dht" 
	@${RM} ${OBJECTDIR}/src/dht/dht.o.d 
	@${RM} ${OBJECTDIR}/src/dht/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/dht/dht.c  -o ${OBJECTDIR}/src/dht/dht.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/dht/dht.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/OLED.o: src/oled/OLED.c  .generated_files/flags/default/7e53d0665c9e7f94d4b3f1e649e1e0760a43f04d .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o.d 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/OLED.c  -o ${OBJECTDIR}/src/oled/OLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/OLED.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/i2c_routines.o: src/oled/i2c_routines.c  .generated_files/flags/default/5f6db54fc2de76e75a45d839d8623dc78d2cc625 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o.d 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/i2c_routines.c  -o ${OBJECTDIR}/src/oled/i2c_routines.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/i2c_routines.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timer.o: src/timer/timer.c  .generated_files/flags/default/43b73ebccf7625fc19e37e1a62c90e8f75412e73 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timer.c  -o ${OBJECTDIR}/src/timer/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timerstart.o: src/timer/timerstart.c  .generated_files/flags/default/8b9258a3c37d7e508e7a00a32362c4e4670eabbb .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timerstart.c  -o ${OBJECTDIR}/src/timer/timerstart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timerstart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart.o: src/uart/uart.c  .generated_files/flags/default/93077291f7a8d79c3bba86bd75b53fd194fcf2f2 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart.c  -o ${OBJECTDIR}/src/uart/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart_dsPIC.o: src/uart/uart_dsPIC.c  .generated_files/flags/default/fdfe60c2822cf3751b1be94711a002e4f3358a6 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart_dsPIC.c  -o ${OBJECTDIR}/src/uart/uart_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_dsPIC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/38947179eeaaa72a16871656f5026b903f604852 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/ampel/ampel.o: src/ampel/ampel.c  .generated_files/flags/default/a556e469ae6958ad78a0bd5789a55911349ebaa8 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/ampel" 
	@${RM} ${OBJECTDIR}/src/ampel/ampel.o.d 
	@${RM} ${OBJECTDIR}/src/ampel/ampel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/ampel/ampel.c  -o ${OBJECTDIR}/src/ampel/ampel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/ampel/ampel.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
