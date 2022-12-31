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
SOURCEFILES_QUOTED_IF_SPACED=src/config/global_definitions.c src/config/pll.c src/dht/dht.c src/main.c src/oled/OLED.c src/timer/timer.c src/timer/timerstart.c src/uart/uart.c src/uart/uart_dsPIC.c src/oled/i2c_routines.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/config/global_definitions.o ${OBJECTDIR}/src/config/pll.o ${OBJECTDIR}/src/dht/dht.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/oled/OLED.o ${OBJECTDIR}/src/timer/timer.o ${OBJECTDIR}/src/timer/timerstart.o ${OBJECTDIR}/src/uart/uart.o ${OBJECTDIR}/src/uart/uart_dsPIC.o ${OBJECTDIR}/src/oled/i2c_routines.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/config/global_definitions.o.d ${OBJECTDIR}/src/config/pll.o.d ${OBJECTDIR}/src/dht/dht.o.d ${OBJECTDIR}/src/main.o.d ${OBJECTDIR}/src/oled/OLED.o.d ${OBJECTDIR}/src/timer/timer.o.d ${OBJECTDIR}/src/timer/timerstart.o.d ${OBJECTDIR}/src/uart/uart.o.d ${OBJECTDIR}/src/uart/uart_dsPIC.o.d ${OBJECTDIR}/src/oled/i2c_routines.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/config/global_definitions.o ${OBJECTDIR}/src/config/pll.o ${OBJECTDIR}/src/dht/dht.o ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/oled/OLED.o ${OBJECTDIR}/src/timer/timer.o ${OBJECTDIR}/src/timer/timerstart.o ${OBJECTDIR}/src/uart/uart.o ${OBJECTDIR}/src/uart/uart_dsPIC.o ${OBJECTDIR}/src/oled/i2c_routines.o

# Source Files
SOURCEFILES=src/config/global_definitions.c src/config/pll.c src/dht/dht.c src/main.c src/oled/OLED.c src/timer/timer.c src/timer/timerstart.c src/uart/uart.c src/uart/uart_dsPIC.c src/oled/i2c_routines.c



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
${OBJECTDIR}/src/config/global_definitions.o: src/config/global_definitions.c  .generated_files/flags/default/6c38496c22d4d7ac062523944dae3e17c4d92b5d .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o.d 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/global_definitions.c  -o ${OBJECTDIR}/src/config/global_definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/global_definitions.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/pll.o: src/config/pll.c  .generated_files/flags/default/a1db93e4586b43d647c54b3ab3285baf5d1055cc .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/pll.o.d 
	@${RM} ${OBJECTDIR}/src/config/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/pll.c  -o ${OBJECTDIR}/src/config/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/pll.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/dht/dht.o: src/dht/dht.c  .generated_files/flags/default/9442eb434a9cafda43bfcd2433b8f67363c84ae4 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/dht" 
	@${RM} ${OBJECTDIR}/src/dht/dht.o.d 
	@${RM} ${OBJECTDIR}/src/dht/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/dht/dht.c  -o ${OBJECTDIR}/src/dht/dht.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/dht/dht.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/cad665f033d0fdb5fd9dbe4354bb768b9189f115 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/OLED.o: src/oled/OLED.c  .generated_files/flags/default/fc53f3b97b23c97583316a1be174669651f5ddbd .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o.d 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/OLED.c  -o ${OBJECTDIR}/src/oled/OLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/OLED.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timer.o: src/timer/timer.c  .generated_files/flags/default/72d3fe504116ebb96c4ee124637ed29e7c0b4dd6 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timer.c  -o ${OBJECTDIR}/src/timer/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timer.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timerstart.o: src/timer/timerstart.c  .generated_files/flags/default/7e05b3028899d50ebf97a4c2dcaffc8119160b92 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timerstart.c  -o ${OBJECTDIR}/src/timer/timerstart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timerstart.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart.o: src/uart/uart.c  .generated_files/flags/default/a31f9a6bfdc324db66afee5df75bbcfb8f469313 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart.c  -o ${OBJECTDIR}/src/uart/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart_dsPIC.o: src/uart/uart_dsPIC.c  .generated_files/flags/default/2eae58bbe51a5ab8f321c7ddcebca8a840976e96 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart_dsPIC.c  -o ${OBJECTDIR}/src/uart/uart_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_dsPIC.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/i2c_routines.o: src/oled/i2c_routines.c  .generated_files/flags/default/a61dea487615116bed5647a2acb911e1869600c4 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o.d 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/i2c_routines.c  -o ${OBJECTDIR}/src/oled/i2c_routines.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/i2c_routines.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/src/config/global_definitions.o: src/config/global_definitions.c  .generated_files/flags/default/7e0332288b8eeac2ea819c8b5aa3e18255caddcc .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o.d 
	@${RM} ${OBJECTDIR}/src/config/global_definitions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/global_definitions.c  -o ${OBJECTDIR}/src/config/global_definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/global_definitions.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/config/pll.o: src/config/pll.c  .generated_files/flags/default/2a288593f3484dbc2d3f21d3f66f7b88abea69b8 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/config" 
	@${RM} ${OBJECTDIR}/src/config/pll.o.d 
	@${RM} ${OBJECTDIR}/src/config/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/config/pll.c  -o ${OBJECTDIR}/src/config/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/config/pll.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/dht/dht.o: src/dht/dht.c  .generated_files/flags/default/7477a77f222ae513c6e238407710f19dad0dd429 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/dht" 
	@${RM} ${OBJECTDIR}/src/dht/dht.o.d 
	@${RM} ${OBJECTDIR}/src/dht/dht.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/dht/dht.c  -o ${OBJECTDIR}/src/dht/dht.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/dht/dht.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/main.o: src/main.c  .generated_files/flags/default/ff37c5fa412e2404764a3c4de330a33243a25694 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/main.o.d 
	@${RM} ${OBJECTDIR}/src/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/main.c  -o ${OBJECTDIR}/src/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/OLED.o: src/oled/OLED.c  .generated_files/flags/default/40424f5ff74d4b717a986657c16a9a16e96372f .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o.d 
	@${RM} ${OBJECTDIR}/src/oled/OLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/OLED.c  -o ${OBJECTDIR}/src/oled/OLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/OLED.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timer.o: src/timer/timer.c  .generated_files/flags/default/21c2d501031efd98cb69a69a63373a78613e2731 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timer.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timer.c  -o ${OBJECTDIR}/src/timer/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timer.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/timer/timerstart.o: src/timer/timerstart.c  .generated_files/flags/default/edc0dc1640df636cd98008a29967d13290264e6a .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/timer" 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o.d 
	@${RM} ${OBJECTDIR}/src/timer/timerstart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/timer/timerstart.c  -o ${OBJECTDIR}/src/timer/timerstart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/timer/timerstart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart.o: src/uart/uart.c  .generated_files/flags/default/cb11eac2a41c95cfd1c1ed01590f5c9d020d8b6b .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart.c  -o ${OBJECTDIR}/src/uart/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/uart/uart_dsPIC.o: src/uart/uart_dsPIC.c  .generated_files/flags/default/6840cc0a946302a96c7d66af00f691e8eb679a1b .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/uart" 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o.d 
	@${RM} ${OBJECTDIR}/src/uart/uart_dsPIC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/uart/uart_dsPIC.c  -o ${OBJECTDIR}/src/uart/uart_dsPIC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/uart/uart_dsPIC.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/src/oled/i2c_routines.o: src/oled/i2c_routines.c  .generated_files/flags/default/df86f356d5bcbed1e2f464aa91cdbd63b7f5f7e0 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/src/oled" 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o.d 
	@${RM} ${OBJECTDIR}/src/oled/i2c_routines.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  src/oled/i2c_routines.c  -o ${OBJECTDIR}/src/oled/i2c_routines.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/src/oled/i2c_routines.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"src" -I"src/config" -I"src/dht" -I"src/oled" -I"src/timer" -I"src/uart" -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/dht_22_FJ.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
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
