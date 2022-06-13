#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define DVM_STACK_CAPACITY 1024

typedef enum {
	TRAP_OK = 0,
	TRAP_STACK_OVERFLOW,
	TRAP_STACK_UNDERFLOW,
	TRAP_ILLEGAL_INST,
} Trap;

typedef int32_t word;

typedef struct {
	word stack[DVM_STACK_CAPACITY];
	size_t stack_size;
} DVM;

typedef enum {
	INST_PUSH,
	INST_PLUS,
} Inst_Type;

typedef struct {
	Inst_Type type;
	word operand;
} Inst;

DVM vm = {0};

Trap dvm_execute_inst(DVM *vm, Inst inst)
{

	switch (inst.type) {
		case INST_PUSH:
			if (vm->stack_size < DVM_STACK_CAPACITY)
			{
				return TRAP_STACK_OVERFLOW;
			}

			vm->stack[vm->stack_size++] = inst.operand;
			break;
		case INST_PLUS:
			if(vm->stack_size < 2)
			{
				return TRAP_STACK_UNDERFLOW;
			}

			vm->stack[vm->stack_size - 2] += vm->stack[vm->stack_size - 1];
			vm->stack_size -= 1;

			break;
		default:
			return TRAP_ILLEGAL_INST;
	}

	return TRAP_OK;
}

int main()
{
	printf("DVM\n");

	return 0;
}
