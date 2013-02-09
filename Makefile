MAIN_SRC	=	example.c
EXAMPLE_SRC	=	ComplexNumber.c
API_SRC		=	ObjectSystem.c
FRAMEWORK_SRC	=	ObjectSystemFramework.c

EXAMPLE_H	=	ComplexNumber.h
API_H		=	ObjectSystem.h
FRAMEWORK_H	=	ObjectSystemFramework.h

SRC_DIR		=	src
HEADERS_DIR	=	headers
EXAMPLE_DIR	=	Example
FRAMEWORK_DIR	=	ObjC++

FRAMEWORK_SRC_D	=	${SRC_DIR}/${FRAMEWORK_DIR}
EXAMPLE_SRC_D	=	${SRC_DIR}/${EXAMPLE_DIR}
FRAMEWORK_H_D	=	${HEADERS_DIR}/${FRAMEWORK_DIR}
EXAMPLE_H_D	=	${HEADERS_DIR}/${EXAMPLE_DIR}

OBJ_DIR		=	obj

FRAMEWORK_OBJ_D	=	${OBJ_DIR}/${FRAMEWORK_DIR}
EXAMPLE_OBJ_D	=	${OBJ_DIR}/${EXAMPLE_DIR}

TARGET		=	ObjectiveC++

LDFLAGS		=	
CFLAGS		=	-O0 -g3 -Wall -Wextra -c

INCLUDE		=	.

CC		=	gcc

MAIN_OBJ	=	${OBJ_DIR}/${MAIN_SRC:.c=.o}
EXAMPLE_OBJ	=	${EXAMPLE_OBJ_D}/${EXAMPLE_SRC:.c=.o}
API_OBJ		=	${FRAMEWORK_OBJ_D}/${API_SRC:.c=.o}
FRAMEWORK_OBJ	=	${FRAMEWORK_OBJ_D}/${FRAMEWORK_SRC:.c=.o}

.PHONY: all clean

all: makedir ${TARGET}

makedir:
	mkdir -p ${FRAMEWORK_OBJ_D} ${EXAMPLE_OBJ_D}

${TARGET}: ${SRC_DIR}/example.c ${API_OBJ} ${FRAMEWORK_OBJ} ${FRAMEWORK_OBJ_D}/Bool.o ${FRAMEWORK_OBJ_D}/Character.o ${FRAMEWORK_OBJ_D}/Number.o ${FRAMEWORK_OBJ_D}/String.o ${EXAMPLE_OBJ}
# 	@echo linking target $@
	${CC} ${LDLAGS} -o $@ $^

${API_OBJ}: ${FRAMEWORK_SRC_D}/${API_SRC} ${FRAMEWORK_H_D}/${API_H} ${FRAMEWORK_OBJ} ${FRAMEWORK_OBJ_D}/Bool.o ${FRAMEWORK_OBJ_D}/Character.o ${FRAMEWORK_OBJ_D}/Number.o ${FRAMEWORK_OBJ_D}/String.o
# 	@echo compiling $@
	${CC} ${CFLAGS} -o $@ $<

${FRAMEWORK_OBJ}: ${FRAMEWORK_SRC_D}/${FRAMEWORK_SRC} ${FRAMEWORK_H_D}/${FRAMEWORK_H}
# 	@echo compiling $@
	${CC} ${CFLAGS} -o $@ $<

${FRAMEWORK_OBJ_D}/Bool.o: ${FRAMEWORK_SRC_D}/Bool.c ${FRAMEWORK_H_D}/Bool.h
# 	@echo compiling $@
	${CC} ${CFLAGS} -o $@ $<

${FRAMEWORK_OBJ_D}/Character.o: ${FRAMEWORK_SRC_D}/Character.c ${FRAMEWORK_H_D}/Character.h
# 	@echo compiling $@
	${CC} ${CFLAGS} -o $@ $<

${FRAMEWORK_OBJ_D}/Number.o: ${FRAMEWORK_SRC_D}/Number.c ${FRAMEWORK_H_D}/Number.h
# 	@echo compiling $@
	${CC} ${CFLAGS} -o $@ $<

${FRAMEWORK_OBJ_D}/String.o: ${FRAMEWORK_SRC_D}/String.c ${FRAMEWORK_H_D}/String.h
# 	@echo compiling $@
	${CC} ${CFLAGS} -o $@ $<

${EXAMPLE_OBJ}: ${EXAMPLE_SRC_D}/${EXAMPLE_SRC} ${EXAMPLE_H_D}/${EXAMPLE_H} ${FRAMEWORK_H_D}/${FRAMEWORK_H}
# 	@echo compiling $@
	${CC} ${CFLAGS} -o $@ $<

clean:
	rm -rf ${OBJ_DIR} ${TARGET}
