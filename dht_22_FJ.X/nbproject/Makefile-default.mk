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
SOURCEFILES_QUOTED_IF_SPACED=src/ampel/ampel.c src/config/global_definitions.c src/config/pll.c src/dht/dht.c src/oled/OLED.c src/oled/i2c_routines.c src/timer/timer.c src/timer/timerstart.c src/uart/uart.c src/uart/uart_dsPIC.c src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/ampel/ampel.o ${OBJECTDIR}/src/config/global_definitions.o ${OBJECTDIR}/src/config/pll.o ${OBJECTDIR}/src/dht/dht.o ${OBJECTDIR}/src/oled/OLED.o ${OBJECTDIR}/src/oled/i2c_routines.o ${OBJECTDIR}/src/timer/timer.o ${OBJECTDIR}/src/timer/timerstart.o ${OBJECTDIR}/src/uart/uart.o ${OBJECTDIR}/src/uart/uart_dsPIC.o ${OBJECTDIR}/src/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/ampel/ampel.o.d ${OBJECTDIR}/src/config/global_definitions.o.d ${OBJECTDIR}/src/config/pll.o.d ${OBJECTDIR}/src/dht/dht.o.d ${OBJECTDIR}/src/oled/OLED.o.d ${OBJECTDIR}/src/oled/i2c_routines.o.d ${OBJECTDIR}/src/timer/timer.o.d ${OBJECTDIR}/src/timer/timerstart.o.d ${OBJECTDIR}/src/uart/uart.o.d ${OBJECTDIR}/src/uart/uart_dsPIC.o.d ${OBJECTDIR}/src/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/ampel/ampel.o ${OBJECTDIR}/src/config/global_definitions.o ${OBJECTDIR}/src/config/pll.o ${OBJECTDIR}/src/dht/dht.o ${OBJECTDIR}/src/oled/OLED.o ${OBJECTDIR}/src/oled/i2c_routines.o ${OBJECTDIR}/src/timer/timer.o ${OBJECTDIR}/src/timer/timerstart.o ${OBJECTDIR}/src/uart/uart.o ${OBJECTDIR}/src/uart/uart_dsPIC.o ${OBJECTDIR}/src/main.o

# Source Files
SOURCEFILES=src/ampel/ampel.c src/config/global_definitions.c src/config/pll.c src/dht/dht.c src/oled/OLED.c src/oled/i2c_routines.c src/timer/timer.c src/timer/timerstart.c src/uart/uart.c src/uart/uart_dsPIC.c src/main.c



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
${OBJECTDIR}/src/ampel/ampel.o: src/ampel/ampel.c  .generated_files/flags/default/3cd0ff1ef06234c06de48c325e83319fd0cfcd26 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/ampel" 
	@${RM} ${OBJECTDIR}/src/ampel/ampel.o.d 
	@${RM} ${OBJECTDIR}/src/ampel/ampel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/ampel/ampel.c  -o ${OBJECTDIR}/src/ampel/ampel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/ampel/ampel.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/global_definitions.o: src/config/global_definitions.c  .generated_files/flags/default/a5bcde9b80aba380c8450158a947396e9a4c8155 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o.d 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/global_definitions.c  -o ${OBJECTDIR}/src/config/global_definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/global_definitions.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/pll.o: src/config/pll.c  .generated_files/flags/default/d6849961e06b97eec69e778c8a8797688327f60b .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/pll.o.d 
	@${RM} ${OBJECTDIR}/src/config/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/pll.c  -o ${OBJECTDIR}/src/config/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/pll.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/dht/dht.o: src/dht/dht.c  .generated_files/flags/default/ccba64886c1e4e78e1427a4476707cdfc4d214bd .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/dht" 
	@${RM} ${OBJECTDIR}/src/dht/dht.o.d 
	@${RM} ${OBJECTDIR}/src/dht/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/dht/dht.c  -o ${OBJECTDIR}/src/dht/dht.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/dht/dht.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/OLED.o: src/oled/OLED.c  .generated_files/flags/default/351637067b91a28ad58791bc489e44f5c357b941 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o.d 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/OLED.c  -o ${OBJECTDIR}/src/oled/OLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/OLED.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/i2c_routines.o: src/oled/i2c_routines.c  .generated_files/flags/default/f65f26396a057d36905c14001dfb88fb4641c2b3 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o.d 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/i2c_routines.c  -o ${OBJECTDIR}/src/oled/i2c_routines.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/i2c_routines.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timer.o: src/timer/timer.c  .generated_files/flags/default/c0bb0ae22090e4505ce32824fda195b0d2000747 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timer.c  -o ${OBJECTDIR}/src/timer/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timerstart.o: src/timer/timerstart.c  .generated_files/flags/default/a45b582bfe0a0d141738c9cebc2f741ddfed36fe .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timerstart.c  -o ${OBJECTDIR}/src/timer/timerstart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timerstart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart.o: src/uart/uart.c  .generated_files/flags/default/689f6703d8c7ffac7b06254701cc59d9b835ec1a .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart.c  -o ${OBJECTDIR}/src/uart/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart_dsPIC.o: src/uart/uart_dsPIC.c  .generated_files/flags/default/9042906a4ed682a6841f0c6edcb5671bb845ddea .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart_dsPIC.c  -o ${OBJECTDIR}/src/uart/uart_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_dsPIC.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/948d197d1301b72b7f32cb4773f0e5ccbe83c2ad .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/ampel/ampel.o: src/ampel/ampel.c  .generated_files/flags/default/dc0aefb39e516658653a7d18295ba29e0671551 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/ampel" 
	@${RM} ${OBJECTDIR}/src/ampel/ampel.o.d 
	@${RM} ${OBJECTDIR}/src/ampel/ampel.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/ampel/ampel.c  -o ${OBJECTDIR}/src/ampel/ampel.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/ampel/ampel.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/global_definitions.o: src/config/global_definitions.c  .generated_files/flags/default/ae60f966f374100e61e97371e1cb7ec05197ef73 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o.d 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/global_definitions.c  -o ${OBJECTDIR}/src/config/global_definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/global_definitions.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/pll.o: src/config/pll.c  .generated_files/flags/default/b334b1ee62bd2c6a245551fcffe5a9f8024e202b .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/pll.o.d 
	@${RM} ${OBJECTDIR}/src/config/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/pll.c  -o ${OBJECTDIR}/src/config/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/pll.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/dht/dht.o: src/dht/dht.c  .generated_files/flags/default/3592fc44e1103b9ddc32f1cdd6dd33802fb097ac .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/dht" 
	@${RM} ${OBJECTDIR}/src/dht/dht.o.d 
	@${RM} ${OBJECTDIR}/src/dht/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/dht/dht.c  -o ${OBJECTDIR}/src/dht/dht.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/dht/dht.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/OLED.o: src/oled/OLED.c  .generated_files/flags/default/3ba689e6ef0a8864fa4e02dcd633d7e7a5adc497 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o.d 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/OLED.c  -o ${OBJECTDIR}/src/oled/OLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/OLED.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/i2c_routines.o: src/oled/i2c_routines.c  .generated_files/flags/default/86216679f9488ef84da80cb320041e6a89392fde .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o.d 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/i2c_routines.c  -o ${OBJECTDIR}/src/oled/i2c_routines.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/i2c_routines.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timer.o: src/timer/timer.c  .generated_files/flags/default/d21450af15aff47f28f3633142ceb0dd6d8091ed .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timer.c  -o ${OBJECTDIR}/src/timer/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timerstart.o: src/timer/timerstart.c  .generated_files/flags/default/3e978ede17cda1ccfa4a3fb07701f78e6a6ad533 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timerstart.c  -o ${OBJECTDIR}/src/timer/timerstart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timerstart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart.o: src/uart/uart.c  .generated_files/flags/default/497a8a8be4ef98b546367a3402d0be26c93dcbc8 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart.c  -o ${OBJECTDIR}/src/uart/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart_dsPIC.o: src/uart/uart_dsPIC.c  .generated_files/flags/default/856b7de6dee647b25cc796b83a1a11f71eaab60 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart_dsPIC.c  -o ${OBJECTDIR}/src/uart/uart_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_dsPIC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/cd8ef23c24b0f0a9fc53b53ef0de0c359b955d94 .generated_files/flags/default/154a39b459d497157d1f034ee9131ad407b9cda3
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -I"src/ampel" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
