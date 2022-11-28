/*
 * @lc app=leetcode id=225 lang=c
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start

typedef struct
{
  int read_idx;
  int write_idx;
  int *buf;
  int size;
} Queue;

#define SIZE  10

int myBuffer[SIZE] = {0};
Queue myQueue;

void createQueue(Queue *queue, int *buffer, int buf_size)
{
  memset(buffer, 0, sizeof(buffer));
  queue->buf = buffer;
  queue->read_idx = 0;
  queue->write_idx = 0;
  queue->size = buf_size;
}

bool isEmptyQueue(Queue *queue)
{
  return queue->read_idx == queue->write_idx;
}

int sizeQueue(Queue *queue)
{
  if (queue->write_idx >= queue->read_idx)
  {
    return queue->write_idx - queue->read_idx;
  }
  else
  {
    return queue->size + queue->write_idx - queue->read_idx;
  }
}

bool isFullQueue(Queue *queue)
{
  return queue->read_idx == ((queue->write_idx + 1) % queue->size);
}

void pushQueue(Queue *queue, int val)
{
  if (!isFullQueue(queue))
  {
    queue->buf[queue->write_idx] = val;
    queue->write_idx = (queue->write_idx + 1) % queue->size;
  }
}

int peekQueue(Queue *queue)
{
  if (!isEmptyQueue(queue))
  {
    return queue->buf[queue->read_idx];
  }
  else
  {
    return -1;
  }
}

int popQueue(Queue *queue)
{
  if (!isEmptyQueue(queue))
  {
    int ret = queue->buf[queue->read_idx];
    queue->read_idx = (queue->read_idx + 1) % queue->size;
    return ret;
  }
  else
  {
    return -1;
  }
}

typedef struct
{
  Queue *queue;
} MyStack;

MyStack myStack;

MyStack *myStackCreate()
{
  createQueue(&myQueue, myBuffer, SIZE);

  myStack.queue = &myQueue;

  return &myStack;
}

void myStackPush(MyStack *obj, int x)
{
  pushQueue(obj->queue, x);
}

int myStackPop(MyStack *obj)
{
  int size = sizeQueue(obj->queue);

  if (size <= 0)
  {
    return -1;
  }

  while (size > 1)
  {
    int val = popQueue(obj->queue);

    pushQueue(obj->queue, val);

    size--;
  }

  return popQueue(obj->queue);
}

int myStackTop(MyStack *obj)
{
  int val = myStackPop(obj);
  myStackPush(obj, val);

  return val;
}

bool myStackEmpty(MyStack *obj)
{
  return isEmptyQueue(obj->queue);
}

void myStackFree(MyStack *obj)
{
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
// @lc code=end
