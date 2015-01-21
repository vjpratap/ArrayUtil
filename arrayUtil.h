typedef struct array ArrayUtil;

struct array {
	void *base;
	int typeSize;
	int length;
};

int areEqual(ArrayUtil , ArrayUtil );
ArrayUtil create(int , int);
ArrayUtil resize(ArrayUtil , int);
int findIndex(ArrayUtil , void *);
void dispose(ArrayUtil);
