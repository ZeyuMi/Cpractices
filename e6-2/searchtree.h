struct word{
	char *name;
	char *next;
	struct word *leftchild;
	struct word *rightchild;
};

struct word* addtree(struct word*, char *, int);
void printtree(struct word*);
