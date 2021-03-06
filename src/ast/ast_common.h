#ifndef AST_COMMON_H
#define AST_COMMON_H

typedef struct _ast_func_call_node       ast_func_call_node;  // foo()

typedef struct _ast_var_node             ast_var_node;
typedef struct _ast_var_non_indexed_node ast_var_non_indexed_node; // a
typedef struct _ast_var_indexed_node     ast_var_indexed_node;     // a[2]

typedef struct _exp_list_node    exp_list_node;

// Var node

typedef enum
{
  linked,
  not_linked
} ast_link_status;

struct _ast_var_non_indexed_node
{
  ast_link_status link_status;
  union {
    const char *var_name; 
    ast_decl_node *decl;
  } value;
};

struct _ast_var_indexed_node
{
  ast_exp_node *base;
  ast_exp_node *index;
};

typedef enum
{
  non_indexed,
  indexed
  
} ast_var_tag;

struct _ast_var_node
{
  ast_var_tag tag;

  union
  {
    ast_var_non_indexed_node non_indexed;
    ast_var_indexed_node     indexed;

  } value;
};

// Function call node

struct _ast_func_call_node
{
  ast_link_status link_status;
  union {
    const char    *func_name;
    ast_decl_node *decl;
  } value;
  exp_list_node *params;
};

// Expression List

struct _exp_list_node
{
  ast_exp_node  *exp;
  exp_list_node *next;
};

#endif