typedef struct array ArrayUtil;
typedef int (match)(void*,void*);
struct array {
	void *base;
	int typeSize;
	int length;
};

typedef int (MatchFunc)(void *, void *);

typedef char * basePtr;

int areEqual(ArrayUtil , ArrayUtil );
ArrayUtil create(int , int);
ArrayUtil resize(ArrayUtil , int);
int findIndex(ArrayUtil , void *);
void dispose(ArrayUtil);
void* findFirst(ArrayUtil util, MatchFunc*, void* hint);
