#ifndef CODEGEN_H
#define CODEGEN_H

#include "decl.h"
#include "stmt.h"
#include "expr.h"


void decl_codegen(struct decl *d, int segment);
void function_preamble_codegen(struct decl *d);
void function_epilogue_codegen(struct decl *d);

void stmt_codegen(struct stmt *s, struct decl *func);
void print_codegen(struct stmt *s);
void if_else_codegen(struct stmt *s, struct decl *func);
void for_loop_codegen(struct stmt *s, struct decl *func);

int label_create();
char *label_name(int i);

void expr_codegen(struct expr *e);
void comparison_codegen(struct expr *e, char *type);
void func_codegen(struct expr *e);
void array_start_codegen(struct expr *e);
void array_start_address_codegen(struct expr *e);
void assignment_codegen(struct expr *e);

char* symbol_codegen(struct symbol *s);

char *scratch_name(int reg);
int scratch_alloc();
void scratch_free(int reg);

#endif
