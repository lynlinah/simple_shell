#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* function prototypes listed below */
int pmpt(char **env_v);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t get_line(char **str);
int t_strlen(char *str, int pos, char delm);
char *no_spc_inf(char *str);
char **_str_tok(char *str, char *delm);
char **c_str_tok(char *str, char *delm);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _cd(char **str, list_t *env, int num);
int blt_in(char **cmd, list_t *env_v, int err, char **f_cmd);
void non_inv(list_t *env_v);
char *_which(char *str, list_t *env);
int __exit(char **s, list_t *env, int num, char **command);
int _execve(char *argv[], list_t *env, int num);
void fr_ptr(char **astr);
void free_linked_list(list_t *list) ;
int env_v(char **cmd, list_t *env_v);
char *g_env_v(char *str, list_t *env_v);
list_t *env_ll(char **env_v);
list_t *add_end_node(list_t **head, char *str);
size_t prt_lst(list_t *link);
int delete_nodeint_at_index(list_t **head, int index);
int fn_env_v(list_t *env_v, char *var);
int unset_env_v(list_t **env_v, char **var);
int set_env_v(list_t **env_v, char **var);
void not_fn(char *cmd, int cmd_i, list_t *env_v);
void not_exec(char *cmd, int cmd_i, list_t *env_v)
void nan_no(char *cmd, int cmd_i, list_t *env_v);
char *int2str(int num);
void ctrl_c(int sig);
void ctrl_D(int i, char *f_cmd, list_t *env_v);
char *no_spc(char *env_v);
int cnt_n0(int n);
char *str_dup(char *str, int x_bt);


#endif
