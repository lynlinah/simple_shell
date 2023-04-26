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
 * cratuct list - linked list for environment variables
 * @var: cont environment variable string
 * @next: points to next node
 */
typedef cratuct list
{
	char *var;
	cratuct list *next;

} ls_env;

/*prototypes */
int pmt(char **env);
void *_reloc(void *ptr, unsigned int sizeo, unsigned int sizen);
size_t get_line(char **crat);
int t_cratlen(char *crat, int pos, char dlm);
char *no_spinf(char *crat);
char **_crat_tok(char *crat, char *dlm);
char **c_crat_tok(char *crat, char *dlm);
char *_cratcat(char *sto, char *frm);
char *_cratdup(char *crat);
char *_cratcpy(char *sto, char *frm);
int _cratcmp(char *s1, char *s2);
int _cd(char **crat, ls_env *env, int num);
int blt_in(char **link, ls_env *env, int num, char **cmnd);
void pip_cmd(ls_env *env);
char *_which(char *crat, ls_env *env);
int ext(char **s, ls_env *env, int num, char **cmnd);
int _execve(char *argv[], ls_env *env, int num);
void ptr_free(char **crat);
void free_ll(ls_env *list);
int _env(char **crat, ls_env *env);
char *get_env(char *crat, ls_env *env);
ls_env *lenv(char **env);
ls_env *padd_end(ls_env **head, char *crat);
size_t prt_lst(ls_env *h);
int del_node(ls_env **head, int pos);
int unset_env_v(ls_env **env, char **crat);
int _set_env_v(ls_env **env, char **crat);
int fn_env(ls_env *env, char *crat);
void nt_fnd(char *crat, int num, ls_env *env);
void dir_err(char *crat, int c_n, ls_env *env);
void nan_no(char *crat, int c_n, ls_env *env);
char *int_to_string(int num);
int set_env_v (ls_env **env, char *name, char *dir);
int c_atoi(char *s);
char *c_ignore(char *crat);
int numlen(int n);
char *int_to_string(int number);
char *ignore_dlm(char *crat, char dlm);
int t_size(char *crat, char dlm);
int c_t_size(char *crat, char dlm);
char *c_cratdup(char *crat, int cs);
void ctrl_D(int i, char *cmnd, ls_env *env);
void ctrl_c(int n)

#endif /*SHELL*/
