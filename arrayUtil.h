typedef struct array arrayUtil;

struct array {
	void *base;
	int typeSize;
	int length;
};

int areEqual(arrayUtil *, arrayUtil *);
arrayUtil create(int , int);
arrayUtil resize(arrayUtil *, int);
