/*
 * @lc app=leetcode id=1114 lang=c
 *
 * [1114] Print in Order
 */

// @lc code=start
typedef struct {
    // User defined data may be declared here.
    volatile int state[2];    
} Foo;

#define NONE            (0)
#define CALLED          (1)
#define EXECUTED        (2)


Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    for (int i = 0; i < 2; i++)
    {
        obj->state[i] = NONE;
    }

    return obj;
}

void first(Foo* obj)
{
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    obj->state[0] = EXECUTED;
}

void second(Foo* obj)
{
    while (obj->state[0] != EXECUTED);

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();

    obj->state[1] = EXECUTED;
}

void third(Foo* obj)
{
    while (obj->state[0] != EXECUTED);

    while (obj->state[1] != EXECUTED);

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
}
// @lc code=end

