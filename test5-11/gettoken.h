#define MAXTOKEN 100
enum {NAME, PARENS, BRACKETS};
int gettoken(void);
extern int tokentype;
extern char token[MAXTOKEN];
extern char name[MAXTOKEN];
extern char datatype[MAXTOKEN];
extern char out[1000];
