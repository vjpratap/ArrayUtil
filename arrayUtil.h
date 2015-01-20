typedef struct array arrayUtil;

struct array {
	void *base;
	int typeSize;
	int length;
};

int areEqual(arrayUtil *, arrayUtil *);
