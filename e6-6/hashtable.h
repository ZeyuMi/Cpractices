struct nlist{
	struct nlist *next;
	char *name;
	char *defn;
};

struct nlist *install(char *, char *);
struct nlist *lookup(char *);
int undef(char *);

